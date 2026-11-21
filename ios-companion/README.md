# ARWA iPhone companion

The complete Swift/UIKit phone app, Xcode project, and MicroLumin SDK integration are included here. This extends MLDemo with a Guides home screen, a current-guide screen, direct Wi-Fi controls, and offline voice-navigation status. The gear button opens the original MLDemo settings and features. The main vendor framework binary remains a local dependency because GitHub secret scanning identified embedded credentials in it and its generated ABI metadata.

The original kit in `Microlumin_Ship` is unchanged. This project is now inside the ARWA repository. On the development machine, the previous `../arwa-ios` path is an alias to this folder, so the already-open Xcode workspace continues to work.

## Build from a fresh checkout

1. Copy the organizer-supplied `MLVisionM6SDK.framework` into `ios-companion/MLDemo/MLVisionM6SDK/`. Its binary and generated ABI metadata are ignored by Git; their working copies remain on the development machine. The remaining vendor integration files are included in the repo.
2. Install the locked public dependencies with CocoaPods:
   ```sh
   cd ios-companion
   pod install
   ```
   The existing development checkout already has its local Pods; they are ignored by Git.
3. Open `MLDemo.xcworkspace` in Xcode. Select the **MLDemo** scheme and a real iPhone running iOS 15 or later. The Bluetooth SDK requires physical hardware.
4. In Signing & Capabilities, select your development team. This app uses `com.arwa.companion` and appears as **ARWA** on the phone.
5. Press Run. Trust the development certificate and enable iPhone Developer Mode if requested.

The vendor AIUI configuration contains a literal secret, so the actual `aiui.cfg` stays local and is ignored. A redacted `aiui.cfg.example` is included beside it. If you use the vendor AIUI features, copy the example to `aiui.cfg` and supply your own credential. The ARWA guide and offline Vosk voice navigation do not need that service credential.

## Connect and run a guide

1. Build/install the Android companion using `../android-glasses/README.md`.
2. In the iPhone app, use **Set Up Glasses / Connect Glasses** to pair through the existing MicroLumin Bluetooth flow.
3. Open **ARWA Companion** on the glasses. Both devices need the same reachable Wi-Fi; glasses Wi-Fi settings are available in the phone app.
4. After Bluetooth connection, use **Set Up Guides** to select the ARWA name shown inside your glasses. Check the name when other teams' devices are nearby. Allow Local Network access on the iPhone.
5. If discovery fails, enter the exact Wi-Fi address shown inside the glasses under **Manual Address**.
6. Return to **Guides**, open the motor-coupling guide, and tap **Start on Glasses** when ready to change the display.

The glasses own and persist guide progress. The phone catches up after reconnecting. Voice, touchpad, and phone buttons update the same local state; no laptop or hosted server is required during use.

Voice navigation uses the glasses microphone and offline Vosk recognition for **next**, **back**, **show**, and **hide**. Accept the glasses' microphone permission prompt on first use. The current-guide screen shows microphone status and a voice on/off control. Recognition stops when the guide is not open in the foreground; microphone audio is not sent to the phone or server.

The first version includes one bundled eight-step motor-coupling guide. General guide imports/downloads, automatic launching of the Android app, and the separate voice-over branch's narration are not included. This prototype trusts the local Wi-Fi network; device identity matching prevents accidental endpoint changes but is not cryptographic authentication.

## Source and assets

- `MLDemo/GuidesViewController.swift`: Guides, current-guide controls, voice controls, and one-time guide connection setup.
- `MLDemo/GuideConnection.swift`: HTTP connection, pairing-specific remembered device, acknowledgement, and reconnect.
- `MLDemo/GuideDiscovery.swift`: Bonjour/DNS-SD discovery (`_arwa-guide._tcp`).
- `MLDemo/Guide.swift`, `MLDemo/coupling.json`: guide model and generated metadata.
- `MLDemo/SceneDelegate.swift`: Guides is the app's root screen.
- `../android-glasses`: receiving Android app and bundled 3D viewer.
- `../scripts/package-guide.js`: generates guide assets for both platforms from the original guide.

To update the guide, run `npm ci` and `node scripts/package-guide.js` from the repository root, then rebuild both apps. Do not edit generated JSON or copied viewer files independently.

Before building the glasses app from a clean checkout, run `python3 scripts/prepare-voice-model.py` from the repository root. It downloads and verifies the model used by the voice-commands branch; model downloads, build output, and signing credentials are excluded from Git.

The original MLDemo setup notes and known SDK workarounds are preserved in `MLDemo-REFERENCE.md`.

## Validation

The Android APK builds successfully. Navigation and voice-result deduplication checks pass, and all app Swift sources pass type checking against the real SDK and built Pods. The user verified manual Wi-Fi connection, guide launch, and spoken back/next navigation with both phone and glasses following. Automatic discovery did not work on the tested network. Complete signed iPhone builds are run in Xcode on the user's Mac; command-line builds in the agent environment hit Interface Builder/CoreSimulator service failures.
