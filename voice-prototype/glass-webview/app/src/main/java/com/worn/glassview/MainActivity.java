package com.worn.glassview;

import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.WindowManager;
import android.webkit.ConsoleMessage;
import android.webkit.JavascriptInterface;
import android.webkit.WebChromeClient;
import android.webkit.WebResourceError;
import android.webkit.WebResourceRequest;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

/**
 * Full-screen WebView for the M6 glasses.
 *
 * Default page: http://localhost:8080/display (reach the Mac with `adb reverse tcp:8080 tcp:8080`).
 * Other page:   adb shell am start -n com.worn.glassview/.MainActivity --es url http://10.3.194.240:8080/display
 *               (the URL is remembered for the next launch).
 *
 * Temple touchpad (tap = ENTER → next, double tap = F9 → back) / ring keys are logged (`adb logcat -s GlassView`) and passed to the page as
 * ArrowRight / ArrowLeft keydown events, which both display.html and workflow3d-preview.html handle.
 * Voice: the glasses' own microphone listens for next / back / show / hide (offline, see VoiceCommands)
 * and sends them to <page origin>/cmd.
 * The page also sees window.ARWAGlasses, which workflow3d-preview.html uses to switch to its glasses layout.
 */
public class MainActivity extends Activity {
    static final String TAG = "GlassView";
    static final String DEFAULT_URL = "http://localhost:8080/display";
    static final long RETRY_MS = 2000;

    private WebView web;
    private String url;
    private VoiceCommands voice;
    private volatile String voiceStatus = "off";
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final Runnable retry = () -> { Log.i(TAG, "retrying " + url); web.loadUrl(url); };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        WebView.setWebContentsDebuggingEnabled(true); // chrome://inspect on the Mac

        web = new WebView(this);
        web.setBackgroundColor(Color.BLACK);
        WebSettings s = web.getSettings();
        s.setJavaScriptEnabled(true);
        s.setDomStorageEnabled(true);
        s.setMediaPlaybackRequiresUserGesture(false); // step voice-over audio can autoplay
        s.setMixedContentMode(WebSettings.MIXED_CONTENT_ALWAYS_ALLOW);
        s.setCacheMode(WebSettings.LOAD_NO_CACHE);
        web.addJavascriptInterface(new Bridge(), "ARWAGlasses");

        web.setWebViewClient(new WebViewClient() {
            @Override
            public void onReceivedError(WebView view, WebResourceRequest req, WebResourceError err) {
                if (!req.isForMainFrame()) return;
                Log.w(TAG, "load failed: " + err.getDescription() + " (" + url + ")");
                showWaiting(String.valueOf(err.getDescription()));
            }
            @Override
            public void onPageFinished(WebView view, String loaded) {
                Log.i(TAG, "loaded " + loaded);
                if (voice != null) voice.setOutputPlaying(false); // a new page isn't playing anything yet
            }
        });
        web.setWebChromeClient(new WebChromeClient() {
            @Override
            public boolean onConsoleMessage(ConsoleMessage m) {
                Log.i(TAG, "js: " + m.message() + " @" + m.sourceId() + ":" + m.lineNumber());
                return true;
            }
        });

        setContentView(web);
        hideSystemUi();
        url = pickUrl(getIntent());
        web.loadUrl(url);

