package com.worn.glassview;

import android.content.Context;
import android.net.Uri;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import org.json.JSONObject;
import org.vosk.LibVosk;
import org.vosk.LogLevel;
import org.vosk.Model;
import org.vosk.Recognizer;
import org.vosk.android.RecognitionListener;
import org.vosk.android.SpeechService;
import org.vosk.android.StorageService;

import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Listens on the glasses' own microphone (offline, Vosk) for voice commands and POSTs each one to the
 * server's /cmd, the same endpoint the phone/Mac remote uses:
 *   next, back, show, hide      → page / view
 *   repeat                      → say the current step again
 *   mute                        → mute_toggle (see below)
 *   sound on, voice on          → unmute
 *
 * The recognizer only knows these phrases (a grammar), which makes it fast and accurate.
 * "unmute" is not in the small model's vocabulary: it is always heard as "mute" (tested with five voices).
 * So "mute" is sent as a toggle: saying "unmute" while muted turns the sound back on, as you'd expect.
 *
 * Avoiding false commands (tested offline with the same model and grammar):
 *  - A grammar forces any speech onto the nearest command, and the glasses' mic hears their own speaker.
 *    So the mic is paused while the voice-over plays (setOutputPlaying, called by the page) and for
 *    ECHO_TAIL_MS after. Without this the voice-over triggered 8 false commands across 5 steps.
 *  - Only a finished, short utterance counts: exactly one command, nothing after it, and at most one
 *    unknown sound before it (a breath or click, e.g. "[unk] mute"). Acting on partial guesses was faster
 *    but fired on chatter like "let's go back next week".
 * Log: adb logcat -s GlassView
 */
class VoiceCommands implements RecognitionListener {
    private static final String TAG = MainActivity.TAG;
    private static final float SAMPLE_RATE = 16000f;
    private static final long ECHO_TAIL_MS = 500;      // speaker reverb + audio buffers after playback ends
    private static final long MAX_DEAF_MS = 45000;     // safety: never stay deaf if the page forgets to say "done"
    // "[unk]" soaks up other speech so it isn't forced onto one of the commands.
    private static final String GRAMMAR =
            "[\"next\", \"back\", \"show\", \"hide\", \"repeat\", \"mute\", \"sound on\", \"voice on\", \"[unk]\"]";

    interface Status { void onVoiceStatus(String status); }

    private final Context context;
    private final Status status;
    private final ExecutorService net = Executors.newSingleThreadExecutor();
    private final Handler main = new Handler(Looper.getMainLooper());
    private volatile String cmdUrl;
    private Model model;
    private Recognizer recognizer;
    private SpeechService speech;
    private boolean appPaused = false, outputPlaying = false;
    private volatile long deafUntil = 0;   // results arriving before this time are echo: ignore them

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
        if (speech != null) return;
        status.onVoiceStatus("loading model");
        // Copies the model from the APK's assets to app storage on first run (a few seconds), then loads it.
        StorageService.unpack(context, "model-en-us", "model",
                m -> { model = m; listen(); },
                e -> { Log.e(TAG, "voice: model failed", e); status.onVoiceStatus("model error: " + e.getMessage()); });
    }

    private void listen() {
        try {
            recognizer = new Recognizer(model, SAMPLE_RATE, GRAMMAR);
            speech = new SpeechService(recognizer, SAMPLE_RATE);
            speech.startListening(this);
            Log.i(TAG, "voice: listening on the glasses mic");
            status.onVoiceStatus("listening");
            applyPause();
        } catch (Exception e) {
            Log.e(TAG, "voice: could not start the microphone", e);
            status.onVoiceStatus("mic error: " + e.getMessage());
        }
    }

    /** App in background (onPause) → stop listening. */
    void pause(boolean paused) { main.post(() -> { appPaused = paused; applyPause(); }); }

    /** The page started / stopped playing the voice-over. Called from JavaScript (any thread). */
    void setOutputPlaying(boolean playing) {
        main.post(() -> {
            main.removeCallbacks(resumeAfterEcho);
            main.removeCallbacks(forceResume);
            if (playing) {
                outputPlaying = true;
                deafUntil = Long.MAX_VALUE;
                applyPause();
                main.postDelayed(forceResume, MAX_DEAF_MS);
                Log.i(TAG, "voice: voice-over playing, mic paused");
            } else if (outputPlaying) {
                deafUntil = System.currentTimeMillis() + ECHO_TAIL_MS;
                main.postDelayed(resumeAfterEcho, ECHO_TAIL_MS);
            }
        });
    }

    private final Runnable resumeAfterEcho = () -> {
        outputPlaying = false;
        if (recognizer != null) recognizer.reset(); // drop half-heard voice-over audio
        applyPause();
        Log.i(TAG, "voice: voice-over done, listening again");
    };
    private final Runnable forceResume = () -> { Log.w(TAG, "voice: no end-of-playback signal, listening again"); deafUntil = 0; resumeAfterEcho.run(); };

    private void applyPause() { if (speech != null) speech.setPause(appPaused || outputPlaying); }

    void stop() {
        main.removeCallbacksAndMessages(null);
        if (speech != null) { speech.stop(); speech.shutdown(); speech = null; }
        net.shutdownNow();
    }

    // ---------- recognition ----------
    // Partial guesses are only logged; a command is sent when the utterance is finished (about half a
    // second of silence) and passes accept().

    @Override public void onPartialResult(String json) { }

    @Override public void onResult(String json) { handle(field(json, "text")); }

    @Override public void onFinalResult(String json) { handle(field(json, "text")); }

    @Override public void onError(Exception e) {
        Log.e(TAG, "voice: error", e);
        status.onVoiceStatus("error: " + e.getMessage());
    }

    @Override public void onTimeout() { Log.i(TAG, "voice: timeout"); }

    private void handle(String text) {
        if (text == null || text.trim().isEmpty() || text.trim().equals("[unk]")) return;
        if (System.currentTimeMillis() < deafUntil) { Log.i(TAG, "voice: ignored during voice-over: \"" + text + "\""); return; }
        String cmd = accept(text);
        Log.i(TAG, "voice heard: \"" + text + "\"" + (cmd == null ? " → no command" : " → " + cmd));
        if (cmd != null) send(cmd, text);
    }

    /** The one command in a short utterance, or null. "[unk] next" → next; "next [unk]" or "show hide" → null. */
    static String accept(String text) {
        String[] w = text.trim().split("\\s+");
        String cmd = null;
        int unknownBefore = 0;
        for (int i = 0; i < w.length; i++) {
            String c = null;
            switch (w[i]) {
                case "next": case "back": case "show": case "hide": case "repeat": c = w[i]; break;
                case "mute": c = "mute_toggle"; break;
                case "sound": case "voice":
                    if (i + 1 < w.length && w[i + 1].equals("on")) { c = "unmute"; i++; }
                    break;
                case "[unk]":
                    if (cmd != null) return null;          // speech after the command: part of a sentence
                    unknownBefore++;
                    continue;
                default: break;
            }
            if (c == null || cmd != null) return null;     // a stray word, or a second command
            cmd = c;
        }
        return unknownBefore <= 1 ? cmd : null;
    }

    private static String field(String json, String key) {
        try { return new JSONObject(json).optString(key, ""); } catch (Exception e) { return ""; }
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
