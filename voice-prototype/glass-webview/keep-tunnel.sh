#!/bin/sh
# Keeps the USB tunnel (glasses localhost:8080 -> this Mac) alive. adb drops it whenever the
# USB connection blips; this re-creates it every 2 s. Leave it running in a terminal; Ctrl-C to stop.
#   ./keep-tunnel.sh <adb-serial>
SERIAL="${1:?usage: $0 <adb-serial>}"
while true; do
  if adb -s "$SERIAL" get-state >/dev/null 2>&1; then
    if ! adb -s "$SERIAL" reverse --list 2>/dev/null | grep -q "tcp:8080"; then
      adb -s "$SERIAL" reverse tcp:8080 tcp:8080 >/dev/null 2>&1 && echo "$(date +%T) tunnel restored"
    fi
  fi
  sleep 2
done
