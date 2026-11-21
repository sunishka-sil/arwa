package com.worn.glassview;

import android.content.Context;
import android.net.Uri;
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
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Listens on the glasses' own microphone (offline, Vosk) for "next", "back", "show", "hide"
 * and POSTs each one to the server's /cmd, the same endpoint the phone/Mac remote uses.
 *
 * The recognizer only knows these four words (a grammar), which makes it fast and accurate.
 * Log: adb logcat -s GlassView
 */
class VoiceCommands implements RecognitionListener {
    private static final String TAG = MainActivity.TAG;
    private static final float SAMPLE_RATE = 16000f;
    // "[unk]" soaks up other speech so it isn't forced onto one of the commands.
    private static final String GRAMMAR = "[\"next\", \"back\", \"show\", \"hide\", \"[unk]\"]";

    interface Status { void onVoiceStatus(String status); }

    private final Context context;
    private final Status status;
    private final ExecutorService net = Executors.newSingleThreadExecutor();
    private volatile String cmdUrl;
    private Model model;
    private SpeechService speech;
    // Commands already sent for the current utterance, in the order they were heard.
    private final List<String> fired = new ArrayList<>();

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
            Recognizer rec = new Recognizer(model, SAMPLE_RATE, GRAMMAR);
            speech = new SpeechService(rec, SAMPLE_RATE);
            speech.startListening(this);
            Log.i(TAG, "voice: listening on the glasses mic");
            status.onVoiceStatus("listening");
        } catch (Exception e) {
            Log.e(TAG, "voice: could not start the microphone", e);
            status.onVoiceStatus("mic error: " + e.getMessage());
        }
    }

    void pause(boolean paused) { if (speech != null) speech.setPause(paused); }

    void stop() {
        if (speech != null) { speech.stop(); speech.shutdown(); speech = null; }
        net.shutdownNow();
    }

    // ---------- recognition ----------
    // Act on partial results (fast). The recognizer re-guesses the whole utterance each time, so compare
    // the new guess with what was already sent, word by word: a command in a new position, or a different
    // command in a position already sent (e.g. "next" re-guessed as "back"), is sent. The final result
    // catches anything the partials missed, then the list resets for the next utterance.

    @Override public void onPartialResult(String json) {
        handle(field(json, "partial"), false);
    }

    @Override public void onResult(String json) {
        handle(field(json, "text"), true);
    }

    @Override public void onFinalResult(String json) {
        handle(field(json, "text"), true);
    }

    @Override public void onError(Exception e) {
        Log.e(TAG, "voice: error", e);
        status.onVoiceStatus("error: " + e.getMessage());
    }

    @Override public void onTimeout() { Log.i(TAG, "voice: timeout"); }

    private void handle(String text, boolean isFinal) {
        List<String> cmds = commandsIn(text);
        if (!cmds.isEmpty() || isFinal) Log.i(TAG, "voice " + (isFinal ? "final" : "partial") + ": \"" + text + "\"");
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

    private static List<String> commandsIn(String text) {
        List<String> out = new ArrayList<>();
        if (text == null) return out;
        for (String w : text.trim().split("\\s+")) {
            if (w.equals("next") || w.equals("back") || w.equals("show") || w.equals("hide")) out.add(w);
        }
        return out;
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
