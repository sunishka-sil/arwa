package com.arwa.glasses;

import android.content.Context;
import android.content.SharedPreferences;
import android.util.Log;
import android.net.nsd.NsdManager;
import android.net.nsd.NsdServiceInfo;
import android.provider.Settings;
import org.json.JSONObject;
import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.concurrent.*;

/** Small, app-local HTTP service. No laptop or vendor glasses-side SDK is involved. */
final class GuideServer implements Closeable {
    static final int PORT = 8080;
    private final Context context;
    private final Runnable launch;
    private final Runnable voiceSettingsChanged;
    private final SharedPreferences prefs;
    private final GuideState state = new GuideState();
    private final String deviceId;
    private final String deviceLabel;
    private NsdManager nsd;
    private NsdManager.RegistrationListener registration;
    private final ThreadPoolExecutor workers = new ThreadPoolExecutor(4, 4, 0, TimeUnit.SECONDS,
            new ArrayBlockingQueue<>(16), new ThreadPoolExecutor.AbortPolicy());
    private final Set<String> requests = new LinkedHashSet<>();
    private ServerSocket socket;
    private volatile boolean running;
    private volatile long viewerSeen;
    private volatile long displayedRevision = -1;
    private volatile boolean foreground;
    private volatile boolean viewerEnabled;
    private volatile boolean voiceEnabled;
    private volatile String voiceStatus = "Waiting for guide";
    private volatile String lastVoiceCommand = "";
    private static final Set<String> FILES = new HashSet<>(Arrays.asList(
            "workflow3d.html", "workflow-steps.js", "hud-layout.js", "widget.js", "arwa-client.js", "vendor/three.min.js"));

    GuideServer(Context context, Runnable launch, Runnable voiceSettingsChanged) {
        this.context = context;
        this.launch = launch;
        this.voiceSettingsChanged = voiceSettingsChanged;
        prefs = context.getSharedPreferences("arwa-guide", Context.MODE_PRIVATE);
        voiceEnabled = prefs.getBoolean("voiceEnabled", true);
        String androidId = Settings.Secure.getString(context.getContentResolver(), Settings.Secure.ANDROID_ID);
        deviceId = androidId != null ? androidId : prefs.getString("deviceId", UUID.randomUUID().toString());
        prefs.edit().putString("deviceId", deviceId).apply();
        deviceLabel = "ARWA-" + deviceId.substring(Math.max(0, deviceId.length() - 4));
        state.restore(prefs.getBoolean("started", false), prefs.getInt("step", 0),
                prefs.getBoolean("hidden", false), prefs.getLong("revision", 0));
    }

    void start() throws IOException {
        socket = new ServerSocket();
        socket.setReuseAddress(true);
        socket.bind(new InetSocketAddress(PORT));
        running = true;
        Thread accept = new Thread(() -> {
            while (running) {
                try {
                    Socket client = socket.accept();
                    client.setSoTimeout(5000);
                    try { workers.execute(() -> serve(client)); }
                    catch (RejectedExecutionException e) { client.close(); }
                } catch (IOException e) { if (running) Log.e("ARWA", "Guide connection failed", e); }
            }
        }, "ARWA-guide-listener");
        accept.setDaemon(true);
        accept.start();
        advertise();
    }

    private void advertise() {
        try {
            nsd = (NsdManager) context.getSystemService(Context.NSD_SERVICE);
            NsdServiceInfo info = new NsdServiceInfo();
            info.setServiceName(deviceLabel);
            info.setServiceType("_arwa-guide._tcp.");
            info.setPort(PORT);
            info.setAttribute("protocol", "1");
            info.setAttribute("deviceId", deviceId);
            registration = new NsdManager.RegistrationListener() {
                public void onServiceRegistered(NsdServiceInfo s) { Log.i("ARWA", "Discoverable as " + s.getServiceName()); }
                public void onRegistrationFailed(NsdServiceInfo s, int e) { Log.w("ARWA", "Discovery registration failed: " + e); }
                public void onServiceUnregistered(NsdServiceInfo s) { }
                public void onUnregistrationFailed(NsdServiceInfo s, int e) { }
            };
            nsd.registerService(info, NsdManager.PROTOCOL_DNS_SD, registration);
        } catch (Exception e) { Log.w("ARWA", "Automatic discovery unavailable; use the Wi-Fi address", e); }
    }

