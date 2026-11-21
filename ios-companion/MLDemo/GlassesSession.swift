//
//  GlassesSession.swift
//  MLDemo
//
//  Single owner of the SDK's connection, file-sync and Wi-Fi callbacks.
//  Screens read state from here and reload on `.glassesDidChange`.
//

import UIKit
import CoreBluetooth
import MLVisionM6SDK

extension Notification.Name {
    static let glassesDidChange = Notification.Name("GlassesSession.didChange")
    static let glassesWifiJoinResult = Notification.Name("GlassesSession.wifiJoinResult")
    static let eventLogDidChange = Notification.Name("EventLog.didChange")
}

/// Adds a line to the in-app Event Log (and the Xcode console).
func appLog(_ message: String) {
    EventLog.shared.add(message)
    print("[app] \(message)")
}

final class EventLog {
    static let shared = EventLog()
    private(set) var lines: [String] = []
    private let maxLines = 1000
    private let timeFormatter: DateFormatter = {
        let formatter = DateFormatter()
        formatter.dateFormat = "HH:mm:ss"
        return formatter
    }()

    func add(_ message: String) {
        print("APP_\(message)")
        let now = Date()
        DispatchQueue.main.async {
            self.lines.append("\(self.timeFormatter.string(from: now))  \(message)")
            if self.lines.count > self.maxLines {
                self.lines.removeFirst(self.lines.count - self.maxLines)
            }
            NotificationCenter.default.post(name: .eventLogDidChange, object: nil)
        }
    }

    func clear() {
        lines.removeAll()
        NotificationCenter.default.post(name: .eventLogDidChange, object: nil)
    }

    var text: String { lines.joined(separator: "\n") }
}

/// A pair of glasses seen while searching.
struct NearbyGlasses: Equatable {
    let id: String          // the SDK's device identifier ("mac" in its discovery payload)
    var name: String
    var rssi: Int
    var lastSeen: Date

    var signal: String {
        switch rssi {
        case 1...: return "Signal unknown"   // 127 = unavailable
        case (-60)...: return "Strong signal"
        case (-75)..<(-60): return "Good signal"
        default: return "Weak signal"
        }
    }

    var shortID: String { id.count > 6 ? "…" + id.suffix(6) : id }
}

/// Watches the phone's Bluetooth power and permission state (the SDK doesn't report it).
final class BluetoothMonitor: NSObject, CBCentralManagerDelegate {
    private var manager: CBCentralManager?
    var onChange: ((CBManagerState) -> Void)?
    var state: CBManagerState { manager?.state ?? .unknown }

    func start() {
        manager = CBCentralManager(delegate: self, queue: .main,
                                   options: [CBCentralManagerOptionShowPowerAlertKey: false])
    }

    func centralManagerDidUpdateState(_ central: CBCentralManager) {
        onChange?(central.state)
    }
}

final class GlassesSession {
    static let shared = GlassesSession()

    enum ConnectionState: Equatable {
        case idle
        case searching
        case connecting(name: String)
        case connected
        case reconnecting(attempt: Int)
        case bluetoothOff
        case bluetoothUnauthorized
    }

    /// Screen timeout choices, in the order the SDK expects (0–3).
    static let screenTimeoutOptions = ["15 seconds", "30 seconds", "1 minute", "Always on"]

    /// Delays (seconds) before each reconnect attempt after an unexpected disconnect.
    private static let reconnectDelays: [Double] = [1, 3, 5, 10, 20, 30, 30]
    var reconnectLimit: Int { Self.reconnectDelays.count }

    private(set) var state: ConnectionState = .idle {
        didSet { if state != oldValue { updateDiscoveryPolicy() } }
    }
    /// Why the last connection ended or failed. Shown while idle.
    private(set) var idleMessage: String?
    private(set) var idleMessageIsError = false
    /// Pairs found while searching, in the order they were first seen.
    private(set) var nearby: [NearbyGlasses] = []
    /// Name of the pair currently (or most recently) connected.
    private(set) var connectedName: String?
    /// When the current connection started (for the uptime readout).
    private(set) var connectedSince: Date?
    private(set) var glassInfo: [String: Any] = [:]
    /// Latest battery percentage and charging state reported by the glasses.
    private(set) var batteryLevel: Int?
    private(set) var isCharging: Bool?

    private(set) var pendingFiles: [[String: Any]] = []   // waiting on the glasses
    private(set) var syncedFiles: [[String: Any]] = []    // downloaded to the phone
    private(set) var fileTransfer: FileTransferState = .idle
    private var requestedFileCount = 0
    private var receivedFileCount = 0

    enum FileTransferState: Equatable {
        case idle
        case checking
        case downloading(received: Int, total: Int)
        case finished(count: Int)
        case failed(String)
    }

    /// Seconds without a new file before a download is reported as stalled.
    private static let fileStallTimeout: Double = 45

    private(set) var wifiNetworks: [[String: Any]] = []
    private(set) var lastWifiUpdate: [String: Any]?

    // Last values sent to the glasses (the SDK doesn't report all of them back).
    private(set) var volume = 50
    private(set) var brightness = 5
    private(set) var screenTimeout = 0
    private(set) var developerMode = false

    var isConnected: Bool { state == .connected }

    var isReconnecting: Bool {
        if case .reconnecting = state { return true }
        return false
    }

    var isConnecting: Bool {
        if case .connecting = state { return true }
        return false
    }

