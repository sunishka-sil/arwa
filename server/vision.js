// Computer vision via Claude: read a photo of a machine panel (or an asset label) into structured JSON.
// The model only *reads*; pass/fail against the recipe is plain code below, so verdicts are auditable.
const Anthropic = require('@anthropic-ai/sdk');
const { z } = require('zod');
const { betaZodOutputFormat } = require('@anthropic-ai/sdk/helpers/beta/zod');

const PanelReading = z.object({
  asset_label: z.string().nullable().describe('Machine or asset ID printed on the unit or tag, e.g. "3A" or "1-RH-V-023A"; null if not visible'),
  recipe: z.string().nullable().describe('Selected recipe/program letter or name shown on the panel; null if not visible'),
  speed_rpm: z.number().nullable().describe('Speed setpoint shown, in rpm; null if not visible'),
  heater_C: z.number().nullable().describe('Heater/temperature setpoint shown, in °C; null if not visible'),
  fault_code: z.string().nullable().describe('Active fault/alarm code shown, e.g. "E-17"; null if none visible'),
  other_readings: z.array(z.object({ name: z.string(), value: z.string() })).describe('Any other clearly legible values'),
  legibility: z.enum(['clear', 'partial', 'unreadable']),
});

const SYSTEM = `You read photos taken by a maintenance technician of an industrial machine's control panel or asset tag.
Report only what is actually legible in the image. Never guess a value you cannot read; use null instead.
Numbers are setpoints or readings as displayed. Ignore reflections, hands and background objects.`;

let client = null;
function getClient() {
  if (!client) client = new Anthropic(); // reads ANTHROPIC_API_KEY or an `ant auth login` profile
  return client;
}

async function readPanel({ base64, mediaType = 'image/jpeg' }) {
  const response = await getClient().beta.messages.parse({
    model: 'claude-opus-5-5',
    max_tokens: 2000,
    betas: ['server-side-fallback-2026-07-01'],
    fallbacks: 'default', // if a safety classifier declines, the API retries on a fallback model in the same call
    output_config: { effort: 'low', format: betaZodOutputFormat(PanelReading) }, // low effort: this is a quick read, speed matters
    system: SYSTEM,
    messages: [{
      role: 'user',
      content: [
        { type: 'image', source: { type: 'base64', media_type: mediaType, data: base64 } },
        { type: 'text', text: 'Read this panel.' },
      ],
    }],
  });
  if (response.stop_reason === 'refusal') throw new Error('Vision request was declined');
  if (!response.parsed_output) throw new Error(`Could not parse panel reading (stop_reason: ${response.stop_reason})`);
  return response.parsed_output;
}

// Deterministic comparison against the recipe spec.
function checkAgainstRecipe(reading, spec) {
  const tol = spec.tolerance || {};
  const checks = [];
  const num = (name, label, unit) => {
    const actual = reading[name];
    const ok = actual != null && Math.abs(actual - spec[name]) <= (tol[name] ?? 0);
    checks.push({ name, label, expected: `${spec[name]} ${unit}`, actual: actual == null ? 'not readable' : `${actual} ${unit}`, ok });
  };
  checks.push({ name: 'recipe', label: 'Recipe', expected: spec.recipe, actual: reading.recipe ?? 'not readable',
    ok: reading.recipe != null && reading.recipe.trim().toUpperCase().endsWith(spec.recipe.toUpperCase()) });
  num('speed_rpm', 'Speed', 'rpm');
  num('heater_C', 'Heater', '°C');
  if (reading.fault_code && !/^(none|0|e-?0)$/i.test(reading.fault_code)) checks.push({ name: 'fault', label: 'Fault', expected: 'none', actual: reading.fault_code, ok: false });
  return { ok: checks.every((c) => c.ok), checks };
}

module.exports = { readPanel, checkAgainstRecipe, PanelReading };