    boolean isStarted() { synchronized (state) { return state.started; } }
    void viewerClosed() { viewerEnabled = false; viewerSeen = 0; displayedRevision = -1; }
    void setViewerEnabled(boolean enabled) { viewerEnabled = enabled; if (!enabled) viewerClosed(); }
    void setForeground(boolean value) { foreground = value; }
    boolean canListen() { synchronized (state) { return voiceEnabled && state.started && foreground && viewerEnabled; } }
    boolean isVoiceEnabled() { return voiceEnabled; }
    void setVoiceStatus(String status) { voiceStatus = status; }
    void setVoiceEnabled(boolean enabled) {
        voiceEnabled = enabled;
        prefs.edit().putBoolean("voiceEnabled", enabled).apply();
        voiceSettingsChanged.run();
    }

    void voiceCommand(String command) {
        synchronized (state) {
            if (!canListen()) return;
            state.command(command, null);
            lastVoiceCommand = command;
            save();
        }
    }

    private JSONObject snapshot() throws Exception {
        synchronized (state) {
            return new JSONObject().put("app", "arwa-glasses").put("protocol", 1)
                    .put("deviceId", deviceId).put("deviceLabel", deviceLabel)
                    .put("type", "wf").put("job", GuideState.GUIDE_ID).put("guideVersion", 1)
                    .put("started", state.started).put("step", state.step).put("total", GuideState.TOTAL)
                    .put("hidden", state.hidden).put("revision", state.revision)
                    .put("voiceEnabled", voiceEnabled).put("voiceStatus", voiceStatus).put("lastVoiceCommand", lastVoiceCommand)
                    .put("viewerReady", foreground && viewerEnabled && viewerSeen > 0 && System.currentTimeMillis() - viewerSeen < 4000)
                    .put("displayedRevision", displayedRevision);
        }
    }

    private void save() {
        prefs.edit().putBoolean("started", state.started).putInt("step", state.step)
                .putBoolean("hidden", state.hidden).putLong("revision", state.revision).apply();
    }

    private void serve(Socket client) {
        try (Socket ignored = client) {
          try {
            InputStream in = client.getInputStream();
            String first = line(in);
            if (first == null) return;
            String[] request = first.split(" ");
            if (request.length != 3) { reply(client, 400, "Bad request"); return; }
            Map<String, String> headers = new HashMap<>();
            int size = first.length();
            for (String h; (h = line(in)) != null && !h.isEmpty();) {
                size += h.length();
                if (size > 8192) { reply(client, 413, "Headers too large"); return; }
                int colon = h.indexOf(':');
                if (colon > 0) headers.put(h.substring(0, colon).toLowerCase(Locale.US), h.substring(colon + 1).trim());
            }
            String method = request[0], path = new URI(request[1]).getPath();
            boolean local = client.getInetAddress().isLoopbackAddress();
            // Reject cross-origin browser requests. This prototype trusts the local Wi-Fi network.
            String origin = headers.get("origin");
            if (origin != null && !origin.equals("http://127.0.0.1:" + PORT) && !origin.equals("http://localhost:" + PORT)) {
                reply(client, 403, "Origin not allowed"); return;
            }
            if (headers.containsKey("transfer-encoding")) { reply(client, 400, "Use Content-Length"); return; }
            int length = Integer.parseInt(headers.getOrDefault("content-length", "0"));
            if (length < 0 || length > 16384) { reply(client, 413, "Body too large"); return; }
            byte[] body = new byte[length];
            int offset = 0;
            while (offset < length) { int n = in.read(body, offset, length - offset); if (n < 0) throw new EOFException(); offset += n; }
            boolean companion = path.startsWith("/api/companion/");
            if (!companion && !local) { reply(client, 403, "Use the companion API"); return; }

            if (method.equals("GET") && (path.equals("/api/wf") || path.equals("/api/companion/status"))) {
                json(client, 200, snapshot()); return;
            }
            if (method.equals("POST") && path.equals("/api/viewer") && local) {
                JSONObject b = new JSONObject(new String(body, StandardCharsets.UTF_8));
                if (viewerEnabled) { displayedRevision = b.getLong("revision"); viewerSeen = System.currentTimeMillis(); }
                json(client, 200, snapshot()); return;
            }
            if (method.equals("POST") && (path.equals("/api/wf") || path.equals("/api/companion/command"))) {
                JSONObject b = new JSONObject(new String(body, StandardCharsets.UTF_8));
                if (!GuideState.GUIDE_ID.equals(b.optString("job", GuideState.GUIDE_ID))) { reply(client, 400, "Guide not installed"); return; }
                String cmd = b.getString("cmd"), id = b.getString("requestId");
                if (id.isEmpty() || id.length() > 80) { reply(client, 400, "Invalid request ID"); return; }
                boolean shouldLaunch = false;
                synchronized (state) {
                    if (!requests.contains(id)) {
                        if (cmd.equals("voice_on") || cmd.equals("voice_off")) {
                            setVoiceEnabled(cmd.equals("voice_on"));
                        } else {
                            state.command(cmd, b.has("step") ? b.getInt("step") : null);
                            save();
                        }
                        requests.add(id);
                        if (requests.size() > 128) requests.remove(requests.iterator().next());
                        shouldLaunch = cmd.equals("start");
                    }
                }
                if (shouldLaunch) { viewerClosed(); launch.run(); }
                json(client, 200, snapshot()); return;
            }
            if (!method.equals("GET")) { reply(client, 405, "Method not allowed"); return; }
            if (path.equals("/") || path.equals("/setup")) {
                String addresses = String.join("<br>", addresses());
                String html = "<!doctype html><meta name='viewport' content='width=device-width,initial-scale=1'>"
                        + "<style>body{background:#000;color:#fff;font:22px system-ui;margin:28px}small{color:#aaa}h1{font-size:26px}</style>"
                        + "<h1>" + deviceLabel + "</h1><small>After Bluetooth pairing, choose this name in ARWA on your iPhone.</small>"
                        + "<p>Keep both devices on the same Wi-Fi.</p><small>Manual connection address:</small><p>"
                        + (addresses.isEmpty() ? "Join Wi-Fi using MicroLumin Settings" : addresses) + "</p>"
                        + "<small>Keep ARWA open on the glasses.</small><script>setTimeout(function(){location.reload()},10000)</script>";
                bytes(client, 200, "text/html; charset=utf-8", html.getBytes(StandardCharsets.UTF_8)); return;
            }
            String file = path.startsWith("/") ? path.substring(1) : path;
            if (!FILES.contains(file)) { reply(client, 404, "Not found"); return; }
            try (InputStream asset = context.getAssets().open("guide/" + file)) {
                ByteArrayOutputStream out = new ByteArrayOutputStream();
                byte[] buffer = new byte[8192]; for (int n; (n = asset.read(buffer)) != -1;) out.write(buffer, 0, n);
                bytes(client, 200, file.endsWith(".html") ? "text/html; charset=utf-8" : "application/javascript; charset=utf-8", out.toByteArray());
            }
          } catch (IllegalArgumentException | org.json.JSONException e) {
              reply(client, 400, e.getMessage() == null ? "Invalid request" : e.getMessage());
          }
        } catch (Exception e) {
            Log.w("ARWA", "Guide request: " + e.getMessage());
        }
    }

