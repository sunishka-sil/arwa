// Corner-panel layout for the glasses: shrink the whole view into one corner so the centre of vision stays clear.
// The waveguide's focal distance is fixed by the optics; what we control is size and position on the 640x480 panel.
// URL: ?pos=tr|tl|br|bl|full (default tr inside the M6 app, full in a normal browser), ?size=0.72 (fraction of the display), ?y=18 (gap from the top/bottom edge, % of the display)
// Pages put everything inside <div id="box">; this scales it from the chosen corner.
(function () {
  var q = new URLSearchParams(location.search);
  var pos = q.get('pos') || (window.ARWAGlasses ? 'tr' : 'full');
  var box = document.getElementById('box');
  if (!box || pos === 'full') return;
  var s = Math.max(0.3, Math.min(1, Number(q.get('size') || 0.72)));
  var m = 3; // % margin from the display edge
  var v = pos[0] === 'b' ? 'bottom' : 'top', h = pos[1] === 'l' ? 'left' : 'right';
  box.style.position = 'absolute';
  box.style.width = '100vw'; box.style.height = '100vh';
  // ?y= vertical margin in % of the display (default 18 inside the M6 app, where 3 sat too high and clipped the top row)
  var my = Number(q.get('y') != null ? q.get('y') : (window.ARWAGlasses ? 18 : m));
  box.style[v] = my + 'vh'; box.style[h] = m + 'vw';
  box.style.transformOrigin = v + ' ' + h;
  box.style.transform = 'scale(' + s + ')';
  document.body.classList.add('boxed');
  document.documentElement.style.setProperty('--box-scale', s);
  window.ARWA_BOX = { pos: pos, size: s };
})();
