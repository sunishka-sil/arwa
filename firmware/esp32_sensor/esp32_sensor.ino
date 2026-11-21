// ARWA ESP32 sensor node (optional: the simulator publishes the same thing).
// Board: any ESP32. Libraries: PubSubClient (Nick O'Leary), ArduinoJson v7.
// Wiring (pick what you have):
//   ACS712-05B / ACS723 current sensor OUT -> GPIO34 (ADC1). Powered from 5V; divide OUT to <=3.3V!
//   DS18B20 or plain NTC thermistor        -> GPIO35 (this sketch reads an NTC divider; swap in OneWire if you use DS18B20)
// Safety: measure a LOW-VOLTAGE mock load only (e.g. a 12V fan/LED strip through the sensor). No mains at the hackathon.
#include <WiFi.h>
#include <PubSubClient.h>
#include <time.h>

const char* WIFI_SSID = "YOUR_SSID";
const char* WIFI_PASS = "YOUR_PASS";
const char* MQTT_HOST = "192.168.1.50";   // laptop running `npm start`
const int   MQTT_PORT = 1883;
const char* TOPIC     = "arwa/v1/telemetry/demo/hall1/rowB/rack2/pdu07";
const float RATED_A   = 16.0;             // for load_pct; use your mock load's max for a nicer demo
const int   PIN_I = 34, PIN_T = 35;
const float ACS_MV_PER_A = 185.0;         // ACS712-05B; 100 for -20A, 66 for -30A

WiFiClient net; PubSubClient mqtt(net);
float zeroMv = 0;

float readMv(int pin) { uint32_t s = 0; for (int i = 0; i < 64; i++) s += analogReadMilliVolts(pin); return s / 64.0; }

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(300); Serial.print('.'); }
  configTime(0, 0, "pool.ntp.org");        // real epoch ms -> honest end-to-end latency numbers
  mqtt.setServer(MQTT_HOST, MQTT_PORT);
  zeroMv = readMv(PIN_I);                  // calibrate with the load OFF at boot
}

void loop() {
  if (!mqtt.connected()) { mqtt.connect(("arwa-esp32-" + String((uint32_t)ESP.getEfuseMac(), HEX)).c_str()); delay(500); return; }
  mqtt.loop();
  static uint32_t last = 0;
  if (millis() - last < 250) return;       // 4 Hz
  last = millis();
  float amps = fabs(readMv(PIN_I) - zeroMv) / ACS_MV_PER_A;
  if (amps < 0.08) amps = 0;
  float v = readMv(PIN_T) / 1000.0;        // NTC 10k + 10k divider from 3.3V
  float r = 10000.0 * v / (3.3 - v);
  float tempC = 1.0 / (log(r / 10000.0) / 3950.0 + 1.0 / 298.15) - 273.15;
  struct timeval tv; gettimeofday(&tv, nullptr);
  unsigned long long ts = (unsigned long long)tv.tv_sec * 1000ULL + tv.tv_usec / 1000;
  char buf[200];
  snprintf(buf, sizeof buf, "{\"ts\":%llu,\"signals\":{\"current_A\":%.2f,\"load_pct\":%.1f,\"temp_C\":%.1f}}", ts, amps, 100.0 * amps / RATED_A, tempC);
  mqtt.publish(TOPIC, buf);
}
