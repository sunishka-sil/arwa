//
//  FeatureViewControllers.swift
//  MLDemo
//
//  Feature screens. SDK calls are the same ones the vendor demo made.
//

import UIKit
import MLVisionM6SDK
import QuickLook
import Photos

// MARK: - Voice assistant

final class AssistantViewController: FormViewController {
    private var interceptOn = false
    private var phrase = "The weather is nice today"
    private var results: [String] = []

    override func viewDidLoad() {
        title = "Voice Assistant"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        observe(.glassesDidChange)

        // Intent domains whose results come back to this app.
        MLVisionM6SDKManager.registDomain(["aigc", "settings", "global"])
        MLVisionM6SDKManager.assistantResultBlock { [weak self] type, data in
            let line = "\(Self.name(of: type)): \(data)"
            appLog("Assistant \(line)")
            DispatchQueue.main.async {
                guard let self else { return }
                self.results.insert(line, at: 0)
                self.results = Array(self.results.prefix(30))
                self.reload()
            }
        }
        MLVisionM6SDKManager.onEngineStateBlock { state, extra in
            appLog("Assistant engine: \(state) \(extra)")
        }
    }

    override func buildSections() -> [FormSection] {
        var resultRows: [FormRow] = results.isEmpty
            ? [.text("Speech and intents recognized by the assistant appear here.", secondary: true)]
            : results.map { .text($0, monospaced: true) }
        if !results.isEmpty {
            resultRows.append(.action(title: "Clear", symbol: "trash", destructive: true, handler: { [weak self] in
                self?.results = []
                self?.reload()
            }))
        }

        let connected = GlassesSession.shared.isConnected
        return [glassesRequiredSection()].compactMap { $0 } + [
            FormSection(header: "Assistant",
                        footer: "Intercept is off by default. While it’s on, recognized speech is handed to this app.",
                        rows: [
                .action(title: "Wake Assistant", symbol: "waveform.circle", enabled: connected, handler: {
                    appLog("Assistant: wake")
                    MLVisionM6SDKManager.startAssistant(.ASR, tts: "Hello", modelId: "namibox")
                }),
                .action(title: "Exit Assistant", symbol: "xmark.circle", enabled: connected, handler: {
                    appLog("Assistant: exit")
                    MLVisionM6SDKManager.stopAssistant()
                }),
                .toggle(title: "Intercept Speech", symbol: "arrow.down.to.line", isOn: interceptOn, enabled: connected, onChange: { [weak self] on in
                    // The SDK flips this setting on every call.
                    self?.interceptOn = on
                    appLog("Assistant: intercept \(on ? "on" : "off")")
                    MLVisionM6SDKManager.switchAsrIntercept()
                }),
            ]),
            FormSection(header: "Speak on Glasses", rows: [
                .textField(placeholder: "Text to speak", text: phrase, onChange: { [weak self] in self?.phrase = $0 }),
                .action(title: "Speak", symbol: "speaker.wave.2", enabled: connected, handler: { [weak self] in
                    guard let self else { return }
                    self.view.endEditing(true)
                    let text = self.phrase.trimmingCharacters(in: .whitespacesAndNewlines)
                    guard !text.isEmpty else { return }
                    appLog("Assistant: speak “\(text)”")
                    MLVisionM6SDKManager.playTTS(forAssistant: .exit, text: text, modelId: "namibox")
                }),
                .action(title: "Stop Speaking", symbol: "stop.circle", enabled: connected, handler: {
                    MLVisionM6SDKManager.stopTTSForAssistant()
                }),
            ]),
            FormSection(header: "Results", rows: resultRows),
        ]
    }

    private static func name(of type: MLVisionAssistantResultType) -> String {
        switch type {
        case .typeASR: return "Speech"
        case .typeNLU: return "Intent"
        case .typeSpeakable: return "Speakable"
        case .typeCmd: return "Command"
        case .typPpageItemClick: return "Item tap"
        case .typeError: return "Error"
        @unknown default: return "Result \(type.rawValue)"
        }
    }
}

// MARK: - Camera & recording on the glasses

final class CameraViewController: FormViewController {
    // App IDs from the SDK: 25 = camera, 26 = audio, 28 = video.
    override func viewDidLoad() {
        title = "Camera"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        observe(.glassesDidChange)
    }

