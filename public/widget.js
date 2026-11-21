// Draws the six "ask" widgets. Shared by the glasses (workflow3d.html) and the phone (voice.html).
// Designed for a single-colour waveguide: meaning is carried by size, symbols and blinking, never by hue.
(function (g) {
  var esc = function (s) { return String(s == null ? '' : s).replace(/[&<>"]/g, function (c) { return { '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]; }); };
  var ICON = { big_number: '#', reading: '◉', note: '✎', hazard: '⚠', next_peek: '▸', progress: '◔' };
  var TREND = { up: '↑', down: '↓', flat: '→' };
  function html(w) {
    if (!w) return '';
    var big = w.value != null && w.value !== '' ? '<span class="wv">' + esc(w.value) + '</span>' + (w.unit ? '<span class="wu"> ' + esc(w.unit) + '</span>' : '') + (w.trend ? '<span class="wt"> ' + TREND[w.trend] + '</span>' : '') : '';
    return '<div class="w w-' + esc(w.type) + '"><div class="wk">' + (ICON[w.type] || '') + ' ' + esc(w.title) + '</div>' +
      (big ? '<div class="wb">' + big + '</div>' : '') + (w.detail ? '<div class="wd">' + esc(w.detail) + '</div>' : '') + '</div>';
  }
  var CSS = '.w{border-left:6px solid currentColor;padding:4px 10px;background:#000}' +
    '.w .wk{font:700 .8em system-ui;letter-spacing:.06em;text-transform:uppercase}' +
    '.w .wb{line-height:1}.w .wv{font:800 2.4em system-ui}.w .wu{font:600 .9em system-ui}.w .wt{font:800 1.6em system-ui}' +
    '.w .wd{font:500 .85em system-ui;opacity:.85;margin-top:2px}' +
    '.w-hazard{border-left-width:12px;animation:wblink 1s steps(2) infinite}.w-note .wd{font-style:italic}' +
    '@keyframes wblink{50%{opacity:.35}}';
  g.ARWA_WIDGET = { html: html, css: CSS };
})(window);