    /// Bluetooth is usable (or not yet known).
    var canUseBluetooth: Bool { state != .bluetoothOff && state != .bluetoothUnauthorized }

    /// The pair this phone is bound to, from the SDK's saved binding. The SDK connects to it
    /// automatically whenever it sees it while scanning.
    var pairedGlasses: (id: String?, name: String)? {
        // The SDK saves the bound pair's serial under BLEFirstGlassInfoKey (removed on unbind) and its details
        // under BLEGlassInfoKey.
        let defaults = UserDefaults.standard
        guard let serial = defaults.string(forKey: "BLEFirstGlassInfoKey"), !serial.isEmpty else { return nil }
        let info = defaults.dictionary(forKey: "BLEGlassInfoKey") ?? [:]
        let id = ["deviceIdentifier", "macAddress", "mac", "sn"].lazy.compactMap { info[$0] as? String }.first(where: { !$0.isEmpty })
        let name = ["name", "deviceName", "glassName", "bleName"].lazy
            .compactMap { info[$0] as? String }
            .first(where: { !$0.isEmpty })
            .map(Self.cleanName) ?? connectedName ?? "Paired Glasses"
        return (id, name)
    }

    private var started = false
    private var observers: [NSObjectProtocol] = []
    private let bluetooth = BluetoothMonitor()
    private var work: [String: DispatchWorkItem] = [:]

    private var lastDiscoveredID: String?       // the SDK connects to the pair it discovered last
    private var targetID: String? {
        didSet { updateDiscoveryPolicy() }
    }   // pair we're trying to reach
    private var targetName: String?
    private var isFindingTarget = false         // rescanning until the SDK discovers the target
    private var lastConnectedID: String?
    private var userEndedConnection = false     // don't auto-reconnect after Disconnect/Unbind
    private var reconnectAttempt = 0
    /// Set while we drop a connection the SDK made on its own, so the disconnect that follows isn't treated as a failure.
    private var rejectingConnection = false
    private var loggedRejectedIDs: Set<String> = []
    private var loggedNearbyIDs: Set<String> = []

    // MARK: Setup

    /// Initializes the SDK once and registers every callback. Mirrors the vendor demo's `initMLVisionM6SDK()`.
    func start(delegate: NSObject) {
        guard !started else { return }
        started = true

        DiscoveryGate.onPairedSeen = { [weak self] rssi in self?.pairedSeenWhileSearching(rssi: rssi) }
        DiscoveryGate.install()
        BluetoothTrafficProbe.install()
        updateDiscoveryPolicy()
        MLVisionM6SDKManager.setLog(true)
        MLVisionM6OCSDK.setShowLog(true)   // the SDK's own diagnostics, written to Documents/Logs
        InterpretingTap.install()          // reads live interpreting results from those logs
        MLVisionM6SDKManager.sdkInit(withDelegate: delegate)
        // SDK-provided screens in English (MLSDKLanguageType_English = 1)
        MLVisionM6OCSDK.setAppLanguage(languageType: MLSDKLanguageType(rawValue: 1)!)
        SpeechLanguages.applyAtStartup()      // English by default, then the user's last choice

        let center = NotificationCenter.default
        func on(_ name: String, _ handler: @escaping (Notification) -> Void) {
            observers.append(center.addObserver(forName: NSNotification.Name(rawValue: name), object: nil, queue: .main, using: handler))
        }
        on(MLVisonBLEBindDeviceNotification) { [weak self] _ in self?.didBind() }
        on(MLVisonBLEBindFailDeviceNotification) { [weak self] _ in self?.didFailToBind() }
        on(MLVisonBLEDisconnectDeviceNotification) { [weak self] _ in self?.didDisconnect() }
        on(MLVisonBLEUnbindDeviceNotification) { [weak self] _ in self?.didUnbind(byGlasses: true) }
        on(MLVisonBLEDiscoverTimeoutNotification) { [weak self] _ in self?.didHitDiscoverTimeout() }
        on(MLVisonBLEDiscoverDeviceNotification) { [weak self] note in
            guard let device = note.object as? [String: Any] else { return }
            self?.didDiscover(device)
        }
        observers.append(center.addObserver(forName: UIApplication.willEnterForegroundNotification, object: nil, queue: .main) { [weak self] _ in
            self?.didEnterForeground()
        })

        bluetooth.onChange = { [weak self] state in self?.bluetoothChanged(state) }
        bluetooth.start()

        MLVisionM6SDKManager.handleBLEMessage { [weak self] type, info in
            appLog("BLE message (type \(type)): \(info)")
            // Status updates (type 10) carry battery level and charging state whenever they change.
            guard type == 10, let payload = info["pljson"] as? [AnyHashable: Any] else { return }
            // If the glasses echo developer mode back, trust their value over what we last sent.
            if let developer = (payload["developer_mode"] as? Bool).map({ $0 ? 1 : 0 }) ?? Self.intValue(payload["developer_mode"]) {
                DispatchQueue.main.async { self?.update { $0.developerMode = developer != 0 } }
            }
            // …and the glasses' Wi-Fi state: {"wifi": {"connected_info": {"ssid", "bssid", "enable"}}}.
            if let wifi = payload["wifi"] as? [AnyHashable: Any], let status = wifi["connected_info"] as? [AnyHashable: Any] {
                let ssid = status["ssid"] as? String ?? ""
                let enabled = Self.intValue(status["enable"]).map { $0 != 0 }
                DispatchQueue.main.async { self?.updateWifiStatus(ssid: ssid, enabled: enabled) }
            }
            let level = Self.intValue(payload["get_battery_info"])
            let charging = Self.intValue(payload["get_charge_state"]).map { $0 != 0 }
            guard level != nil || charging != nil else { return }
            DispatchQueue.main.async { self?.updateBattery(level: level, charging: charging) }
        }

        MLVisionM6SDKManager.fileTransferBlock { [weak self] type, data in
            DispatchQueue.main.async { self?.handleFileTransfer(type: type, data: data) }
        }

        MLVisionM6OCSDK.getBleWifiChangedBlock { [weak self] info in
            DispatchQueue.main.async { self?.handleWifiUpdate(info) }
        }

        MLVisionM6OCSDK.getBleWifiConnectResultBlock { [weak self] success in
            DispatchQueue.main.async {
                appLog("Glasses Wi-Fi join result: \(success ? "success" : "failed")")
                if success, let name = self?.pendingJoinName { self?.confirmedWifiName = name }
                self?.pendingJoinName = nil
                NotificationCenter.default.post(name: .glassesWifiJoinResult, object: nil, userInfo: ["success": success])
                self?.changed()
            }
        }

        appLog("SDK started")
        if let paired = pairedGlasses {
            appLog("Paired with \(paired.name) (\(paired.id ?? "no ID saved"))")
        }
    }

