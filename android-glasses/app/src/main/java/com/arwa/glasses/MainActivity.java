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
import android.speech.tts.TextToSpeech;
import android.speech.tts.UtteranceProgressListener;
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
import java.util.Locale;

/**
 * ARWA on the M6: a local bundled guide viewer with direct phone controls over Wi-Fi.
 * Plain Android (API 28 on the glasses), no MicroLumin SDK needed. 640x480, black = see-through.
 *
 * Default URL is served inside the glasses. Explicit URL extras retain the original laptop demo.
 * Debug:       adb logcat -s ARWA   (keys, page console, camera, voice)
 */
public class MainActivity extends Activity {
    private static final String TAG = "ARWA";
    private static final String LOCAL_BASE = "http://127.0.0.1:8080";
    private GuideServer guideServer;
    private WebView web;
    private String base;          // e.g. http://localhost:8080, used for the camera POST
    private TextToSpeech tts;
    private boolean ttsReady = false;
    private VoiceCommands voice;
    private boolean askingForMicrophone;
    private boolean speaking;
    private boolean destroyed;
    private int speechGeneration;
    private static final int VOICE_PERMISSION = 3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        // The microphone is requested only once a guide is open and voice navigation is enabled.

        // Native speech out. WebView has no speechSynthesis, so the page calls ARWAGlasses.say(text).
        tts = new TextToSpeech(this, status -> {
            ttsReady = status == TextToSpeech.SUCCESS;
            if (ttsReady) tts.setLanguage(Locale.US);
            Log.i(TAG, "TTS " + (ttsReady ? "ready" : "unavailable (no engine on glasses?), tones only"));
        });
        tts.setOnUtteranceProgressListener(new UtteranceProgressListener() {
            @Override public void onStart(String id) {
                runOnUiThread(() -> { speechGeneration++; speaking = true; updateVoiceListening(); });
            }
            @Override public void onDone(String id) { doneSpeaking(); }
            @Override public void onError(String id) { doneSpeaking(); }
            private void doneSpeaking() {
                runOnUiThread(() -> {
                    int generation = speechGeneration;
                    web.postDelayed(() -> {
                        if (generation == speechGeneration) { speaking = false; updateVoiceListening(); }
                    }, 500);
                });
            }
        });

        web = new WebView(this);
        web.setBackgroundColor(Color.BLACK);
        web.setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);
        WebSettings s = web.getSettings();
        s.setJavaScriptEnabled(true);
        s.setDomStorageEnabled(true);
        s.setMediaPlaybackRequiresUserGesture(false); // tones without a tap
        web.setWebViewClient(new WebViewClient() {
            @Override public void onPageStarted(WebView view, String url, android.graphics.Bitmap icon) {
                if (guideServer != null) guideServer.viewerClosed();
                updateVoiceListening();
            }
            @Override public void onPageFinished(WebView view, String url) {
                if (guideServer != null) guideServer.setViewerEnabled(url.startsWith(LOCAL_BASE + "/workflow3d.html"));
                updateVoiceListening();
            }
        });
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

        guideServer = new GuideServer(this, () -> runOnUiThread(this::openLocalGuide),
                () -> runOnUiThread(this::updateVoiceListening));
        voice = new VoiceCommands(this, new VoiceCommands.Listener() {
            @Override public void onStatus(String status) {
                guideServer.setVoiceStatus(status);
                Log.i(TAG, "Voice status: " + status);
            }
            @Override public void onCommand(String command) { guideServer.voiceCommand(command); }
        });
        try {
            guideServer.start();
        } catch (Exception ex) {
            Log.e(TAG, "Could not start companion connection", ex);
            web.loadData("<body style='background:black;color:white'>ARWA could not start its phone connection. Close and reopen the app.</body>", "text/html", "UTF-8");
            return;
        }
        Intent i = getIntent();
        swap = i != null && i.getBooleanExtra("swap", false);
        String url = i != null && i.getStringExtra("url") != null ? i.getStringExtra("url")
                : LOCAL_BASE + (guideServer.isStarted() && (i == null || !i.getBooleanExtra("setup", false)) ? "/workflow3d.html?local=1" : "/setup");
        Uri u = Uri.parse(url);
        base = u.getScheme() + "://" + u.getAuthority();
        Log.i(TAG, "Loading " + url + " · WebView " + web.getSettings().getUserAgentString());
        web.loadUrl(url);
    }

    private void openLocalGuide() {
        base = LOCAL_BASE;
        web.loadUrl(LOCAL_BASE + "/workflow3d.html?local=1");
    }

    @Override protected void onResume() {
        super.onResume();
        if (guideServer != null) guideServer.setForeground(true);
        updateVoiceListening();
    }

    @Override protected void onPause() {
        if (guideServer != null) guideServer.setForeground(false);
        updateVoiceListening();
        super.onPause();
    }

    @Override public void onBackPressed() {
        // Return to the address screen without terminating a running guide.
        if (guideServer != null) guideServer.viewerClosed();
        base = LOCAL_BASE;
        web.loadUrl(LOCAL_BASE + "/setup");
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
        if (checkSelfPermission(Manifest.permission.CAMERA) != PackageManager.PERMISSION_GRANTED) {
            runOnUiThread(() -> requestPermissions(new String[]{Manifest.permission.CAMERA}, 1));
            toast("Allow camera access, then try again");
            return;
        }
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

    // ---- Offline voice navigation, adapted from the voice-commands branch ----
    private void updateVoiceListening() {
        if (destroyed || voice == null || guideServer == null) return;
        if (!guideServer.canListen() || speaking) {
            voice.stop(!guideServer.isVoiceEnabled() ? "Off" : speaking ? "Paused while speaking" : "Paused");
            return;
        }
        if (checkSelfPermission(Manifest.permission.RECORD_AUDIO) != PackageManager.PERMISSION_GRANTED) {
            guideServer.setVoiceStatus("Microphone permission needed");
            if (!askingForMicrophone) {
                askingForMicrophone = true;
                requestPermissions(new String[]{Manifest.permission.RECORD_AUDIO}, VOICE_PERMISSION);
            }
            return;
        }
        voice.start();
    }

    @Override public void onRequestPermissionsResult(int code, String[] permissions, int[] results) {
        super.onRequestPermissionsResult(code, permissions, results);
        if (code != VOICE_PERMISSION) return;
        askingForMicrophone = false;
        if (results.length > 0 && results[0] == PackageManager.PERMISSION_GRANTED) updateVoiceListening();
        else if (guideServer != null) {
            guideServer.setVoiceEnabled(false);
            guideServer.setVoiceStatus("Microphone permission denied");
        }
    }

    @Override protected void onDestroy() {
        if (guideServer != null) guideServer.close();
        destroyed = true;
        if (voice != null) voice.close();
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
        @JavascriptInterface public void startVoice() { runOnUiThread(() -> guideServer.setVoiceEnabled(true)); }
    }
}
