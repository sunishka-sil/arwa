// Layer 4: router. Role + priority + device class decide who sees what.
// Output is the single marker message shape every device understands ("server sends meaning, device draws it").

const PRIORITY_RANK = { critical: 0, high: 1, medium: 2, low: 3 };

function fmt(sig, digits = 0) {
  return sig ? `${sig.value.toFixed(digits)}${sig.unit ? ' ' + sig.unit : ''}`.replace(' %', '%') : '--';
}

class Router {
  constructor({ state, run, roles, handoff = null, now = () => Date.now() }) {
    this.handoff = handoff;
    this.state = state;
    this.run = run;
    this.roles = roles;
    this.now = now;
    this.flash = null; // transient hazard, e.g. wrong-asset scan: { marker, until }
  }

  // Generic transient marker (vision verdicts, camera hazard). Shown on top for `ms`.
  flashMarker(marker, ms = 6000) {
    this.flash = { until: this.now() + ms, marker: { anchor: null, asset_id: null, ...marker } };
  }

  flashWrongAsset(scannedAsset, expectedLabel) {
    this.flash = {
      until: this.now() + 6000,
      marker: {
        marker_id: 'm-wrong-asset',
        asset_id: scannedAsset?.asset_id || null,
        anchor: scannedAsset?.anchor || null,
        kind: 'hazard',
        priority: 'critical',
        severity_color: 'red',
        headline: `WRONG ASSET: ${scannedAsset?.label || 'unknown tag'}`,
        detail: `This is not ${expectedLabel}. Step back.`,
      },
    };
  }

  // All markers relevant right now, before role filtering.
  allMarkers() {
    const out = [];
    const run = this.run;
    const target = run.targetAsset;
    const tSnap = this.state.snapshot(target.asset_id);
    const step = run.step;
    const gate = run.gate();

    if (this.flash && this.flash.until > this.now()) out.push({ ...this.flash.marker, data_age_s: 0, stale: false });

    // Track 02: pending handoff packet + findings pinned to assets
    if (this.handoff) out.push(...this.handoff.markers());

    // Step marker
    if (step) {
      out.push({
        marker_id: 'm-step',
        asset_id: target.asset_id,
        anchor: target.anchor,
        kind: 'step',
        priority: 'high',
        severity_color: gate.ok ? 'green' : step.hold_point ? 'amber' : 'blue',
        headline: `Step ${step.index}/${run.procedure.steps.length}: ${step.text}`,
        detail: gate.ok ? (gate.verification === 'manual_confirm' ? 'Tap confirm when done' : `Verified ✓ ${gate.verification.split(':').slice(-1)[0]}`) : gate.reason,
        data_age_s: tSnap.data_age_s,
        stale: tSnap.stale,
        step: { index: step.index, total: run.procedure.steps.length, requires_reading: step.requires_reading || null, hold_point: !!step.hold_point, can_confirm: gate.ok },
        actions: ['confirm_step', 'call_expert'],
      });
    } else {
      out.push({
        marker_id: 'm-step', asset_id: target.asset_id, anchor: target.anchor, kind: 'step', priority: 'medium',
        severity_color: 'green', headline: 'Procedure complete ✓', detail: 'Evidence logged', data_age_s: tSnap.data_age_s, stale: tSnap.stale,
        step: { index: run.procedure.steps.length, total: run.procedure.steps.length, can_confirm: false }, actions: [],
      });
    }

    // Target marker (green halo), or stale
    out.push(this._assetMarker(target, tSnap, 'target'));

    // Look-alikes: every other asset of the same type in the same rack
    for (const rec of this.state.assets.values()) {
      const a = rec.asset;
      if (a.asset_id === target.asset_id || a.type !== target.type) continue;
      out.push(this._assetMarker(a, this.state.snapshot(a.asset_id), 'lookalike'));
    }

    // Alarms (only on live data)
    for (const rec of this.state.assets.values()) {
      const snap = this.state.snapshot(rec.asset.asset_id);
      for (const al of snap.alarms) {
        out.push({
          marker_id: `m-alarm-${rec.asset.anchor.id}-${al.id}`, asset_id: rec.asset.asset_id, anchor: rec.asset.anchor,
          kind: 'alarm', priority: al.severity === 'red' ? 'critical' : 'medium', severity_color: al.severity,
          headline: `${rec.asset.label}: ${al.text}`, detail: 'Active alarm', data_age_s: snap.data_age_s, stale: false, actions: ['call_expert'],
        });
      }
    }
    return out;
  }

  _assetMarker(asset, snap, kind) {
    const base = { marker_id: `m-${kind}-${asset.anchor.id}`, asset_id: asset.asset_id, anchor: asset.anchor, kind, data_age_s: snap.data_age_s, stale: snap.stale };
    if (snap.stale) {
      return {
        ...base, priority: kind === 'target' ? 'critical' : 'low', severity_color: 'grey',
        headline: `${asset.label}: DATA STALE`,
        detail: snap.data_age_s === null ? 'No data received yet' : `No update for ${snap.data_age_s}s. Do not rely on readings.`,
        actions: ['call_expert'],
      };
    }
    const s = snap.signals;
    if (kind === 'lookalike') {
      return { ...base, priority: 'medium', severity_color: 'red', headline: `NOT THIS ONE: ${asset.label}`, detail: `Feed ${asset.feed}. Target is to the ${asset.position === 'right' ? 'left' : 'right'}.`, actions: [] };
    }
    // Redundancy consequence: if target opens, partner carries the rack.
    const partnerId = asset.redundancy?.partner_asset_id;
    const pSnap = partnerId ? this.state.snapshot(partnerId) : null;
    const consequence = pSnap && !pSnap.stale ? `Open → feed ${asset.redundancy.partner_feed} carries 100% of rack (now ${fmt(pSnap.signals.load_pct)})` : `Partner feed ${asset.redundancy?.partner_feed || '?'} data stale`;
    return {
      ...base, priority: 'high', severity_color: snap.state === 'Faulted' ? 'red' : 'green',
      headline: `${asset.label} · ${snap.state}`,
      detail: `${fmt(s.load_pct)} load · ${fmt(s.current_A, 1)} · ${fmt(s.temp_C)} | ${consequence}`,
      readings: { load_pct: s.load_pct?.value ?? null, current_A: s.current_A?.value ?? null, temp_C: s.temp_C?.value ?? null },
      actions: ['call_expert'],
    };
  }

  // Markers for one client. device: 'glasses' | 'phone'.
  markersFor({ role = 'electrical_tech', device = 'phone' } = {}) {
    const rule = this.roles[role] || this.roles.electrical_tech;
    const max = rule.max_markers[device] ?? 5;
    return this.allMarkers()
      .filter((m) => rule.kinds.includes(m.kind))
      .map((m) => ({ ...m, for_role: role }))
      .sort((a, b) => PRIORITY_RANK[a.priority] - PRIORITY_RANK[b.priority])
      .slice(0, max);
  }
}

module.exports = { Router };
