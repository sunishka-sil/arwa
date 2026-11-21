//
//  HomeViewController.swift
//  MLDemo
//
//  Home: a header for the glasses, then standard grouped sections.
//

import UIKit
import MLVisionM6SDK

final class HomeViewController: FormViewController {
    private let session = GlassesSession.shared
    private let header = DeviceHeaderView()
    private let volume = SliderRowView(title: "Volume", symbol: "speaker.wave.2", range: 0...100, step: 10, format: { "\($0)%" })
    private let brightness = SliderRowView(title: "Brightness", symbol: "sun.max", range: 0...10, step: 1, format: { "\($0)" })
    private var previousState: GlassesSession.ConnectionState?

    override func viewDidLoad() {
        title = "Settings"
        session.start(delegate: self)
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .always
        navigationItem.backButtonDisplayMode = .minimal

        volume.onCommit = { [weak self] in self?.session.setVolume($0) }
        brightness.onCommit = { [weak self] in self?.session.setBrightness($0) }

        observe(.glassesDidChange) { [weak self] _ in
            self?.playHapticForStateChange()
            self?.reload()
        }
        previousState = session.state
    }

    override func reload() {
        header.update(model: headerModel())
        volume.update(value: session.volume, enabled: session.isConnected)
        brightness.update(value: session.brightness, enabled: session.isConnected)
        super.reload()
    }

    override func buildSections() -> [FormSection] {
        let s = session
        let linked = s.isConnected
        var sections = [FormSection(rows: [.view(header)])]

        sections.append(FormSection(rows: [
            .navigation(title: "Guide Connection", symbol: "wifi", handler: { [weak self] in self?.push(GuideSetupViewController()) })
        ]))

        sections.append(FormSection(
            header: "Display and Sound",
            footer: linked ? nil : "Available when your glasses are connected.",
            rows: [
                .view(volume),
                .view(brightness),
                .menu(title: "Screen Timeout", symbol: "timer",
                      selected: GlassesSession.screenTimeoutOptions[s.screenTimeout],
                      options: GlassesSession.screenTimeoutOptions, enabled: linked,
                      onSelect: { s.setScreenTimeout(GlassesSession.screenTimeoutOptions.firstIndex(of: $0) ?? 0) }),
            ]))

        sections.append(FormSection(header: "Features", rows: [
            .navigation(title: "Voice Assistant", symbol: "bubble.left.and.bubble.right",
                        handler: { [weak self] in self?.push(AssistantViewController()) }),
            .navigation(title: "Camera", symbol: "camera",
                        handler: { [weak self] in self?.push(CameraViewController()) }),
            .navigation(title: "Live Interpreting", symbol: "character.bubble", value: interpretingValue,
                        handler: { [weak self] in self?.push(InterpretingViewController()) }),
            .navigation(title: "Record and Transcribe", symbol: "mic",
                        handler: { [weak self] in self?.push(RecordViewController()) }),
            .navigation(title: "Transcribe Samples", symbol: "waveform",
                        handler: { [weak self] in self?.push(TranscribeViewController()) }),
        ]))

        sections.append(FormSection(header: "Connectivity", rows: [
            .navigation(title: "Wi-Fi", symbol: "wifi", value: wifiValue,
                        handler: { [weak self] in self?.push(WifiViewController()) }),
            .navigation(title: "Files", symbol: "tray.and.arrow.down", value: filesValue,
                        handler: { [weak self] in self?.push(FilesViewController()) }),
        ]))

        sections.append(FormSection(
            header: "Developer",
            footer: linked
                ? "Turns on USB debugging (ADB) so you can install apps from a computer. After switching it on, unplug and replug the glasses’ USB cable."
                : "Available when your glasses are connected.",
            rows: [
                .toggle(title: "Developer Mode", symbol: "hammer", isOn: s.developerMode, enabled: linked,
                        onChange: { s.setDeveloperMode($0) }),
            ]))

        var device: [FormRow] = []
        if linked {
            device.append(.navigation(title: "About These Glasses", symbol: "info.circle",
                                      handler: { [weak self] in self?.push(DeviceInfoViewController()) }))
            device.append(.action(title: "Disconnect", handler: { s.disconnect() }))
        }
        if linked || s.pairedGlasses != nil {
            device.append(.action(title: "Forget These Glasses…", destructive: true,
                                  handler: { [weak self] in self?.confirmForget() }))
        }
        if !device.isEmpty {
            sections.append(FormSection(header: "Device", rows: device))
        }

        sections.append(FormSection(rows: [
            .navigation(title: "Event Log", symbol: "doc.plaintext",
                        handler: { [weak self] in self?.push(LogViewController()) }),
        ]))
        return sections
    }

