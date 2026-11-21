// Voice-over demo server. No dependencies: `node server.js` (macOS, for the `say` voice).
//
//   /display   → what the glasses show: step title + description, read aloud on every step change
//   /remote    → buttons (and optional browser mic) for next / back / show / hide / repeat / mute / unmute
//
// Same command interface as voice-prototype/voice-test, so the GlassView glasses app (glasses mic → POST /cmd)
// drives this demo unchanged. State is pushed to every open page with Server-Sent Events (/events).
// Audio: GET /api/tts?text=... → WAV made with macOS `say`; every step is pre-generated at startup.

const http = require('http');
const fs = require('fs');
const path = require('path');
const crypto = require('crypto');
const { execFile } = require('child_process');

const PORT = Number(process.env.PORT || 8080);
const VOICE = process.env.TTS_VOICE || '';           // any name from `say -v ?`, e.g. Samantha
const RATE = String(Number(process.env.TTS_RATE) || 180); // words per minute
const PUBLIC = path.join(__dirname, 'public');
const TTS_DIR = path.join(__dirname, '.tts-cache');

// ---------- steps + the exact words spoken for each ----------
const data = JSON.parse(fs.readFileSync(path.join(__dirname, 'steps.json'), 'utf8'));
// Spell out codes a voice would mangle ("CB-12" → "C B 12").
function speakable(t) {
  return String(t || '')
    .replace(/\bCB-(\d+)/g, 'C B $1')
    .replace(/\bB2-0?(\d+)/g, 'B 2 $1')
    .replace(/\bPDU\b/g, 'P D U')
    .replace(/\bQR\b/g, 'Q R')
    .replace(/\s+/g, ' ').trim();
}
const STEPS = data.steps.map((s, i, all) => ({
  title: s.title,
  description: s.description,
  speech: speakable(`Step ${i + 1} of ${all.length}. ${s.title}. ${s.description}`),
}));

// ---------- state ----------
let state = { title: data.title, steps: STEPS, step: 0, visible: true, muted: false, last: null, seq: 0 };
const clients = new Set();
function broadcast() {
  const msg = 'data: ' + JSON.stringify(state) + '\n\n';
  for (const res of clients) res.write(msg);
}
function apply(cmd, source) {
  // The glasses' offline recognizer hears "unmute" as "mute", so it sends mute_toggle (see VoiceCommands.java).
  if (cmd === 'mute_toggle') cmd = state.muted ? 'unmute' : 'mute';
  switch (cmd) {
    case 'next': state.step = Math.min(STEPS.length - 1, state.step + 1); state.visible = true; break;
    case 'back': state.step = Math.max(0, state.step - 1); state.visible = true; break;
    case 'goto': break; // handled by caller
    case 'show': state.visible = true; break;
    case 'hide': state.visible = false; break;
    case 'repeat': break; // the display replays the current step (even when muted: it was asked for)
    case 'mute': state.muted = true; break;
    case 'unmute': state.muted = false; break; // the display says the current step again
    case 'restart': state.step = 0; state.visible = true; state.muted = false; break;
    default: return false;
  }
  state.seq++;
  state.last = { cmd, source: source || 'unknown', at: Date.now() };
  console.log(new Date().toLocaleTimeString(), cmd.padEnd(7), '→ step', state.step + 1, state.visible ? '' : '(hidden)', state.muted ? '(muted)' : '', '·', state.last.source);
  broadcast();
  return true;
}

// ---------- text → speech ----------
const pending = new Map();
function ttsFile(text) {
  const key = crypto.createHash('sha1').update(VOICE + '|' + RATE + '|' + text).digest('hex');
  const out = path.join(TTS_DIR, key + '.wav');
  if (fs.existsSync(out)) return Promise.resolve(out);
  if (pending.has(key)) return pending.get(key);
  const p = new Promise((resolve, reject) => {
    if (process.platform !== 'darwin') return reject(new Error('needs macOS `say`'));
    fs.mkdirSync(TTS_DIR, { recursive: true });
    const txt = path.join(TTS_DIR, key + '.txt'), tmp = out + '.part.wav';
    fs.writeFileSync(txt, text); // read from a file, so text can never be taken as a command-line option
    const args = ['-r', RATE, '-o', tmp, '--data-format=LEI16@22050', '-f', txt]; // 16-bit WAV plays everywhere
    if (VOICE) args.unshift('-v', VOICE);
    execFile('say', args, { timeout: 20000 }, (err) => {
      fs.rmSync(txt, { force: true });
      if (err) { fs.rmSync(tmp, { force: true }); return reject(err); }
      fs.renameSync(tmp, out);
      resolve(out);
    });
  }).finally(() => pending.delete(key));
  pending.set(key, p);
  return p;
}