    override func buildSections() -> [FormSection] {
        let on = GlassesSession.shared.isConnected
        return [glassesRequiredSection()].compactMap { $0 } + [
            FormSection(header: "Photo", rows: [
                .action(title: "Take Photo", symbol: "camera", enabled: on, handler: {
                    Self.open(25, ["action": "com.mlaixr.camera.takephoto", "CaptureBack": true])
                }),
                .action(title: "Exit Camera", symbol: "xmark.circle", enabled: on, handler: {
                    Self.exit(26, ["action": "com.mlaixr.camera.video.stop"])
                }),
            ]),
            FormSection(header: "Video", rows: [
                .action(title: "Start Video", symbol: "video", enabled: on, handler: {
                    Self.open(28, ["action": "com.mlaixr.camera.video.start", "CaptureBack": true])
                }),
                .action(title: "Stop Video", symbol: "stop.circle", enabled: on, handler: {
                    Self.exit(28, ["action": "com.mlaixr.camera.video.stop"])
                }),
            ]),
            FormSection(header: "Audio",
                        footer: "Photos, videos and recordings are saved on the glasses. Use File Sync on the home screen to download them.",
                        rows: [
                .action(title: "Start Audio Recording", symbol: "mic", enabled: on, handler: {
                    Self.open(26, ["action": "com.mlaixr.record.action.start_default", "CaptureBack": true])
                }),
                .action(title: "Stop Audio Recording", symbol: "stop.circle", enabled: on, handler: {
                    Self.exit(26, ["action": "com.mlaixr.record.action.stop"])
                }),
            ]),
        ]
    }

    private static func open(_ app: Int, _ ext: [String: Any]) {
        appLog("Open glasses app \(app): \(ext)")
        MLVisionM6SDKManager.openApp(app, ext: ext)
    }

    private static func exit(_ app: Int, _ ext: [String: Any]) {
        appLog("Exit glasses app \(app): \(ext)")
        MLVisionM6SDKManager.exitApp(app, ext: ext)
    }
}

// MARK: - Live interpreting

final class InterpretingViewController: FormViewController {
    private var isRunning = false
    private var isMuted = false
    private var lines: [(source: String, translation: String)] = []
    private var heardNothing = false
    private var silenceCheck: DispatchWorkItem?
    /// The sentence in progress (from the SDK's log), replaced as Azure refines it.
    private var partial: (source: String, translation: String)?
    /// Azure keeps sending the last sentence briefly after Stop; keep listening until then.
    private var acceptLateUntil: Date?
    private var lateCommit: DispatchWorkItem?
    /// Stop was tapped; recognition keeps running briefly so speech already captured still comes through.
    private var isFinishing = false
    private var finishWork: DispatchWorkItem?
    /// Azure returns text 4–7 seconds behind the audio from the glasses.
    private static let finishDelay: Double = 5

    override func viewDidLoad() {
        title = "Live Interpreting"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        observe(.glassesDidChange) { [weak self] _ in
            guard let self else { return }
            // Interpreting listens through the glasses; if they drop, end the session.
            if self.isRunning && !GlassesSession.shared.isConnected {
                self.finishWork?.cancel()
                self.finishStopping()
            } else {
                self.reload()
            }
        }
        observe(.interpretingPartial) { [weak self] note in
            guard let self else { return }
            let late = self.acceptLateUntil.map { $0 > Date() } ?? false
            guard self.isRunning || late else { return }
            let source = note.userInfo?["source"] as? String ?? ""
            let translation = note.userInfo?["translation"] as? String ?? ""
            guard !source.isEmpty else { return }
            self.partial = (source, translation)
            self.heardNothing = false
            self.reload()
            self.scrollToLatest()
        }
    }

    private func scrollToLatest() {
        let section = 2
        guard tableView.numberOfSections > section else { return }
        let rows = tableView.numberOfRows(inSection: section)
        guard rows > 0 else { return }
        tableView.scrollToRow(at: IndexPath(row: rows - 1, section: section), at: .bottom, animated: true)
    }

