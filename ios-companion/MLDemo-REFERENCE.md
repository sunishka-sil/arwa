# MLDemo: iOS sample app for the MicroLumin M6

A working iPhone app that connects to M6 glasses through `MLVisionM6SDK`, with one screen for each main SDK feature. Every team runs it first, whichever platform they build for: it checks that your glasses and phone work, and it's how you turn on the glasses' Developer Mode for installing glasses apps. Then copy whatever code you need.

Before you start, charge the glasses: they'll probably arrive flat. Keep them on the USB cable, and long-press the power button to turn them on the first time.

## Run it

1. Open **`MLDemo.xcworkspace`** (not the `.xcodeproj`). The Pods are already checked in, so you don't need to run `pod install`.
2. Select the **MLDemo** target, then **Signing & Capabilities**:
   - **Team**: choose your own Apple ID or team.
   - **Bundle Identifier**: change `com.CHANGEME.mldemo` to something unique, such as `com.yourname.mldemo`.
3. Choose a **real iPhone** (iOS 15 or later) and press Run. The SDK uses Bluetooth, so the Simulator won't work.
4. On iOS 16 or later, turn on Developer Mode on the iPhone when asked (Settings › Privacy & Security › Developer Mode). The phone restarts.
5. On the phone, go to Settings › General › VPN & Device Management and trust your developer certificate (needed the first time with a free Apple ID).
6. Open MLDemo and allow Bluetooth. On the Glasses screen, tap **Set Up Glasses**, then tap your pair. In a room full of glasses, hold yours next to the phone: they'll have the strongest signal. The glasses say "Connected" when they're linked. Next time, just tap **Connect**.

Tested with Xcode 26.5.

## What's in the app

| Screen | What it shows | Code |
|---|---|---|
| Glasses (home) | Search, pair, connect and disconnect; volume, brightness and screen timeout | `HomeViewController.swift`, `GlassesSession.swift` |
| Voice Assistant | Wake the assistant, show its results, and speak text on the glasses | `FeatureViewControllers.swift` (`AssistantViewController`) |
| Camera | Take photos, record video and record audio on the glasses | `CameraViewController` |
| Live Interpreting | Simultaneous interpretation with source and target languages | `InterpretingViewController`, `InterpretingTap.swift` |
| Record and Transcribe / Transcribe Samples | Recording, transcription, and summaries; three sample `.wav` files are bundled | `RecordViewController`, `TranscribeViewController` |
| Wi-Fi | Join the glasses to a network (saved passwords go in the Keychain) | `WifiViewController.swift`, `SavedNetworks.swift` |
| Files | Sync media files from the glasses to the phone | `FilesViewController` |
| Developer (on the Glasses screen) | Turn the glasses' Developer Mode (USB debugging) on or off | `HomeViewController.swift`, `GlassesSession.setDeveloperMode(_:)` |
| Event Log | Everything the app and SDK reported | `LogViewController` |

**Speech language.** Live Interpreting and Record and Transcribe share one "Speak in" language, which defaults to English on first launch. Change it from either screen; the app remembers your choice (`SpeechLanguages.swift`). Transcribe Samples uses the SDK's `startTranscribe(filePath:)`, which has no language parameter.

`GlassesSession.swift` is the one place that talks to the SDK. Start there if you're building your own app.

When the app runs without the Xcode debugger attached, it writes console output (including the SDK's own logs) to `Documents/console.log`. You can pull it off the phone with Finder or Xcode's Devices window.

## Developer Mode (installing apps on the glasses)

The glasses run Android 9. To install your own app on them, turn on USB debugging with MLDemo:

1. Connect the glasses in MLDemo, then turn on **Developer Mode** in the Developer section of the Glasses screen. It's greyed out until the glasses are connected.
2. Unplug the glasses' USB cable and plug it into your computer again.
3. Run `adb devices -l`. The glasses show up with `model:XNM_Glass`. If a prompt on the glasses asks to allow USB debugging, accept it.
4. Install and start your app with `adb install -r app-debug.apk` and `adb shell am start -n com.you.app/.MainActivity`.

`01_Start_Here/README.md` ("Building a glasses app") has the display specs and more detail. The toggle sends `{"developer_mode": true}` to the glasses' device-settings channel (BLE message type 10), the same message the Android SDK's `DevModel.addDeveloperMode` builds. If the glasses report `developer_mode` back, the toggle follows their value.

## Known SDK issues (and how this app works around them)

These are SDK bugs. If you build your own app directly on `MLVisionM6SDK`, you'll hit them too. The workarounds are in `DiscoveryGate.swift`.

1. **The SDK auto-connects to paired glasses.** As soon as any SDK scan sees the last-paired glasses, the SDK connects to them, and the glasses announce "Connected" even if the user didn't choose them. The SDK has no option to turn this off. `DiscoveryGate` replaces `MLBLEManager`'s `centralManager:didDiscoverPeripheral:advertisementData:RSSI:` at runtime, so the paired glasses only reach the SDK while the user is connecting.
2. **The SDK crashes after a photo is taken.** When the glasses' camera app (app 25) sends its app-status message, the SDK hits a Swift trap in `MLBLEManager.handleAppInfo`. `BluetoothTrafficProbe` drops that one status message before the SDK sees it. The photo itself is unaffected.
3. **Some SDK messages are in Chinese.** Interpreting results come through the SDK's log (`翻译中:`). Some file errors (`不在同一个网络`, "not on the same network") and the default device name (`未命名`, "Unnamed") are Chinese too. `InterpretingTap.swift` and `GlassesSession.swift` match these strings, so leave them in Chinese.

Both workarounds use the Objective-C runtime to patch private SDK classes (`_TtC13MLVisionM6SDK12MLBLEManager`). If a future SDK build renames those classes, the app logs that the workaround couldn't be installed and carries on without it.

## Using the SDK in a new project

Follow `01_Start_Here/MLVisionM6SDK_Integration_Guide_EN.docx`, with two corrections:

- Add this to your Podfile's `post_install`, or YYKit won't compile on current Xcode:
  ```ruby
  if target.name == 'YYKit'
    config.build_settings['OTHER_CFLAGS'] = '$(inherited) -Wno-error=parentheses'
  end
  ```
- This app also uses `pod 'CocoaLumberjack/Swift', '~> 3.8.5'` (for `InterpretingTap`). The guide's pod list doesn't include it.

Compare this project's `Podfile`, build settings and `Info.plist` permission strings with yours if something doesn't link or a permission prompt is missing.
