package com.arwa.glasses;

import android.content.Context;
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
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Adapted from origin/voice-commands f54cb11 (voice-prototype/.../VoiceCommands.java).
 * Same offline model/grammar and glasses microphone; commands go directly to local guide state.
 * Lifecycle methods and callbacks run on the main thread. Audio never leaves the glasses.
 */
final class VoiceCommands implements AutoCloseable {
    interface Listener {
        void onStatus(String status);
        void onCommand(String command);
    }
    private final Context context;
    private final Listener listener;
    private final Handler main = new Handler(Looper.getMainLooper());
    private final ExecutorService loader = Executors.newSingleThreadExecutor();
    private final VoiceCommandTracker tracker = new VoiceCommandTracker();
    private Model model;
    private Recognizer recognizer;
    private SpeechService speech;
    private boolean loading, wanted, closed;
    private int generation;

    VoiceCommands(Context context, Listener listener) {
        this.context = context.getApplicationContext();
        this.listener = listener;
    }

    void start() {
        if (closed) return;
        wanted = true;
        if (speech != null || loading) return;
        if (model != null) { listen(); return; }
        loading = true;
        listener.onStatus("Loading speech model");
        loader.execute(() -> {
            try {
                LibVosk.setLogLevel(LogLevel.WARNINGS);
                String path = StorageService.sync(context, "model-en-us", "voice-model");
                Model loaded = new Model(path);
                main.post(() -> {
                    loading = false;
                    if (closed) { loaded.close(); return; }
                    model = loaded;
                    if (wanted) listen();
                });
            } catch (Exception | LinkageError error) {
                Log.e("ARWA", "Voice model failed", error);
                main.post(() -> {
                    loading = false;
                    if (!closed && wanted) listener.onStatus("Speech model unavailable");
                });
            }
        });
    }

    private void listen() {
        if (!wanted || closed || speech != null) return;
        int ticket = ++generation;
        tracker.reset();
        try {
            recognizer = new Recognizer(model, 16000f, VoiceCommandTracker.GRAMMAR);
            speech = new SpeechService(recognizer, 16000f);
            if (!speech.startListening(new RecognitionListener() {
                private void result(String json, String key, boolean finished) {
                    if (!active(ticket)) return;
                    String text;
                    try { text = new JSONObject(json).optString(key, ""); } catch (Exception e) { return; }
                    for (String command : tracker.accept(text, finished)) {
                        Log.i("ARWA", "Voice command: " + command);
                        listener.onCommand(command);
                    }
                }
                public void onPartialResult(String json) { result(json, "partial", false); }
                public void onResult(String json) { result(json, "text", true); }
                public void onFinalResult(String json) { result(json, "text", true); }
                public void onTimeout() {
                    if (active(ticket)) { stop("Paused"); start(); }
                }
                public void onError(Exception error) {
                    if (!active(ticket)) return;
                    Log.e("ARWA", "Microphone failed", error);
                    stop("Microphone unavailable");
                }
            })) throw new IllegalStateException("Microphone did not start");
            listener.onStatus("Listening");
            Log.i("ARWA", "Offline voice listening on glasses microphone");
        } catch (Exception | LinkageError error) {
            Log.e("ARWA", "Could not start offline voice", error);
            stop("Microphone unavailable");
        }
    }

    private boolean active(int ticket) { return !closed && wanted && speech != null && ticket == generation; }

    void stop(String status) {
        wanted = false;
        generation++;
        tracker.reset();
        if (speech != null) { speech.cancel(); speech.shutdown(); speech = null; }
        if (recognizer != null) { recognizer.close(); recognizer = null; }
        if (!closed) listener.onStatus(status);
    }

    @Override public void close() {
        closed = true;
        stop("Off");
        loader.shutdownNow();
        if (model != null) { model.close(); model = null; }
    }
}