    // MARK: Searching

    /// Collects nearby pairs. The SDK stops scanning at the first pair it finds, so we restart
    /// its scan after each discovery to build a full list.
    func startSearching() {
        guard canUseBluetooth else { return }
        cancelAllWork()
        userEndedConnection = false
        nearby = []
        loggedNearbyIDs = []
        loggedRejectedIDs = []
        setIdleMessage(nil)
        state = .searching
        appLog("Searching for glasses")
        MLVisionM6SDKManager.startScan()
        schedule("searchLimit", after: 60) { [weak self] in
            guard let self else { return }
            self.finishSearching(message: self.nearby.isEmpty ? "No glasses found. Make sure they’re on and close to your phone." : nil)
        }
        schedulePrune()
        changed()
    }

    func stopSearching() {
        finishSearching(message: nil)
    }

    private func finishSearching(message: String?) {
        guard state == .searching else { return }
        cancel("rescan", "searchLimit", "prune")
        MLVisionM6SDKManager.stopScan()
        appLog("Stopped searching")
        state = .idle
        setIdleMessage(message)
        changed()
    }

    private func rescanSoon() {
        schedule("rescan", after: 0.3) {
            MLVisionM6SDKManager.startScan()
        }
    }

    /// Drops pairs that haven't been seen recently.
    private func schedulePrune() {
        schedule("prune", after: 3) { [weak self] in
            guard let self, self.state == .searching else { return }
            let cutoff = Date().addingTimeInterval(-20)
            let before = self.nearby.count
            self.nearby.removeAll { $0.lastSeen < cutoff }
            if self.nearby.count != before { self.changed() }
            self.schedulePrune()
        }
    }

    // MARK: Connecting

    /// Connects to a specific pair from the search results.
    func connect(to device: NearbyGlasses) {
        guard canUseBluetooth else { return }
        cancelAllWork()
        userEndedConnection = false
        targetID = device.id
        targetName = device.name
        state = .connecting(name: device.name)
        setIdleMessage(nil)

        if lastDiscoveredID == device.id {
            // The SDK's current discovery is this pair, so it will connect to it.
            MLVisionM6SDKManager.stopScan()
            beginConnect()
        } else {
            // Rescan until the SDK discovers this pair, then connect.
            appLog("Looking for \(device.name) (\(device.shortID))")
            isFindingTarget = true
            MLVisionM6SDKManager.startScan()
            schedule("findTimeout", after: 20) { [weak self] in
                self?.connectFailed("Couldn’t find \(device.name). Make sure the glasses are on and nearby, then try again.")
            }
        }
        changed()
    }

    /// Connects to the bound pair (the SDK connects to it when it sees it while scanning).
    func connectToPaired() {
        guard canUseBluetooth, let paired = pairedGlasses else { return }
        cancelAllWork()
        userEndedConnection = false
        targetID = paired.id
        targetName = paired.name
        isFindingTarget = true
        state = .connecting(name: paired.name)
        setIdleMessage(nil)
        appLog("Looking for paired glasses \(paired.name)")
        MLVisionM6SDKManager.startScan()
        schedule("findTimeout", after: 20) { [weak self] in
            self?.connectFailed("\(paired.name) weren’t found nearby. Make sure they’re on, then try again.")
        }
        changed()
    }

    func cancelConnecting() {
        appLog("Connection cancelled")
        userEndedConnection = true
        cancelAllWork()
        MLVisionM6SDKManager.stopScan()
        MLVisionM6SDKManager.cancelConnect()
        resetTarget()
        state = .idle
        setIdleMessage(nil)
        changed()
    }

    private func beginConnect() {
        isFindingTarget = false
        cancel("findTimeout", "rescan")
        appLog("Connecting to \(targetName ?? "glasses")")
        MLVisionM6SDKManager.startConnect()
        schedule("connectTimeout", after: 15) { [weak self] in
            guard let self else { return }
            MLVisionM6SDKManager.cancelConnect()
            self.connectFailed("\(self.targetName ?? "The glasses") didn’t respond. Try again, or restart the glasses.")
        }
    }

    private func connectFailed(_ message: String) {
        appLog("Connection failed: \(message)")
        cancelAllWork()
        MLVisionM6SDKManager.stopScan()
        resetTarget()
        state = .idle
        setIdleMessage(message, isError: true)
        changed()
    }

