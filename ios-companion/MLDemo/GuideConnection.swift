import UIKit

/// Bluetooth pairing is the owner of a remembered, explicitly selected Wi-Fi endpoint.
/// No first-found-device auto-connect: even a single discovery needs one-time selection.
@MainActor
final class GuideConnection {
    static let shared = GuideConnection()
    private(set) var nearby: [GuideDiscovery.Device] = []
    private(set) var snapshot: GuideSnapshot?
    private(set) var connected = false
    private(set) var busy = false
    private(set) var message = "Connect your glasses to set up guides."
    private(set) var selectedName: String?
    private let discovery = GuideDiscovery()
    private let session: URLSession
    private var endpoint: URL?
    private var expectedDeviceID: String?
    private var pairedKey: String?
    private var polling: Task<Void, Never>?
    private var observers: [NSObjectProtocol] = []
    private var generation = 0
    private var started = false

    private init() {
        let config = URLSessionConfiguration.ephemeral
        config.timeoutIntervalForRequest = 4
        config.timeoutIntervalForResource = 6
        config.requestCachePolicy = .reloadIgnoringLocalCacheData
        session = URLSession(configuration: config)
    }

    func start() {
        guard !started else { return }
        started = true
        discovery.onChange = { [weak self] devices in
            guard let self else { return }
            self.nearby = devices
            if let id = self.expectedDeviceID, let known = devices.first(where: { $0.deviceID == id }), self.endpoint != known.url {
                self.endpoint = known.url
                self.polling?.cancel(); self.polling = nil
                self.beginPolling()
            }
            self.changed()
        }
        discovery.onError = { [weak self] message in self?.message = message; self?.changed() }
        for name in [Notification.Name.glassesDidChange, UIApplication.didBecomeActiveNotification] {
            observers.append(NotificationCenter.default.addObserver(forName: name, object: nil, queue: .main) { [weak self] _ in
                Task { @MainActor in self?.updatePairing() }
            })
        }
        observers.append(NotificationCenter.default.addObserver(forName: UIApplication.didEnterBackgroundNotification, object: nil, queue: .main) { [weak self] _ in
            Task { @MainActor in
                self?.polling?.cancel(); self?.polling = nil
                self?.connected = false
                self?.discovery.stop()
                self?.changed()
            }
        })
        updatePairing()
    }

    private func updatePairing() {
        let glasses = GlassesSession.shared
        let newKey = glasses.pairedGlasses.flatMap { $0.id } ?? UserDefaults.standard.string(forKey: "BLEFirstGlassInfoKey")
        if pairedKey != newKey {
            generation += 1
            polling?.cancel(); polling = nil
            endpoint = nil; expectedDeviceID = nil; selectedName = nil; snapshot = nil; connected = false
            pairedKey = newKey
            if let key = newKey, let binding = UserDefaults.standard.dictionary(forKey: "ARWA.guideBinding.\(key)"),
               let id = binding["id"] as? String, let raw = binding["url"] as? String, let url = URL(string: raw) {
                expectedDeviceID = id; endpoint = url; selectedName = binding["name"] as? String
            }
        }
        guard newKey != nil else {
            discovery.stop()
            message = "Connect your glasses to set up guides."
            changed(); return
        }
        discovery.start()
        if endpoint != nil { beginPolling() }
        else { message = "Choose your ARWA glasses to finish setup."; changed() }
    }

    func select(_ device: GuideDiscovery.Device) async {
        await select(url: device.url, expectedID: device.deviceID, name: device.name)
    }

    func selectManual(address: String) async {
        let raw = address.trimmingCharacters(in: .whitespacesAndNewlines)
        guard let parts = URLComponents(string: raw.contains("://") ? raw : "http://\(raw)"),
              parts.scheme == "http", parts.host?.isEmpty == false, parts.user == nil, parts.password == nil,
              parts.query == nil, parts.fragment == nil, parts.path.isEmpty || parts.path == "/" else {
            message = "Enter the Wi-Fi address shown on the glasses, such as 192.168.1.25:8080."; changed(); return
        }
        var url = parts
        if url.port == nil { url.port = 8080 }
        url.path = ""
        guard let endpoint = url.url else { return }
        await select(url: endpoint, expectedID: nil, name: nil)
    }