    private func commitPartial() {
        if let partial { lines.append(partial) }
        partial = nil
    }

    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        // Leaving the screen stops interpreting without saving (as in the vendor demo).
        if isMovingFromParent {
            finishWork?.cancel()
            MLVisionM6OCSDK.stopSimulInterpreting(isEndAndSave: false)
        }
    }

    override func buildSections() -> [FormSection] {
        let source = MLVisionM6OCSDK.getSourceLanguage()
        let target = MLVisionM6OCSDK.getTargetLanguage()
        let sources = MLVisionM6OCSDK.getSupportedSourceLanguages()
        let targets = MLVisionM6OCSDK.getSupportedTargetLanguages()

        var shown = lines
        if let partial { shown.append(partial) }
        let sameLanguage = !source.isEmpty && source.prefix(2).lowercased() == target.prefix(2).lowercased()
        let transcriptRows: [FormRow] = shown.isEmpty
            ? [.text(!isRunning ? "Translations appear here."
                     : heardNothing ? "Nothing recognized yet. Check that “Speak in” matches the language you’re speaking. With glasses connected, the app listens through the glasses’ microphone; disconnect them to use this phone’s microphone instead."
                     : "Listening…", secondary: true)]
            : shown.map { .item(title: $0.translation.isEmpty ? $0.source : $0.translation,
                                subtitle: $0.translation.isEmpty || $0.translation == $0.source ? nil : $0.source) }

        return [
            FormSection(header: "Languages", rows: [
                .menu(title: "Speak in", symbol: "mic", selected: source,
                      options: sources.isEmpty ? [source] : sources, display: Self.languageName,
                      enabled: !isRunning, onSelect: { [weak self] code in
                    appLog("Interpreting source → \(code)")
                    SpeechLanguages.setSource(code)
                    self?.reload()
                }),
                .menu(title: "Translate to", symbol: "character.bubble", selected: target,
                      options: targets.isEmpty ? [target] : targets, display: Self.languageName,
                      enabled: !isRunning, onSelect: { [weak self] code in
                    appLog("Interpreting target → \(code)")
                    SpeechLanguages.setTarget(code)
                    self?.reload()
                }),
                .action(title: "Swap Languages", symbol: "arrow.left.arrow.right", enabled: !isRunning, handler: { [weak self] in
                    SpeechLanguages.swap()
                    appLog("Interpreting languages swapped")
                    self?.reload()
                }),
            ]),
            FormSection(header: "Session",
                        footer: isFinishing ? "Catching up on what you just said…"
                            : isRunning ? "Text appears a few seconds behind your speech. Stop and Save keeps a text and audio copy on this phone."
                            : !GlassesSession.shared.isConnected ? "Connect your glasses to start. Interpreting listens through their microphone." : nil,
                        rows: [
                .action(title: isFinishing ? "Finishing…" : isRunning ? "Stop and Save" : "Start Interpreting",
                        symbol: isRunning ? "stop.circle.fill" : "play.circle.fill",
                        destructive: isRunning, enabled: !isFinishing && (isRunning || GlassesSession.shared.isConnected),
                        handler: { [weak self] in self?.toggleRunning() }),
                .toggle(title: "Mute Spoken Translation", symbol: "speaker.slash", isOn: isMuted, onChange: { [weak self] on in
                    self?.isMuted = on
                    MLVisionM6OCSDK.muteTts(mute: on)
                }),
            ]),
            FormSection(header: "Transcript",
                        footer: sameLanguage ? "“Speak in” and “Translate to” are the same language, so the translation repeats what you say." : nil,
                        rows: transcriptRows),
        ]
    }

    private func toggleRunning() {
        if isRunning {
            guard !isFinishing else { return }
            isFinishing = true
            appLog("Interpreting finishing")
            reload()
            let work = DispatchWorkItem { [weak self] in self?.finishStopping() }
            finishWork = work
            DispatchQueue.main.asyncAfter(deadline: .now() + Self.finishDelay, execute: work)
            return
        }
        start()
    }

    private func finishStopping() {
        isFinishing = false
        do {
            MLVisionM6OCSDK.setSimulInterpretingAudioPathBlock { textPath, audioPath in
                appLog("Interpreting saved: text \(textPath), audio \(audioPath)")
            }
            MLVisionM6OCSDK.stopSimulInterpreting(isEndAndSave: true)
            appLog("Interpreting stopped")
            isRunning = false
            // Keep the sentence in progress: Azure sends its last refinements a few seconds after Stop.
            acceptLateUntil = Date().addingTimeInterval(4)
            lateCommit?.cancel()
            let commit = DispatchWorkItem { [weak self] in
                self?.acceptLateUntil = nil
                self?.commitPartial()
                self?.reload()
            }
            lateCommit = commit
            DispatchQueue.main.asyncAfter(deadline: .now() + 4, execute: commit)
            heardNothing = false
            silenceCheck?.cancel()
        }
        reload()
    }

    private func start() {
        do {
            lines = []
            partial = nil
            lateCommit?.cancel()
            acceptLateUntil = nil
            MLVisionM6OCSDK.startSimulInterpreting()
            MLVisionM6OCSDK.setSimulInterpretingResultBlock { [weak self] result in
                let source = "\(result["src"] ?? "")"
                let translation = "\(result["dst"] ?? "")"
                appLog("Interpreting: \(source) → \(translation)")
                DispatchQueue.main.async {
                    guard let self else { return }
                    self.partial = nil   // the finished sentence replaces the one in progress
                    self.lines.append((source, translation))
                    self.reload()
                    let last = IndexPath(row: self.lines.count - 1, section: 2)
                    if self.tableView.numberOfSections > 2, self.tableView.numberOfRows(inSection: 2) > last.row {
                        self.tableView.scrollToRow(at: last, at: .bottom, animated: true)
                    }
                }
            }
            appLog("Interpreting started")
            isRunning = true
            heardNothing = false
            let started = Date()
            silenceCheck?.cancel()
            let check = DispatchWorkItem { [weak self] in
                guard let self, self.isRunning, self.lines.isEmpty, self.partial == nil else { return }
                appLog("Interpreting: nothing recognized after \(Int(Date().timeIntervalSince(started))) s")
                self.heardNothing = true
                self.reload()
            }
            silenceCheck = check
            DispatchQueue.main.asyncAfter(deadline: .now() + 15, execute: check)
        }
        reload()
    }

    static func languageName(_ code: String) -> String {
        guard !code.isEmpty else { return "Choose" }
        return Locale.current.localizedString(forIdentifier: code) ?? code
    }
}

