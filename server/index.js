// ARWA hackathon server: one process, five layers.
//  1 Sources   -> sim/sensor.js or ESP32 publish to MQTT
//  2 Transport -> embedded MQTT broker (aedes) on :1883, or an external one via MQTT_URL
//  3 Adapter + state model -> server/state.js
//  4 Router    -> server/router.js (+ procedure gate in server/procedure.js)
//  5 Delivery  -> WebSocket /ws (+ HTTP poll /api/markers, + MQTT arwa/v1/markers/<role>/<device>)

const http = require('http');
const fs = require('fs');
const path = require('path');
const net = require('net');
const os = require('os');
const { WebSocketServer } = require('ws');
const mqtt = require('mqtt');
const QRCode = require('qrcode');

const { StateModel } = require('./state');
const { ProcedureRun } = require('./procedure');
const { Router } = require('./router');
const vision = require('./vision');
const recipes = JSON.parse(fs.readFileSync(path.join(__dirname, '..', 'data', 'recipes.json'), 'utf8'));

const ROOT = path.join(__dirname, '..');

// .env (optional): KEY=value lines, e.g. ANTHROPIC_API_KEY=sk-ant-... Real environment variables win. Never commit .env.
try {
  for (const line of fs.readFileSync(path.join(ROOT, '.env'), 'utf8').split(/\r?\n/)) {
    const m = /^\s*([A-Z0-9_]+)\s*=\s*(.*?)\s*$/.exec(line);
    if (m && !line.trim().startsWith('#') && process.env[m[1]] === undefined) process.env[m[1]] = m[2].replace(/^["']|["']$/g, '');
  }
} catch {}
const assistant = require('./assistant');
global.window = global.window || {}; require('../public/workflow-steps.js'); const WF_JOBS = global.window.WF_JOBS;
const HTTP_PORT = Number(process.env.PORT || 8080);
const MQTT_PORT = Number(process.env.MQTT_PORT || 1883);
const STALE_S = Number(process.env.STALE_S || 3);
const TOPIC_PREFIX = 'arwa/v1/telemetry/';

const PACK = process.env.PACK || 'datacenter'; // asset pack: data/packs/<PACK>/{assets,procedure}.json
const load = (f) => JSON.parse(fs.readFileSync(path.join(ROOT, 'data', f), 'utf8'));
const dcim = load(`packs/${PACK}/assets.json`);
const procedure = load(`packs/${PACK}/procedure.json`);
const { roles } = load('roles.json');

const state = new StateModel({ assets: dcim.assets, staleAfterS: STALE_S });
const run = new ProcedureRun({ procedure, state, evidencePath: path.join(ROOT, 'logs', 'evidence.jsonl') });
const { HandoffBook } = require('./handoff');
const handoff = new HandoffBook({ state, run });
const router = new Router({ state, run, roles, handoff });

// ---------- Layer 2: transport ----------
async function startBroker() {
  if (process.env.MQTT_URL) return process.env.MQTT_URL;
  const aedes = require('aedes');
  const broker = aedes.createBroker ? await aedes.createBroker() : aedes();
  const srv = net.createServer(broker.handle);
  await new Promise((res) => srv.listen(MQTT_PORT, res));
  console.log(`[mqtt] embedded broker on :${MQTT_PORT}`);
  return `mqtt://127.0.0.1:${MQTT_PORT}`;
}

// ---------- Layer 3: adapter (MQTT -> normalised signals) ----------
// Topic: arwa/v1/telemetry/<asset_id>   e.g. arwa/v1/telemetry/demo/hall1/rowB/rack2/pdu07
// Payload: {"ts": 1732060000000, "signals": {"current_A": 7.1, "temp_C": 31.2, "load_pct": 44}}
//      or: {"ts": ..., "signal": "current_A", "value": 7.1, "unit": "A"}
const UNITS = { current_A: 'A', temp_C: '°C', load_pct: '%', vibration_g: 'g' };
let lastSrcTs = null;
function ingestMqtt(topic, buf) {
  if (!topic.startsWith(TOPIC_PREFIX)) return;
  const asset_id = topic.slice(TOPIC_PREFIX.length);
  let msg;
  try { msg = JSON.parse(buf.toString()); } catch { return; }
  const ts = Number(msg.ts) > 1e12 ? Number(msg.ts) : Date.now(); // ESP32 without NTP sends millis(); fall back to receive time
  const entries = msg.signals ? Object.entries(msg.signals) : [[msg.signal, msg.value]];
  for (const [signal, value] of entries) {
    if (signal == null || value == null || Number.isNaN(Number(value))) continue;
    state.ingest({ asset_id, signal, value, unit: UNITS[signal] || msg.unit || '', ts });
  }
  lastSrcTs = ts;
  schedulePush();
}

// ---------- Layer 5: delivery ----------
const clients = new Set(); // { ws, role, device, name }

// Shared step state for the guided workflow (workflow3d.html on the glasses, voice.html on the phone).
// One source of truth so "next" said to the phone moves both screens. hidden = glasses view cleared.
// Two jobs (public/workflow-steps.js): coupling (default) and mccb. Pick at start with WF_JOB=mccb, or from the phone.
const wf = { job: WF_JOBS[process.env.WF_JOB] ? process.env.WF_JOB : 'coupling', step: 0, hidden: false, total: 8, by: null, heard: null, cmd: null, ts: Date.now() };
// ---- "Ask": phone speech -> one glanceable widget on the glasses (server/assistant.js) ----
const SIGNAL_NAMES = { load_pct: ['Load', ['load']], current_A: ['Current', ['current', 'amps', 'amp']], temp_C: ['Temperature', ['temp', 'temperature', 'hot', 'heat']],
  vibration_mms: ['Vibration', ['vibration', 'vibrating', 'shaking']], speed_rpm: ['Speed', ['speed', 'rpm', 'running']] };
const sigHist = new Map(); // key -> [{t, v}] last ~2 min, sampled every 5 s, for trend arrows
setInterval(() => {
  const snap = state.snapshot(run.targetAsset.asset_id); if (!snap || snap.stale) return;
  for (const [k, v] of Object.entries(snap.signals)) { if (!v) continue; const h = sigHist.get(k) || []; h.push({ t: Date.now(), v: v.value }); while (h.length > 24) h.shift(); sigHist.set(k, h); }
}, 5000);
function askContext() {
  const snap = state.snapshot(run.targetAsset.asset_id);
  const readings = snap ? Object.entries(snap.signals).map(([k, v]) => {
    const [name, aliases] = SIGNAL_NAMES[k] || [k, []]; const h = sigHist.get(k) || []; const old = h.length > 3 ? h[0].v : null;
    const cur = v ? v.value : null; const d = old == null || cur == null ? 0 : cur - old; const band = Math.max(Math.abs(old || 0) * 0.03, 0.05);
    return { key: k, name, aliases, value: cur == null ? null : Math.round(cur * 10) / 10, unit: (v && v.unit) || '', stale: snap.stale, age_s: snap.data_age_s,
      trend: d > band ? 'up' : d < -band ? 'down' : 'flat' };
  }) : [];
  const findings = handoff.open().map((f) => ({ by: f.by, label: f.label || f.anchor_id, note: f.note || '' }));
  const J = WF_JOBS[wf.job], S = J.steps;
  return { job: J.title, steps: S, index: wf.step, total: S.length, step: S[wf.step] || null, next: S[wf.step + 1] || null, readings, findings };
}
let lastWidget = null;
async function handleAsk(text, by) {
  text = String(text || '').trim().slice(0, 200); if (!text) return null;
  const r = await assistant.ask(text, askContext());
  lastWidget = { type: 'widget', heard: text, by, ts: Date.now(), ttl_s: r.widget.type === 'hazard' ? 12 : 8, ...r };
  const m = JSON.stringify(lastWidget); for (const c of clients) if (c.ws.readyState === 1) c.ws.send(m);
  try { run._log({ event: 'ask', heard: text, by, source: r.source, widget: r.widget, ms: r.ms, step: wf.step + 1 }); } catch {}
  return lastWidget;
}

function wfMsg() { return JSON.stringify({ type: 'wf', ...wf }); }
function wfBroadcast() { const m = wfMsg(); for (const c of clients) if (c.ws.readyState === 1) c.ws.send(m); }
function wfCommand(cmd, { step, by, heard, job } = {}) {
  const WF_TOTAL = WF_JOBS[wf.job].steps.length;                          // step === WF_TOTAL means finished
  if (cmd === 'job') { if (!WF_JOBS[job]) return false; wf.job = job; wf.step = 0; wf.hidden = false; wf.total = WF_JOBS[job].steps.length; }
  else if (cmd === 'next') wf.step = Math.min(WF_TOTAL, wf.step + 1);
  else if (cmd === 'back') wf.step = Math.max(0, wf.step - 1);
  else if (cmd === 'goto') wf.step = Math.max(0, Math.min(WF_TOTAL, Number(step) || 0));
  else if (cmd === 'hide') wf.hidden = true;
  else if (cmd === 'show') wf.hidden = false;
  else if (cmd === 'restart') { wf.step = 0; wf.hidden = false; }
  else return false;
  if (cmd === 'next' || cmd === 'back' || cmd === 'goto') wf.hidden = false; // moving on brings the view back
  Object.assign(wf, { by: by || null, heard: heard || null, cmd, ts: Date.now() });
  wfBroadcast();
  try { run._log({ event: 'workflow_' + cmd, job: wf.job, step: wf.step + 1, hidden: wf.hidden, by, heard }); } catch {}
  return true;
}
let pushTimer = null;
let mqttClient = null;

function payloadFor(c) {
  return JSON.stringify({ type: 'markers', server_ts: Date.now(), src_ts: lastSrcTs, markers: router.markersFor(c) });
}

function pushAll() {
  pushTimer = null;
  for (const c of clients) if (c.ws.readyState === 1) c.ws.send(payloadFor(c));
  if (mqttClient) {
    for (const role of Object.keys(roles)) for (const device of ['glasses', 'phone']) {
      mqttClient.publish(`arwa/v1/markers/${role}/${device}`, JSON.stringify(router.markersFor({ role, device })), { retain: true });
    }
  }
}
function schedulePush() { if (!pushTimer) pushTimer = setTimeout(pushAll, 50); } // coalesce bursts, <=50 ms added latency

setInterval(() => { if (state.sweep().length) schedulePush(); }, 250);
setInterval(schedulePush, 1000); // refresh data_age_s on screens

function handleAction(c, msg) {
  const by = `${c.name || 'anon'}@${c.device}`;
  switch (msg.action) {
    case 'scan': {
      const r = run.scan(String(msg.anchor_id || ''), by);
      if (r.match) router.flash = null;
      else if (r.asset && r.asset.asset_id !== run.targetAsset.asset_id) router.flashWrongAsset(r.asset, run.targetAsset.label);
      c.ws.send(JSON.stringify({ type: 'scan_result', ...r }));
      break;
    }
    case 'confirm_step': {
      const r = run.confirm(by);
      c.ws.send(JSON.stringify({ type: 'confirm_result', ...r }));
      break;
    }
    case 'call_expert':
      run.callExpert(by);
      for (const o of clients) if (o.role === 'remote_expert' && o.ws.readyState === 1) o.ws.send(JSON.stringify({ type: 'expert_call', from: by, step: run.step?.index, asset_id: run.targetAsset.asset_id }));
      c.ws.send(JSON.stringify({ type: 'info', text: 'Expert notified' }));
      break;
    case 'finding': {
      const r = handoff.addFinding({ anchor_id: msg.anchor_id, asset_id: msg.asset_id, by: c.name || by, note: msg.note, signal: msg.signal });
      c.ws.send(JSON.stringify({ type: 'info', text: r.ok ? `Finding ${r.finding.id} pinned to ${r.finding.label}` : r.reason }));
      break;
    }
    case 'close_finding': handoff.closeFinding(msg.id, c.name || by); break;
    case 'handoff': {
      const p = handoff.handOff({ from: c.name || by, to: msg.to });
      c.ws.send(JSON.stringify({ type: 'info', text: `Handed off ${p.finding_ids.length} finding(s)` }));
      break;
    }
    case 'pick_up': {
      const p = handoff.pickUp(c.name || by);
      c.ws.send(JSON.stringify({ type: 'info', text: p ? `Picked up handoff from ${p.from}` : 'Nothing to pick up' }));
      break;
    }
    case 'hazard': // from the camera hazard watcher (cv.html): a hand entered the danger zone
      router.flashMarker({ marker_id: 'm-hazard-cam', kind: 'hazard', priority: 'critical', severity_color: 'red',
        headline: 'HANDS CLEAR', detail: String(msg.detail || 'Hand in the danger zone'), data_age_s: 0, stale: false }, 2500);
      break;
    case 'ask': // free speech from the phone -> one widget for the glasses
      handleAsk(msg.text, by).catch((e) => console.error('[ask]', e.message));
      return;
    case 'wf': // workflow voice/button command: { cmd: next|back|hide|show|goto|restart, step?, heard? }
      wfCommand(String(msg.cmd || ''), { step: msg.step, job: msg.job, by, heard: msg.heard ? String(msg.heard).slice(0, 80) : null });
      return;
    case 'reset':
      run.reset(); router.flash = null; break;
    case 'ping':
      c.ws.send(JSON.stringify({ type: 'pong', t: msg.t, server_ts: Date.now() })); return;
  }
  schedulePush();
}

// ---------- HTTP ----------
const MIME = { '.html': 'text/html; charset=utf-8', '.js': 'text/javascript', '.css': 'text/css', '.json': 'application/json', '.svg': 'image/svg+xml' };
const trialsPath = path.join(ROOT, 'logs', 'trials.csv');

async function handler(req, res) {
  const url = new URL(req.url, 'http://x');
  const send = (code, body, type = 'application/json') => { res.writeHead(code, { 'content-type': type, 'access-control-allow-origin': '*' }); res.end(body); };
  try {
    if (url.pathname === '/api/markers') return send(200, JSON.stringify({ server_ts: Date.now(), src_ts: lastSrcTs, markers: router.markersFor({ role: url.searchParams.get('role') || 'electrical_tech', device: url.searchParams.get('device') || 'glasses' }) }));
    if (url.pathname === '/api/state') return send(200, JSON.stringify({ assets: [...state.assets.keys()].map((id) => state.snapshot(id)), step: run.step, done: run.done }, null, 2));
    if (url.pathname === '/api/handoff') return send(200, JSON.stringify(handoff.view(), null, 2));
    if (url.pathname === '/api/evidence') { const p = path.join(ROOT, 'logs', 'evidence.jsonl'); return send(200, fs.existsSync(p) ? fs.readFileSync(p) : '', 'text/plain'); }
    if (url.pathname.startsWith('/qr/') && url.pathname.endsWith('.svg')) {
      const id = decodeURIComponent(url.pathname.slice(4, -4));
      return send(200, await QRCode.toString(`arwa:${id}`, { type: 'svg', margin: 1, errorCorrectionLevel: 'H' }), MIME['.svg']);
    }
    if (url.pathname === '/api/vision/panel' && req.method === 'POST') {
      // body: {"image": "data:image/jpeg;base64,...", "recipe": "B"}
      const body = JSON.parse(await readBody(req));
      const m = /^data:(image\/(?:jpeg|png|webp));base64,(.+)$/.exec(body.image || '');
      if (!m) return send(400, JSON.stringify({ error: 'Send image as a base64 data URL (jpeg/png/webp).' }));
      const spec = recipes[body.recipe || 'B'];
      if (!spec) return send(400, JSON.stringify({ error: `Unknown recipe ${body.recipe}` }));
      const t0 = Date.now();
      let reading;
      try { reading = await vision.readPanel({ base64: m[2], mediaType: m[1] }); }
      catch (e) {
        const noKey = /api key|auth|credential/i.test(e.message);
        return send(noKey ? 503 : 502, JSON.stringify({ error: noKey ? 'Vision needs ANTHROPIC_API_KEY set where the server runs.' : e.message }));
      }
      const verdict = vision.checkAgainstRecipe(reading, spec);
      const bad = verdict.checks.find((c) => !c.ok);
      router.flashMarker({ marker_id: 'm-vision', kind: bad ? 'hazard' : 'status', priority: bad ? 'critical' : 'high',
        severity_color: bad ? 'red' : 'green',
        headline: bad ? `✕ ${bad.label} ${bad.actual}, spec ${bad.expected}` : `✓ Panel matches recipe ${spec.recipe}`,
        detail: bad ? 'Fix before restart (read from camera)' : verdict.checks.map((c) => `${c.label} ${c.actual}`).join(' · '),
        data_age_s: 0, stale: false }, 8000);
      schedulePush();
      run._log({ event: 'vision_panel_check', recipe: spec.recipe, ok: verdict.ok, reading, ms: Date.now() - t0 });
      return send(200, JSON.stringify({ reading, ...verdict, ms: Date.now() - t0 }));
    }
    if (url.pathname === '/api/ask' && req.method === 'POST') { // {"text":"what's the torque"} -> the widget (also pushed to the glasses)
      const b = JSON.parse((await readBody(req)) || '{}');
      return send(200, JSON.stringify(await handleAsk(b.text, 'http')));
    }
    if (url.pathname === '/api/ask/context') return send(200, JSON.stringify({ engine: process.env.ANTHROPIC_API_KEY ? 'claude:' + assistant.MODEL : 'rules', context: assistant.contextText(askContext()) }));
    if (url.pathname === '/api/wf') { // GET state, or POST {"cmd":"next"} from any device that can do HTTP
      if (req.method === 'POST') { const b = JSON.parse((await readBody(req)) || '{}'); wfCommand(String(b.cmd || ''), { step: b.step, job: b.job, by: 'http', heard: b.heard }); }
      return send(200, JSON.stringify(wf));
    }
    if (url.pathname === '/api/action' && req.method === 'POST') { // for SDKs that can do HTTP but not WebSocket
      const body = await readBody(req);
      const fake = { ws: { send() {}, readyState: 1 }, role: 'electrical_tech', device: 'glasses', name: 'http' };
      handleAction(fake, JSON.parse(body || '{}'));
      return send(200, JSON.stringify({ ok: true, step: run.step }));
    }
    if (url.pathname === '/api/trials') {
      if (req.method === 'POST') {
        const t = JSON.parse(await readBody(req));
        fs.mkdirSync(path.dirname(trialsPath), { recursive: true });
        if (!fs.existsSync(trialsPath)) fs.writeFileSync(trialsPath, 'ts,participant,condition,seconds,wrong_picks,notes\n');
        const esc = (v) => `"${String(v ?? '').replace(/"/g, '""')}"`;
        fs.appendFileSync(trialsPath, [new Date().toISOString(), t.participant, t.condition, t.seconds, t.wrong_picks, t.notes].map(esc).join(',') + '\n');
        return send(200, '{"ok":true}');
      }
      return send(200, fs.existsSync(trialsPath) ? fs.readFileSync(trialsPath) : 'ts,participant,condition,seconds,wrong_picks,notes\n', 'text/csv');
    }
    if (url.pathname === '/vendor/jsQR.js') return send(200, fs.readFileSync(require.resolve('jsqr/dist/jsQR.js')), MIME['.js']);
    if (url.pathname === '/vendor/three.min.js') return send(200, fs.readFileSync(path.join(ROOT, 'node_modules', 'three', 'build', 'three.min.js')), MIME['.js']);
    let file = url.pathname === '/' ? '/index.html' : url.pathname;
    file = path.normalize(file).replace(/^(\.\.[/\\])+/, '');
    const full = path.join(ROOT, 'public', file);
    if (!full.startsWith(path.join(ROOT, 'public')) || !fs.existsSync(full)) return send(404, 'not found', 'text/plain');
    return send(200, fs.readFileSync(full), MIME[path.extname(full)] || 'application/octet-stream');
  } catch (e) {
    return send(500, JSON.stringify({ error: e.message }));
  }
}
const server = http.createServer(handler);

// Phones only allow camera (QR scan) on HTTPS or localhost. HTTPS_PORT serves the same app with a self-signed cert:
// open https://<laptop-ip>:8443/phone.html and accept the warning once.
const HTTPS_PORT = Number(process.env.HTTPS_PORT || 8443);
function startHttps() {
  try {
    const certDir = path.join(ROOT, 'logs');
    const keyP = path.join(certDir, 'dev-key.pem'), certP = path.join(certDir, 'dev-cert.pem');
    if (!fs.existsSync(keyP)) {
      const pems = require('selfsigned').generate([{ name: 'commonName', value: 'arwa.local' }], { days: 30, keySize: 2048 });
      fs.mkdirSync(certDir, { recursive: true });
      fs.writeFileSync(keyP, pems.private); fs.writeFileSync(certP, pems.cert);
    }
    const s = require('https').createServer({ key: fs.readFileSync(keyP), cert: fs.readFileSync(certP) }, handler);
    attachWs(s);
    s.listen(HTTPS_PORT, () => console.log(`[https] self-signed on :${HTTPS_PORT} (use this on phones for camera QR scan)`));
  } catch (e) { console.warn('[https] disabled:', e.message); }
}

function readBody(req) {
  return new Promise((resolve) => { let b = ''; req.on('data', (d) => (b += d)); req.on('end', () => resolve(b)); });
}

function attachWs(srv) {
 const wss = new WebSocketServer({ server: srv, path: '/ws' });
 wss.on('connection', (ws, req) => {
  const q = new URL(req.url, 'http://x').searchParams;
  const c = { ws, role: q.get('role') || 'electrical_tech', device: q.get('device') || 'phone', name: q.get('name') || '' };
  clients.add(c);
  ws.send(payloadFor(c));
  ws.send(wfMsg());
  ws.on('message', (d) => { try { handleAction(c, JSON.parse(d)); } catch {} });
  ws.on('close', () => clients.delete(c));
 });
}
attachWs(server);

(async () => {
  const mqttUrl = await startBroker();
  mqttClient = mqtt.connect(mqttUrl, { clientId: 'arwa-core-' + process.pid });
  mqttClient.on('connect', () => { mqttClient.subscribe(TOPIC_PREFIX + '#'); console.log(`[mqtt] core subscribed to ${TOPIC_PREFIX}# on ${mqttUrl}`); });
  mqttClient.on('message', ingestMqtt);
  startHttps();
  server.listen(HTTP_PORT, () => {
    const ips = Object.values(os.networkInterfaces()).flat().filter((i) => i && i.family === 'IPv4' && !i.internal).map((i) => i.address);
    console.log(`[http] ARWA on http://localhost:${HTTP_PORT}  (LAN: ${ips.map((ip) => `http://${ip}:${HTTP_PORT}`).join(', ') || 'none'})`);
    console.log(`       phone: /phone.html   glasses: /glasses.html   expert: /phone.html?role=remote_expert   QR sheet: /qr.html   study: /study.html`);
    console.log(`       stale after ${STALE_S}s of silence`);
  });
})();