    private func select(url: URL, expectedID: String?, name: String?) async {
        guard let key = pairedKey, !busy else { return }
        busy = true; message = "Connecting to \(name ?? "your glasses")…"; changed()
        generation += 1
        let current = generation
        polling?.cancel(); polling = nil
        connected = false; snapshot = nil; endpoint = nil; expectedDeviceID = nil
        defer { busy = false; changed() }
        do {
            let value = try await fetch(url: url, command: nil)
            guard current == generation, pairedKey == key else { return }
            if let id = expectedID, value.deviceId != id { throw failure("These glasses changed identity. Choose them again.") }
            endpoint = url; expectedDeviceID = value.deviceId; selectedName = name ?? value.deviceLabel
            UserDefaults.standard.set(["id": value.deviceId, "url": url.absoluteString, "name": selectedName!], forKey: "ARWA.guideBinding.\(key)")
            receive(value); beginPolling()
        } catch { if current == generation { message = error.localizedDescription; connected = false } }
    }

    func command(_ command: String) async {
        guard let endpoint, let id = expectedDeviceID, connected, !busy else { return }
        busy = true; changed()
        let current = generation
        defer { busy = false; changed() }
        do {
            let value = try await fetch(url: endpoint, command: ["cmd": command, "job": "coupling", "requestId": UUID().uuidString])
            guard current == generation else { return }
            guard value.deviceId == id else { throw failure("This address belongs to different glasses. Choose your glasses again.") }
            receive(value)
            if command == "start" {
                // A successful HTTP response acknowledges the command, not that the viewer rendered it.
                let target = value.revision
                for _ in 0..<20 {
                    try await Task.sleep(nanoseconds: 300_000_000)
                    let displayed = try await fetch(url: endpoint, command: nil)
                    guard current == generation else { return }
                    guard displayed.deviceId == id else { throw failure("The connected glasses changed.") }
                    receive(displayed)
                    if displayed.viewerReady && displayed.displayedRevision >= target { return }
                }
                message = "Guide selected, but the display hasn’t responded. Open ARWA on the glasses and try again."
            }
        } catch { if current == generation { connected = false; message = error.localizedDescription } }
    }

    private func beginPolling() {
        guard polling == nil, let url = endpoint, let id = expectedDeviceID else { return }
        let current = generation
        polling = Task { [weak self] in
            while !Task.isCancelled {
                guard let self, current == self.generation else { return }
                do {
                    let value = try await self.fetch(url: url, command: nil)
                    guard !Task.isCancelled, current == self.generation else { return }
                    guard value.deviceId == id else { throw self.failure("Different glasses answered. Choose your glasses again.") }
                    self.receive(value)
                } catch {
                    guard !Task.isCancelled, current == self.generation else { return }
                    self.connected = false
                    self.message = "Guide connection lost. Keep ARWA open and both devices on the same Wi-Fi."
                    self.changed()
                }
                try? await Task.sleep(nanoseconds: 750_000_000)
            }
        }
    }

    private func receive(_ value: GuideSnapshot) {
        if let old = snapshot, old.deviceId == value.deviceId, old.revision > value.revision { return }
        snapshot = value; connected = true
        message = value.started ? (value.viewerReady ? "Guide ready on your glasses" : "Open ARWA on your glasses to show the guide.") : "Ready to start a guide"
        changed()
    }

    private func fetch(url: URL, command: [String: String]?) async throws -> GuideSnapshot {
        var request = URLRequest(url: url.appendingPathComponent(command == nil ? "api/companion/status" : "api/companion/command"))
        if let command {
            request.httpMethod = "POST"
            request.setValue("application/json", forHTTPHeaderField: "Content-Type")
            request.httpBody = try JSONSerialization.data(withJSONObject: command)
        }
        let (data, response) = try await session.data(for: request)
        guard let http = response as? HTTPURLResponse, http.statusCode == 200 else {
            let error = (try? JSONSerialization.jsonObject(with: data)) as? [String: Any]
            throw failure(error?["error"] as? String ?? "The glasses couldn’t complete this request.")
        }
        let value = try JSONDecoder().decode(GuideSnapshot.self, from: data)
        guard value.app == "arwa-glasses", value.protocol == 1, value.job == "coupling", value.guideVersion == 1,
              value.total == 8, (0...value.total).contains(value.step), !value.deviceId.isEmpty else {
            throw failure("This device needs the matching ARWA glasses app update.")
        }
        return value
    }

    private func failure(_ message: String) -> NSError { NSError(domain: "ARWA", code: 1, userInfo: [NSLocalizedDescriptionKey: message]) }
    private func changed() { NotificationCenter.default.post(name: .guideConnectionDidChange, object: self) }
}