// MARK: - Transcribe bundled sample files

final class TranscribeViewController: FormViewController {
    private struct Sample {
        let file: String
        var status = "Not started"
        var text = ""
        var isRunning = false
    }

    private var samples = ["11111", "22222", "33333"].map { Sample(file: $0) }

    override func viewDidLoad() {
        title = "Transcribe Samples"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never

        // Partial text as it arrives.
        MLVisionM6OCSDK.setTranscribeChangedBlock { [weak self] filePath, content, error, _, _ in
            DispatchQueue.main.async {
                guard let self, let index = self.index(for: filePath) else { return }
                if let error {
                    appLog("Transcription segment error (\(filePath)): \(error.localizedDescription)")
                    return
                }
                self.samples[index].text += (self.samples[index].text.isEmpty ? "" : " ") + content
                self.reload()
            }
        }
        // Final result.
        MLVisionM6OCSDK.setTranscribeSuccessBlock { [weak self] filePath, content, error, start, end in
            DispatchQueue.main.async {
                guard let self, let index = self.index(for: filePath) else { return }
                self.samples[index].isRunning = false
                if let error {
                    appLog("Transcription failed (\(filePath)): \(error.localizedDescription)")
                    self.samples[index].status = "Failed: \(error.localizedDescription)"
                } else {
                    appLog("Transcription done (\(filePath)), \(start)–\(end) ms")
                    self.samples[index].status = "Done"
                    self.samples[index].text = content
                }
                self.reload()
            }
        }
        MLVisionM6OCSDK.setTranscribeProgressBlock { [weak self] filePath, current, total in
            DispatchQueue.main.async {
                guard let self, let index = self.index(for: filePath) else { return }
                self.samples[index].status = "Transcribing \(current) of \(total)"
                self.reload()
            }
        }
    }

    override func buildSections() -> [FormSection] {
        samples.enumerated().map { index, sample in
            var rows: [FormRow] = [
                .value(title: "\(sample.file).wav", value: sample.status, symbol: "waveform"),
                .action(title: sample.isRunning ? "Transcribing…" : "Transcribe", symbol: "text.bubble",
                        enabled: !sample.isRunning, handler: { [weak self] in self?.start(index) }),
            ]
            if !sample.text.isEmpty { rows.append(.text(sample.text)) }
            return FormSection(header: "Sample \(index + 1)",
                               footer: index == samples.count - 1 ? "Sample recordings bundled with the demo app." : nil,
                               rows: rows)
        }
    }

    private func start(_ index: Int) {
        guard let path = Bundle.main.path(forResource: samples[index].file, ofType: "wav") else {
            showAlert(title: "File Missing", message: "\(samples[index].file).wav isn’t in the app bundle.")
            return
        }
        samples[index].isRunning = true
        samples[index].status = "Starting…"
        samples[index].text = ""
        reload()
        appLog("Transcribing \(path)")
        MLVisionM6OCSDK.startTranscribe(filePath: path)
    }

    private func index(for filePath: String) -> Int? {
        samples.firstIndex { filePath.contains($0.file) }
    }
}

// MARK: - Record & transcribe

final class RecordViewController: FormViewController {
    private let player = MLAudioPlayerManager()
    private var isRecording = false
    private var transcript = ""
    private var hasAudio = false
    private var isPlaying = false
    private var isFinishing = false
    private var finishWork: DispatchWorkItem?
    /// The phrase in progress, from the SDK's log (it only reports finished sentences itself).
    private var partial = ""
    /// Recording recognizes speech in the interpreting *target* language, so while recording the target is set
    /// to the chosen language and restored afterwards.
    private var savedTarget: String?

    override func viewDidLoad() {
        title = "Record and Transcribe"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        navigationItem.rightBarButtonItem = UIBarButtonItem(
            title: "Recordings", primaryAction: UIAction { [weak self] _ in self?.push(RecordingsViewController()) })

        MLVisionM6SDKManager.setAudioRecordCompleteBlockWithFile { [weak self] dict in
            appLog("Recording saved: \(dict)")
            guard let localPath = dict["localPath"] as? String, !localPath.isEmpty else { return }
            DispatchQueue.main.async { self?.loadAudio(localPath: localPath) }
        }
        MLVisionM6SDKManager.setAudioRecordSummaryBlockWithFile { dict in
            appLog("Recording summarized: \(dict["title"] ?? "") — \(dict["summary"] ?? "")")
        }
        MLVisionM6SDKManager.setAudioRecordRecognizingBlock { [weak self] text in
            DispatchQueue.main.async {
                guard let self else { return }
                self.transcript = Self.merge(self.transcript, text)
                self.partial = ""
                self.reload()
            }
        }
        observe(.glassesDidChange) { [weak self] _ in
            guard let self else { return }
            if self.isRecording && !GlassesSession.shared.isConnected {
                self.finishWork?.cancel()
                self.isFinishing = false
                self.isRecording = false
                appLog("Recording stopped: glasses disconnected")
                MLVisionM6SDKManager.stopAudioRecording()
                self.restoreTargetLanguage()
            }
            self.reload()
        }
        observe(.interpretingPartial) { [weak self] note in
            guard let self, self.isRecording else { return }
            let next = note.userInfo?["source"] as? String ?? ""
            guard !next.isEmpty else { return }
            // Recording sends short, overlapping phrases. When a phrase isn't a continuation of the last one,
            // keep the last one and start a new phrase.
            if !self.partial.isEmpty && !Self.continues(self.partial, with: next) {
                self.transcript = Self.merge(self.transcript, self.partial)
            }
            self.partial = next
            self.reload()
        }
        player.finishedBlock = { [weak self] in
            guard let self else { return }
            self.isPlaying = false
            self.player.seek(to: 0)
            self.reload()
        }
    }