    private static String line(InputStream in) throws IOException {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        for (int c; (c = in.read()) != -1;) {
            if (c == '\n') return out.toString("US-ASCII").replace("\r", "");
            if (out.size() >= 8192) throw new IOException("Header too large");
            out.write(c);
        }
        return null;
    }
    private static void json(Socket s, int status, JSONObject body) throws IOException { bytes(s, status, "application/json", body.toString().getBytes(StandardCharsets.UTF_8)); }
    private static void reply(Socket s, int status, String error) throws IOException {
        try { json(s, status, new JSONObject().put("error", error)); } catch (org.json.JSONException e) { throw new IOException(e); }
    }
    private static void bytes(Socket s, int status, String type, byte[] body) throws IOException {
        OutputStream out = s.getOutputStream();
        out.write(("HTTP/1.1 " + status + " " + (status == 200 ? "OK" : "Error") + "\r\nContent-Type: " + type
                + "\r\nContent-Length: " + body.length + "\r\nCache-Control: no-store\r\nConnection: close\r\nX-Content-Type-Options: nosniff\r\n\r\n").getBytes(StandardCharsets.US_ASCII));
        out.write(body); out.flush();
    }
    private static List<String> addresses() {
        List<String> result = new ArrayList<>();
        try {
            for (NetworkInterface n : Collections.list(NetworkInterface.getNetworkInterfaces()))
                if (n.isUp()) for (InetAddress a : Collections.list(n.getInetAddresses()))
                    if (a instanceof Inet4Address && !a.isLoopbackAddress() && !a.isLinkLocalAddress()) result.add(a.getHostAddress() + ":" + PORT);
        } catch (Exception e) { Log.w("ARWA", "No Wi-Fi address", e); }
        return result;
    }
    @Override public void close() {
        running = false;
        try { if (nsd != null && registration != null) nsd.unregisterService(registration); } catch (Exception ignored) { }
        try { if (socket != null) socket.close(); } catch (IOException ignored) { }
        workers.shutdownNow();
    }
}
