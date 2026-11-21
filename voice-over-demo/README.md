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
| "voice off" | Stop the voice-over now; later steps change silently |
| "voice on" | Turn the voice-over back on and read the current step |
| "show" / "hide" | Show or clear the text on the glasses |

"Sound off" / "sound on" also work. A touchpad tap while the voice-over is talking mutes it; otherwise a tap means "next".

**Why "voice off" and not "mute":** the glasses' offline speech model doesn't know "unmute" (it always hears "mute"), and "mute" was unreliable on the glasses. "Voice off" and "voice on" were each recognized 6 times out of 6 across six test voices, and never confused with each other. They act once you finish the phrase, so a half-heard "voice o…" can't flip the wrong way.

### Interrupting the voice-over

You can talk over the voice-over, but **say the command firmly**. The glasses' mic also hears their own speaker, and the recognizer turns that speech into commands: before this check, the steps kept changing on their own. The M6 has no echo canceller, so the app uses loudness instead.

While the voice-over plays, a command only counts if the mic is clearly louder than the speaker's echo. It needs both:
- at least **2.5×** the echo level measured over the last 2 s;
- at least **2500** in absolute level.

What we measured on the M6:

| Sound at the mic | Peak vs echo level | Absolute peak |
|---|---|---|
| Speaker echo alone | up to 2.86× | up to 2439 |
| A command spoken over the voice-over | about 4× | 3000–4000 |

These thresholds are `BARGE_RATIO` / `BARGE_MIN` in `VoiceCommands.java`. If interrupting is too hard, lower them. If the voice-over starts triggering itself, raise them. The log shows the levels: `adb logcat -s GlassView`, then look for "mic during voice-over".

When nothing is playing, commands react to the recognizer's first guess (fast), as before.

**Restarts at step 1.** Opening the display (starting the glasses app) begins the demo at step 1, unmuted. The Mac preview doesn't reset anything.

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

`POST /cmd {"cmd": "next" | "back" | "show" | "hide" | "repeat" | "mute" | "unmute" | "mute_toggle" | "restart" | "goto", "step": 0}` ("voice off" sends mute, "voice on" sends unmute)

The display page also takes keys (M = mute toggle):
- → / Enter / Space: next
- ←: back
- R: repeat
- H: hide
- S: show