        voice = new VoiceCommands(this, st -> { voiceStatus = st; Log.i(TAG, "voice status: " + st); });
        voice.setPageUrl(url);
        if (checkSelfPermission(Manifest.permission.RECORD_AUDIO) == PackageManager.PERMISSION_GRANTED) voice.start();
        else requestPermissions(new String[]{Manifest.permission.RECORD_AUDIO}, 1);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] results) {
        if (results.length > 0 && results[0] == PackageManager.PERMISSION_GRANTED) voice.start();
        else Log.w(TAG, "voice: microphone permission denied");
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        String next = pickUrl(intent);
        if (!next.equals(url) || intent.hasExtra("url")) { url = next; voice.setPageUrl(url); handler.removeCallbacks(retry); web.loadUrl(url); }
    }

    private String pickUrl(Intent intent) {
        SharedPreferences prefs = getSharedPreferences("glassview", MODE_PRIVATE);
        String fromIntent = intent != null ? intent.getStringExtra("url") : null;
        if (fromIntent != null && !fromIntent.isEmpty()) {
            prefs.edit().putString("url", fromIntent).apply();
            return fromIntent;
        }
        return prefs.getString("url", DEFAULT_URL);
    }

    /** Black "waiting for server" screen that retries until the page loads. */
    private void showWaiting(String why) {
        String html = "<html><body style='margin:0;background:#000;color:#9ca3af;font:20px sans-serif;"
                + "display:flex;align-items:center;justify-content:center;height:100vh;text-align:center'>"
                + "<div>Waiting for server…<br><small style='color:#4b5563'>" + escape(url) + "<br>" + escape(why)
                + "</small></div></body></html>";
        web.loadDataWithBaseURL(null, html, "text/html", "utf-8", null);
        handler.removeCallbacks(retry);
        handler.postDelayed(retry, RETRY_MS);
    }

    private static String escape(String s) {
        return s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;");
    }

    // ---------- keys from the temple touchpad / ring ----------
    @Override
    public boolean dispatchKeyEvent(KeyEvent e) {
        int code = e.getKeyCode();
        if (e.getAction() == KeyEvent.ACTION_DOWN) {
            Log.i(TAG, "key " + KeyEvent.keyCodeToString(code) + " (" + code + ") repeat=" + e.getRepeatCount());
        }
        // A touchpad gesture sends BACK, which would close the app mid-demo. Swallow it.
        // To leave the app: adb shell am force-stop com.worn.glassview (or the HOME key, which apps can't block).
        if (code == KeyEvent.KEYCODE_BACK) return true;
        String key = mapKey(code);
        if (key == null) return super.dispatchKeyEvent(e); // volume etc. behave normally
        if (e.getAction() == KeyEvent.ACTION_DOWN && e.getRepeatCount() == 0) {
            web.evaluateJavascript("window.dispatchEvent(new KeyboardEvent('keydown',{key:'" + key + "',bubbles:true}))", null);
        }
        return true;
    }

    private static String mapKey(int code) {
        switch (code) {
            case KeyEvent.KEYCODE_DPAD_RIGHT:
            case KeyEvent.KEYCODE_DPAD_DOWN:
            case KeyEvent.KEYCODE_DPAD_CENTER:
            case KeyEvent.KEYCODE_ENTER:
            case KeyEvent.KEYCODE_PAGE_DOWN:
            case KeyEvent.KEYCODE_MEDIA_NEXT:
            case KeyEvent.KEYCODE_MEDIA_PLAY_PAUSE:
                return "ArrowRight";
            case KeyEvent.KEYCODE_DPAD_LEFT:
            case KeyEvent.KEYCODE_DPAD_UP:
            case KeyEvent.KEYCODE_PAGE_UP:
            case KeyEvent.KEYCODE_MEDIA_PREVIOUS:
            case KeyEvent.KEYCODE_F9:          // M6 temple touchpad double tap
                return "ArrowLeft";
            default:
                return null;
        }
    }

    @Override
    public void onBackPressed() { /* blocked: see dispatchKeyEvent */ }

    // ---------- lifecycle ----------
    private void hideSystemUi() {
        web.setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY | View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION);
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) hideSystemUi();
    }

    @Override
    protected void onResume() { super.onResume(); web.onResume(); voice.pause(false); }

    @Override
    protected void onPause() { web.onPause(); voice.pause(true); super.onPause(); }

    @Override
    protected void onDestroy() {
        handler.removeCallbacksAndMessages(null);
        voice.stop();
        web.destroy();
        super.onDestroy();
    }

    /** window.ARWAGlasses in the page. */
    class Bridge {
        @JavascriptInterface public String device() { return "M6"; }
        @JavascriptInterface public String voiceStatus() { return voiceStatus; }
        /** The page tells us when its voice-over audio plays, so the mic doesn't hear the speaker. */
        @JavascriptInterface public void voiceOver(boolean playing) { if (voice != null) voice.setOutputPlaying(playing); }
        @JavascriptInterface public void log(String msg) { Log.i(TAG, "page: " + msg); }
        @JavascriptInterface public void reload() { handler.post(() -> web.loadUrl(url)); }
    }
}
