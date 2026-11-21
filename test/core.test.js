const test = require('node:test');
const assert = require('node:assert');
const { StateModel } = require('../server/state');
const { ProcedureRun } = require('../server/procedure');
const { Router } = require('../server/router');
const assets = require('../data/packs/datacenter/assets.json').assets;
const procedure = require('../data/packs/datacenter/procedure.json');
const { roles } = require('../data/roles.json');

function rig() {
  let t = 1_000_000;
  const now = () => t;
  const state = new StateModel({ assets, staleAfterS: 3, now });
  const run = new ProcedureRun({ procedure, state, now });
  const router = new Router({ state, run, roles, now });
  const feed = (id, sig) => Object.entries(sig).forEach(([signal, value]) => state.ingest({ asset_id: `demo/hall1/rowB/rack2/${id}`, signal, value, ts: t }));
  return { state, run, router, feed, tick: (ms) => { t += ms; state.sweep(); } };
}

test('asset with no data is Stale, never shows a value', () => {
  const { state } = rig();
  const s = state.snapshot('demo/hall1/rowB/rack2/pdu07');
  assert.equal(s.state, 'Stale');
  assert.equal(state.reading('demo/hall1/rowB/rack2/pdu07', 'current_A'), null);
});

test('feed drop flips to Stale after threshold and hides last-known value', () => {
  const { state, feed, tick } = rig();
  feed('pdu07', { current_A: 7, load_pct: 44, temp_C: 31 });
  assert.equal(state.snapshot('demo/hall1/rowB/rack2/pdu07').state, 'Running');
  tick(2900);
  assert.equal(state.snapshot('demo/hall1/rowB/rack2/pdu07').state, 'Running');
  tick(200);
  const s = state.snapshot('demo/hall1/rowB/rack2/pdu07');
  assert.equal(s.state, 'Stale');
  assert.equal(s.signals.current_A, null);
});

test('router: glasses get <=3 markers, target green, look-alike red on phone', () => {
  const { router, feed } = rig();
  feed('pdu07', { current_A: 7, load_pct: 44, temp_C: 31 });
  feed('pdu08', { current_A: 6, load_pct: 38, temp_C: 30 });
  const g = router.markersFor({ device: 'glasses' });
  assert.ok(g.length <= 3);
  const p = router.markersFor({ device: 'phone' });
  assert.equal(p.find((m) => m.kind === 'target').severity_color, 'green');
  assert.equal(p.find((m) => m.kind === 'lookalike').severity_color, 'red');
  assert.match(p.find((m) => m.kind === 'target').detail, /feed B carries 100%/);
});

test('supervisor role does not see step markers', () => {
  const { router, feed } = rig();
  feed('pdu07', { current_A: 7, load_pct: 44, temp_C: 31 });
  assert.ok(router.markersFor({ role: 'supervisor', device: 'phone' }).every((m) => m.kind !== 'step'));
});

test('procedure: scan gate, wrong asset rejected, partner hold point, reading gate', () => {
  const { run, feed, router } = rig();
  feed('pdu07', { current_A: 7, load_pct: 44, temp_C: 31 });
  feed('pdu08', { current_A: 6, load_pct: 38, temp_C: 30 });
  assert.ok(run.confirm('t').ok); // step 1 navigate
  assert.equal(run.confirm('t').ok, false); // step 2 needs scan
  assert.equal(run.scan('pdu08', 't').match, false); // wrong asset
  router.flashWrongAsset(run.state.findByAnchor('pdu08'), 'PDU B2-07');
  assert.equal(router.markersFor({ device: 'glasses' })[0].kind, 'hazard');
  assert.ok(run.scan('pdu07', 't').match);
  assert.ok(run.confirm('t').ok); // step 2
  feed('pdu08', { load_pct: 85 });
  assert.equal(run.confirm('t').ok, false); // hold point fails: partner overloaded
  feed('pdu08', { load_pct: 40 });
  assert.ok(run.confirm('t').ok); // step 3
  assert.match(run.confirm('t').reason, /current_A is 7/); // step 4 blocked
  feed('pdu07', { current_A: 0.05 });
  assert.ok(run.confirm('t').ok); // step 4 verified by reading
  assert.ok(run.confirm('t').ok); // step 5
  assert.ok(run.done);
});

test('reading gate refuses when data is stale', () => {
  const { run, feed, tick } = rig();
  feed('pdu07', { current_A: 0 }); feed('pdu08', { load_pct: 30 });
  run.stepIdx = 3; // step 4
  tick(4000);
  assert.match(run.confirm('t').reason, /stale/i);
});

test('handoff: finding pinned to asset, packet carries it, shift B sees captured vs now', () => {
  const { state, run, feed } = rig();
  const { HandoffBook } = require('../server/handoff');
  const book = new HandoffBook({ state, run });
  const router = new Router({ state, run, roles, handoff: book });
  feed('pdu07', { current_A: 7, load_pct: 44, temp_C: 41 });
  feed('pdu08', { current_A: 6, load_pct: 38, temp_C: 30 });
  const r = book.addFinding({ anchor_id: 'pdu07', by: 'Maya', note: 'hot smell', signal: 'temp_C' });
  assert.ok(r.ok);
  const p = book.handOff({ from: 'Maya' });
  assert.deepEqual(p.finding_ids, [r.finding.id]);
  feed('pdu07', { temp_C: 44 });
  const ms = router.markersFor({ device: 'phone' });
  assert.ok(ms.find((m) => m.kind === 'handoff'));
  const f = ms.find((m) => m.kind === 'finding');
  assert.match(f.detail, /41\.0 → now 44\.0.*↑/);
  assert.equal(book.pickUp('Dev').picked_up_by, 'Dev');
  assert.ok(!router.markersFor({ device: 'phone' }).find((m) => m.kind === 'handoff'));
  book.closeFinding(r.finding.id, 'Dev');
  assert.equal(book.open().length, 0);
});