    // MARK: Header

    private func headerModel() -> DeviceHeaderView.Model {
        let s = session
        let paired = s.pairedGlasses
        let name = s.connectedName ?? paired?.name ?? "Your Glasses"
        switch s.state {
        case .idle:
            if let paired {
                return .init(name: paired.name, status: "Not connected", isError: s.idleMessageIsError,
                             message: s.idleMessage,
                             primary: ("Connect", { s.connectToPaired() }),
                             secondary: ("Use Different Glasses", { [weak self] in self?.presentPairing() }))
            }
            return .init(name: "No Glasses Set Up", status: s.idleMessage == nil ? "Not connected" : "Couldn’t connect",
                         isError: s.idleMessageIsError,
                         message: s.idleMessage ?? "Turn on your glasses and keep them close to your phone.",
                         primary: ("Set Up Glasses", { [weak self] in self?.presentPairing() }))
        case .searching:
            // Searching only happens while the Nearby Glasses sheet is open, and the sheet has its own
            // controls. Buttons here would sit behind the sheet, and tapping them would dismiss it.
            return .init(name: s.connectedName ?? paired?.name ?? "Looking for Glasses", status: "Searching nearby…", busy: true)
        case .connecting(let target):
            return .init(name: target, status: "Connecting…", busy: true,
                         secondary: ("Cancel", { s.cancelConnecting() }))
        case .connected:
            var status = "Connected"
            if let battery = s.batteryLevel {
                status += s.isCharging == true ? " · \(battery)%, charging" : " · \(battery)% battery"
            } else if s.isCharging == true {
                status += " · Charging"
            }
            return .init(name: name, status: status)
        case .reconnecting(let attempt):
            return .init(name: name, status: "Reconnecting…", busy: true,
                         message: "Lost the connection. Trying again (\(attempt) of \(s.reconnectLimit)).",
                         secondary: ("Stop Trying", { s.stopReconnecting() }))
        case .bluetoothOff:
            return .init(name: name, status: "Bluetooth is off",
                         message: "Turn on Bluetooth in Control Center to connect.")
        case .bluetoothUnauthorized:
            return .init(name: name, status: "Bluetooth access needed", isError: true,
                         message: "Allow Bluetooth for this app in Settings to connect to your glasses.",
                         primary: ("Open Settings", {
                             if let url = URL(string: UIApplication.openSettingsURLString) { UIApplication.shared.open(url) }
                         }))
        }
    }

    // MARK: Row values

    private var interpretingValue: String? {
        let source = MLVisionM6OCSDK.getSourceLanguage(), target = MLVisionM6OCSDK.getTargetLanguage()
        guard !source.isEmpty, !target.isEmpty else { return nil }
        func short(_ code: String) -> String {
            Locale.current.localizedString(forLanguageCode: code)?.components(separatedBy: " ").first ?? code
        }
        return "\(short(source)) to \(short(target))"
    }

    private var wifiValue: String? {
        guard session.isConnected else { return nil }
        if let name = session.confirmedWifiName { return name }
        if !session.wifiEnabled { return "Off" }
        if session.wifiStatusKnown { return "Not connected" }
        return session.lastJoinedWifiName.map { "Last joined \($0)" }
    }

    private var filesValue: String? {
        let waiting = session.pendingFiles.count
        return waiting > 0 ? "\(waiting) waiting" : nil
    }

    // MARK: Actions

    func presentPairing() {
        guard presentedViewController == nil else { return }
        let navigation = UINavigationController(rootViewController: PairingViewController())
        if let sheet = navigation.sheetPresentationController {
            sheet.detents = [.medium(), .large()]
            sheet.prefersGrabberVisible = true
        }
        present(navigation, animated: true)
    }

    private func confirmForget() {
        let name = session.connectedName ?? session.pairedGlasses?.name ?? "these glasses"
        confirm(title: "Forget \(name)?",
                message: "You’ll need to set them up again to use them with this phone.",
                actionTitle: "Forget") { [weak self] in
            Haptics.warning()
            self?.session.unbind()
        }
    }

    private func playHapticForStateChange() {
        let state = session.state
        defer { previousState = state }
        guard let previous = previousState, previous != state else { return }
        switch (previous, state) {
        case (_, .connected): Haptics.success()
        case (.connected, .reconnecting): Haptics.warning()
        case (_, .idle) where session.idleMessageIsError: Haptics.error()
        default: break
        }
    }
}

// MARK: - Header view

/// Name, one line of status, an optional explanation and up to two buttons.
final class DeviceHeaderView: UIView {
    struct Model {
        var name: String
        var status: String
        var isError = false
        var busy = false
        var message: String? = nil
        var primary: (String, () -> Void)? = nil
        var secondary: (String, () -> Void)? = nil
    }

