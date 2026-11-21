// Bundled viewer adapter. The glasses own progress; the phone is an optional remote.
// Short local HTTP polls keep the first companion build dependency-free on Android 9.
(function (global) {
  function connect(options) {
    var live = false, busy = false, last = null, queue = Promise.resolve();
    function status(value) { if (live !== value) { live = value; if (options.onStatus) options.onStatus(value ? 'live' : 'offline'); } }
    function deliver(value) {
      if (last !== null && value.revision < last) return;
      status(true);
      var hint = typeof document !== 'undefined' && document.getElementById('hint');
      if (hint && value.voiceStatus) hint.textContent = value.voiceStatus === 'Listening' ? 'Voice: next · back · show · hide' : 'Voice: ' + value.voiceStatus;
      if (last !== value.revision) {
        if (options.onEvent) options.onEvent(value);
        last = value.revision;
      }
      // Report only after the page applied state and had a chance to draw it.
      requestAnimationFrame(function () { requestAnimationFrame(function () {
        fetch('/api/viewer', { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify({ revision: value.revision }) }).catch(function () {});
      }); });
    }
    function json(response) { if (!response.ok) throw new Error('Guide request failed: ' + response.status); return response.json(); }
    function poll() {
      if (busy) { setTimeout(poll, 250); return; }
      fetch('/api/wf', { cache: 'no-store' }).then(json).then(deliver).catch(function () { status(false); })
        .then(function () { setTimeout(poll, 250); });
    }
    poll();
    return {
      rtt: null,
      send: function (action, extra) {
        if (action !== 'wf') return;
        var body = {};
        Object.keys(extra || {}).forEach(function (key) { body[key] = extra[key]; });
        body.requestId = Date.now() + '-' + Math.random().toString(36).slice(2);
        queue = queue.then(function () {
          busy = true;
          return fetch('/api/wf', { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify(body) })
            .then(json).then(deliver).catch(function () { status(false); }).then(function () { busy = false; });
        });
      }
    };
  }
  global.ARWA = { connect: connect };
})(window);