    private func resetTarget() {
        targetID = nil
        targetName = nil
        isFindingTarget = false
    }

    // MARK: Disconnecting

    func disconnect() {
        appLog("Disconnecting")
        userEndedConnection = true
        cancelAllWork()
        MLVisionM6SDKManager.cancelConnect()
        clearConnectionData()
        state = .idle
        setIdleMessage(nil)
        changed()
    }

    func unbind() {
        appLog("Unbinding glasses")
        userEndedConnection = true
        cancelAllWork()
        MLVisionM6SDKManager.unbound()
        didUnbind(byGlasses: false)
    }

    /// Stops trying to reconnect after an unexpected disconnect.
    func stopReconnecting() {
        appLog("Stopped reconnecting")
        userEndedConnection = true
        cancelAllWork()
        MLVisionM6SDKManager.stopScan()
        state = .idle
        setIdleMessage("Disconnected from \(connectedName ?? "the glasses").")
        changed()
    }

    // MARK: SDK events

    private func didDiscover(_ payload: [String: Any]) {
        let device = NearbyGlasses(id: Self.deviceID(payload), name: Self.displayName(payload),
                                   rssi: (payload["rssi"] as? Int) ?? 127, lastSeen: Date())
        lastDiscoveredID = device.id
        if !loggedNearbyIDs.contains(device.id) {
            loggedNearbyIDs.insert(device.id)
            appLog("Found \(device.name) (\(device.id)), \(device.signal.lowercased())")
        }

        switch state {
        case .searching:
            if let index = nearby.firstIndex(where: { $0.id == device.id }) {
                nearby[index] = device
            } else {
                nearby.append(device)
            }
            changed()
            rescanSoon()

        case .connecting:
            guard isFindingTarget else { return }
            if let targetID, device.id == targetID {
                beginConnect()
            } else {
                rescanSoon()
            }

        case .reconnecting:
            // Only after an unexpected drop: reconnect to the pair that was connected.
            if let lastConnectedID, device.id == lastConnectedID {
                targetID = device.id
                targetName = connectedName
                beginConnect()
            }

        default:
            break
        }
    }

    private func didHitDiscoverTimeout() {
        switch state {
        case .searching:
            rescanSoon()
        case .connecting where isFindingTarget:
            rescanSoon()
        default:
            break
        }
    }

    private func didBind() {
        let info = Self.stringKeyed(MLVisionM6SDKManager.getGlassInfo())
        let wasReconnecting = isReconnecting

        // Only keep connections the user asked for, to the pair they asked for. The SDK connects to the
        // paired glasses by itself whenever it sees them (while scanning, from its keep-alive timer, or when
        // iOS restores Bluetooth), so anything else is dropped right away.
        let boundID = Self.deviceID(info)
        let boundName = Self.displayName(info)
        switch state {
        case .connecting:
            if let targetID, !Self.sameDevice(targetID, boundID) {
                rejectConnection(id: boundID, name: boundName, reason: "not the pair you chose")
                return
            }
        case .reconnecting:
            if let lastConnectedID, !Self.sameDevice(lastConnectedID, boundID) {
                rejectConnection(id: boundID, name: boundName, reason: "not the pair that was connected")
                return
            }
        case .connected:
            break   // a repeat notice for the current connection
        default:
            rejectConnection(id: boundID, name: boundName, reason: "you didn’t ask to connect")
            if state == .searching {
                // Show the pair in the list so it can be chosen.
                if let index = nearby.firstIndex(where: { Self.sameDevice($0.id, boundID) }) {
                    nearby[index].lastSeen = Date()
                } else {
                    nearby.append(NearbyGlasses(id: boundID, name: boundName, rssi: 127, lastSeen: Date()))
                }
                changed()
            }
            return
        }

        cancelAllWork()
        lastConnectedID = targetID ?? pairedGlasses?.id ?? lastDiscoveredID ?? lastConnectedID
        connectedName = targetName ?? pairedGlasses?.name ?? connectedName ?? "M6 Glasses"
        resetTarget()
        reconnectAttempt = 0
        userEndedConnection = false
        glassInfo = info
        batteryLevel = Self.batteryLevel(in: info) ?? batteryLevel
        if let charging = Self.intValue(info["get_charge_state"] ?? info["charging"]) { isCharging = charging != 0 }
        if let volume = info["volume"] as? Int { self.volume = volume }
        state = .connected
        connectedSince = Date()
        setIdleMessage(nil)
        appLog(wasReconnecting ? "Reconnected to \(connectedName ?? "glasses")" : "Connected: \(info)")
        changed()

        scheduleBatteryPoll()

        // Register the glasses voice assistant, and switch the glasses UI to English (0 = Chinese, 1 = English).
        MLVisionM6OCSDK.notifyFlavor(flavor: "namibox")
        MLVisionM6OCSDK.setGlassLanguage(language: 1)
    }

    private func rejectConnection(id: String, name: String, reason: String) {
        if !loggedRejectedIDs.contains(id + reason) {
            loggedRejectedIDs.insert(id + reason)
            appLog("Dropped automatic connection to \(name) (\(id)): \(reason)")
        }
        rejectingConnection = true
        MLVisionM6SDKManager.cancelConnect()
        if isConnecting && !isFindingTarget {
            // The SDK grabbed the wrong pair mid-connect; go back to looking for the chosen one.
            cancel("connectTimeout")
            isFindingTarget = true
            let name = targetName ?? "the glasses"
            schedule("findTimeout", after: 20) { [weak self] in
                self?.connectFailed("Couldn’t find \(name). Make sure the glasses are on and nearby, then try again.")
            }
        }
        // Keep scanning if we're still looking for something.
        if state == .searching || isConnecting || isReconnecting { rescanSoon() }
    }

