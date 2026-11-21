package com.arwa.glasses;

import java.util.Arrays;
import java.util.List;

public final class VoiceCommandTrackerTest {
    public static void main(String[] args) {
        VoiceCommandTracker tracker = new VoiceCommandTracker();
        matches(tracker.accept("next", false), "next");
        matches(tracker.accept("next", false));
        matches(tracker.accept("next", true));
        matches(tracker.accept("next", false), "next");
        matches(tracker.accept("next next", false), "next");
        matches(tracker.accept("next next", true));
        matches(tracker.accept("next", false), "next");
        matches(tracker.accept("back", false)); // recognizer correction must not execute another action
        matches(tracker.accept("back", true));
        matches(tracker.accept("[unk] [unk]", true));
        matches(tracker.accept("hide", true), "hide");
        matches(tracker.accept("SHOW", true), "show");
        matches(tracker.accept("restart delete reset", true));
        matches(tracker.accept("back", false), "back");
        tracker.reset();
        matches(tracker.accept("back", true), "back");
        matches(tracker.accept(null, true));
        System.out.println("Voice recognition deduplication checks passed");
    }
    private static void matches(List<String> actual, String... expected) {
        if (!actual.equals(Arrays.asList(expected))) throw new AssertionError(actual + " != " + Arrays.toString(expected));
    }
}
