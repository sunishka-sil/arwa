// Device-agnostic ARWA client. Everything device-specific lives in the page that uses it.
// Server sends meaning (marker JSON); the device maps severity_color to its own palette and draws it.
(function (global) {
  const PALETTES = {
    // full-colour displays (phone, colour waveguide)
    color: { green: '#22c55e', red: '#ef4444', amber: '#f59e0b', blue: '#38bdf8', grey: '#9ca3af' },
    // single-colour waveguides (the M6 is green-only): hue is lost, so encode by brightness here and by
    // blink / border / icon in the page. White = the display's brightest green.
    mono: { green: '#d4d4d4', red: '#ffffff', amber: '#ffffff', blue: '#a3a3a3', grey: '#525252' },
  };
  const ICON = { green: '✓', red: '✕', amber: '!', blue: '›', grey: '?' };

  function connect({ role = 'electrical_tech', device = 'phone', name = '', onMarkers, onEvent, onStatus }) {
    const proto = location.protocol === 'https:' ? 'wss' : 'ws';
    let ws, retry = 0, rtt = null;
    const api = {
      send(action, extra = {}) { if (ws && ws.readyState === 1) ws.send(JSON.stringify({ action, ...extra })); },
      get rtt() { return rtt; },
    };
    function open() {
      ws = new WebSocket(`${proto}://${location.host}/ws?role=${encodeURIComponent(role)}&device=${device}&name=${encodeURIComponent(name)}`);
      ws.onopen = () => { retry = 0; onStatus && onStatus('live'); };
      ws.onclose = () => { onStatus && onStatus('offline'); setTimeout(open, Math.min(5000, 300 * 2 ** retry++)); };
      ws.onmessage = (ev) => {
        const m = JSON.parse(ev.data);
        if (m.type === 'markers') {
          const now = Date.now();
          // end-to-end latency: sensor timestamp -> drawn on this device (assumes NTP-synced clocks; use RTT/2 as sanity check)
          const e2e = m.src_ts ? now - m.src_ts : null;
          onMarkers && onMarkers(m.markers, { e2e_ms: e2e, server_ts: m.server_ts, rtt_ms: rtt });
        } else if (m.type === 'pong') {
          rtt = Date.now() - m.t;
        } else onEvent && onEvent(m);
      };
    }
    open();
    setInterval(() => api.send('ping', { t: Date.now() }), 2000);
    return api;
  }

  // Compact text rendering for tiny / text-only displays (any SDK that can show a string).
  // Max 3 lines: headline, detail, data-age/stale.
  function toLines(marker, width = 28) {
    const cut = (s) => (s && s.length > width ? s.slice(0, width - 1) + '…' : s || '');
    const age = marker.stale ? 'DATA STALE' : marker.data_age_s != null ? `data ${marker.data_age_s}s old` : '';
    return [`${ICON[marker.severity_color] || ''} ${cut(marker.headline)}`, cut(marker.detail), age].filter(Boolean);
  }

  global.ARWA = { connect, toLines, PALETTES, ICON };
})(window);