    /// Compares device IDs. MAC addresses are compared without separators or case; anything that
    /// can't be compared that way is assumed to match rather than risk dropping the right pair.
    static func sameDevice(_ a: String, _ b: String) -> Bool {
        func mac(_ value: String) -> String? {
            let hex = value.uppercased().filter { $0.isHexDigit }
            return hex.count == 12 && value.count <= 17 ? hex : nil
        }
        guard let first = mac(a), let second = mac(b) else { return true }
        return first == second
    }

    private func didFailToBind() {
        appLog("SDK reported a failed connection")
        switch state {
        case .connecting(let name):
            connectFailed("Couldn’t connect to \(name). Try again.")
        case .reconnecting:
            break   // keep trying
        default:
            break
        }
    }

    private func didDisconnect() {
        if rejectingConnection {
            rejectingConnection = false
            if state != .connected { return }   // we dropped a connection we didn't want; nothing changes
        }
        appLog("Disconnected")
        clearConnectionData()

        guard canUseBluetooth else { return }   // Bluetooth off/denied is shown instead
        if userEndedConnection {
            if state != .searching { state = .idle }
            changed()
            return
        }
        switch state {
        case .connected:
            appLog("Connection lost unexpectedly; reconnecting")
            reconnectAttempt = 0
            scheduleReconnectAttempt()
        case .connecting(let name):
            connectFailed("The connection to \(name) dropped. Try again.")
        default:
            changed()
        }
    }

    private func didUnbind(byGlasses: Bool) {
        if byGlasses { appLog("Glasses reported they were unbound") }
        cancelAllWork()
        clearConnectionData()
        resetTarget()
        glassInfo = [:]
        connectedName = nil
        lastConnectedID = nil
        lastDiscoveredID = nil
        nearby = []
        if canUseBluetooth { state = .idle }
        setIdleMessage(byGlasses ? "The glasses were unbound from this phone." : nil)
        changed()
    }

    // MARK: Reconnecting

    private func scheduleReconnectAttempt() {
        guard reconnectAttempt < Self.reconnectDelays.count else {
            MLVisionM6SDKManager.stopScan()
            state = .idle
            setIdleMessage("Lost connection to \(connectedName ?? "the glasses"). Make sure they’re on and nearby, then reconnect.",
                           isError: true)
            appLog("Gave up reconnecting")
            changed()
            return
        }
        let delay = Self.reconnectDelays[reconnectAttempt]
        reconnectAttempt += 1
        state = .reconnecting(attempt: reconnectAttempt)
        changed()
        schedule("reconnect", after: delay) { [weak self] in
            guard let self, self.isReconnecting else { return }
            appLog("Reconnect attempt \(self.reconnectAttempt) of \(Self.reconnectDelays.count)")
            MLVisionM6SDKManager.startScan()   // paired glasses reconnect automatically when seen
            self.schedule("reconnectNext", after: 8) { [weak self] in self?.scheduleReconnectAttempt() }
        }
    }

    private func didEnterForeground() {
        // Timers may not have fired while in the background; try again right away.
        if isReconnecting {
            appLog("Back in foreground; retrying connection")
            reconnectAttempt = max(0, reconnectAttempt - 1)
            cancel("reconnect", "reconnectNext")
            scheduleReconnectAttempt()
        }
    }

    // MARK: Bluetooth state

    private func bluetoothChanged(_ bluetoothState: CBManagerState) {
        switch bluetoothState {
        case .poweredOn:
            appLog("Bluetooth is on")
            if state == .bluetoothOff || state == .bluetoothUnauthorized {
                state = .idle
                setIdleMessage(nil)
            }
            // Never connect on our own here: the user picks glasses and taps Connect.
            changed()
        case .poweredOff:
            appLog("Bluetooth is off")
            cancelAllWork()
            clearConnectionData()
            resetTarget()
            state = .bluetoothOff
            changed()
        case .unauthorized:
            appLog("Bluetooth access not allowed")
            cancelAllWork()
            resetTarget()
            state = .bluetoothUnauthorized
            changed()
        default:
            break   // unknown / resetting / unsupported
        }
    }

    /// Data that came from the glasses and is stale once they disconnect.
    private func clearConnectionData() {
        connectedSince = nil
        batteryLevel = nil
        isCharging = nil
        cancel("batteryPoll")
        pendingFiles = []
        if fileTransfer != .idle { fileTransfer = .idle }
        cancel("files")
        wifiNetworks = []
        lastWifiUpdate = nil
        confirmedWifiName = nil
        wifiStatusKnown = false
        reportedWifiOn = nil
        // pendingJoinName survives: joining a network makes the glasses drop Bluetooth for a few seconds.
    }

    private func setIdleMessage(_ message: String?, isError: Bool = false) {
        idleMessage = message
        idleMessageIsError = isError && message != nil
    }

    // MARK: Scheduled work

    private func schedule(_ key: String, after seconds: Double, _ block: @escaping () -> Void) {
        work[key]?.cancel()
        let item = DispatchWorkItem(block: block)
        work[key] = item
        DispatchQueue.main.asyncAfter(deadline: .now() + seconds, execute: item)
    }

