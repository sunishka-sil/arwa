import UIKit

/// The companion's home. Vendor features remain together under Settings.
final class GuidesViewController: FormViewController {
    private let glasses = GlassesSession.shared
    private let connection = GuideConnection.shared
    private var guide: Guide?
    private var guideError: String?
    private var setupPresentedForPair: String?

    override func viewDidLoad() {
        title = "Guides"
        do { guide = try Guide.bundled() } catch { guideError = error.localizedDescription }
        glasses.start(delegate: self)
        super.viewDidLoad()
        navigationItem.backButtonDisplayMode = .minimal
        navigationItem.rightBarButtonItem = UIBarButtonItem(image: UIImage(systemName: "gearshape"), style: .plain,
                                                           target: self, action: #selector(openSettings))
        navigationItem.rightBarButtonItem?.accessibilityLabel = "Settings"
        observe(.glassesDidChange) { [weak self] _ in self?.reload(); self?.offerSetupAfterPairing() }
        observe(.guideConnectionDidChange)
        connection.start()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        offerSetupAfterPairing()
    }

    override func buildSections() -> [FormSection] {
        let paired = glasses.pairedGlasses
        var rows: [FormRow] = [
            .status(title: glasses.connectedName ?? paired?.name ?? "Your glasses",
                    subtitle: glasses.isConnected ? "Connected\(glasses.batteryLevel.map { " · \($0)% battery" } ?? "")"
                        : glasses.isConnecting ? "Connecting…"
                        : glasses.isReconnecting ? "Reconnecting…"
                        : glasses.idleMessage ?? "Connect to set up your glasses",
                    symbol: "eyeglasses", tint: glasses.isConnected ? .systemGreen : Theme.textSecondary)
        ]
        if !glasses.isConnected {
            rows.append(.action(title: paired == nil ? "Set Up Glasses" : "Connect Glasses", symbol: "link",
                                enabled: !glasses.isConnecting && !glasses.isReconnecting, handler: { [weak self] in
                guard let self else { return }
                if self.glasses.pairedGlasses != nil { self.glasses.connectToPaired() } else { self.pair() }
            }))
        }
        if paired != nil {
            rows.append(.navigation(title: connection.connected ? "Guide Connection" : "Set Up Guides", subtitle: connection.message,
                                    symbol: "wifi", value: connection.selectedName, handler: { [weak self] in self?.push(GuideSetupViewController()) }))
        }
        var sections = [FormSection(rows: rows)]
        if let guide {
            sections.append(FormSection(header: "Your Guides", rows: [
                .navigation(title: guide.title, subtitle: "\(guide.steps.count) steps · 3D walkthrough", symbol: "cube.transparent",
                            value: connection.connected && connection.snapshot?.started == true ? "In progress" : nil,
                            handler: { [weak self] in self?.push(CurrentGuideViewController(guide: guide)) })
            ]))
        } else {
            sections.append(FormSection(rows: [.status(title: "Guide unavailable", subtitle: guideError, symbol: "exclamationmark.triangle", tint: Theme.danger)]))
        }
        return sections
    }

    @objc private func openSettings() { push(HomeViewController()) }

    private func pair() {
        let navigation = UINavigationController(rootViewController: PairingViewController())
        if let sheet = navigation.sheetPresentationController {
            sheet.detents = [.medium(), .large()]
            sheet.prefersGrabberVisible = true
        }
        present(navigation, animated: true)
    }

    private func offerSetupAfterPairing() {
        let pairID = glasses.pairedGlasses?.id ?? UserDefaults.standard.string(forKey: "BLEFirstGlassInfoKey")
        guard glasses.isConnected, let id = pairID,
              connection.selectedName == nil, setupPresentedForPair != id,
              presentedViewController == nil, navigationController?.topViewController === self else { return }
        setupPresentedForPair = id
        push(GuideSetupViewController())
    }
}

final class CurrentGuideViewController: FormViewController {
    private let guide: Guide
    private let connection = GuideConnection.shared

