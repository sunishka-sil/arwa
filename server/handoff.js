// Track 02: seamless handoff. Findings are pinned to an asset ID (not a notebook or a person),
// and a handoff packet carries open findings + where the procedure stopped to the next person, on any device.
class HandoffBook {
  constructor({ state, run, now = () => Date.now() }) {
    this.state = state; this.run = run; this.now = now;
    this.findings = []; // { id, asset_id, label, by, ts, note, signal, value, unit, status }
    this.packet = null; // { id, from, to, ts, finding_ids, step_index, procedure_id, picked_up_by, picked_up_ts }
    this.seq = 1;
  }

  addFinding({ anchor_id, asset_id, by, note = '', signal }) {
    const asset = asset_id ? this.state.get(asset_id)?.asset : this.state.findByAnchor(anchor_id);
    if (!asset) return { ok: false, reason: 'Unknown asset' };
    const snap = this.state.snapshot(asset.asset_id);
    const sig = signal || Object.keys(snap.signals)[0];
    const r = snap.signals[sig];
    const f = { id: `F-${this.seq++}`, asset_id: asset.asset_id, label: asset.label, by, ts: this.now(), note,
      signal: sig, value: r ? r.value : null, unit: r ? r.unit : '', stale_at_capture: snap.stale, status: 'open' };
    this.findings.push(f);
    this.run._log({ event: 'finding', ...f });
    return { ok: true, finding: f };
  }

  closeFinding(id, by) {
    const f = this.findings.find((x) => x.id === id);
    if (!f) return { ok: false };
    f.status = 'closed'; f.closed_by = by; f.closed_ts = this.now();
    this.run._log({ event: 'finding_closed', id, by });
    return { ok: true };
  }

  open() { return this.findings.filter((f) => f.status === 'open'); }

  handOff({ from, to = 'next shift' }) {
    this.packet = { id: `H-${this.seq++}`, from, to, ts: this.now(), finding_ids: this.open().map((f) => f.id),
      step_index: this.run.step ? this.run.step.index : null, procedure_id: this.run.procedure.procedure_id, picked_up_by: null };
    this.run._log({ event: 'handoff', ...this.packet });
    return this.packet;
  }

  pickUp(by) {
    if (!this.packet || this.packet.picked_up_by) return null;
    this.packet.picked_up_by = by; this.packet.picked_up_ts = this.now();
    this.run._log({ event: 'handoff_picked_up', id: this.packet.id, by, gap_s: (this.now() - this.packet.ts) / 1000 });
    return this.packet;
  }

  // Full packet for any device / remote expert: findings with their current live value next to the captured one.
  view() {
    return {
      packet: this.packet,
      findings: this.findings.map((f) => {
        const now = this.state.reading(f.asset_id, f.signal);
        return { ...f, now_value: now ? now.value : null, now_stale: !now };
      }),
    };
  }

  markers() {
    const out = [];
    const hhmm = (t) => new Date(t).toTimeString().slice(0, 5);
    if (this.packet && !this.packet.picked_up_by) {
      out.push({ marker_id: 'm-handoff', asset_id: null, anchor: null, kind: 'handoff', priority: 'high', severity_color: 'blue',
        headline: `Handoff from ${this.packet.from} · ${hhmm(this.packet.ts)}`,
        detail: `${this.packet.finding_ids.length} open finding(s) · resume at step ${this.packet.step_index ?? '–'}`,
        data_age_s: 0, stale: false, actions: ['pick_up'] });
    }
    for (const f of this.open()) {
      const now = this.state.reading(f.asset_id, f.signal);
      const fmt = (v) => (v == null ? '--' : Number(v).toFixed(1));
      const trend = now && f.value != null ? (now.value > f.value * 1.03 ? ' ↑' : now.value < f.value * 0.97 ? ' ↓' : ' →') : '';
      const anchor = this.state.get(f.asset_id)?.asset.anchor || null;
      out.push({ marker_id: `m-finding-${f.id}`, asset_id: f.asset_id, anchor, kind: 'finding', priority: 'high', severity_color: 'amber',
        headline: `${f.label}: finding by ${f.by} · ${hhmm(f.ts)}`,
        detail: `${f.signal} ${fmt(f.value)} → now ${now ? fmt(now.value) : 'STALE'}${f.unit}${trend}${f.note ? ` · "${f.note}"` : ''}`,
        data_age_s: this.state.dataAgeS(f.asset_id), stale: !now, actions: ['close_finding', 'call_expert'] });
    }
    return out;
  }
}
module.exports = { HandoffBook };
