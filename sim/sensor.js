// Layer 1: simulated sensor feed for two identical PDUs (B2-07 = target/left, B2-08 = look-alike/right).
// Publishes to the same topics/payload as the ESP32 sketch, so you can swap in real hardware without touching anything else.
//
// Keys (focus this terminal):
//   o  open CB-12 on B2-07 (current ramps to 0 A over ~1.5 s)   c  close CB-12 again
//   p  pause B2-07 feed (simulates unplugged sensor -> stale)  r  resume feed
//   h  toggle over-temp alarm on B2-07                         l  toggle high load on B2-08 (fails hold point)
//   q  quit
const mqtt = require('mqtt');

const URL = process.env.MQTT_URL || 'mqtt://127.0.0.1:1883';
const HZ = Number(process.env.SIM_HZ || 2);
const PREFIX = 'arwa/v1/telemetry/';

const pdus = {
  'demo/hall1/rowB/rack2/pdu07': { base_A: 7.4, current: 7.4, open: false, paused: false, hot: false, highLoad: false, temp: 31 },
  'demo/hall1/rowB/rack2/pdu08': { base_A: 6.1, current: 6.1, open: false, paused: false, hot: false, highLoad: false, temp: 30 },
};
// SIM_ASSETS=pdu08 -> only simulate the look-alike (when the real ESP32 feeds pdu07)
const ONLY = (process.env.SIM_ASSETS || '').split(',').filter(Boolean);
const ids = Object.keys(pdus);
const simIds = ONLY.length ? ids.filter((id) => ONLY.some((o) => id.endsWith(o))) : ids;
const RATED = 16;

const client = mqtt.connect(URL, { clientId: 'arwa-sim-' + process.pid, reconnectPeriod: 1000 });
client.on('connect', () => console.log(`[sim] connected to ${URL}, publishing ${HZ} Hz. Keys: o/c breaker, p/r pause feed, h heat, l partner load, q quit`));
client.on('error', (e) => console.error('[sim]', e.message));

function tick() {
  for (const id of simIds) {
    const p = pdus[id];
    if (p.paused) continue;
    const target = p.open ? 0 : (p.highLoad ? RATED * 0.85 : p.base_A) + (Math.random() - 0.5) * 0.3;
    p.current += (target - p.current) * (p.open ? 0.45 : 0.6); // first-order ramp
    if (p.open && p.current < 0.05) p.current = 0;
    p.temp += ((p.hot ? 52 : 30 + p.current * 0.3) - p.temp) * 0.25;
    const payload = {
      ts: Date.now(),
      signals: {
        current_A: +p.current.toFixed(2),
        load_pct: +((p.current / RATED) * 100).toFixed(1),
        temp_C: +p.temp.toFixed(1),
      },
    };
    client.publish(PREFIX + id, JSON.stringify(payload));
  }
}
setInterval(tick, 1000 / HZ);

const T = pdus[ids[0]], P = pdus[ids[1]];
const actions = {
  o: () => { T.open = true; return 'CB-12 OPEN on B2-07'; },
  c: () => { T.open = false; return 'CB-12 CLOSED on B2-07'; },
  p: () => { T.paused = true; return 'B2-07 feed PAUSED (expect DATA STALE within STALE_S)'; },
  r: () => { T.paused = false; return 'B2-07 feed RESUMED'; },
  h: () => { T.hot = !T.hot; return `B2-07 over-temp ${T.hot ? 'ON' : 'OFF'}`; },
  l: () => { P.highLoad = !P.highLoad; return `B2-08 high load ${P.highLoad ? 'ON' : 'OFF'}`; },
  q: () => process.exit(0),
};
function onKey(k) {
  const f = actions[k.toLowerCase()];
  if (f) console.log(`[sim] ${new Date().toISOString().slice(11, 23)} ${f()}`);
}
if (process.stdin.isTTY) {
  process.stdin.setRawMode(true);
  process.stdin.on('data', (d) => { const s = d.toString(); if (s === '\u0003') process.exit(0); for (const ch of s) onKey(ch); });
} else {
  process.stdin.on('data', (d) => d.toString().split(/\s+/).filter(Boolean).forEach((w) => onKey(w[0])));
}
module.exports = { pdus };
