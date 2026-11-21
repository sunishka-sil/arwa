// Voice-command test server. No dependencies: `node server.js`.
//
//   /          → links to both pages
//   /display   → what the glasses show (shapes for now, PDF pages later)
//   /remote    → microphone + voice recognition ("next", "back", "show", "hide")
//
// The server keeps the state ({ page, visible }) and pushes it to every open page
// with Server-Sent Events. Commands arrive as POST /cmd {"cmd":"next"}.
//
// HTTP on :8080 (works on this Mac via localhost, and on the glasses via `adb reverse tcp:8080 tcp:8080`).
// HTTPS on :8443 if certs/ exists (run ./make-cert.sh) — a phone needs HTTPS to use its microphone.

const http = require('http');
const https = require('https');
const fs = require('fs');
const path = require('path');
const os = require('os');

const PORT = Number(process.env.PORT || 8080);
const HTTPS_PORT = Number(process.env.HTTPS_PORT || 8443);
const PAGES = 5; // number of demo pages (shapes); replace with the PDF page count later
const PUBLIC = path.join(__dirname, 'public');

let state = { page: 0, pages: PAGES, visible: true, last: null, seq: 0 };
const clients = new Set();

function broadcast() {
  const msg = 'data: ' + JSON.stringify(state) + '\n\n';
  for (const res of clients) res.write(msg);
}

function apply(cmd, source) {
  switch (cmd) {
    case 'next': state.page = Math.min(state.pages - 1, state.page + 1); break;
    case 'back': state.page = Math.max(0, state.page - 1); break;
    case 'show': state.visible = true; break;
    case 'hide': state.visible = false; break;
    default: return false;
  }
  state.seq++;
  state.last = { cmd, source: source || 'unknown', at: Date.now() };
  console.log(new Date().toLocaleTimeString(), cmd.padEnd(4), '→ page', state.page + 1, state.visible ? 'shown' : 'hidden', '(' + state.last.source + ')');
  broadcast();
  return true;
}

const TYPES = { '.html': 'text/html; charset=utf-8', '.js': 'text/javascript', '.css': 'text/css', '.pdf': 'application/pdf', '.png': 'image/png', '.mp3': 'audio/mpeg' };
const ROUTES = { '/': 'index.html', '/display': 'display.html', '/remote': 'remote.html' };

function handler(req, res) {
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
      let data = {};
      try { data = JSON.parse(body || '{}'); } catch (e) {}
      const ok = apply(String(data.cmd || '').toLowerCase(), data.source);
      res.writeHead(ok ? 200 : 400, { 'Content-Type': 'application/json' });
      res.end(JSON.stringify(ok ? state : { error: 'unknown command' }));
    });
    return;
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

function lanIPs() {
  return Object.values(os.networkInterfaces()).flat().filter((i) => i && i.family === 'IPv4' && !i.internal).map((i) => i.address);
}

http.createServer(handler).listen(PORT, () => {
  console.log('\nVoice test server');
  console.log('  On this Mac:   http://localhost:' + PORT + '/display   and   http://localhost:' + PORT + '/remote');
  console.log('  On the glasses: adb reverse tcp:' + PORT + ' tcp:' + PORT + '  then open http://localhost:' + PORT + '/display');
});

const certDir = path.join(__dirname, 'certs');
if (fs.existsSync(path.join(certDir, 'key.pem'))) {
  https.createServer({ key: fs.readFileSync(path.join(certDir, 'key.pem')), cert: fs.readFileSync(path.join(certDir, 'cert.pem')) }, handler)
    .listen(HTTPS_PORT, () => {
      lanIPs().forEach((ip) => console.log('  On a phone:    https://' + ip + ':' + HTTPS_PORT + '/remote   (accept the certificate warning)'));
      console.log('');
    });
} else {
  console.log('  (Phone mic needs HTTPS: run ./make-cert.sh, then restart.)\n');
}
