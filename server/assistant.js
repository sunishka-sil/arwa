// "Ask" assistant: the technician speaks a question to the phone; the answer comes back as ONE glanceable
// widget for the glasses panel (never a paragraph). Two engines, same output shape:
//   - Claude (when ANTHROPIC_API_KEY is set): picks the widget type and fills it from the job context.
//   - Rules (always available, no key, no internet): keyword matching over the same context.
// The model only chooses and formats; every number it may show is in the context we send, so it can't invent specs.
const Anthropic = require('@anthropic-ai/sdk');
const { z } = require('zod');
const { betaZodOutputFormat } = require('@anthropic-ai/sdk/helpers/beta/zod');

const MODEL = process.env.ARWA_MODEL || 'claude-opus-5-5';

// The six widgets the glasses know how to draw. Keep this list short: each is designed for a 1-second glance.
const Widget = z.object({
  type: z.enum(['big_number', 'reading', 'note', 'hazard', 'next_peek', 'progress'])
    .describe('big_number: one spec value. reading: a live sensor value with trend. note: a finding or short fact. hazard: a safety warning. next_peek: what the next step is. progress: where the job stands.'),
  title: z.string().describe('2-4 words, e.g. "Torque", "Last shift", "Next"'),
  value: z.string().nullable().describe('The one number or short value to show big, e.g. "70". null if the widget has no single value.'),
  unit: z.string().nullable().describe('Unit for value, e.g. "N·m", "mm", "°C". null if none.'),
  trend: z.enum(['up', 'down', 'flat']).nullable().describe('Only for reading widgets with history; otherwise null.'),
  detail: z.string().nullable().describe('At most 8 words of context, e.g. "bolts 1 → 3 → 2 → 4". null if not needed.'),
});

const SYSTEM = `You turn a maintenance technician's spoken question into ONE glanceable widget for a small monochrome display in their glasses.
They are mid-task with their hands busy. Rules:
- Choose the single widget type that answers the question best. Prefer the smallest answer: one number beats a sentence.
- Use only values present in the JOB CONTEXT. Never invent specs, readings, names or times. If the context doesn't contain the answer, use a note widget with title "Not in job data" and a 2-5 word detail saying what's missing.
- title is 2-4 words. detail is at most 8 words. No full sentences, no greetings, no markdown.
- Use hazard only for genuine safety content from the context or the question (e.g. "is it safe to…").
- The speech-to-text may contain mistakes; interpret it in the context of the current step.`;

let client = null;
const hasKey = () => !!(process.env.ANTHROPIC_API_KEY || process.env.ANTHROPIC_AUTH_TOKEN);

function contextText(ctx) {
  const s = ctx.step, n = ctx.next;
  const lines = [
    `Job: ${ctx.job || 'mount motor to pump with a jaw coupling'}, ${ctx.total} steps.`,
    'All step specs: ' + (ctx.steps || []).map((x, i) => x.spec ? `step ${i + 1} ${x.spec.label} ${x.spec.value} ${x.spec.unit}` : null).filter(Boolean).join('; ') + '.',
    s ? `Current step ${ctx.index + 1}/${ctx.total}: ${s.h}. ${s.d}.` : 'Job complete.',
    s && s.spec ? `Current spec: ${s.spec.label} = ${s.spec.value} ${s.spec.unit}.` : null,
    s && s.hazard ? `Current hazard note: ${s.hazard}.` : null,
    n ? `Next step ${ctx.index + 2}: ${n.h}. ${n.d}.${n.spec ? ` Spec: ${n.spec.label} ${n.spec.value} ${n.spec.unit}.` : ''}` : 'No next step.',
    ctx.readings.length ? 'Live readings: ' + ctx.readings.map((r) => `${r.name} ${r.value} ${r.unit} (${r.trend}, ${r.age_s}s old${r.stale ? ', STALE' : ''})`).join('; ') + '.' : 'No live readings.',
    ctx.findings.length ? 'Open findings from last shift: ' + ctx.findings.map((f) => `${f.by} on ${f.label}: "${f.note}"`).join('; ') + '.' : 'No open findings.',
  ];
  return lines.filter(Boolean).join('\n');
}

