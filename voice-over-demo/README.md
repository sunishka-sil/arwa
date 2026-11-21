# Voice-over demo

Shows the glasses reading each step aloud. When the step changes, the glasses say
*"Step 2 of 5. Scan the QR on PDU B2-07. Use the phone to scan the QR tag on the left PDU…"*,
and show the same title and description on screen.

It's standalone (nothing in the main ARWA app changed) and uses the same commands as `voice-prototype/` on the `voice-commands` branch. If the GlassView app from that branch is on the glasses, you can drive it hands-free with the glasses mic: say "next", "back", "show" or "hide". The touchpad works too: tap = next, double tap = back.

## Run

```bash
cd voice-over-demo
node server.js                     # macOS; no npm install needed
```

- **On the Mac:** open http://localhost:8080/remote. It has buttons (Next, Back, Repeat, Hide, Show), a live view of the glasses screen, and a step list you can click to jump.
  - The preview is muted. Tick "Play voice-over on this Mac too" to hear it on the Mac.
  - Chrome's mic can drive it as well, for testing without glasses.
- **On the glasses** (USB, GlassView installed; see `voice-prototype/README.md`):
  ```bash
  adb -s <serial> reverse tcp:8080 tcp:8080
  adb -s <serial> shell am start -n com.worn.glassview/.MainActivity --es url http://localhost:8080/display
  ```
  Run `voice-prototype/glass-webview/keep-tunnel.sh <serial>` so the tunnel survives USB blips.

## How the voice works

- **The server makes the audio.** It turns each step into WAV audio with macOS `say`, generating all steps at startup (about 18 s) and caching them in `.tts-cache/`. A step change then plays instantly.
- **The glasses play a normal audio file.** This doesn't depend on the glasses having a speech engine of their own.
- **Fallbacks:** if the server can't make audio, `display.html` uses `ARWAGlasses.say()` from the glasses app, then the browser's own speech.
- **Codes are spelled out** so the voice says them clearly: "CB-12" → "C B 12", and likewise "PDU" and "QR". See `speakable()` in `server.js`.
- **Settings:**
  - `TTS_VOICE=Samantha` picks a voice; list the options with `say -v ?`.
  - `TTS_RATE=180` sets the speed in words per minute.

## Change the steps

Edit `steps.json` (title + description per step) and restart the server. The audio is regenerated automatically.

## Commands

`POST /cmd {"cmd": "next" | "back" | "show" | "hide" | "repeat" | "restart" | "goto", "step": 0}`

The display page also takes keys:
- → / Enter / Space: next
- ←: back
- R: repeat
- H: hide
- S: show
