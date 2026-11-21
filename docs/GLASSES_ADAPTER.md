# Getting markers onto the MicroLumin glasses

The SDK docs are not public yet (organisers share them before kickoff; walkthrough is Fri 6:35 PM). The server already exposes
every transport an SDK is likely to support, so the adapter is a thin last mile. Pick the first path that works at the
SDK walkthrough and stop.

| If the SDK turns out to be… | Do this | Effort |
|---|---|---|
| **A. The glasses run Android / have a WebView or browser** | Load `http://<laptop-ip>:8080/glasses.html` full-screen. Done. Map the ring / temple touch to key events or call `window.arwaConfirm()` / `window.arwaExpert()` | 15 min |
| **B. Native Android app on the glasses (Kotlin/Java SDK)** | WebView pointed at `/glasses.html` (fastest), or OkHttp WebSocket to `/ws?device=glasses` and draw `headline` + `detail` with the SDK's text/UI API. Ring callback → send `{"action":"confirm_step"}` | 45–90 min |
| **C. Glasses are a display tethered to a phone (SDK runs on the phone, pushes text/images over BLE)** | Phone companion opens the WebSocket and calls the SDK's "show text" with `ARWA.toLines(marker)` (≤3 lines, ≤28 chars). If the SDK takes bitmaps, render the marker to a 2-colour canvas | 60–120 min |
| **D. Unity SDK** | `UnityWebRequest` poll `GET /api/markers?device=glasses` every 250 ms (or a WebSocket package), TextMeshPro for the two markers | 90+ min |
| **E. Nothing works by Sat 10 AM** | Keep the phone as the scanner + live view, and show `glasses.html` on any HUD you have. Say so honestly in the pitch: the point is that the server and marker format don't change | 0 |

## Display rules for a waveguide
- Black is transparent. Never fill backgrounds. Keep content in the centre ~70 % of the frame.
- Two markers max on glasses (router already caps this). One headline + one detail line each.
- If the display is monochrome, severity can't be colour: the client prefixes `✓ ✕ ! › ?` and stale uses a dashed bar + "DATA STALE".
- Assume the camera (if any) is not exposed to third-party code until proven otherwise. The phone does QR verify.

## Inputs to map
| Input | Action |
|---|---|
| Ring tap / temple tap / Enter | `confirm_step` |
| Ring long-press / swipe back / E | `call_expert` |
| Voice "confirm" / "next" | `confirm_step` (only if the SDK exposes ASR; don't build our own) |
| Head motion | Not needed for MVP. Nice-to-have: nod = confirm on hold points |
