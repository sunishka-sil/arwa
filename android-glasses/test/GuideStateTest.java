package com.arwa.glasses;

/** Run with javac/java, without an Android device or test framework. */
public final class GuideStateTest {
    public static void main(String[] args) {
        GuideState state = new GuideState();
        rejects(() -> state.command("next", null));
        state.command("start", null);
        check(state.started && state.step == 0 && !state.hidden, "start");
        state.command("back", null);
        check(state.step == 0, "back is bounded");
        state.command("hide", null);
        check(state.hidden, "hide");
        state.command("next", null);
        check(state.step == 1 && !state.hidden, "next brings the view back");
        for (int i = 0; i < 20; i++) state.command("next", null);
        check(state.step == GuideState.TOTAL, "completion is bounded");
        state.command("back", null);
        check(state.step == GuideState.TOTAL - 1, "review after completion");
        long revision = state.revision;
        rejects(() -> state.command("goto", -1));
        rejects(() -> state.command("goto", GuideState.TOTAL + 1));
        rejects(() -> state.command("bogus", null));
        check(state.revision == revision, "invalid commands do not change progress");
        GuideState restored = new GuideState();
        restored.restore(state.started, state.step, state.hidden, state.revision);
        check(restored.step == state.step && restored.revision == state.revision && restored.started, "restore progress after restart");
        restored.command("start", null);
        check(restored.step == 0 && restored.revision > revision, "restart preserves command ordering");
        restored.restore(true, 1000, true, 10);
        check(restored.step == GuideState.TOTAL, "bad persisted position is bounded");
        System.out.println("Guide state checks passed");
    }
    private static void check(boolean value, String name) { if (!value) throw new AssertionError(name); }
    private static void rejects(Runnable operation) {
        try { operation.run(); } catch (IllegalArgumentException expected) { return; }
        throw new AssertionError("Expected rejection");
    }
}
