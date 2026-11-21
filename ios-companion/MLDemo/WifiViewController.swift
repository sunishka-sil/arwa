//
//  WifiViewController.swift
//  MLDemo
//
//  Puts the glasses on a Wi-Fi network. All commands go to the glasses over Bluetooth,
//  so the glasses must be connected first.
//

import UIKit

final class WifiViewController: FormViewController {
    private let session = GlassesSession.shared
    private var ssid = ""
    private var bssid = ""
    private var password = ""
    private var isJoining = false
    private var hasScanned = false
    private var joinTimeout: DispatchWorkItem?

    override func viewDidLoad() {
        title = "Glasses Wi-Fi"
        super.viewDidLoad()
        navigationItem.largeTitleDisplayMode = .never
        observe(.glassesDidChange) { [weak self] _ in
            guard let self else { return }
            // Switching networks makes the glasses drop Bluetooth for a few seconds; the app reconnects and the
            // result arrives afterwards, so a disconnect during a join isn't a failure.
            if self.isJoining, self.session.confirmedWifiName == self.ssid {
                self.joinFinished(success: true)
                return
            }
            if self.isJoining && !self.session.isConnected && !self.session.isReconnecting {
                self.joinTimeout?.cancel()
                self.isJoining = false
                self.showAlert(title: "Glasses Disconnected",
                               message: "The glasses didn’t reconnect after switching networks. Reconnect them and check the Wi-Fi status.")
            }
            self.reload()
        }
        observe(.glassesWifiJoinResult) { [weak self] note in
            self?.joinFinished(success: note.userInfo?["success"] as? Bool ?? false)
        }
    }

    override func buildSections() -> [FormSection] {
        let connected = session.isConnected
        var sections: [FormSection] = []

        if !connected {
            sections.append(FormSection(rows: [
                .text("Connect your glasses to change these settings. Wi-Fi details are sent to them over Bluetooth.",
                      secondary: true),
            ]))
        }

        sections.append(FormSection(
            header: "Status",
            footer: isJoining
                ? "Joining… The glasses briefly disconnect from Bluetooth while they switch networks."
                : session.wifiStatusKnown || !connected ? nil
                : "Waiting for the glasses to report their network. This shows the last one they joined.",
            rows: [
                .toggle(title: "Wi-Fi", symbol: "wifi", isOn: connected && session.wifiEnabled, enabled: connected,
                        onChange: { [weak self] on in self?.session.setWifi(on: on) }),
                session.confirmedWifiName.map { .value(title: "Connected To", value: $0, symbol: "network") }
                    ?? (session.wifiStatusKnown
                        ? .value(title: "Connected To", value: "None", symbol: "network")
                        : .value(title: "Last Joined", value: connected ? (session.lastJoinedWifiName ?? "None") : "—",
                                 symbol: "network")),
            ]))

        let saved = SavedNetworks.all
        if !saved.isEmpty {
            let formatter = RelativeDateTimeFormatter()
            formatter.unitsStyle = .full
            sections.append(FormSection(
                header: "Saved Networks",
                footer: "Tap to rejoin. Swipe left to forget a network.",
                rows: saved.map { network in
                    let isCurrent = network.ssid == session.confirmedWifiName
                    let used: String? = isCurrent ? nil
                        : network.lastUsed == .distantPast ? "Joined before"
                        : "Joined \(formatter.localizedString(for: network.lastUsed, relativeTo: Date()))"
                    return .item(title: network.ssid, subtitle: used, symbol: isCurrent ? "checkmark" : "wifi",
                                 busy: isJoining && ssid == network.ssid,
                                 onTap: connected && !isJoining && !isCurrent ? { [weak self] in self?.rejoin(network) } : nil,
                                 onDelete: { [weak self] in
                                     SavedNetworks.forget(ssid: network.ssid)
                                     self?.reload()
                                 })
                }))
        }

        sections.append(FormSection(
            header: "Join a Network",
            footer: "Use a home network or your iPhone’s Personal Hotspot, and put your Mac on the same network. Networks that need a username, such as eduroam, aren’t supported.",
            rows: [
                .textField(placeholder: "Network name", text: ssid, onChange: { [weak self] in self?.ssid = $0 }),
                .textField(placeholder: "Password", text: password, secure: true, onChange: { [weak self] in self?.password = $0 }),
                .textField(placeholder: "BSSID (optional)", text: bssid, onChange: { [weak self] in self?.bssid = $0 }),
                .action(title: isJoining ? "Joining…" : "Join Network", symbol: "arrow.right.circle",
                        enabled: connected && !isJoining, handler: { [weak self] in self?.join() }),
            ]))

        var networkRows: [FormRow] = [
            .action(title: "Scan for Networks", symbol: "antenna.radiowaves.left.and.right", enabled: connected,
                    handler: { [weak self] in self?.scan() }),
        ]
        for network in session.wifiNetworks {
            let name = (network["ssid"] as? String).flatMap { $0.isEmpty ? nil : $0 } ?? "Hidden network"
            let id = network["bssid"] as? String ?? ""
            networkRows.append(.item(title: name, subtitle: id.isEmpty ? nil : id, symbol: "wifi",
                                     onTap: { [weak self] in self?.choose(name: name, bssid: id) }))
        }
        if hasScanned && session.wifiNetworks.isEmpty {
            networkRows.append(.text("No networks reported yet. If none appear, type the network name above.", secondary: true))
        }
        sections.append(FormSection(header: "Nearby Networks",
                                    footer: session.wifiNetworks.isEmpty ? nil : "Tap a network to fill in its name.",
                                    rows: networkRows))
        return sections
    }

