# Voice command prototype

Hands-free page control on the M6 glasses: say **next**, **back**, **show** or **hide** and the display on the glasses changes. The glasses app also recognizes **repeat**, **mute** and **sound on** / **voice on**, which drive the voice-over demo in `../voice-over-demo/`; run that demo's server instead of `voice-test` to get spoken steps. Tested on our glasses: speech recognition runs on the glasses themselves (their own microphone, offline) and commands land in about 15 ms.

The pages are placeholder shapes for now. The plan is to swap in PDF pages / furniture steps and add a voice-over per step.

## How it fits together

```
 Glasses (GlassView app)                          Mac
 ┌──────────────────────────────┐   USB tunnel   ┌──────────────────────────┐
 │ WebView: localhost:8080/display ◀──────────────│ voice-test/server.js     │
 │ Mic → Vosk (offline) ──── POST /cmd ──────────▶│ holds { page, visible }  │
 │ Touchpad: tap = next,        │  (adb reverse) │ pushes changes to pages  │
 │           double tap = back  │                └──────────▲───────────────┘
 └──────────────────────────────┘                           │
                                     Optional: /remote in Chrome (Mac mic) or on a phone
```

- `voice-test/`: Node server with no dependencies, plus the pages.
  - `/display`: what the glasses show. Black background = see-through.
  - `/remote`: browser mic remote (Chrome speech recognition) with manual buttons.
- `glass-webview/`: the glasses app (package `com.worn.glassview`).
  - Full-screen WebView, plus offline voice commands (`VoiceCommands.java`, Vosk).
  - Blocks the Back key so a touchpad swipe can't close it mid-demo.

## Setup

1. **Speech model** (not in git, 68 MB): download `vosk-model-small-en-us-0.15.zip` from https://alphacephei.com/vosk/models and unzip its contents into `glass-webview/app/src/main/assets/model-en-us/`. Then add a file there named `uuid` containing any text, for example `vosk-small-en-us-0.15`.
2. **Glasses:** turn on Developer Mode with MLDemo, plug them into the Mac over USB, and find the serial with `adb devices -l`.
3. **Start the server:**
   ```bash
   cd voice-test && node server.js
   ```
4. **Build, install and launch** (JDK 17+; Android Studio's bundled JDK works):
   ```bash
   cd glass-webview
   export JAVA_HOME="/Applications/Android Studio.app/Contents/jbr/Contents/Home"
   ./run-on-glasses.sh <serial>
   ./keep-tunnel.sh <serial>     # leave running: re-creates the USB tunnel if it drops
   ```

## Useful commands

```bash
adb -s <serial> logcat -s GlassView                                   # what the mic heard, keys, page loads
adb -s <serial> shell am start -n com.worn.glassview/.MainActivity     # reopen the app
adb -s <serial> shell am force-stop com.worn.glassview                 # close it (Back is blocked)
adb -s <serial> exec-out screencap -p > shot.png                       # screenshot of the glasses
./run-on-glasses.sh <serial> http://localhost:8080/<other-page>        # show a different page
```

## Glasses quirks we found

- **Old browser engine:** the WebView is Chrome 74. CSS `inset` and flexbox `gap` don't work; use `top/right/bottom/left` and margins.
- **Status bar:** the system bar covers the top ~35 px of the 640×480 screen, so keep content below it.
- **USB tunnel:** `adb reverse` silently disappears when the USB link blips. `keep-tunnel.sh` restores it.
- **Touchpad keys:** tap = `KEYCODE_ENTER`, double tap = `KEYCODE_F9`. Another gesture sends `F11`, `O`, `F12`, `BACK`.
- **Phone mic:** a phone browser needs HTTPS to use the mic on `/remote`. Run `voice-test/make-cert.sh` (self-signed, kept out of git) and open `https://<mac-ip>:8443/remote`.
