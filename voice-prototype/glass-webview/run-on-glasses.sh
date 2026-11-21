#!/bin/sh
# Install GlassView on the glasses and open the voice-test display.
#   ./run-on-glasses.sh <adb-serial> [url]
# <adb-serial> is the first column of `adb devices -l` (e.g. 10.3.195.12:5555).
# Without a url, the glasses open http://localhost:8080/display, tunnelled to this Mac with adb reverse.
set -e
cd "$(dirname "$0")"
SERIAL="$1"; URL="${2:-http://localhost:8080/display}"
if [ -z "$SERIAL" ]; then echo "usage: $0 <adb-serial> [url]"; adb devices -l; exit 1; fi
APK=app/build/outputs/apk/debug/app-debug.apk
if [ ! -f "$APK" ]; then
  JAVA_HOME="/Applications/Android Studio.app/Contents/jbr/Contents/Home" ./gradlew -q :app:assembleDebug
fi
adb -s "$SERIAL" install -r "$APK"
adb -s "$SERIAL" shell pm grant com.worn.glassview android.permission.RECORD_AUDIO || true
adb -s "$SERIAL" reverse tcp:8080 tcp:8080
adb -s "$SERIAL" shell am start -n com.worn.glassview/.MainActivity --es url "$URL"
echo "Running. Logs and touchpad key codes: adb -s $SERIAL logcat -s GlassView"
