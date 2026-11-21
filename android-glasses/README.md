# ARWA glasses app (Android, for the MicroLumin M6)

## Phone companion build

The default screen now runs locally and advertises an ARWA name for the Swift companion in `../ios-companion`.
The existing motor-coupling guide and Three.js are bundled into the APK; the laptop is not needed for guide playback.
Debug builds install as **ARWA Companion** (`com.arwa.glasses.companion`), alongside the original app.

Prepare the offline speech model from the arwa folder with `python3 scripts/prepare-voice-model.py` (verified download, about 40 MB).
Build with JDK 17, Android SDK 34, and `./gradlew assembleDebug`. Then install `app/build/outputs/apk/debug/app-debug.apk`
and open **ARWA Companion** on the glasses. In the iPhone app, connect through the existing Bluetooth flow, select the
ARWA name shown on your glasses in Set Up Guides, and start the motor-coupling guide. Both devices need the same reachable Wi-Fi.

To open the companion from ADB when you are ready to change the display:
`adb shell am start -n com.arwa.glasses.companion/com.arwa.glasses.MainActivity`

To return to its setup/name screen, press Android Back, or launch a fresh instance with `--ez setup true`.
Guide progress is saved on the glasses. HTTP APIs live at `/api/companion/status` and `/api/companion/command` on port 8080.
No phone connection code is required. The initial prototype trusts the local Wi-Fi network.

### Voice navigation

The glasses' own microphone now supports **next**, **back**, **show**, and **hide**, using the offline Vosk recognizer
adapted from `origin/voice-commands` commit `f54cb11`. It updates the same local guide state as the touchpad and phone.
The phone continues to follow progress; no laptop or phone microphone is needed.

Voice is enabled by default when a guide is open. Accept the microphone permission prompt on first use. The footer
shows whether the model is loading, listening, paused, or off. The updated iPhone current-guide screen has a voice
on/off control and shows the last voice command. Existing phone builds can still navigate the updated glasses.

Recognition stops and releases the microphone when the app goes into the background or returns to the setup screen.
It also pauses around Android text-to-speech so spoken output does not navigate the guide. Touchpad/phone controls
remain available. Partial and final hypotheses are deduplicated, and corrections at an already-fired position do not
execute a second command.

The English model is bundled in the APK and is copied to app storage on first use. Its download is ignored by git;
`scripts/prepare-voice-model.py` checks SHA-256 and supplies the required `uuid`. The build fails with setup instructions
if model files are missing. This integration adds navigation commands; the separate `voice-over` branch's narration
and playback controls are not included.

The older laptop workflow below uses the original release package name, `com.arwa.glasses`.
For a debug companion build, replace that package with `com.arwa.glasses.companion` and use the full activity class
`com.arwa.glasses.MainActivity` in launch commands. An explicit `--es url` still opens laptop-hosted pages.

## Original laptop workflow

A small plain-Android app for the glasses: a full-screen WebView on the ARWA server's `glasses.html`
(black background = see-through), touchpad/ring keys mapped to confirm / call expert, and a
`window.ARWAGlasses` bridge for the glasses' camera (panel check), speaker (spoken alerts) and mic (voice).
No MicroLumin SDK and no Mac needed: the kit has no glasses-side SDK, so this uses standard Android APIs.

Glasses: Android 9 (API 28), arm64, 640×480 at 160 dpi. This app: minSdk 24, targetSdk 28.

## 0. One-time: Developer Mode (needs MLDemo on an iPhone)
`adb` only sees the glasses after Developer Mode is on, and the only documented switch is in the iOS MLDemo app
(Glasses › Developer › Developer Mode). It is a setting on the glasses, so any iPhone running MLDemo can flip it once:
an organizer's or another team's. Afterwards unpair the glasses from that iPhone. First check whether it's already on:
plug the glasses in and run `adb devices -l` (look for `model:XNM_Glass`).

## 1. Build and run (Windows)
1. Android Studio (includes JDK 17 and adb). File › Open › this `android-glasses` folder. Let it sync.
2. Laptop: in `arwa-starter`, `npm start` (and `npm run sim` in a second window for test data).
3. Glasses on the USB cable: `adb devices -l` shows `XNM_Glass`. Accept the USB-debugging prompt on the glasses.
4. Let the glasses reach the laptop over the cable: `adb reverse tcp:8080 tcp:8080`
5. Run in Android Studio with the glasses selected, or:
   ```
   adb install -r app\build\outputs\apk\debug\app-debug.apk
   adb shell pm grant com.arwa.glasses android.permission.CAMERA
   adb shell pm grant com.arwa.glasses android.permission.RECORD_AUDIO
   adb shell am start -n com.arwa.glasses/.MainActivity
   ```
