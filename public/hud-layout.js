// Corner-panel layout for the glasses: shrink the whole view into one corner so the centre of vision stays clear.
// The waveguide's focal distance is fixed by the optics; what we control is size and position on the 640x480 panel.
// URL: ?pos=tr|tl|br|bl|full (default tr inside the M6 app, full in a normal browser), ?size=0.55 (fraction of the display)
// Pages put everything inside <div id="box">; this scales it from the chosen corner.
(function () {
  var q = new URLSearchParams(location.search);
  var pos = q.get('pos') || (window.ARWAGlasses ? 'tr' : 'full');
  var box = document.getElementById('box');
  if (!box || pos === 'full') return;
  var s = Math.max(0.3, Math.min(1, Number(q.get('size') || 0.55)));
  var m = 3; // % margin from the display edge
  var v = pos[0] === 'b' ? 'bottom' : 'top', h = pos[1] === 'l' ? 'left' : 'right';
  box.style.position = 'absolute';
  box.style.width = '100vw'; box.style.height = '100vh';
  box.style[v] = m + 'vh'; box.style[h] = m + 'vw';
  box.style.transformOrigin = v + ' ' + h;
  box.style.transform = 'scale(' + s + ')';
  document.body.classList.add('boxed');
  document.documentElement.style.setProperty('--box-scale', s);
  window.ARWA_BOX = { pos: pos, size: s };
})();
