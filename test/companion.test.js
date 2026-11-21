const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const root = path.resolve(__dirname, '..');
const flush = () => new Promise(resolve => setImmediate(resolve));

test('bundled glasses viewer matches the original guide and needs no external assets', () => {
  const original = { window: {} }, bundled = { window: {} };
  vm.runInNewContext(fs.readFileSync(path.join(root, 'public/workflow-steps.js'), 'utf8'), original);
  const assets = path.join(root, 'android-glasses/app/src/main/assets/guide');
  vm.runInNewContext(fs.readFileSync(path.join(assets, 'workflow-steps.js'), 'utf8'), bundled);
  assert.equal(bundled.window.WF_JOBS.coupling.steps.length, 8);
  assert.equal(JSON.stringify(original.window.WF_JOBS.coupling.steps), JSON.stringify(bundled.window.WF_JOBS.coupling.steps));
  const html = fs.readFileSync(path.join(assets, 'workflow3d.html'), 'utf8');
  for (const [, source] of html.matchAll(/<script src="([^"]+)"/g)) {
    assert.ok(source.startsWith('/') && !source.startsWith('//'));
    assert.ok(fs.existsSync(path.join(assets, source)), source);
  }
  assert.equal(html, fs.readFileSync(path.join(root, 'public/workflow3d.html'), 'utf8'));
});

const phoneGuide = path.join(root, 'ios-companion/MLDemo/coupling.json');
test('phone metadata matches the bundled guide', () => {
  const bundled = { window: {} };
  vm.runInNewContext(fs.readFileSync(path.join(root, 'android-glasses/app/src/main/assets/guide/workflow-steps.js'), 'utf8'), bundled);
  const phone = JSON.parse(fs.readFileSync(phoneGuide, 'utf8'));
  assert.equal(JSON.stringify(phone.steps), JSON.stringify(bundled.window.WF_JOBS.coupling.steps));
});

test('viewer serializes touchpad commands, ignores stale replies and acknowledges after drawing', async () => {
  const timers = [], frames = [], applied = [], acknowledged = [], commands = [];
  let revision = 1, deferRead = null;
  const response = value => ({ ok: true, json: async () => value });
  const context = {
    window: {}, console,
    setTimeout: callback => timers.push(callback),
    requestAnimationFrame: callback => frames.push(callback),
    fetch: async (url, options) => {
      if (url === '/api/viewer') { acknowledged.push(JSON.parse(options.body).revision); return response({}); }
      if (options.method === 'POST') {
        const body = JSON.parse(options.body);
        commands.push(body);
        return response({ revision: ++revision, type: 'wf' });
      }
      if (deferRead) return deferRead;
      return response({ revision, type: 'wf' });
    }
  };
  vm.runInNewContext(fs.readFileSync(path.join(root, 'android-glasses/companion-client.js'), 'utf8'), context);
  const link = context.window.ARWA.connect({ onEvent: value => applied.push(value.revision) });
  await flush();
  assert.deepEqual(applied, [1]);
  assert.deepEqual(acknowledged, []);
  frames.shift()(); frames.shift()();
  await flush();
  assert.deepEqual(acknowledged, [1]);
  let finishRead;
  deferRead = new Promise(resolve => { finishRead = resolve; });
  timers.shift()();
  await flush();
  link.send('wf', { cmd: 'next' });
  link.send('wf', { cmd: 'next' });
  await flush();
  assert.deepEqual(commands.map(command => command.cmd), ['next', 'next']);
  assert.notEqual(commands[0].requestId, commands[1].requestId);
  assert.deepEqual(applied, [1, 2, 3]);
  finishRead(response({ revision: 1, type: 'wf' }));
  await flush();
  assert.deepEqual(applied, [1, 2, 3], 'late poll must not rewind the display');
});
