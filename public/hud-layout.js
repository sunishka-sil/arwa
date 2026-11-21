// Corner-panel layout for the glasses: shrink the whole view into one corner so the centre of vision stays clear.
// The waveguide's focal distance is fixed by the optics; what we control is size and position on the 640x480 panel.
// URL: ?pos=c|tr|tl|br|bl|full (default c = centred inside the M6 app, full in a normal browser), ?size=0.72 (fraction of the display), ?y=18 (gap from the top/bottom edge, % of the display)
// Pages put everything inside <div id="box">; this scales it from the chosen corner.
(function () {
  var q = new URLSearchParams(location.search);
  var pos = q.get('pos') || (window.ARWAGlasses ? 'c' : 'full');
  var box = document.getElementById('box');
  if (!box || pos === 'full') return;
  var s = Math.max(0.3, Math.min(1, Number(q.get('size') || (pos === 'c' ? 0.80 : 0.72))));
  var m = 3; // % margin from the display edge
  if (pos === 'c') { // centred on the real display (default in the M6 app); ?y= nudges it down (+) or up (-), in % of the display
    var dy = Number(q.get('y') || 0);
    box.style.position = 'absolute'; box.style.left = '0'; box.style.top = dy + 'vh';
    box.style.width = '100vw'; box.style.height = '100vh';
    box.style.transformOrigin = '50% 50%'; box.style.transform = 'scale(' + s + ')';
    document.body.classList.add('boxed'); document.documentElement.style.setProperty('--box-scale', s);
    window.ARWA_BOX = { pos: pos, size: s };
    setTimeout(function () { var r = box.getBoundingClientRect(); console.log('ARWA layout: display ' + innerWidth + 'x' + innerHeight + ', panel ' + Math.round(r.width) + 'x' + Math.round(r.height) + ' at ' + Math.round(r.left) + ',' + Math.round(r.top) + ' (centred, size ' + s + ', y ' + dy + ')'); }, 300);
    return;
  }
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