    init(guide: Guide) { self.guide = guide; super.init() }
    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    override func viewDidLoad() {
        title = "Motor Coupling"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        observe(.guideConnectionDidChange)
    }

    override func buildSections() -> [FormSection] {
        let state = connection.snapshot
        let active = connection.connected && state?.started == true
        let done = active && state!.step >= guide.steps.count
        let showing = active && state!.viewerReady && state!.displayedRevision >= state!.revision
        var sections = [FormSection(rows: [
            .status(title: guide.title, subtitle: guide.summary, symbol: "cube.transparent", tint: Theme.accent),
            .status(title: connection.busy ? "Working…" : connection.message,
                    subtitle: active && !showing ? "Waiting for the glasses display" : nil,
                    symbol: showing ? "checkmark.circle" : "eyeglasses", tint: showing ? .systemGreen : Theme.textSecondary)
        ])]
        if !connection.connected {
            sections.append(FormSection(rows: [.navigation(title: "Set Up Guide Connection", symbol: "wifi", handler: { [weak self] in self?.push(GuideSetupViewController()) })]))
        }
        if active {
            if let voiceEnabled = state?.voiceEnabled {
                sections.append(FormSection(header: "Voice Navigation", footer: "Say “next”, “back”, “show”, or “hide”. Recognition runs on the glasses, so the phone can stay in your pocket.", rows: [
                    .status(title: state?.voiceStatus ?? "Off", subtitle: state?.lastVoiceCommand.flatMap { $0.isEmpty ? nil : "Last command: \($0)" },
                            symbol: voiceEnabled ? "mic.fill" : "mic.slash", tint: state?.voiceStatus == "Listening" ? .systemGreen : Theme.textSecondary),
                    .action(title: voiceEnabled ? "Turn Voice Navigation Off" : "Turn Voice Navigation On", symbol: voiceEnabled ? "mic.slash" : "mic",
                            enabled: !connection.busy, handler: { [weak self] in self?.send(voiceEnabled ? "voice_off" : "voice_on") })
                ]))
            }
            if done {
                sections.append(FormSection(header: "Complete", rows: [.status(title: "Motor mounted", subtitle: "All \(guide.steps.count) steps completed.", symbol: "checkmark.circle.fill", tint: .systemGreen)]))
            } else {
                let step = guide.steps[state!.step]
                var rows: [FormRow] = [.status(title: step.h, subtitle: step.d)]
                if let spec = step.spec { rows.append(.value(title: spec.label, value: "\(spec.value) \(spec.unit)")) }
                if let hazard = step.hazard { rows.append(.status(title: hazard, subtitle: nil, symbol: "exclamationmark.triangle", tint: Theme.warning)) }
                sections.append(FormSection(header: "Step \(state!.step + 1) of \(guide.steps.count)", rows: rows))
            }
            sections.append(FormSection(rows: [
                .action(title: "Previous Step", symbol: "backward.end", enabled: showing && !connection.busy && state!.step > 0,
                        handler: { [weak self] in self?.send("back") }),
                .action(title: "Next Step", symbol: "forward.end", enabled: showing && !connection.busy && !done,
                        handler: { [weak self] in self?.send("next") }),
                .action(title: state!.hidden ? "Show on Glasses" : "Hide on Glasses", symbol: state!.hidden ? "eye" : "eye.slash",
                        enabled: showing && !connection.busy, handler: { [weak self] in self?.send(state!.hidden ? "show" : "hide") }),
                .action(title: "Restart Guide…", symbol: "arrow.counterclockwise", enabled: !connection.busy,
                        handler: { [weak self] in self?.restart() })
            ]))
        } else {
            sections.append(FormSection(rows: [.action(title: connection.busy ? "Starting…" : "Start on Glasses", symbol: "play.fill",
                                                       enabled: connection.connected && !connection.busy, handler: { [weak self] in self?.send("start") })]))
        }
        sections.append(FormSection(header: "Steps", rows: guide.steps.enumerated().map { index, step in
            .status(title: "\(index + 1). \(step.h)", subtitle: nil,
                    symbol: active && index < state!.step ? "checkmark.circle.fill" : "circle",
                    tint: active && index == state!.step ? Theme.accent : Theme.textSecondary)
        }))
        return sections
    }

