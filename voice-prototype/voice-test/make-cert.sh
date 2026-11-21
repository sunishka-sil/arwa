#!/bin/sh
# Self-signed HTTPS certificate so a phone on the same Wi-Fi can use its microphone on /remote.
# The phone will warn that the certificate isn't trusted; tap through ("Show Details" > "visit this website" on iPhone).
cd "$(dirname "$0")"
mkdir -p certs
SAN="DNS:localhost,IP:127.0.0.1"
for ip in $(ifconfig | awk '/inet / && $2 != "127.0.0.1" {print $2}'); do SAN="$SAN,IP:$ip"; done
openssl req -x509 -newkey rsa:2048 -nodes -days 30 \
  -keyout certs/key.pem -out certs/cert.pem \
  -subj "/CN=voice-test" -addext "subjectAltName=$SAN"
echo "Wrote certs/ for: $SAN"