    deinit {
        MLVisionM6SDKManager.stopAudioRecording()
        if let target = savedTarget { MLVisionM6OCSDK.setTargetLanguage(language: target) }
    }

    override func buildSections() -> [FormSection] {
        [
            FormSection(header: nil, footer: "Recording listens for this language. It’s shared with Live Interpreting’s “Speak in”.", rows: [
                .menu(title: "Language", symbol: "globe", selected: MLVisionM6OCSDK.getSourceLanguage(),
                      options: {
                          let all = MLVisionM6OCSDK.getSupportedSourceLanguages()
                          return all.isEmpty ? [MLVisionM6OCSDK.getSourceLanguage()] : all
                      }(),
                      display: InterpretingViewController.languageName,
                      enabled: !isRecording, onSelect: { [weak self] code in
                    appLog("Recording language → \(code)")
                    SpeechLanguages.setSource(code)
                    self?.reload()
                }),
            ]),
            FormSection(header: nil,
                        footer: isFinishing ? "Catching up on what you just said…"
                            : !isRecording && !GlassesSession.shared.isConnected ? "Connect your glasses to record. Recording uses their microphone."
                            : "Text appears a few seconds behind your speech. When you stop, the recording is summarized and saved under Recordings.",
                        rows: [
                .action(title: isFinishing ? "Finishing…" : isRecording ? "Stop Recording" : "Start Recording",
                        symbol: isRecording ? "stop.circle.fill" : "record.circle",
                        destructive: isRecording, enabled: !isFinishing && (isRecording || GlassesSession.shared.isConnected),
                        handler: { [weak self] in self?.toggleRecording() }),
            ]),
            FormSection(header: "Live Transcript", rows: [
                liveText.isEmpty
                    ? .text(isRecording ? "Listening…" : "The transcript appears here while you record.", secondary: true)
                    : .text(liveText),
            ]),
            FormSection(header: "Playback", rows: [
                .action(title: isPlaying ? "Pause" : "Play Last Recording",
                        symbol: isPlaying ? "pause.fill" : "play.fill",
                        enabled: hasAudio, handler: { [weak self] in self?.togglePlayback() }),
            ]),
        ]
    }

    private var liveText: String {
        Self.merge(transcript, partial)
    }

    private static func words(_ text: String) -> [String] {
        text.split(whereSeparator: { $0.isWhitespace }).map(String.init)
    }

    private static func normalized(_ word: String) -> String {
        word.lowercased().trimmingCharacters(in: .punctuationCharacters)
    }

    /// Whether `next` refines `previous` (same phrase, more words or a correction of the last word).
    private static func continues(_ previous: String, with next: String) -> Bool {
        let old = words(previous).map(normalized), new = words(next).map(normalized)
        guard let first = old.first, let newFirst = new.first else { return true }
        return first == newFirst || new.count >= old.count && Array(new.prefix(max(old.count - 1, 1))) == Array(old.prefix(max(old.count - 1, 1)))
    }

    /// Appends `addition` to `text`, dropping words where the end of `text` overlaps the start of `addition`.
    static func merge(_ text: String, _ addition: String) -> String {
        let base = words(text), extra = words(addition)
        guard !base.isEmpty else { return extra.joined(separator: " ") }
        guard !extra.isEmpty else { return base.joined(separator: " ") }
        let lowerBase = base.map(normalized), lowerExtra = extra.map(normalized)
        var overlap = 0
        for k in stride(from: min(base.count, extra.count), through: 1, by: -1)
        where Array(lowerBase.suffix(k)) == Array(lowerExtra.prefix(k)) {
            overlap = k
            break
        }
        return (base + extra.dropFirst(overlap)).joined(separator: " ")
    }