    private let nameLabel = makeLabel(font: .preferredFont(forTextStyle: .title2).bold(), lines: 2)
    private let statusLabel = makeLabel(font: .preferredFont(forTextStyle: .subheadline), color: Theme.textSecondary)
    private let spinner = UIActivityIndicatorView(style: .medium)
    private let messageLabel = makeLabel(font: .preferredFont(forTextStyle: .footnote), color: Theme.textSecondary, lines: 0)
    private let buttons = UIStackView()
    private var buttonTitles: [String] = []

    override init(frame: CGRect) {
        super.init(frame: frame)
        spinner.hidesWhenStopped = true
        spinner.setContentHuggingPriority(.required, for: .horizontal)
        let statusRow = makeRow([statusLabel, spinner, makeSpacer()], spacing: 6)
        buttons.axis = .vertical
        buttons.spacing = 8
        let stack = UIStackView(arrangedSubviews: [nameLabel, statusRow, messageLabel, buttons])
        stack.axis = .vertical
        stack.spacing = 4
        stack.setCustomSpacing(10, after: statusRow)
        stack.setCustomSpacing(16, after: messageLabel)
        stack.translatesAutoresizingMaskIntoConstraints = false
        addSubview(stack)
        NSLayoutConstraint.activate([
            stack.leadingAnchor.constraint(equalTo: leadingAnchor),
            stack.trailingAnchor.constraint(equalTo: trailingAnchor),
            stack.topAnchor.constraint(equalTo: topAnchor, constant: 4),
            stack.bottomAnchor.constraint(equalTo: bottomAnchor, constant: -4),
        ])
    }

    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    func update(model: Model) {
        nameLabel.text = model.name
        statusLabel.text = model.status
        statusLabel.textColor = model.isError ? Theme.danger : Theme.textSecondary
        model.busy ? spinner.startAnimating() : spinner.stopAnimating()
        messageLabel.text = model.message
        messageLabel.isHidden = model.message == nil

        // Rebuild buttons only when they change, so a tap in progress isn't interrupted.
        let titles = [model.primary?.0, model.secondary?.0].compactMap { $0 }
        guard titles != buttonTitles else { return }
        buttonTitles = titles
        buttons.arrangedSubviews.forEach { $0.removeFromSuperview() }
        if let primary = model.primary { buttons.addArrangedSubview(makeButton(primary.0, style: .primary, action: primary.1)) }
        if let secondary = model.secondary { buttons.addArrangedSubview(makeButton(secondary.0, style: .secondary, action: secondary.1)) }
        buttons.isHidden = titles.isEmpty
    }
}

private extension UIFont {
    func bold() -> UIFont {
        guard let descriptor = fontDescriptor.withSymbolicTraits(.traitBold) else { return self }
        return UIFont(descriptor: descriptor, size: 0)
    }
}

// MARK: - Pairing sheet

final class PairingViewController: FormViewController {
    private let session = GlassesSession.shared
    private var connectingID: String?

    override func viewDidLoad() {
        title = "Nearby Glasses"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        navigationItem.leftBarButtonItem = UIBarButtonItem(systemItem: .close, primaryAction: UIAction { [weak self] _ in
            self?.dismiss(animated: true)
        })
        observe(.glassesDidChange) { [weak self] _ in
            guard let self else { return }
            if self.session.isConnected {
                self.dismiss(animated: true) {
                    NotificationCenter.default.post(name: .glassesDidChange, object: nil)
                }
                return
            }
            self.updateNavigationItem()
            self.reload()
        }
        if session.state == .idle { session.startSearching() }
        updateNavigationItem()
    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        if session.state == .searching { session.stopSearching() }
    }

