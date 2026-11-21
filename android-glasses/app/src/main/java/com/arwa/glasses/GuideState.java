package com.arwa.glasses;

/** The glasses own progress; neither a phone connection nor a browser page owns it. */
public final class GuideState {
    public static final String GUIDE_ID = "coupling";
    public static final int TOTAL = 8;
    public boolean started;
    public int step;
    public boolean hidden;
    public long revision;

    public synchronized void restore(boolean started, int step, boolean hidden, long revision) {
        this.started = started;
        this.step = Math.max(0, Math.min(TOTAL, step));
        this.hidden = hidden;
        this.revision = revision;
    }

    public synchronized void command(String command, Integer target) {
        if (!started && !command.equals("start")) throw new IllegalArgumentException("Start the guide first");
        switch (command) {
            case "start": started = true; step = 0; hidden = false; break;
            case "next": step = Math.min(TOTAL, step + 1); hidden = false; break;
            case "back": step = Math.max(0, step - 1); hidden = false; break;
            case "goto":
                if (target == null || target < 0 || target > TOTAL) throw new IllegalArgumentException("Invalid step");
                step = target; hidden = false; break;
            case "restart": step = 0; hidden = false; break;
            case "hide": hidden = true; break;
            case "show": hidden = false; break;
            default: throw new IllegalArgumentException("Unknown guide command");
        }
        revision++;
    }
}
