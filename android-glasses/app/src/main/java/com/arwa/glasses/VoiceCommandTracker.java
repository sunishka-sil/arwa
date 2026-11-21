package com.arwa.glasses;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/** Deduplicates Vosk's changing partial hypotheses against the final result of one utterance. */
final class VoiceCommandTracker {
    static final String GRAMMAR = "[\"next\", \"back\", \"show\", \"hide\", \"[unk]\"]";
    private int fired;

    List<String> accept(String text, boolean finished) {
        List<String> commands = new ArrayList<>();
        for (String word : (text == null ? "" : text).toLowerCase(Locale.US).trim().split("\\s+")) {
            if (word.equals("next") || word.equals("back") || word.equals("show") || word.equals("hide")) commands.add(word);
        }
        List<String> fresh = new ArrayList<>();
        for (int i = fired; i < commands.size(); i++) fresh.add(commands.get(i));
        // A changed guess at an already-fired position must not execute a second action.
        fired = finished ? 0 : Math.max(fired, commands.size());
        return fresh;
    }

    void reset() { fired = 0; }
}