    private func cancel(_ keys: String...) {
        for key in keys {
            work[key]?.cancel()
            work[key] = nil
        }
    }

    private func cancelAllWork() {
        work.values.forEach { $0.cancel() }
        work = [:]
    }

    private func updateBattery(level: Int?, charging: Bool?) {
        guard isConnected else { return }
        let newLevel = level.map { min(max($0, 0), 100) } ?? batteryLevel
        let newCharging = charging ?? isCharging
        guard newLevel != batteryLevel || newCharging != isCharging else { return }
        batteryLevel = newLevel
        isCharging = newCharging
        changed()
    }

    /// Backup for the glasses' own updates: re-read the SDK's device info once a minute.
    private func scheduleBatteryPoll() {
        schedule("batteryPoll", after: 60) { [weak self] in
            guard let self, self.isConnected else { return }
            let info = Self.stringKeyed(MLVisionM6SDKManager.getGlassInfo())
            self.updateBattery(level: Self.batteryLevel(in: info),
                               charging: Self.intValue(info["get_charge_state"] ?? info["charging"]).map { $0 != 0 })
            self.scheduleBatteryPoll()
        }
    }

    func refreshGlassInfo() {
        update { $0.glassInfo = Self.stringKeyed(MLVisionM6SDKManager.getGlassInfo()) }
    }

    // MARK: Settings

    func setVolume(_ value: Int) {
        let clamped = min(max(value, 0), 100)
        appLog("Volume → \(clamped)")
        MLVisionM6SDKManager.setGlassVolume(clamped)
        update { $0.volume = clamped }
    }

    func setBrightness(_ value: Int) {
        let clamped = min(max(value, 0), 10)
        appLog("Brightness → \(clamped)")
        MLVisionM6OCSDK.setGlassScreenLight(screenLight: clamped)
        update { $0.brightness = clamped }
    }

    func setScreenTimeout(_ index: Int) {
        let clamped = min(max(index, 0), Self.screenTimeoutOptions.count - 1)
        appLog("Screen timeout → \(Self.screenTimeoutOptions[clamped])")
        MLVisionM6OCSDK.setGlassScreenTime(screenTime: clamped)
        update { $0.screenTimeout = clamped }
    }

    /// Turns the glasses' developer mode (USB debugging / ADB) on or off.
    /// Same message as the Android SDK: DevModel.addDeveloperMode(on) adds {"developer_mode": on},
    /// and DevInfoHelper.sendDevMsg sends it unchanged on the DEVINFO channel (type 10).
    func setDeveloperMode(_ on: Bool) {
        appLog("Developer mode → \(on ? "on" : "off")")
        MLVisionM6SDKManager.sendBLEMessage(10, message: ["developer_mode": on])
        update { $0.developerMode = on }
    }

    // MARK: Files

    func requestFiles() {
        appLog("Asking glasses for files to sync")
        fileTransfer = .checking
        changed()
        MLVisionM6SDKManager.requestWaitSendFile()
        schedule("files", after: 15) { [weak self] in
            guard let self, self.fileTransfer == .checking else { return }
            appLog("Glasses didn’t answer the file list request")
            self.update { $0.fileTransfer = .failed("The glasses didn’t respond. Try again.") }
        }
    }

    func downloadPendingFiles() {
        var paths: [String] = []
        for file in pendingFiles {
            if let bigPath = file["bigPath"] as? String, !bigPath.isEmpty { paths.append(bigPath) }
            if let coverPic = file["coverPic"] as? String, !coverPic.isEmpty { paths.append(coverPic) }
        }
        guard !paths.isEmpty else { return }
        if let problem = Self.fileTransferNetworkProblem() {
            appLog("Download not started: \(problem)")
            update { $0.fileTransfer = .failed(problem) }
            return
        }
        appLog("Requesting \(paths.count) file(s) over Wi-Fi (phone at \(Self.localIPv4Addresses().map { "\($0.interface) \($0.address)" }.joined(separator: ", ")))")
        requestedFileCount = pendingFiles.count
        receivedFileCount = 0
        update { $0.fileTransfer = .downloading(received: 0, total: $0.requestedFileCount) }
        MLVisionM6SDKManager.sendTransferFile(paths)
        scheduleFileStall()
    }

    private func scheduleFileStall() {
        schedule("files", after: Self.fileStallTimeout) { [weak self] in
            guard let self, case .downloading(let received, _) = self.fileTransfer else { return }
            appLog("Download stalled after \(received) file(s)")
            self.update {
                $0.fileTransfer = .failed(received == 0
                    ? "No files arrived. Put the glasses and phone on the same network."
                    : "Stopped after \(received) file\(received == 1 ? "" : "s"). Try again.")
            }
        }
    }

    /// The SDK reports file errors in Chinese; turn the known ones into guidance.
    static func fileErrorMessage(_ raw: String) -> String {
        if raw.contains("不在同一个网络") {
            return "Not on the same network. Try this phone’s Personal Hotspot."
        }
        if raw.range(of: "\\p{Han}", options: .regularExpression) != nil {
            return "The glasses couldn’t send the files. Try again."
        }
        return raw
    }