    private func useRecordingLanguage() -> Bool {
        let source = MLVisionM6OCSDK.getSourceLanguage()
        let target = MLVisionM6OCSDK.getTargetLanguage()
        guard !source.isEmpty, source != target else { return false }
        let targets = MLVisionM6OCSDK.getSupportedTargetLanguages()
        let match = targets.first { $0 == source }
            ?? targets.first { $0.prefix(2).lowercased() == source.prefix(2).lowercased() }
            ?? source
        savedTarget = target
        appLog("Recording in \(match) (interpreting target \(target) restored afterwards)")
        MLVisionM6OCSDK.setTargetLanguage(language: match)
        return true
    }

    private func restoreTargetLanguage() {
        guard let target = savedTarget else { return }
        savedTarget = nil
        MLVisionM6OCSDK.setTargetLanguage(language: target)
    }

    private func toggleRecording() {
        if isRecording {
            // Recognition runs a few seconds behind; stopping right away would drop the last words.
            guard !isFinishing else { return }
            isFinishing = true
            appLog("Recording finishing")
            let work = DispatchWorkItem { [weak self] in
                guard let self else { return }
                self.isFinishing = false
                self.isRecording = false
                appLog("Recording stopped")
                MLVisionM6SDKManager.stopAudioRecording()
                self.transcript = Self.merge(self.transcript, self.partial)
                self.partial = ""
                self.restoreTargetLanguage()
                self.reload()
            }
            finishWork = work
            DispatchQueue.main.asyncAfter(deadline: .now() + 5, execute: work)
        } else {
            isRecording = true
            transcript = ""
            partial = ""
            // Changing a language restarts the SDK's recognizers; give them a moment before recording.
            let delay = useRecordingLanguage() ? 1.0 : 0
            DispatchQueue.main.asyncAfter(deadline: .now() + delay) { [weak self] in
                guard let self, self.isRecording else { return }
                appLog("Recording started")
                MLVisionM6SDKManager.startAudioRecording()
            }
        }
        reload()
    }

    private func togglePlayback() {
        isPlaying.toggle()
        isPlaying ? player.play() : player.pause()
        reload()
    }

    private func loadAudio(localPath: String) {
        // The SDK reports an absolute path; resolve it against this app's Documents folder.
        let documents = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)[0]
        let relative = localPath.contains("Documents/") ? (localPath.components(separatedBy: "Documents/").last ?? "") : localPath
        let url = URL(fileURLWithPath: relative.hasPrefix("/") ? relative : documents + "/" + relative)
        hasAudio = player.loadAudio(url: url)
        appLog(hasAudio ? "Audio loaded: \(url.path)" : "Couldn’t load audio: \(url.path)")
        reload()
    }
}

final class RecordingsViewController: FormViewController {
    private var records: [[String: Any]] = []
    private var hasLoaded = false

    override func viewDidLoad() {
        title = "Recordings"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        navigationItem.rightBarButtonItem = UIBarButtonItem(
            title: "Delete All", primaryAction: UIAction { [weak self] _ in self?.confirmDeleteAll() })
        navigationItem.rightBarButtonItem?.tintColor = Theme.danger

        // Refresh the list when a summary finishes.
        MLVisionM6SDKManager.setAudioRecordSummaryBlockWithFile { [weak self] dict in
            appLog("Recording summarized: \(dict["title"] ?? "")")
            DispatchQueue.main.async { self?.load() }
        }
        load()
    }

    private func load() {
        MLVisionM6SDKManager.loadAudioRecordsBlock { [weak self] array in
            DispatchQueue.main.async {
                guard let self else { return }
                self.records = array as? [[String: Any]] ?? []
                self.hasLoaded = true
                self.navigationItem.rightBarButtonItem?.isEnabled = !self.records.isEmpty
                self.reload()
            }
        }
    }

    override func buildSections() -> [FormSection] {
        guard hasLoaded else { return [FormSection(rows: [.text("Loading…", secondary: true)])] }
        guard !records.isEmpty else { return [FormSection(rows: [.text("No recordings yet.", secondary: true)])] }
        let rows: [FormRow] = records.map { record in
            let name = record["fileName"] as? String ?? "Recording"
            let created = record["createTime"] as? String ?? ""
            let done = record["isFinished"] as? Bool ?? false
            let uuid = record["uuid"] as? String
            return .item(title: name,
                         subtitle: [created, done ? "Summarized" : "Summarizing…"].filter { !$0.isEmpty }.joined(separator: " · "),
                         symbol: "doc.text", disclosure: true,
                         onTap: { [weak self] in self?.push(RecordingDetailViewController(record: record)) },
                         onDelete: uuid.map { id in { [weak self] in
                             appLog("Deleting recording \(id)")
                             _ = MLVisionM6OCSDK.deleteAudioRecord(uuid: id)
                             self?.load()
                         } })
        }
        return [FormSection(footer: "Swipe left on a recording to delete it.", rows: rows)]
    }

    private func confirmDeleteAll() {
        confirm(title: "Delete All Recordings?", message: "This can’t be undone.", actionTitle: "Delete All") { [weak self] in
            appLog("Deleting all recordings")
            _ = MLVisionM6OCSDK.deleteAllAudioRecords()
            self?.load()
        }
    }
}

