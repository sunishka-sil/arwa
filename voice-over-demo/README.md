# Voice-over demo

Shows the glasses reading each step aloud. When the step changes, the glasses say
*"Step 2 of 5. Scan the QR on PDU B2-07. Use the phone to scan the QR tag on the left PDU…"*,
and show the same title and description on screen.

It's standalone (nothing in the main ARWA app changed). It works together with the glasses app in `voice-prototype/glass-webview` (GlassView): you drive it hands-free with the glasses' own mic, and every step you move to is read aloud automatically. The touchpad works too: tap = next, double tap = back.

## Voice commands

| Say (to the glasses) | What happens |
|---|---|
| "next" / "back" | Move a step and read the new step aloud (unless muted) |
| "repeat" | Read the current step again (even when muted) |
| "mute" | Stop the voice-over now; later steps change silently |
| "unmute", "sound on" or "voice on" | Turn the voice-over back on and read the current step |
| "show" / "hide" | Show or clear the text on the glasses |

**"unmute" on the glasses:** the glasses' offline speech model doesn't know the word "unmute" and always hears it as "mute". We tested this with five different voices. So the glasses send "mute" as a toggle:
- If the voice-over is muted, saying "unmute" turns it back on, as you'd expect.
- If the voice-over is already on and you say "unmute", it mutes.

"Sound on" and "voice on" were recognized correctly every time and always unmute. The Mac's Chrome mic and the remote buttons send exact mute / unmute.

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

`POST /cmd {"cmd": "next" | "back" | "show" | "hide" | "repeat" | "mute" | "unmute" | "mute_toggle" | "restart" | "goto", "step": 0}`

The display page also takes keys (M = mute toggle):
- → / Enter / Space: next
- ←: back
- R: repeat
- H: hide
- S: show
