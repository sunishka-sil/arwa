package com.arwa.glasses;

import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.speech.RecognitionListener;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;
import android.speech.tts.TextToSpeech;
import android.util.Base64;
import android.util.Log;
import android.view.InputDevice;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.webkit.ConsoleMessage;
import android.webkit.JavascriptInterface;
import android.webkit.PermissionRequest;
import android.webkit.WebChromeClient;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import org.json.JSONObject;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.Locale;

/**
 * ARWA on the M6: a full-screen WebView showing the server's glasses view (markers in, actions out).
 * Plain Android (API 28 on the glasses), no MicroLumin SDK needed. 640x480, black = see-through.
 *
 * Default URL works over the USB cable after:  adb reverse tcp:8080 tcp:8080
 * Over Wi-Fi:  adb shell am start -n com.arwa.glasses/.MainActivity --es url "http://<laptop-ip>:8080/glasses.html?name=glasses&scale=1.2"
 * Debug:       adb logcat -s ARWA   (keys, page console, camera, voice)
 */
public class MainActivity extends Activity {
    private static final String TAG = "ARWA";
    private static final String DEFAULT_URL = "http://localhost:8080/glasses.html?name=glasses&scale=1.2";
    private WebView web;
    private String base;          // e.g. http://localhost:8080, used for the camera POST
    private TextToSpeech tts;
    private boolean ttsReady = false;
    private SpeechRecognizer recognizer;
    private boolean voiceOn = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        // Android 9 asks for camera + mic at runtime. Accept once on the glasses (touchpad tap).
        if (Build.VERSION.SDK_INT >= 23 && (checkSelfPermission(Manifest.permission.CAMERA) != PackageManager.PERMISSION_GRANTED
                || checkSelfPermission(Manifest.permission.RECORD_AUDIO) != PackageManager.PERMISSION_GRANTED)) {
            requestPermissions(new String[]{Manifest.permission.CAMERA, Manifest.permission.RECORD_AUDIO}, 1);
        }
        // Or skip the prompt from the laptop:  adb shell pm grant com.arwa.glasses android.permission.CAMERA  (and RECORD_AUDIO)

        // Native speech out. WebView has no speechSynthesis, so the page calls ARWAGlasses.say(text).
        tts = new TextToSpeech(this, status -> {
            ttsReady = status == TextToSpeech.SUCCESS;
            if (ttsReady) tts.setLanguage(Locale.US);
            Log.i(TAG, "TTS " + (ttsReady ? "ready" : "unavailable (no engine on glasses?), tones only"));
        });