    private func updateNavigationItem() {
        if session.state == .searching {
            let spinner = UIActivityIndicatorView(style: .medium)
            spinner.startAnimating()
            navigationItem.rightBarButtonItem = UIBarButtonItem(customView: spinner)
        } else if session.state == .idle {
            navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Search Again", primaryAction: UIAction { _ in
                GlassesSession.shared.startSearching()
            })
        } else {
            navigationItem.rightBarButtonItem = nil
        }
    }

    override func buildSections() -> [FormSection] {
        let s = session
        let footer = s.pairedGlasses.map {
            "\($0.name) are paired with this phone. To set up different glasses, forget these first."
        }

        var rows: [FormRow] = s.nearby.map { device in
            let connecting = device.id == connectingID && s.isConnecting
            return .item(title: device.name,
                         subtitle: "\(device.signal) · ends in \(device.id.suffix(4))",
                         symbol: "eyeglasses",
                         busy: connecting,
                         onTap: s.isConnecting ? nil : { [weak self] in
                             self?.connectingID = device.id
                             s.connect(to: device)
                         })
        }

        if rows.isEmpty {
            switch s.state {
            case .searching:
                rows.append(.text("Looking for glasses. Keep yours turned on and close to your phone.", secondary: true))
            case .bluetoothOff:
                rows.append(.text("Turn on Bluetooth to search.", secondary: true))
            case .bluetoothUnauthorized:
                rows.append(.text("Allow Bluetooth for this app in Settings to search.", secondary: true))
            default:
                rows.append(.text(s.idleMessage ?? "No glasses found.", secondary: true))
            }
        } else if case .idle = s.state, let message = s.idleMessage {
            rows.insert(.text(message, secondary: true), at: 0)
        }
        return [FormSection(footer: footer, rows: rows)]
    }
}

// MARK: - Shared

extension FormViewController {
    /// A note shown at the top of screens that need the glasses connected.
    func glassesRequiredSection(_ session: GlassesSession = .shared) -> FormSection? {
        guard !session.isConnected else { return nil }
        let text: String
        switch session.state {
        case .reconnecting: text = "Reconnecting to your glasses…"
        case .connecting: text = "Connecting to your glasses…"
        case .bluetoothOff: text = "Bluetooth is off. Turn it on to use these controls."
        default: text = "Connect your glasses to use these controls."
        }
        return FormSection(rows: [.text(text, secondary: true)])
    }
}

// MARK: - Device info

final class DeviceInfoViewController: FormViewController {
    private let session = GlassesSession.shared

    override func viewDidLoad() {
        title = "About These Glasses"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        navigationItem.rightBarButtonItem = UIBarButtonItem(
            systemItem: .refresh,
            primaryAction: UIAction { [weak self] _ in self?.session.refreshGlassInfo() })
        observe(.glassesDidChange)
    }

    override func buildSections() -> [FormSection] {
        let info = session.glassInfo
        guard !info.isEmpty else {
            return [FormSection(rows: [.text("No information yet. Connect your glasses, then tap Refresh.", secondary: true)])]
        }
        let rows: [FormRow] = info.keys.sorted().map { key in
            .value(title: key, value: "\(info[key] ?? "")")
        }
        return [FormSection(footer: "Reported by the glasses.", rows: rows)]
    }
}

// MARK: - Event log

final class LogViewController: UIViewController {
    private let textView = UITextView()
    private var token: NSObjectProtocol?

    override func viewDidLoad() {
        super.viewDidLoad()
        title = "Event Log"
        navigationItem.largeTitleDisplayMode = .never
        view.backgroundColor = .systemBackground

        textView.isEditable = false
        textView.backgroundColor = .clear
        textView.alwaysBounceVertical = true
        textView.font = Theme.mono(12, style: .footnote)
        textView.adjustsFontForContentSizeCategory = true
        textView.textColor = Theme.textSecondary
        textView.textContainerInset = UIEdgeInsets(top: 16, left: 12, bottom: 24, right: 12)
        textView.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(textView)
        NSLayoutConstraint.activate([
            textView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            textView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            textView.topAnchor.constraint(equalTo: view.topAnchor),
            textView.bottomAnchor.constraint(equalTo: view.bottomAnchor),
        ])

        let share = UIBarButtonItem(barButtonSystemItem: .action, target: self, action: #selector(shareLog(_:)))
        let clear = UIBarButtonItem(systemItem: .trash, primaryAction: UIAction { _ in EventLog.shared.clear() })
        navigationItem.rightBarButtonItems = [share, clear]

        token = NotificationCenter.default.addObserver(forName: .eventLogDidChange, object: nil, queue: .main) { [weak self] _ in
            self?.refresh()
        }
        refresh()
    }

    deinit {
        if let token { NotificationCenter.default.removeObserver(token) }
    }

    private func refresh() {
        let text = EventLog.shared.text
        let wasAtBottom = textView.contentOffset.y >= textView.contentSize.height - textView.bounds.height - 40
        textView.text = text.isEmpty ? "No events yet." : text
        if !text.isEmpty, wasAtBottom || textView.contentSize.height <= textView.bounds.height {
            textView.layoutIfNeeded()
            textView.scrollRangeToVisible(NSRange(location: (text as NSString).length - 1, length: 1))
        }
    }

    @objc private func shareLog(_ sender: UIBarButtonItem) {
        let activity = UIActivityViewController(activityItems: [EventLog.shared.text], applicationActivities: nil)
        activity.popoverPresentationController?.barButtonItem = sender
        present(activity, animated: true)
    }
}