    private func send(_ command: String) { Task { await connection.command(command) } }
    private func restart() {
        let alert = UIAlertController(title: "Restart guide?", message: "This returns both screens to step one.", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        alert.addAction(UIAlertAction(title: "Restart", style: .default) { [weak self] _ in self?.send("start") })
        present(alert, animated: true)
    }
}

/// This follows Bluetooth pairing. A discovered endpoint is never implicitly trusted as that pair.
final class GuideSetupViewController: FormViewController {
    private let connection = GuideConnection.shared
    private var address = ""

    override func viewDidLoad() {
        title = "Set Up Guides"
        super.viewDidLoad()
        observe(.guideConnectionDidChange)
        observe(.glassesDidChange)
    }

    override func buildSections() -> [FormSection] {
        guard GlassesSession.shared.pairedGlasses != nil else {
            return [FormSection(rows: [.status(title: "Pair your glasses first", subtitle: "Use Connect Glasses on the Guides screen.", symbol: "eyeglasses")])]
        }
        var sections = [FormSection(rows: [
            .status(title: GlassesSession.shared.connectedName ?? GlassesSession.shared.pairedGlasses!.name,
                    subtitle: "Open ARWA on these glasses. Choose the ARWA name shown inside their display.", symbol: "eyeglasses"),
            .navigation(title: "Glasses Wi-Fi", symbol: "wifi", handler: { [weak self] in self?.push(WifiViewController()) })
        ])]
        let devices: [FormRow] = connection.nearby.map { device in
            .item(title: device.name, subtitle: connection.selectedName == device.name && connection.connected ? "Connected for guides" : "Tap if this name matches your glasses",
                  symbol: "eyeglasses", busy: connection.busy,
                  onTap: { [weak self] in self?.confirm(device) })
        }
        sections.append(FormSection(header: "ARWA Glasses on This Wi-Fi",
                                    footer: "Both devices must be on the same Wi-Fi. This selection is remembered for your Bluetooth pair.",
                                    rows: devices.isEmpty ? [.status(title: "Looking for ARWA…", subtitle: "Keep ARWA open on the glasses and allow Local Network access on this iPhone.", symbol: "antenna.radiowaves.left.and.right")] : devices))
        sections.append(FormSection(rows: [.status(title: connection.message, subtitle: connection.selectedName, symbol: connection.connected ? "checkmark.circle" : "info.circle")]))
        sections.append(FormSection(header: "Manual Address", footer: "Use the Wi-Fi address shown on your glasses if discovery is unavailable.", rows: [
            .textField(placeholder: "192.168.1.25:8080", text: address, onChange: { [weak self] in self?.address = $0 }),
            .action(title: "Use This Address", enabled: !connection.busy, handler: { [weak self] in
                guard let self else { return }
                let alert = UIAlertController(title: "Use this glasses address?", message: "Check that \(self.address) matches the address shown in ARWA on your paired glasses.", preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
                alert.addAction(UIAlertAction(title: "Connect", style: .default) { _ in Task { await self.connection.selectManual(address: self.address) } })
                self.present(alert, animated: true)
            })
        ]))
        return sections
    }

    private func confirm(_ device: GuideDiscovery.Device) {
        let alert = UIAlertController(title: "Connect to \(device.name)?", message: "Confirm that this name is shown inside your paired glasses.", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        alert.addAction(UIAlertAction(title: "Connect", style: .default) { [weak self] _ in
            guard let self else { return }
            Task { await self.connection.select(device) }
        })
        present(alert, animated: true)
    }
}
