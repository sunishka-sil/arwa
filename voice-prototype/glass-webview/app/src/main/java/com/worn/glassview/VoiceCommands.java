package com.worn.glassview;

import android.content.Context;
import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.media.audiofx.AcousticEchoCanceler;
import android.net.Uri;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import org.json.JSONObject;
import org.vosk.LibVosk;
import org.vosk.LogLevel;
import org.vosk.Model;
import org.vosk.Recognizer;
import org.vosk.android.StorageService;

import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Listens on the glasses' own microphone (offline, Vosk) for voice commands and POSTs each one to the
 * server's /cmd, the same endpoint the phone/Mac remote uses:
 *   next, back, show, hide, repeat     → fire on the first guess (fast)
 *   voice off / sound off              → mute     (on the finished phrase, so "voice o…" can't flip wrong)
 *   voice on  / sound on               → unmute
 * ("mute"/"unmute" were dropped: the small model doesn't know "unmute", and "mute" was unreliable on the
 *  glasses. "voice off"/"voice on" were recognized 6/6 each and never confused, tested with six voices.)
 *
 * Interrupting the voice-over (barge-in). The glasses' mic also hears their own speaker, and a command-only
 * grammar turns that speech into commands (it once made the steps change by themselves). So while the
 * voice-over plays, a command only counts if the mic is clearly louder than the speaker's echo:
 *   - an echo canceller is switched on if the glasses have one (the M6 doesn't);
 *   - the echo level is measured during playback (median of the last 2 s), and a command needs a recent
 *     peak of at least BARGE_RATIO times that, which your own voice, right next to the mic, should give.
 * Levels are logged ("mic during voice-over: …") so the thresholds can be tuned on the real glasses.
 * Log: adb logcat -s GlassView
 */
class VoiceCommands {
    private static final String TAG = MainActivity.TAG;
    private static final int RATE = 16000;
    private static final int CHUNK = 1600;                 // 100 ms of audio per step
    private static final long ECHO_TAIL_MS = 500;          // speaker reverb + buffers after playback ends
    private static final long MAX_PLAYING_MS = 45000;     // safety: forget "playing" if the page never says "done"
    // Measured on the M6 (VOICE_RECOGNITION input, RMS of 16-bit samples per 100 ms):
    //   speaker echo alone: peaks up to 2.86x the echo median and up to 2439 absolute;
    //   a command spoken over it: ~4x and 3000-4000 absolute. Both conditions must hold.
    static float BARGE_RATIO = 2.5f;                       // voice must peak this many times above the echo level
    static int BARGE_MIN = 2500;                           // ...and above this absolute level
    private static final String GRAMMAR = "[\"next\", \"back\", \"show\", \"hide\", \"repeat\", "
            + "\"voice off\", \"voice on\", \"sound off\", \"sound on\", \"[unk]\"]";

    interface Status { void onVoiceStatus(String status); }

    private final Context context;
    private final Status status;
    private final ExecutorService net = Executors.newSingleThreadExecutor();
    private final Handler main = new Handler(Looper.getMainLooper());
    private volatile String cmdUrl;
    private Model model;
    private MicLoop mic;
    private volatile boolean appPaused = false;
    private volatile boolean playing = false;               // voice-over playing, or within its echo tail
    private final List<String> fired = new ArrayList<>();  // commands already sent for this utterance (main thread)

    VoiceCommands(Context context, Status status) {
        this.context = context.getApplicationContext();
        this.status = status;
        LibVosk.setLogLevel(LogLevel.WARNINGS);
    }

    /** Commands go to <origin of the page>/cmd, e.g. http://localhost:8080/cmd. */
    void setPageUrl(String pageUrl) {
        Uri u = Uri.parse(pageUrl);
        cmdUrl = u.getScheme() + "://" + u.getEncodedAuthority() + "/cmd";
    }

    void start() {
        if (mic != null) return;
        status.onVoiceStatus("loading model");
        // Copies the model from the APK's assets to app storage on first run (a few seconds), then loads it.
        StorageService.unpack(context, "model-en-us", "model",
                m -> { model = m; listen(); },
                e -> { Log.e(TAG, "voice: model failed", e); status.onVoiceStatus("model error: " + e.getMessage()); });
    }

    private void listen() {
        try {
            mic = new MicLoop(new Recognizer(model, RATE, GRAMMAR));
            mic.start();
            status.onVoiceStatus("listening");
        } catch (Exception e) {
            Log.e(TAG, "voice: could not start the microphone", e);
            status.onVoiceStatus("mic error: " + e.getMessage());
        }
    }

    /** App in background (onPause) → stop feeding audio. */
    void pause(boolean paused) { appPaused = paused; }

    /** The page started / stopped playing the voice-over. Called from JavaScript (any thread). */
    void setOutputPlaying(boolean on) {
        main.post(() -> {
            main.removeCallbacks(endPlaying);
            if (on) {
                if (!playing) Log.i(TAG, "voice: voice-over playing (commands need to be louder than the speaker)");
                playing = true;
                fired.clear();
                if (mic != null) mic.startEchoMeasure();
                main.postDelayed(endPlaying, MAX_PLAYING_MS);
            } else if (playing) {
                main.postDelayed(endPlaying, ECHO_TAIL_MS);
            }
        });
    }

    private final Runnable endPlaying = () -> {
        playing = false;
        fired.clear();
        if (mic != null) mic.requestReset(); // drop half-heard voice-over audio
        Log.i(TAG, "voice: voice-over done, normal listening");
    };

    void stop() {
        main.removeCallbacksAndMessages(null);
        if (mic != null) { mic.finish(); mic = null; }
        net.shutdownNow();
    }

    // ---------- recognition (main thread) ----------
    // Fire on partial guesses. The recognizer re-guesses the whole utterance each time, so compare the new
    // guess with what was already sent, word by word: a command in a new position, or a different command
    // in a position already sent ("next" re-guessed as "back"), is sent. The list resets per utterance.

    private void handle(String text, boolean isFinal, int peak, int echo) {
        List<String> cmds = commandsIn(text, isFinal);
        if (!cmds.isEmpty() || (isFinal && !text.isEmpty()))
            Log.i(TAG, "voice " + (isFinal ? "final" : "partial") + ": \"" + text + "\"  (peak " + peak + (playing ? ", echo " + echo : "") + ")");
        if (playing && !cmds.isEmpty()) {
            int need = Math.max(BARGE_MIN, Math.round(echo * BARGE_RATIO));
            if (peak < need) {
                Log.i(TAG, "voice: ignored during voice-over (peak " + peak + " < " + need + ", likely the speaker)");
                if (isFinal) fired.clear();
                return;
            }
            Log.i(TAG, "voice: interrupting the voice-over (peak " + peak + " ≥ " + need + ")");
        }
        for (int i = 0; i < cmds.size(); i++) {
            String cmd = cmds.get(i);
            if (i >= fired.size()) { fired.add(cmd); send(cmd, text); }
            else if (!fired.get(i).equals(cmd)) {
                Log.i(TAG, "voice: re-guessed \"" + fired.get(i) + "\" as \"" + cmd + "\"");
                fired.set(i, cmd);
                send(cmd, text);
            }
        }
        if (isFinal) fired.clear();
    }

    private static List<String> commandsIn(String text, boolean isFinal) {
        List<String> out = new ArrayList<>();
        if (text == null) return out;
        String[] w = text.trim().split("\\s+");
        for (int i = 0; i < w.length; i++) {
            switch (w[i]) {
                case "next": case "back": case "show": case "hide": case "repeat": out.add(w[i]); break;
                case "voice": case "sound":
                    if (i + 1 < w.length && (w[i + 1].equals("off") || w[i + 1].equals("on"))) {
                        // on/off only from the finished phrase: a partial "voice on" can still become "voice off"
                        if (isFinal) out.add(w[i + 1].equals("off") ? "mute" : "unmute");
                        i++;
                    }
                    break;
                case "on": case "off":
                    // "voice on" sometimes arrives as just "on": accept it as the end of a short finished phrase
                    if (isFinal && i == w.length - 1 && out.isEmpty() && allUnknown(w, i)) out.add(w[i].equals("off") ? "mute" : "unmute");
                    break;
                default: break;
            }
        }
        return out;
    }

    private static boolean allUnknown(String[] w, int end) {
        for (int i = 0; i < end; i++) if (!w[i].equals("[unk]")) return false;
        return end <= 2;
    }

    private static String field(String json, String key) {
        try { return new JSONObject(json).optString(key, ""); } catch (Exception e) { return ""; }
    }

    // ---------- microphone ----------
    /** Reads the mic in 100 ms chunks, measures loudness, feeds the recognizer, posts results to main. */
    private class MicLoop extends Thread {
        private final Recognizer rec;
        private volatile boolean running = true, resetRequested = false;
        private final int[] recent = new int[8];             // last 0.8 s of chunk levels (for the voice peak)
        private final int[] echoWin = new int[20];           // last 2 s of levels during playback (echo level)
        private int recentPos = 0, echoPos = 0, echoCount = 0;
        private volatile int echoLevel = 0;
        private String lastPartial = "";

        MicLoop(Recognizer rec) { super("GlassView-mic"); this.rec = rec; }

        void requestReset() { resetRequested = true; }
        void startEchoMeasure() { echoCount = 0; echoPos = 0; }
        void finish() { running = false; }

        private AudioRecord open() {
            int min = AudioRecord.getMinBufferSize(RATE, AudioFormat.CHANNEL_IN_MONO, AudioFormat.ENCODING_PCM_16BIT);
            int size = Math.max(min, CHUNK * 2 * 4);
            // VOICE_RECOGNITION: unprocessed audio, best for the recognizer. (VOICE_COMMUNICATION was tried for its
            // echo canceller, but the M6 has none, and that input adds call processing.)
            int[] sources = { MediaRecorder.AudioSource.VOICE_RECOGNITION, MediaRecorder.AudioSource.MIC };
            String[] names = { "VOICE_RECOGNITION", "MIC" };
            for (int i = 0; i < sources.length; i++) {
                try {
                    AudioRecord r = new AudioRecord(sources[i], RATE, AudioFormat.CHANNEL_IN_MONO, AudioFormat.ENCODING_PCM_16BIT, size);
                    if (r.getState() != AudioRecord.STATE_INITIALIZED) { r.release(); continue; }
                    String aec = "not available";
                    if (AcousticEchoCanceler.isAvailable()) {
                        AcousticEchoCanceler e = AcousticEchoCanceler.create(r.getAudioSessionId());
                        if (e != null) { e.setEnabled(true); aec = e.getEnabled() ? "on" : "could not enable"; }
                    }
                    Log.i(TAG, "voice: mic source " + names[i] + ", echo canceller " + aec);
                    return r;
                } catch (Exception e) { Log.w(TAG, "voice: mic source " + names[i] + " failed: " + e); }
            }
            return null;
        }

        @Override public void run() {
            AudioRecord ar = open();
            if (ar == null) { main.post(() -> status.onVoiceStatus("mic error: no audio source")); return; }
            ar.startRecording();
            Log.i(TAG, "voice: listening on the glasses mic");
            short[] buf = new short[CHUNK];
            long lastLevelLog = 0;
            try {
                while (running) {
                    int n = ar.read(buf, 0, CHUNK);
                    if (n <= 0) continue;
                    if (appPaused) continue;
                    if (resetRequested) { resetRequested = false; rec.reset(); lastPartial = ""; }

                    // loudness of this chunk
                    double sum = 0;
                    for (int i = 0; i < n; i++) sum += (double) buf[i] * buf[i];
                    int level = (int) Math.sqrt(sum / n);
                    recent[recentPos] = level; recentPos = (recentPos + 1) % recent.length;
                    int peak = 0; for (int v : recent) peak = Math.max(peak, v);
                    if (playing) {
                        echoWin[echoPos] = level; echoPos = (echoPos + 1) % echoWin.length; echoCount = Math.min(echoWin.length, echoCount + 1);
                        int[] w = Arrays.copyOf(echoWin, echoCount); Arrays.sort(w);
                        echoLevel = w[w.length / 2];
                        long now = System.currentTimeMillis();
                        if (now - lastLevelLog > 1000) { lastLevelLog = now; Log.i(TAG, "voice: mic during voice-over: level " + level + ", echo " + echoLevel + ", peak " + peak); }
                    }

                    final int p = peak, e = echoLevel;
                    if (rec.acceptWaveForm(buf, n)) {
                        final String text = field(rec.getResult(), "text");
                        lastPartial = "";
                        main.post(() -> handle(text, true, p, e));
                    } else {
                        final String partial = field(rec.getPartialResult(), "partial");
                        if (!partial.equals(lastPartial)) { lastPartial = partial; main.post(() -> handle(partial, false, p, e)); }
                    }
                }
            } finally {
                try { ar.stop(); } catch (Exception ignored) {}
                ar.release();
                rec.close();
            }
        }
    }

    // ---------- sending ----------
    private void send(String cmd, String heard) {
        final String target = cmdUrl;
        if (target == null) return;
        Log.i(TAG, "voice: command " + cmd);
        net.execute(() -> {
            HttpURLConnection c = null;
            try {
                long t0 = System.currentTimeMillis();
                c = (HttpURLConnection) new URL(target).openConnection();
                c.setConnectTimeout(2000);
                c.setReadTimeout(2000);
                c.setRequestMethod("POST");
                c.setDoOutput(true);
                c.setRequestProperty("Content-Type", "application/json");
                String body = new JSONObject().put("cmd", cmd).put("source", "glasses mic: “" + heard + "”").toString();
                try (OutputStream os = c.getOutputStream()) { os.write(body.getBytes(StandardCharsets.UTF_8)); }
                Log.i(TAG, "voice: sent " + cmd + " → " + c.getResponseCode() + " in " + (System.currentTimeMillis() - t0) + " ms");
            } catch (Exception e) {
                Log.w(TAG, "voice: could not send " + cmd + " to " + target + ": " + e);
            } finally {
                if (c != null) c.disconnect();
            }
        });
    }
}
