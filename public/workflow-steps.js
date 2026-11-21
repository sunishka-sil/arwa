// The guided workflow's steps, shared by the glasses (workflow3d.html) and the phone (voice.html).
// k = short tag, h = instruction, d = detail, part = what's highlighted, parts = 3D parts that animate,
// spec = the one number for this step, hazard = only where it matters. Also read by the server (assistant).
window.WF_STEPS = [
  { k: 'LOCKOUT', h: 'Lock out the motor', d: 'Disconnect to OFF, padlock + tag on the handle', part: 'Disconnect switch', parts: ['switch', 'lever', 'lock'], spec: { label: 'Zero energy', value: '0', unit: 'V' }, hazard: 'Try the start button after locking: motor must not run' },
  { k: 'PUMP HUB', h: 'Slide hub onto pump shaft', d: 'Flush with the shaft end, tighten set screw', part: 'Pump-side hub', parts: ['pumpHub'], spec: { label: 'Set screw', value: '10', unit: 'N·m' } },
  { k: 'MOTOR HUB', h: 'Key in, motor hub on', d: 'Seat the key in the keyway, slide the hub on', part: 'Key + motor-side hub', parts: ['key', 'motorHub'], spec: { label: 'Key', value: '8×7×40', unit: 'mm' } },
  { k: 'SPIDER', h: 'Seat the spider in the jaws', d: '6-lobe elastomer insert, fully between the jaws', part: 'Spider insert', parts: ['spider'], spec: { label: 'Spider', value: '98', unit: 'Shore A' } },
  { k: 'SET MOTOR', h: 'Lower motor onto baseplate', d: 'Hold a 2 mm gap between hubs with the gauge', part: 'Motor + gap gauge', parts: ['motor', 'gauge'], spec: { label: 'Hub gap', value: '2 ±0.5', unit: 'mm' }, hazard: 'Pinch point: hands off the feet while lowering' },
  { k: 'FOOT BOLTS', h: 'Insert the 4 foot bolts', d: 'M12, hand-tight only for now', part: 'M12 foot bolts', parts: ['b0', 'b1', 'b2', 'b3'], spec: { label: 'Foot bolts', value: 'M12', unit: 'hand-tight' } },
  { k: 'TORQUE', h: 'Align, then torque 1 → 3 → 2 → 4', d: 'Cross pattern, 70 N·m each', part: 'Bolt sequence', parts: ['b0', 'b1', 'b2', 'b3'], spec: { label: 'Torque', value: '70', unit: 'N·m' } },
  { k: 'GUARD', h: 'Close the coupling guard', d: 'Both halves latched, then remove lock', part: 'Coupling guard', parts: ['guard'], spec: { label: 'Guard latches', value: '2', unit: 'closed' }, hazard: 'Remove your lock only after the guard is latched' },
];

// Second job: 3-pole MCCB (moulded-case circuit breaker) sub-assembly at one line station. Values are illustrative.
window.WF_MCCB = [
  { k: 'VERIFY', h: 'Scan work order, check the base', d: 'QR on the traveller, base must be the 100 A frame', part: 'Base + work order', parts: ['base', 'tag'], spec: { label: 'Frame', value: '100', unit: 'A' }, hazard: 'Wrong frame base: stop, set aside as WRONG PART' },
  { k: 'STRAPS', h: 'Seat the 6 terminal straps', d: '3 line side on top, 3 load side below', part: 'Terminal straps', parts: ['s0', 's1', 's2', 's3', 's4', 's5'], spec: { label: 'Straps', value: '6', unit: 'seated' } },
  { k: 'CONTACTS', h: 'Drop in the contact arm assembly', d: 'All 3 poles, check the open gap with the gauge', part: 'Contact arms', parts: ['arms', 'gauge'], spec: { label: 'Contact gap', value: '3 ±0.2', unit: 'mm' } },
  { k: 'ARC CHUTES', h: 'Fit the 3 arc chutes', d: 'Vents face the line side, one per pole', part: 'Arc chutes', parts: ['c0', 'c1', 'c2'], spec: { label: 'Arc chutes', value: '3', unit: 'vents to line' } },
  { k: 'TRIP UNIT', h: 'Mount trip unit, set the dial', d: 'Dial to 1.0 × In, matches the work order', part: 'Trip unit + dial', parts: ['trip', 'dial'], spec: { label: 'Trip setting', value: '1.0', unit: '× In' }, hazard: 'Dial must match the work order rating' },
  { k: 'MECHANISM', h: 'Install mechanism and handle', d: 'Hook both springs, handle through the slot', part: 'Mechanism + handle', parts: ['mech', 'handle'], spec: { label: 'Springs', value: '2', unit: 'hooked' }, hazard: 'Stored spring energy: fingers clear of the latch' },
  { k: 'COVER', h: 'Close cover, torque 1 → 3 → 2 → 4', d: 'Cross pattern, 1.2 N·m each', part: 'Cover screws', parts: ['cover', 'w0', 'w1', 'w2', 'w3'], spec: { label: 'Cover torque', value: '1.2', unit: 'N·m' } },
  { k: 'CHECK', h: 'Operate, test trip, then label', d: 'ON → OFF → ON ×3, press TEST, reset, apply label', part: 'Handle + TEST button', parts: ['handle', 'test', 'label'], spec: { label: 'Operations', value: '3', unit: 'cycles' }, hazard: 'Bench test only: never energize at the station' },
];
window.WF_JOBS = {
  coupling: { title: 'Mount motor to pump: jaw coupling', short: 'Motor coupling', page: 'workflow3d.html', done: 'Motor mounted', steps: window.WF_STEPS },
  mccb: { title: 'Assemble a 3-pole MCCB (100 A)', short: 'Circuit breaker', page: 'mccb3d.html', done: 'Breaker assembled', steps: window.WF_MCCB },
};
if (typeof module !== 'undefined') module.exports = window.WF_STEPS;
