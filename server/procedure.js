// Procedure / Step runner. Advisory only: it gates the *checklist*, never the equipment.
// Every confirmed step is written to the evidence log (asset ID, time, verification method). No video.

const fs = require('fs');
const path = require('path');

function parseRequirement(expr) {
  const m = /^\s*([a-zA-Z_][\w]*)\s*(==|!=|<=|>=|<|>)\s*(-?\d+(?:\.\d+)?)\s*$/.exec(expr || '');
  if (!m) throw new Error(`Bad requires_reading expression: ${expr}`);
  return { signal: m[1], op: m[2], value: Number(m[3]) };
}

function compare(actual, op, expected, tolerance = 0) {
  switch (op) {
    case '==': return Math.abs(actual - expected) <= tolerance;
    case '!=': return Math.abs(actual - expected) > tolerance;
    case '<': return actual < expected;
    case '<=': return actual <= expected;
    case '>': return actual > expected;
    case '>=': return actual >= expected;
    default: return false;
  }
}

class ProcedureRun {
  constructor({ procedure, state, evidencePath, now = () => Date.now() }) {
    this.procedure = procedure;
    this.state = state;
    this.now = now;
    this.evidencePath = evidencePath;
    this.reset();
  }

  reset() {
    this.stepIdx = 0; // 0-based into steps
    this.verifiedAnchor = null;
    this.startedAt = this.now();
    this.done = false;
  }

  get step() {
    return this.procedure.steps[this.stepIdx] || null;
  }

  get targetAsset() {
    return this.state.get(this.procedure.target_asset_id)?.asset;
  }

  // Evaluate whether the current step may advance. Returns { ok, reason, verification }.
  gate() {
    const step = this.step;
    if (!step) return { ok: false, reason: 'Procedure complete' };
    const target = this.procedure.target_asset_id;

    if (step.requires_scan) {
      if (this.verifiedAnchor === step.requires_scan) return { ok: true, verification: `qr:${step.requires_scan}` };
      return { ok: false, reason: `Scan ${this.targetAsset?.label || 'target'} QR to verify` };
    }

    if (step.check_partner) {
      const partnerId = this.targetAsset?.redundancy?.partner_asset_id;
      const r = this.state.reading(partnerId, step.check_partner.signal);
      if (!r) return { ok: false, reason: 'Partner feed data stale: cannot verify' };
      const pass = compare(r.value, step.check_partner.op, step.check_partner.value);
      return pass
        ? { ok: true, verification: `reading:${partnerId}:${step.check_partner.signal}=${r.value}`, hold_point: true }
        : { ok: false, reason: `Partner ${step.check_partner.signal} ${r.value} fails ${step.check_partner.op} ${step.check_partner.value}` };
    }

    if (step.requires_reading) {
      const req = parseRequirement(step.requires_reading);
      const r = this.state.reading(target, req.signal);
      if (!r) return { ok: false, reason: 'Data stale: cannot verify reading' };
      const pass = compare(r.value, req.op, req.value, step.tolerance || 0);
      return pass
        ? { ok: true, verification: `reading:${req.signal}=${r.value}${r.unit}` }
        : { ok: false, reason: `Waiting: ${req.signal} is ${r.value}${r.unit}, need ${req.op} ${req.value}` };
    }

    return { ok: true, verification: 'manual_confirm' };
  }

  // A QR/fiducial scan from any device. Returns { match, asset }.
  scan(anchorId, by) {
    const asset = this.state.findByAnchor(anchorId);
    const expected = this.step?.requires_scan;
    const match = !!expected && anchorId === expected;
    if (match) this.verifiedAnchor = anchorId;
    this._log({ event: 'scan', anchor_id: anchorId, asset_id: asset?.asset_id || null, match, expected: expected || null, by });
    return { match, asset, expected };
  }

  confirm(by) {
    const g = this.gate();
    if (!g.ok) {
      this._log({ event: 'confirm_rejected', step: this.step?.index, reason: g.reason, by });
      return { ok: false, reason: g.reason };
    }
    this._log({ event: 'step_confirmed', step: this.step.index, text: this.step.text, verification: g.verification, by });
    this.stepIdx += 1;
    if (this.stepIdx >= this.procedure.steps.length) {
      this.done = true;
      this._log({ event: 'procedure_complete', duration_s: (this.now() - this.startedAt) / 1000, by });
    }
    return { ok: true, verification: g.verification };
  }

  callExpert(by) {
    this._log({ event: 'call_expert', step: this.step?.index, by });
  }

  _log(entry) {
    const line = { ts: new Date(this.now()).toISOString(), procedure_id: this.procedure.procedure_id, asset_id: this.procedure.target_asset_id, ...entry };
    if (this.evidencePath) {
      fs.mkdirSync(path.dirname(this.evidencePath), { recursive: true });
      fs.appendFileSync(this.evidencePath, JSON.stringify(line) + '\n');
    }
    return line;
  }
}

module.exports = { ProcedureRun, parseRequirement, compare };