final class RecordingDetailViewController: FormViewController {
    private let record: [String: Any]

    init(record: [String: Any]) {
        self.record = record
        super.init()
    }

    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    override func viewDidLoad() {
        title = record["fileName"] as? String ?? "Recording"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
    }

    override func buildSections() -> [FormSection] {
        let summary = record["summary"] as? String ?? ""
        let transcript = record["originText"] as? String ?? ""
        return [
            FormSection(header: "Summary", rows: [
                summary.isEmpty ? .text("Not summarized yet.", secondary: true) : .text(summary),
            ]),
            FormSection(header: "Transcript", rows: [
                transcript.isEmpty ? .text("No transcript.", secondary: true) : .text(transcript),
            ]),
            FormSection(header: "Details", rows: [
                .value(title: "Created", value: record["createTime"] as? String ?? "—"),
                .value(title: "File", value: record["fileName"] as? String ?? "—"),
            ]),
        ]
    }
}

// MARK: - File sync

final class FilesViewController: FormViewController, QLPreviewControllerDataSource {
    private let session = GlassesSession.shared
    private var previewItems: [URL] = []

    override func viewDidLoad() {
        title = "File Sync"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        observe(.glassesDidChange)
    }

    // MARK: Files on this phone

    /// Where the SDK saves photos and videos it downloads from the glasses.
    static var downloadsFolder: URL {
        FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)[0]
            .appendingPathComponent("MLMultiMediaDirectory", isDirectory: true)
    }

    /// Downloaded photos and videos, newest first (thumbnails left out).
    static func localDownloads() -> [URL] {
        let keys: [URLResourceKey] = [.contentModificationDateKey, .fileSizeKey]
        let files = (try? FileManager.default.contentsOfDirectory(at: downloadsFolder, includingPropertiesForKeys: keys)) ?? []
        return files
            .filter { !$0.lastPathComponent.hasPrefix("cover_pic_") && !$0.lastPathComponent.hasPrefix(".") }
            .sorted { captureDate(of: $0) > captureDate(of: $1) }
    }

    /// The glasses name files after the capture time in milliseconds.
    static func captureDate(of url: URL) -> Date {
        let stem = url.deletingPathExtension().lastPathComponent
        if let ms = Double(stem), ms > 1_000_000_000_000 { return Date(timeIntervalSince1970: ms / 1000) }
        return (try? url.resourceValues(forKeys: [.contentModificationDateKey]).contentModificationDate) ?? .distantPast
    }

    private static func isVideo(_ url: URL) -> Bool { ["mp4", "mov"].contains(url.pathExtension.lowercased()) }

    private func preview(_ url: URL) {
        previewItems = Self.localDownloads()
        let controller = QLPreviewController()
        controller.dataSource = self
        controller.currentPreviewItemIndex = previewItems.firstIndex(of: url) ?? 0
        present(controller, animated: true)
    }

    func numberOfPreviewItems(in controller: QLPreviewController) -> Int { previewItems.count }
    func previewController(_ controller: QLPreviewController, previewItemAt index: Int) -> QLPreviewItem {
        previewItems[index] as NSURL
    }

    private func deleteLocal(_ url: URL) {
        let cover = url.deletingLastPathComponent()
            .appendingPathComponent("cover_pic_" + url.deletingPathExtension().lastPathComponent + ".jpg")
        try? FileManager.default.removeItem(at: url)
        try? FileManager.default.removeItem(at: cover)
        appLog("Deleted \(url.lastPathComponent) from this phone")
        reload()
    }

    private func saveAllToPhotos() {
        let files = Self.localDownloads()
        guard !files.isEmpty else { return }
        PHPhotoLibrary.requestAuthorization(for: .addOnly) { [weak self] status in
            DispatchQueue.main.async {
                guard status == .authorized || status == .limited else {
                    self?.showAlert(title: "Photos Access Needed",
                                    message: "Allow this app to add photos in Settings, then try again.")
                    return
                }
                PHPhotoLibrary.shared().performChanges({
                    for url in files {
                        let request = PHAssetCreationRequest.forAsset()
                        request.addResource(with: Self.isVideo(url) ? .video : .photo, fileURL: url, options: nil)
                        request.creationDate = Self.captureDate(of: url)
                    }
                }) { success, error in
                    DispatchQueue.main.async {
                        appLog(success ? "Saved \(files.count) file(s) to Photos" : "Saving to Photos failed: \(error?.localizedDescription ?? "unknown")")
                        if success { Haptics.success() }
                        self?.showAlert(title: success ? "Saved to Photos" : "Couldn’t Save",
                                        message: success ? "\(files.count) item\(files.count == 1 ? "" : "s") added to your library."
                                                         : (error?.localizedDescription ?? "Try again."))
                    }
                }
            }
        }
    }

    override func buildSections() -> [FormSection] {
        let s = session
        let connected = s.isConnected
        var downloading = false
        if case .downloading = s.fileTransfer { downloading = true }
        let checking = s.fileTransfer == .checking

        var sections: [FormSection] = []
        if let required = glassesRequiredSection() { sections.append(required) }

        // Current transfer.
        switch s.fileTransfer {
        case .idle:
            break
        case .checking:
            sections.append(FormSection(rows: [.item(title: "Checking the glasses for new files…", symbol: "arrow.clockwise", busy: true)]))
        case let .downloading(received, total):
            sections.append(FormSection(
                footer: "Files come over Wi-Fi. Keep this app open until they finish.",
                rows: [.item(title: "Downloading \(min(received + 1, total)) of \(total)",
                             subtitle: received == 0 ? "Waiting for the glasses to connect" : "\(received) done",
                             symbol: "arrow.down.circle", busy: true)]))
        case let .finished(count):
            sections.append(FormSection(rows: [
                .status(title: "Downloaded \(count) file\(count == 1 ? "" : "s")", subtitle: nil,
                        symbol: "checkmark.circle.fill", tint: .systemGreen),
            ]))
        case let .failed(message):
            sections.append(FormSection(rows: [
                .status(title: "Download failed", subtitle: message,
                        symbol: "exclamationmark.triangle.fill", tint: Theme.warning),
            ]))
        }

        var pendingRows: [FormRow] = [
            .action(title: "Check for New Files", symbol: "arrow.clockwise", enabled: connected && !downloading && !checking,
                    handler: { s.requestFiles() }),
        ]
        pendingRows += s.pendingFiles.map { .item(title: Self.name(of: $0), symbol: Self.symbol(for: $0)) }
        if !s.pendingFiles.isEmpty {
            let count = s.pendingFiles.count
            pendingRows.append(.action(title: "Download \(count) File\(count == 1 ? "" : "s")",
                                       symbol: "arrow.down.circle", enabled: connected && !downloading,
                                       handler: { s.downloadPendingFiles() }))
        }
        var pendingFooter: String?
        if connected {
            let network = (s.confirmedWifiName.map { "Glasses on \($0). " }
                ?? s.lastJoinedWifiName.map { "Glasses last joined \($0). " }) ?? ""
            pendingFooter = network + "Downloads need the glasses and phone on the same network."
        }
        if connected, !s.pendingFiles.isEmpty, !downloading,
           let problem = GlassesSession.fileTransferNetworkProblem() {
            pendingFooter = problem
        }

        let local = Self.localDownloads()
        let dateFormatter = DateFormatter()
        dateFormatter.dateStyle = .medium
        dateFormatter.timeStyle = .short
        var syncedRows: [FormRow] = local.map { url in
            let size = (try? url.resourceValues(forKeys: [.fileSizeKey]).fileSize).map {
                ByteCountFormatter.string(fromByteCount: Int64($0), countStyle: .file)
            }
            let kind = Self.isVideo(url) ? "Video" : "Photo"
            return .item(title: dateFormatter.string(from: Self.captureDate(of: url)),
                         subtitle: [kind, size].compactMap { $0 }.joined(separator: " · "),
                         symbol: Self.isVideo(url) ? "video" : "photo", disclosure: true,
                         onTap: { [weak self] in self?.preview(url) },
                         onDelete: { [weak self] in self?.deleteLocal(url) })
        }
        if local.isEmpty {
            syncedRows.append(.text("Nothing downloaded yet.", secondary: true))
        } else {
            syncedRows.append(.action(title: "Save All to Photos", symbol: "square.and.arrow.down",
                                      handler: { [weak self] in self?.saveAllToPhotos() }))
            if !s.syncedFiles.isEmpty {
                syncedRows.append(.action(title: "Confirm Downloads", symbol: "checkmark.circle", enabled: connected && !downloading,
                                          handler: { s.confirmDownloads() }))
            }
        }
        let downloaded = local

        sections += [
            FormSection(header: "On Glasses", footer: pendingFooter, rows: pendingRows),
            FormSection(header: "Downloaded",
                        footer: downloaded.isEmpty ? nil : "Stored in this app, and in the Files app under On My iPhone. Tap to view or share; swipe left to delete from this phone.",
                        rows: syncedRows),
        ]
        return sections
    }

    private static func name(of file: [String: Any]) -> String {
        if let name = file["fileName"] as? String, !name.isEmpty { return name }
        if let path = file["bigPath"] as? String { return (path as NSString).lastPathComponent }
        return "File"
    }

    private static func symbol(for file: [String: Any]) -> String {
        let name = name(of: file).lowercased()
        if ["mp4", "mov"].contains(where: name.hasSuffix) { return "video" }
        if ["wav", "mp3", "m4a", "opus", "pcm"].contains(where: name.hasSuffix) { return "waveform" }
        return "photo"
    }
}