6. `adb logcat -s ARWA` shows keys, page errors, camera and voice. Press each touchpad gesture / ring button and
   adjust `dispatchKeyEvent` in `MainActivity.java` to the codes you see.

adb on Windows lives at `%LOCALAPPDATA%\Android\Sdk\platform-tools\adb.exe`.

## Over Wi-Fi instead of the cable
Glasses and laptop on the same Wi-Fi (join it from MLDemo's Wi-Fi screen), then:
`adb shell am start -n com.arwa.glasses/.MainActivity --es url "http://<laptop-ip>:8080/glasses.html?name=glasses&scale=1.2"`
Allow Node through Windows Firewall when asked. For the demo, the cable + `adb reverse` is the safer bet.

## What may not work on the glasses (and the fallback)
| Feature | How | If it fails |
|---|---|---|
| Ring / touchpad | key events in `dispatchKeyEvent` | launcher may swallow them: tap = click also confirms; phone buttons |
| Spoken alerts | Android TextToSpeech | no TTS engine on glasses → tones only (WebAudio) |
| Voice commands | Android SpeechRecognizer | no recognizer service → ring + phone |
| Panel check | `android.hardware.Camera` still → `POST /api/vision/panel` | launcher holds the camera → phone camera on `cv.html` |
| Screen stuck on "Connecting…" | old WebView JS | check `page:` lines in logcat |

## 3D animations on the glasses
`anim3d.html` renders three.js wireframe scenes (served by the laptop, works offline). Open one on the glasses:
`adb shell am start -n com.arwa.glasses/.MainActivity --es url "http://localhost:8080/anim3d.html?scene=bolts"`
Scenes: `scene=bolts` (cover-plate star tightening pattern, ring = next bolt) and `scene=arrow` (3D wayfinding arrow).
Guided jobs: `workflow3d.html` (motor-to-pump coupling) and `mccb3d.html` (3-pole circuit breaker assembly). Switch job from the phone's Job menu; the glasses page follows.
The fps counter sits bottom-right; lower `?fps=20` if the glasses struggle.

## Where the view sits on the display
Inside this app every page shrinks into a corner panel (top right, 55% of the display) so the centre of vision stays clear.
Change it per page with URL params: `pos=tr|tl|br|bl|full` and `size=0.4…1`, e.g.
`adb shell am start -n com.arwa.glasses/.MainActivity --es url "http://localhost:8080/glasses.html?pos=tl&size=0.5"`
The image distance is fixed by the optics; size and position are what software controls.

## Voice from the phone (hands-free, reliable)
The glasses' own mic isn't reliable, so voice runs on the phone: open `https://<laptop-ip>:8443/voice.html` in Chrome
(Android) or Safari (iOS), accept the certificate warning once, tap the mic, and pocket the phone.
Say **next**, **back**, **hide** (clears the glasses view) or **show**; "step five" jumps. The glasses page
`workflow3d.html` follows within a few hundred ms. Phone and laptop must be on the same Wi-Fi (travel router).

## Side touchpad (and ring)
Same four commands as phone voice: **swipe forward = next**, **swipe back = back**, **tap = hide/show the view**,
**hold = call expert**. Key events, touch events and touchpad scroll are all handled; each logs under `ARWA`
(`key …`, `touch gesture dx=…`, `scroll h=…`, then `nav next|back|toggle|expert`). If swipes are reversed, start with
`--ez swap true`. If nothing at all logs, the launcher is keeping the pad: use phone voice and tell us.

## Ask (AI) from the phone
Say or type a question on `voice.html` ("what's the torque?", "is it safe?", "what's next?", "how hot is it?").
The laptop answers with ONE widget on the glasses (big number, reading + trend, note, hazard, next step, progress).
With `ANTHROPIC_API_KEY` in `.env` Claude picks the widget; without it a keyword rules engine does, offline.
Check what the AI sees: `http://localhost:8080/api/ask/context`.