    /// Files travel over Wi-Fi: this phone runs a small server and the glasses connect to it,
    /// so both need to be on the same network (or the glasses on this phone's Personal Hotspot).
    static func fileTransferNetworkProblem() -> String? {
        let interfaces = Set(localIPv4Addresses().map(\.interface))
        let phoneOnWifi = interfaces.contains("en0")
        let phoneHotspot = interfaces.contains { $0.hasPrefix("bridge") }
        if !phoneOnWifi && !phoneHotspot {
            return "This phone isn’t on Wi-Fi or Personal Hotspot."
        }
        // The SDK always gives the glasses this phone's Wi-Fi address, even when they're on its hotspot.
        if phoneOnWifi && phoneHotspot {
            return "Turn off this phone’s Wi-Fi in Settings so files go through Personal Hotspot."
        }
        return nil
    }

    /// A file's name without any folder, from whichever key the SDK filled in.
    static func fileName(of file: [String: Any]) -> String {
        for key in ["fileName", "bigPath", "originFileName", "localPath"] {
            if let value = file[key] as? String, !value.isEmpty { return (value as NSString).lastPathComponent }
        }
        return ""
    }

    static func localIPv4Addresses() -> [(interface: String, address: String)] {
        var result: [(String, String)] = []
        var first: UnsafeMutablePointer<ifaddrs>?
        guard getifaddrs(&first) == 0 else { return [] }
        defer { freeifaddrs(first) }
        var pointer = first
        while let entry = pointer?.pointee {
            defer { pointer = entry.ifa_next }
            guard let address = entry.ifa_addr, address.pointee.sa_family == UInt8(AF_INET),
                  (entry.ifa_flags & UInt32(IFF_UP)) != 0 else { continue }
            let name = String(cString: entry.ifa_name)
            guard name == "en0" || name.hasPrefix("bridge") else { continue }
            var host = [CChar](repeating: 0, count: Int(NI_MAXHOST))
            if getnameinfo(address, socklen_t(address.pointee.sa_len), &host, socklen_t(host.count), nil, 0, NI_NUMERICHOST) == 0 {
                result.append((name, String(cString: host)))
            }
        }
        return result
    }

    func confirmDownloads() {
        let names = syncedFiles.compactMap { $0["fileName"] as? String }
        guard !names.isEmpty else { return }
        appLog("Confirming \(names.count) downloaded file(s)")
        MLVisionM6SDKManager.sendFileArrayDownloadConfirm(names)
    }

    func deleteFromGlasses(fileName: String) {
        appLog("Deleting \(fileName) from glasses")
        MLVisionM6SDKManager.sendFileArrayDelete([fileName])
    }

    private func handleFileTransfer(type: MLVisionFileTransferType, data: Any) {
        switch type {
        case .typeError:
            appLog("File transfer error: \(data)")
            let message = Self.fileErrorMessage(data as? String ?? "\(data)")
            cancel("files")
            update { $0.fileTransfer = .failed(message) }
        case .typeWaitSendFile:
            appLog("Files waiting on glasses: \((data as? [Any])?.count ?? 0)")
            if fileTransfer == .checking { cancel("files") }
            update {
                $0.pendingFiles = data as? [[String: Any]] ?? []
                if $0.fileTransfer == .checking { $0.fileTransfer = .idle }
            }
        case .typDownloadFile:
            appLog("Downloaded: \(data)")
            guard let file = data as? [String: Any] else { break }
            let name = Self.fileName(of: file)
            // Each photo or video arrives along with its thumbnail; count only the main file.
            let isThumbnail = name.hasPrefix("cover_pic_")
            update { session in
                if !session.syncedFiles.contains(where: { Self.fileName(of: $0) == name }) {
                    session.syncedFiles.append(file)
                }
                session.pendingFiles.removeAll { Self.fileName(of: $0) == name }
                guard case .downloading = session.fileTransfer, !isThumbnail else { return }
                session.receivedFileCount += 1
                if session.receivedFileCount >= session.requestedFileCount {
                    session.fileTransfer = .finished(count: session.receivedFileCount)
                } else {
                    session.fileTransfer = .downloading(received: session.receivedFileCount, total: session.requestedFileCount)
                }
            }
            if case .downloading = fileTransfer { scheduleFileStall() } else { cancel("files") }
        case .typeDeleteFile:
            appLog("Glasses confirmed deleted files: \(data)")
            if let deleted = data as? [String] {
                update { session in
                    session.syncedFiles.removeAll { deleted.contains($0["fileName"] as? String ?? "") }
                }
                MLVisionM6SDKManager.deleteLocalFile(deleted)
            }
        @unknown default:
            appLog("File transfer event \(type.rawValue): \(data)")
        }
    }

    // MARK: Wi-Fi

    var wifiEnabled: Bool { reportedWifiOn ?? MLVisionM6OCSDK.getWifiEnable() }

    /// The network the glasses joined most recently, from the SDK's saved settings. This can be stale: the SDK
    /// keeps it across sessions and the glasses don't report when they leave a network.
    var lastJoinedWifiName: String? {
        guard let name = MLVisionM6OCSDK.getWifiConnectInfo()?["ssid"] as? String, !name.isEmpty else { return nil }
        return name
    }

    /// The network the glasses report being on during this connection (nil if none or not reported yet).
    private(set) var confirmedWifiName: String?
    /// Whether the glasses have reported their Wi-Fi state during this connection.
    private(set) var wifiStatusKnown = false
    private var reportedWifiOn: Bool?
    private var pendingJoinName: String?