    private func scan() {
        hasScanned = true
        session.scanWifi()
    }

    private func choose(name: String, bssid: String) {
        ssid = name == "Hidden network" ? "" : name
        self.bssid = bssid
        view.endEditing(true)
        reload()
        // Move straight to the password field.
        let joinSection = (session.isConnected ? 1 : 2) + (SavedNetworks.all.isEmpty ? 0 : 1)
        if let cell = tableView.cellForRow(at: IndexPath(row: 1, section: joinSection)) as? TextFieldCell {
            cell.field.becomeFirstResponder()
        }
    }

    private func rejoin(_ network: SavedNetwork) {
        ssid = network.ssid
        bssid = network.bssid
        password = SavedNetworks.password(for: network.ssid)
        join()
    }

    private func join() {
        view.endEditing(true)
        let name = ssid.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !name.isEmpty else {
            showAlert(title: "Enter a Network Name", message: "Type the Wi-Fi name, or scan and pick a network.")
            return
        }
        if name == session.confirmedWifiName {
            // Rejoining restarts the glasses' Wi-Fi (and drops Bluetooth) for nothing.
            showAlert(title: "Already Connected", message: "The glasses are already on “\(name)”.")
            return
        }
        isJoining = true
        reload()
        session.joinWifi(ssid: name, bssid: bssid.trimmingCharacters(in: .whitespacesAndNewlines), password: password)

        let timeout = DispatchWorkItem { [weak self] in
            guard let self, self.isJoining else { return }
            self.isJoining = false
            self.reload()
            self.showAlert(title: "No Response",
                           message: "The glasses didn’t report a result. Check the Event Log, then try again.")
        }
        joinTimeout = timeout
        DispatchQueue.main.asyncAfter(deadline: .now() + 45, execute: timeout)
    }

    private func joinFinished(success: Bool) {
        joinTimeout?.cancel()
        let wasJoining = isJoining
        isJoining = false
        reload()
        guard wasJoining else { return }
        if success {
            SavedNetworks.save(ssid: ssid, bssid: bssid, password: password)
            showAlert(title: "Glasses Joined “\(ssid)”",
                      message: "Saved for next time.")
        } else {
            showAlert(title: "Couldn’t Join “\(ssid)”",
                      message: "Check the network name and password. The glasses need a network that uses only a password.")
        }
    }
}