async function askClaude(question, ctx) {
  if (!client) client = new Anthropic(); // reads ANTHROPIC_API_KEY (from the environment or .env)
  const response = await client.beta.messages.parse({
    model: MODEL,
    max_tokens: 2000,
    betas: ['server-side-fallback-2026-07-01'],
    fallbacks: 'default', // if a safety classifier declines, the API retries on a fallback model in the same call
    output_config: { effort: 'low', format: betaZodOutputFormat(Widget) }, // low effort: a quick pick, latency matters
    system: SYSTEM,
    messages: [{ role: 'user', content: `JOB CONTEXT\n${contextText(ctx)}\n\nTECHNICIAN SAID: "${question}"` }],
  });
  if (response.stop_reason === 'refusal') throw new Error('declined');
  if (!response.parsed_output) throw new Error(`no widget (stop_reason: ${response.stop_reason})`);
  return response.parsed_output;
}

// ---- Rules engine: the offline fallback. Same widget shape. ----
function askRules(question, ctx) {
  const q = ' ' + question.toLowerCase() + ' ';
  const s = ctx.step, n = ctx.next;
  const has = (re) => re.test(q);
  const W = (type, title, value, unit, detail, trend = null) => ({ type, title, value, unit, trend, detail });
  if (has(/ (safe|danger|hazard|careful|risk|warning) /)) {
    return s && s.hazard ? W('hazard', 'Careful', null, null, s.hazard) : W('note', 'No hazard noted', null, null, 'for this step');
  }
  if (has(/ (next|after this|coming up|then what) /)) {
    return n ? W('next_peek', `Next: step ${ctx.index + 2}`, n.spec ? n.spec.value : null, n.spec ? n.spec.unit : null, n.h) : W('progress', 'Last step', null, null, 'finish and log');
  }
  if (has(/ (how many|left|progress|where am i|how far|remaining) /)) {
    return W('progress', 'Progress', `${Math.min(ctx.index + 1, ctx.total)}/${ctx.total}`, 'steps', s ? s.h : 'done');
  }
  if (has(/ (last shift|note|finding|before me|previous tech|handoff|anyone) /)) {
    const f = ctx.findings[0];
    return f ? W('note', `${f.by}: ${f.label}`, null, null, f.note.slice(0, 48)) : W('note', 'No open findings', null, null, 'from last shift');
  }
  const r = ctx.readings.find((x) => q.includes(' ' + x.key + ' ') || q.includes(x.name.toLowerCase()) || (x.aliases || []).some((a) => q.includes(a)));
  if (r || has(/ (reading|temp|temperature|current|load|vibration|amps|running) /)) {
    const x = r || ctx.readings[0];
    if (!x) return W('note', 'No live data', null, null, 'sensor not connected');
    return W('reading', x.name, x.stale ? '--' : String(x.value), x.unit, x.stale ? `DATA STALE ${x.age_s}s` : `${Math.round(x.age_s)} s ago`, x.stale ? null : x.trend);
  }
  // a spec named in the question (e.g. "torque" while still on step 1) -> that step's number, with where it applies
  const named = (ctx.steps || []).map((x, i) => ({ x, i })).find(({ x }) => x.spec && x.spec.label.toLowerCase().split(/\s+/).some((w) => w.length > 2 && q.includes(' ' + w)));
  if (named) return W('big_number', named.x.spec.label, named.x.spec.value, named.x.spec.unit, named.i === ctx.index ? (named.x.k === 'TORQUE' ? 'bolts 1 → 3 → 2 → 4' : named.x.h) : `at step ${named.i + 1}: ${named.x.h}`);
  if (s && s.spec && has(/ (spec|tight|how much|value|size|what number|setting|nm|newton|this step) /)) {
    return W('big_number', s.spec.label, s.spec.value, s.spec.unit, s.k === 'TORQUE' ? 'bolts 1 → 3 → 2 → 4' : s.h);
  }
  return W('note', 'Not in job data', null, null, 'ask about spec, next, safety, readings');
}

async function ask(question, ctx) {
  const t0 = Date.now();
  if (hasKey()) {
    try { return { widget: await askClaude(question, ctx), source: 'claude', ms: Date.now() - t0 }; }
    catch (e) { return { widget: askRules(question, ctx), source: 'rules', ms: Date.now() - t0, note: `AI unavailable (${e.message}), used rules` }; }
  }
  return { widget: askRules(question, ctx), source: 'rules', ms: Date.now() - t0 };
}

module.exports = { ask, askRules, contextText, Widget, MODEL };