// ---------- HTTP ----------
const TYPES = { '.html': 'text/html; charset=utf-8', '.js': 'text/javascript', '.css': 'text/css' };
const ROUTES = { '/': 'remote.html', '/display': 'display.html', '/remote': 'remote.html' };

async function handler(req, res) {
  const url = new URL(req.url, 'http://x');

  if (url.pathname === '/events') {
    res.writeHead(200, { 'Content-Type': 'text/event-stream', 'Cache-Control': 'no-cache', Connection: 'keep-alive' });
    res.write('retry: 1000\n');
    res.write('data: ' + JSON.stringify(state) + '\n\n');
    clients.add(res);
    const ping = setInterval(() => res.write(': ping\n\n'), 15000);
    req.on('close', () => { clearInterval(ping); clients.delete(res); });
    return;
  }

  if (url.pathname === '/cmd' && req.method === 'POST') {
    let body = '';
    req.on('data', (c) => { body += c; if (body.length > 1e4) req.destroy(); });
    req.on('end', () => {
      let d = {};
      try { d = JSON.parse(body || '{}'); } catch (e) {}
      const cmd = String(d.cmd || '').toLowerCase();
      if (cmd === 'goto') state.step = Math.max(0, Math.min(STEPS.length - 1, Number(d.step) || 0));
      const ok = apply(cmd, d.source);
      res.writeHead(ok ? 200 : 400, { 'Content-Type': 'application/json' });
      res.end(JSON.stringify(ok ? state : { error: 'unknown command' }));
    });
    return;
  }

  if (url.pathname === '/api/tts') {
    const text = String(url.searchParams.get('text') || '').replace(/\s+/g, ' ').trim().slice(0, 500);
    if (!text) { res.writeHead(400); return res.end('text required'); }
    try {
      const f = await ttsFile(text);
      res.writeHead(200, { 'Content-Type': 'audio/wav', 'Cache-Control': 'max-age=86400' });
      return res.end(fs.readFileSync(f));
    } catch (e) {
      res.writeHead(501, { 'Content-Type': 'application/json' });
      return res.end(JSON.stringify({ error: 'no server voice: ' + e.message }));
    }
  }

  const file = ROUTES[url.pathname] || url.pathname.slice(1);
  const full = path.join(PUBLIC, path.normalize(file));
  if (!full.startsWith(PUBLIC)) { res.writeHead(403); return res.end(); }
  fs.readFile(full, (err, buf) => {
    if (err) { res.writeHead(404); return res.end('not found'); }
    res.writeHead(200, { 'Content-Type': TYPES[path.extname(full)] || 'application/octet-stream', 'Cache-Control': 'no-store' });
    res.end(buf);
  });
}

http.createServer(handler).listen(PORT, () => {
  console.log('\nVoice-over demo');
  console.log('  Remote (this Mac): http://localhost:' + PORT + '/remote');
  console.log('  Glasses:           adb reverse tcp:' + PORT + ' tcp:' + PORT + '  then GlassView opens http://localhost:' + PORT + '/display');
  const t0 = Date.now();
  STEPS.reduce((p, s) => p.then(() => ttsFile(s.speech)), Promise.resolve())
    .then(() => console.log(`  Voice-over: ${STEPS.length} steps ready (${((Date.now() - t0) / 1000).toFixed(1)} s)\n`))
    .catch((e) => console.warn('  Voice-over: could not pre-generate audio (' + e.message + '); pages fall back to device speech\n'));
});
