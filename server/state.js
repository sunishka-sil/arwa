// Layer 3: state model. One vocabulary, keyed by asset ID.
// Asset -> State (Running | Idle | Faulted | Offline | Stale) + Signals + Alarms.
// "Stale" is its own state: if a feed goes quiet we never show a last-known value as if it were live.

const { EventEmitter } = require('events');

const STATES = ['Running', 'Idle', 'Faulted', 'Offline', 'Stale'];

class StateModel extends EventEmitter {
  constructor({ assets, staleAfterS = 5, now = () => Date.now() } = {}) {
    super();
    this.staleAfterMs = staleAfterS * 1000;
    this.now = now;
    this.assets = new Map(); // asset_id -> { asset, signals: Map, alarms: Map, lastSeen }
    for (const a of assets || []) {
      this.assets.set(a.asset_id, { asset: a, signals: new Map(), alarms: new Map(), lastSeen: null, state: 'Stale' });
    }
  }

  // Normalised input from any adapter (MQTT sim, ESP32, BMS...).
  // { asset_id, signal, value, unit, ts }  ts = source timestamp in ms
  ingest({ asset_id, signal, value, unit, ts }) {
    const rec = this.assets.get(asset_id);
    if (!rec) return false; // unknown asset: ignore (log upstream)
    const t = Number.isFinite(ts) ? ts : this.now();
    rec.signals.set(signal, { value: Number(value), unit: unit || '', ts: t, received: this.now() });
    rec.lastSeen = this.now();
    this._evaluateAlarms(rec);
    this._recompute(rec);
    this.emit('change', asset_id, { signal, src_ts: t });
    return true;
  }

  _evaluateAlarms(rec) {
    const temp = rec.signals.get('temp_C');
    if (temp && temp.value >= 45) rec.alarms.set('over_temp', { id: 'over_temp', text: `Temp ${temp.value.toFixed(0)}°C`, severity: 'red' });
    else rec.alarms.delete('over_temp');
    const load = rec.signals.get('load_pct');
    if (load && load.value >= 80) rec.alarms.set('high_load', { id: 'high_load', text: `Load ${load.value.toFixed(0)}%`, severity: 'amber' });
    else rec.alarms.delete('high_load');
  }

  _recompute(rec) {
    const prev = rec.state;
    let next;
    if (rec.lastSeen === null || this.now() - rec.lastSeen > this.staleAfterMs) next = 'Stale';
    else if (rec.alarms.size > 0 && [...rec.alarms.values()].some((a) => a.severity === 'red')) next = 'Faulted';
    else {
      const cur = rec.signals.get('current_A');
      next = cur && Math.abs(cur.value) < 0.2 ? 'Idle' : 'Running';
    }
    rec.state = next;
    if (prev !== next) this.emit('stateChange', rec.asset.asset_id, prev, next);
    return next;
  }

  // Call periodically (e.g. every 250 ms). Returns asset IDs whose state changed.
  sweep() {
    const changed = [];
    for (const [id, rec] of this.assets) {
      const before = rec.state;
      if (this._recompute(rec) !== before) changed.push(id);
    }
    return changed;
  }

  dataAgeS(asset_id) {
    const rec = this.assets.get(asset_id);
    if (!rec || rec.lastSeen === null) return null;
    return Math.round((this.now() - rec.lastSeen) / 100) / 10;
  }

  isStale(asset_id) {
    const rec = this.assets.get(asset_id);
    return !rec || rec.state === 'Stale';
  }

  // Returns the live value, or null if stale. Never returns a last-known value for a stale asset.
  reading(asset_id, signal) {
    const rec = this.assets.get(asset_id);
    if (!rec || rec.state === 'Stale') return null;
    const s = rec.signals.get(signal);
    return s ? s : null;
  }

  snapshot(asset_id) {
    const rec = this.assets.get(asset_id);
    if (!rec) return null;
    const stale = rec.state === 'Stale';
    const signals = {};
    for (const [k, v] of rec.signals) signals[k] = stale ? null : { value: v.value, unit: v.unit, ts: v.ts };
    return {
      asset_id,
      label: rec.asset.label,
      state: rec.state,
      stale,
      data_age_s: this.dataAgeS(asset_id),
      signals,
      alarms: stale ? [] : [...rec.alarms.values()],
    };
  }

  get(asset_id) {
    return this.assets.get(asset_id);
  }

  findByAnchor(anchorId) {
    for (const rec of this.assets.values()) if (rec.asset.anchor && rec.asset.anchor.id === anchorId) return rec.asset;
    return null;
  }
}

module.exports = { StateModel, STATES };