    private func updateWifiStatus(ssid: String, enabled: Bool?) {
        let name = ssid.isEmpty ? nil : ssid
        guard !wifiStatusKnown || name != confirmedWifiName || (enabled != nil && enabled != reportedWifiOn) else { return }
        appLog("Glasses Wi-Fi: \(name.map { "on “\($0)”" } ?? "not on a network")\(enabled == false ? ", Wi-Fi off" : "")")
        wifiStatusKnown = true
        confirmedWifiName = name
        if let enabled { reportedWifiOn = enabled }
        changed()
    }

    func setWifi(on: Bool) {
        appLog("Glasses Wi-Fi → \(on ? "on" : "off")")
        MLVisionM6OCSDK.setGlassWifi(isOpen: on)
        changed()
    }

    func scanWifi() {
        appLog("Glasses scanning for Wi-Fi networks")
        update { $0.wifiNetworks = [] }
        MLVisionM6OCSDK.startScanWifi()
    }

    func joinWifi(ssid: String, bssid: String, password: String) {
        appLog("Asking glasses to join “\(ssid)”")   // never log the password
        pendingJoinName = ssid
        MLVisionM6OCSDK.connectToWifi(ssid: ssid, bssid: bssid, password: password)
    }

    private func handleWifiUpdate(_ raw: [AnyHashable: Any]) {
        let info = Self.stringKeyed(raw)
        appLog("Glasses Wi-Fi update: \(Self.redactingPasswords(info))")
        update { session in
            session.lastWifiUpdate = info
            // Scan results follow the protocol in the PDF: {"info": [{ssid, bssid, ...}]}, possibly wrapped in "wifi".
            let wrapped = info["wifi"] as? [String: Any]
            if let list = (info["info"] ?? wrapped?["info"]) as? [[String: Any]] {
                session.wifiNetworks = list
            }
        }
    }

    // MARK: Helpers

    private func update(_ change: (GlassesSession) -> Void) {
        change(self)
        changed()
    }

    /// Tells the discovery filter whether the paired glasses may connect right now.
    private func updateDiscoveryPolicy() {
        let paired = pairedGlasses
        let pairedID = paired?.id
        var allow = false
        switch state {
        case .connecting:
            allow = targetID.map { id in pairedID.map { Self.sameDevice(id, $0) } ?? true } ?? true
        case .reconnecting:
            allow = lastConnectedID.map { id in pairedID.map { Self.sameDevice(id, $0) } ?? true } ?? true
        case .connected:
            allow = true
        default:
            allow = false
        }
        let searching = state == .searching
        DiscoveryGate.update {
            $0.pairedName = paired?.name
            $0.pairedID = pairedID
            $0.allowPaired = allow
            $0.isSearching = searching
        }
    }

    /// The paired glasses were seen while searching; list them so they can be chosen.
    private func pairedSeenWhileSearching(rssi: Int) {
        guard state == .searching, let paired = pairedGlasses else { return }
        let id = paired.id ?? paired.name
        let device = NearbyGlasses(id: id, name: paired.name, rssi: rssi == 0 ? 127 : rssi, lastSeen: Date())
        if !loggedNearbyIDs.contains(id) {
            loggedNearbyIDs.insert(id)
            appLog("Found paired \(paired.name) (\(id)), \(device.signal.lowercased())")
        }
        if let index = nearby.firstIndex(where: { Self.sameDevice($0.id, id) }) {
            nearby[index] = device
        } else {
            nearby.append(device)
        }
        changed()
        // Bluetooth reports each device once per scan; restart it so the pair stays fresh in the list.
        schedule("rescan", after: 2) { MLVisionM6SDKManager.startScan() }
    }

    private func changed() {
        updateDiscoveryPolicy()
        if Thread.isMainThread {
            NotificationCenter.default.post(name: .glassesDidChange, object: nil)
        } else {
            DispatchQueue.main.async { NotificationCenter.default.post(name: .glassesDidChange, object: nil) }
        }
    }

    static func stringKeyed(_ dictionary: [AnyHashable: Any]) -> [String: Any] {
        dictionary.reduce(into: [:]) { result, pair in result["\(pair.key)"] = pair.value }
    }

    static func redactingPasswords(_ value: Any) -> Any {
        if let dictionary = value as? [String: Any] {
            return dictionary.reduce(into: [String: Any]()) { result, pair in
                result[pair.key] = pair.key.lowercased().contains("password") ? "••••" : redactingPasswords(pair.value)
            }
        }
        if let array = value as? [Any] { return array.map(redactingPasswords) }
        return value
    }

    static func displayName(_ device: [String: Any]) -> String {
        for key in ["name", "deviceName", "localName", "bleName", "peripheralName"] {
            if let name = device[key] as? String, !name.isEmpty { return cleanName(name) }
        }
        return "M6 Glasses"
    }

    /// The SDK names unnamed devices "未命名" ("Unnamed").
    static func cleanName(_ name: String) -> String {
        name == "未命名" ? "Unnamed Glasses" : name
    }

    static func deviceID(_ device: [String: Any]) -> String {
        for key in ["mac", "macAddress", "uuid", "identifier", "sn"] {
            if let id = device[key] { return "\(id)" }
        }
        return displayName(device)
    }

    static func intValue(_ value: Any?) -> Int? {
        switch value {
        case let number as Int: return number
        case let number as NSNumber: return number.intValue
        case let text as String: return Int(text.trimmingCharacters(in: .whitespaces))
        default: return nil
        }
    }

    private static func batteryLevel(in info: [String: Any]) -> Int? {
        for key in ["battery", "batteryLevel", "get_battery_info", "power", "electricity"] {
            if let level = intValue(info[key]) { return level }
        }
        return nil
    }
}