        web = new WebView(this);
        web.setBackgroundColor(Color.BLACK);
        web.setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);
        WebSettings s = web.getSettings();
        s.setJavaScriptEnabled(true);
        s.setDomStorageEnabled(true);
        s.setMediaPlaybackRequiresUserGesture(false); // tones without a tap
        web.setWebViewClient(new WebViewClient());
        web.setWebChromeClient(new WebChromeClient() {
            @Override public void onPermissionRequest(PermissionRequest request) { request.grant(request.getResources()); }
            // Page errors show in logcat. Old WebViews fail on new JS syntax, so check here first if the screen stays on "Connecting…".
            @Override public boolean onConsoleMessage(ConsoleMessage m) {
                Log.i(TAG, "page: " + m.message() + " (" + m.sourceId() + ":" + m.lineNumber() + ")");
                return true;
            }
        });
        web.addJavascriptInterface(new Bridge(), "ARWAGlasses");
        setContentView(web);

        Intent i = getIntent();
        swap = i != null && i.getBooleanExtra("swap", false);
        String url = i != null && i.getStringExtra("url") != null ? i.getStringExtra("url") : DEFAULT_URL;
        Uri u = Uri.parse(url);
        base = u.getScheme() + "://" + u.getAuthority();
        Log.i(TAG, "Loading " + url + " · WebView " + web.getSettings().getUserAgentString());
        web.loadUrl(url);
    }

    // ---- Side touchpad + ring -> the same four commands as phone voice ----
    // swipe forward = next, swipe back = back, tap = hide/show the view, long-press = call expert.
    // The kit says the touchpad arrives as key events; some builds send touch or scroll events instead,
    // so all three paths are handled and logged. Run `adb logcat -s ARWA` and use the pad to see which.
    // If swipes feel reversed: adb shell am start -n com.arwa.glasses/.MainActivity --ez swap true
    private boolean swap = false;
    private static final long LONG_MS = 600;
    private static final float SWIPE_PX = 40;

    private void nav(String c) {
        if (swap && c.equals("next")) c = "back"; else if (swap && c.equals("back")) c = "next";
        Log.i(TAG, "nav " + c);
        String fallback = c.equals("next") ? "window.arwaConfirm && arwaConfirm()"
                : (c.equals("back") || c.equals("expert")) ? "window.arwaExpert && arwaExpert()" : "0";
        js("window.arwaNav ? arwaNav('" + c + "') : (" + fallback + ")");
    }

    @Override
    public boolean dispatchKeyEvent(KeyEvent e) {
        int k = e.getKeyCode();
        if (e.getAction() == KeyEvent.ACTION_DOWN && e.getRepeatCount() == 0)
            Log.i(TAG, "key " + KeyEvent.keyCodeToString(k) + " code=" + k + " scan=" + e.getScanCode()
                    + " src=" + (e.getDevice() != null ? e.getDevice().getName() : "?"));
        switch (k) {
            case KeyEvent.KEYCODE_DPAD_RIGHT: case KeyEvent.KEYCODE_DPAD_DOWN: case KeyEvent.KEYCODE_PAGE_DOWN:
            case KeyEvent.KEYCODE_MEDIA_NEXT: case KeyEvent.KEYCODE_TAB:
                if (e.getAction() == KeyEvent.ACTION_DOWN && e.getRepeatCount() == 0) nav("next"); return true;
            case KeyEvent.KEYCODE_DPAD_LEFT: case KeyEvent.KEYCODE_DPAD_UP: case KeyEvent.KEYCODE_PAGE_UP:
            case KeyEvent.KEYCODE_MEDIA_PREVIOUS:
                if (e.getAction() == KeyEvent.ACTION_DOWN && e.getRepeatCount() == 0) nav("back"); return true;
            case KeyEvent.KEYCODE_ENTER: case KeyEvent.KEYCODE_DPAD_CENTER: case KeyEvent.KEYCODE_MEDIA_PLAY_PAUSE:
            case KeyEvent.KEYCODE_HEADSETHOOK:
                // act on release: short = hide/show, held = call expert
                if (e.getAction() == KeyEvent.ACTION_UP && !e.isCanceled())
                    nav(e.getEventTime() - e.getDownTime() > LONG_MS ? "expert" : "toggle");
                return true;
            case KeyEvent.KEYCODE_CAMERA: // add the code of whichever button you want for "check panel"
                if (e.getAction() == KeyEvent.ACTION_DOWN) snap("B"); return true;
        }
        return super.dispatchKeyEvent(e);
    }

    // Touch path: the pad reports as a touch surface. Swipe along its dominant axis, tap, or hold.
    private float downX, downY; private long downT; private boolean tracking = false;
    private boolean gesture(MotionEvent ev, String path) {
        switch (ev.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                downX = ev.getX(); downY = ev.getY(); downT = ev.getEventTime(); tracking = true; return true;
            case MotionEvent.ACTION_MOVE: return tracking;
            case MotionEvent.ACTION_UP: {
                if (!tracking) return false; tracking = false;
                float dx = ev.getX() - downX, dy = ev.getY() - downY; long dt = ev.getEventTime() - downT;
                Log.i(TAG, path + " gesture dx=" + (int) dx + " dy=" + (int) dy + " ms=" + dt + " src=0x" + Integer.toHexString(ev.getSource()));
                if (Math.max(Math.abs(dx), Math.abs(dy)) > SWIPE_PX) {
                    float d = Math.abs(dx) >= Math.abs(dy) ? dx : -dy; // forward = +x, or up on a vertical pad
                    nav(d > 0 ? "next" : "back");
                } else nav(dt > LONG_MS ? "expert" : "toggle");
                return true;
            }
            case MotionEvent.ACTION_CANCEL: tracking = false; return true;
        }
        return false;
    }
    @Override public boolean dispatchTouchEvent(MotionEvent ev) { return gesture(ev, "touch") || super.dispatchTouchEvent(ev); }

    // Generic-motion path: touchpad (SOURCE_TOUCHPAD) movement or scroll wheels.
    private long lastScroll = 0;
    @Override public boolean dispatchGenericMotionEvent(MotionEvent ev) {
        if (ev.getActionMasked() == MotionEvent.ACTION_SCROLL) {
            float h = ev.getAxisValue(MotionEvent.AXIS_HSCROLL), v = ev.getAxisValue(MotionEvent.AXIS_VSCROLL);
            Log.i(TAG, "scroll h=" + h + " v=" + v + " src=0x" + Integer.toHexString(ev.getSource()));
            float d = Math.abs(h) >= Math.abs(v) ? h : v;
            if (d != 0 && ev.getEventTime() - lastScroll > 400) { lastScroll = ev.getEventTime(); nav(d > 0 ? "next" : "back"); }
            return true;
        }
        if ((ev.getSource() & InputDevice.SOURCE_TOUCHPAD) == InputDevice.SOURCE_TOUCHPAD) return gesture(ev, "touchpad");
        return super.dispatchGenericMotionEvent(ev);
    }

    private void js(String code) { web.post(() -> web.evaluateJavascript(code, null)); }
    private void toast(String t) { js("window.flash && flash(" + JSONObject.quote(t) + ")"); }

    // ---- Camera: one still from the glasses camera -> POST /api/vision/panel -> server pushes the verdict marker ----
    // Plain android.hardware.Camera (works on API 28, no SDK). If the launcher holds the camera, open() throws: see logcat.
    private void snap(String recipe) {
        toast("Reading panel…");
        new Thread(() -> {
            Camera cam = null;
            try {
                cam = Camera.open(0);
                Camera.Parameters p = cam.getParameters();
                Camera.Size best = null; // ~1600 px wide is plenty for reading an HMI and keeps the upload small
                for (Camera.Size sz : p.getSupportedPictureSizes())
                    if (sz.width <= 1600 && (best == null || sz.width > best.width)) best = sz;
                if (best != null) p.setPictureSize(best.width, best.height);
                p.setJpegQuality(85);
                if (p.getSupportedFocusModes().contains(Camera.Parameters.FOCUS_MODE_AUTO)) p.setFocusMode(Camera.Parameters.FOCUS_MODE_AUTO);
                cam.setParameters(p);
                cam.setPreviewTexture(new SurfaceTexture(10));
                cam.startPreview();
                Thread.sleep(600); // let exposure settle
                final Camera c = cam;
                final byte[][] out = new byte[1][];
                final Object lock = new Object();
                c.takePicture(null, null, (data, camera) -> { synchronized (lock) { out[0] = data; lock.notify(); } });
                synchronized (lock) { if (out[0] == null) lock.wait(5000); }
                if (out[0] == null) throw new Exception("camera timeout");
                Log.i(TAG, "snap " + out[0].length + " bytes, posting");
                String body = new JSONObject()
                        .put("image", "data:image/jpeg;base64," + Base64.encodeToString(out[0], Base64.NO_WRAP))
                        .put("recipe", recipe).toString();
                String res = post(base + "/api/vision/panel", body);
                Log.i(TAG, "vision: " + res);
            } catch (Exception ex) {
                Log.e(TAG, "snap failed", ex);
                toast("Camera: " + ex.getMessage());
            } finally {
                if (cam != null) cam.release();
            }
        }).start();
    }

    private static String post(String url, String json) throws Exception {
        HttpURLConnection h = (HttpURLConnection) new URL(url).openConnection();
        h.setRequestMethod("POST"); h.setDoOutput(true); h.setConnectTimeout(5000); h.setReadTimeout(30000);
        h.setRequestProperty("Content-Type", "application/json");
        try (OutputStream o = h.getOutputStream()) { o.write(json.getBytes("UTF-8")); }
        InputStream in = h.getResponseCode() < 400 ? h.getInputStream() : h.getErrorStream();
        java.util.Scanner sc = new java.util.Scanner(in, "UTF-8").useDelimiter("\\A");
        return h.getResponseCode() + " " + (sc.hasNext() ? sc.next() : "");
    }

    // ---- Voice in: Android SpeechRecognizer if the glasses have a recognition service (they may not) ----
    private void startListening() {
        if (!SpeechRecognizer.isRecognitionAvailable(this)) { Log.i(TAG, "no speech recognizer on this device; use ring/touchpad"); return; }
        voiceOn = true;
        if (recognizer == null) {
            recognizer = SpeechRecognizer.createSpeechRecognizer(this);
            recognizer.setRecognitionListener(new RecognitionListener() {
                @Override public void onResults(Bundle r) {
                    ArrayList<String> l = r.getStringArrayList(SpeechRecognizer.RESULTS_RECOGNITION);
                    if (l != null && !l.isEmpty()) { Log.i(TAG, "heard: " + l.get(0)); js("window.arwaVoice && arwaVoice(" + JSONObject.quote(l.get(0)) + ")"); }
                    relisten();
                }
                @Override public void onError(int err) { Log.i(TAG, "voice error " + err); relisten(); }
                @Override public void onReadyForSpeech(Bundle b) {}
                @Override public void onBeginningOfSpeech() {}
                @Override public void onRmsChanged(float v) {}
                @Override public void onBufferReceived(byte[] b) {}
                @Override public void onEndOfSpeech() {}
                @Override public void onPartialResults(Bundle b) {}
                @Override public void onEvent(int t, Bundle b) {}
            });
        }
        relisten();
    }
    private void relisten() {
        if (!voiceOn) return;
        web.postDelayed(() -> {
            Intent it = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
            it.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
            it.putExtra(RecognizerIntent.EXTRA_LANGUAGE, "en-US");
            recognizer.startListening(it);
        }, 300);
    }

    @Override protected void onDestroy() {
        voiceOn = false;
        if (recognizer != null) recognizer.destroy();
        if (tts != null) tts.shutdown();
        super.onDestroy();
    }

    /** Called from the page as window.ARWAGlasses.* */
    private class Bridge {
        @JavascriptInterface public String device() { return "microlumin-m6"; }
        @JavascriptInterface public boolean canSpeak() { return ttsReady; }
        @JavascriptInterface public void say(String text) {
            if (ttsReady) tts.speak(text, TextToSpeech.QUEUE_FLUSH, null, "arwa");
        }
        @JavascriptInterface public void snapPanel(String recipe) { snap(recipe == null || recipe.isEmpty() ? "B" : recipe); }
        @JavascriptInterface public void startVoice() { runOnUiThread(MainActivity.this::startListening); }
    }
}
