# ARWA starter (Worn hackathon, Nov 20–21 2026)

**Right asset, right step.** Live equipment state pinned to the physical asset, one thing at a time, on any device.
Read-only and advisory: nothing here writes to equipment.

```
sim/sensor.js or ESP32 ──MQTT──▶ adapter ─▶ state model ─▶ router ─▶ WebSocket / HTTP / MQTT ─▶ glasses · phone · expert
  (1 sources)          (2 transport)   (3: Stale is a state)  (4: role+priority+device)   (5: server sends meaning, device draws)
```

## Run it (one laptop, 2 minutes)

```bash
npm install
npm start            # terminal 1: MQTT broker :1883, web :8080, https :8443
npm run sim          # terminal 2: simulated PDUs. keys: o/c breaker, p/r pause feed, h heat, l partner load
npm test             # 6 tests: stale detection, router rules, step gating
```

Or `npm run demo` to run both in one terminal (keys go to the sim).

Open on the same Wi-Fi (the server prints the LAN URL):

| URL | What |
|---|---|
| `/glasses.html` | Glasses view. Black = transparent on a waveguide. `?mono=1` for monochrome, `?scale=1.3` for bigger text. Enter/Space/→/tap = confirm, E/← = call expert |
| `https://<ip>:8443/phone.html` | Technician phone: camera QR scan with green halo / red outline, confirm, expert. **Camera needs HTTPS**: accept the self-signed cert once |
| `/phone.html?role=remote_expert` | Remote expert: same asset and step, receives the call |
| `/phone.html?role=supervisor` | Router demo: status and alarms only, no steps |
| `/qr.html` | Print the QR tags (`arwa:pdu07`, `arwa:pdu08`) |
| `/study.html` | With vs without ARWA timing study, saves to `logs/trials.csv` |
| `/api/markers?device=glasses` | Raw marker JSON for any SDK that can only poll HTTP |
| `/api/evidence` | Evidence log (asset ID, time, verification method). No video |

## Computer vision (phone camera, works without glasses camera access)
- `https://<ip>:8443/cv.html` → **Check panel**: snap the machine panel (or `/panel.html` on a tablet). Claude (`claude-opus-5-5`, low effort, structured output) reads recipe, speed, heater and fault code; `data/recipes.json` decides pass/fail in plain code. The verdict also flashes on every glasses view. Needs `ANTHROPIC_API_KEY` (or `ant auth login`) where `npm start` runs; without it the page says so.
- **Hazard zone**: prop a phone up as the cell camera. MediaPipe hand tracking runs on the phone; a hand inside the red box sends `HANDS CLEAR` to the glasses. No images leave the phone.
- If the M6 SDK lets us take a photo, post it to the same `POST /api/vision/panel` endpoint.

## The demo script in 60 seconds
1. Step 1/5 navigate → confirm.
2. Scan **B2-08** (look-alike) → glasses flash `✕ WRONG ASSET`. Scan **B2-07** → verified.
3. Step 3 hold point checks feed B load < 50 %. Press `l` in the sim to overload B: the step refuses. Press `l` again.
4. Step 4 "Open breaker CB-12": confirm is **blocked** until the live reading says 0 A. Press `o` (or flip the real switch): current ramps to 0, the step turns green, confirm.
5. Press `p` (or unplug the ESP32): within 3 s every screen says `DATA STALE`, never a last-known value. Press `r`.
6. HUD shows sensor→screen latency (≈50 ms on LAN) and WebSocket RTT.

## Files
```
server/state.js      Asset, State (Running|Idle|Faulted|Offline|Stale), Signal, Alarm; stale sweep
server/procedure.js  Procedure/Step runner: scan gate, hold point on partner feed, reading gate, evidence log
server/router.js     Builds marker JSON; role filter, priority sort, device cap (glasses 2, phone 5)
server/index.js      Embedded MQTT broker (aedes), MQTT adapter, WebSocket + HTTP delivery, QR SVGs, HTTPS
sim/sensor.js        Two PDUs at 2 Hz on arwa/v1/telemetry/<asset_id>. SIM_ASSETS=pdu08 when the ESP32 feeds pdu07
firmware/esp32_sensor ESP32 + ACS712/ACS723 + NTC → same topic/payload. Low-voltage mock load only
data/packs/<pack>/   Asset list + procedure per vertical (PACK=datacenter today); data/recipes.json, data/roles.json
server/vision.js     Claude vision panel reader + deterministic recipe check
public/ui.html       Clickable glasses UI prototype (Cell 3 + nuclear), no server needed
public/arwa-client.js The only client library: connect(), toLines() for text-only displays, palettes
docs/GLASSES_ADAPTER.md How to put markers on the MicroLumin glasses once we see the SDK
```

## Config
`PORT=8080 HTTPS_PORT=8443 MQTT_PORT=1883 STALE_S=3 MQTT_URL=mqtt://other-broker:1883 SIM_HZ=2`

## Telemetry contract
Topic `arwa/v1/telemetry/<site>/<hall>/<row>/<rack>/<device>`, payload
`{"ts": <epoch ms>, "signals": {"current_A": 7.1, "load_pct": 44, "temp_C": 31}}`.
Markers go out on WebSocket `/ws?role=&device=`, on `GET /api/markers`, and retained on MQTT `arwa/v1/markers/<role>/<device>`.
Actions come back as `{"action": "confirm_step" | "scan" (+anchor_id) | "call_expert" | "reset"}` over WS or `POST /api/action`.

## Not built, on purpose
No equipment control, no video recording, no ML/anomaly detection, no custom hardware beyond one sensor.
