//
//  DiscoveryGate.swift
//  MLDemo
//
//  The SDK connects to the paired glasses the moment any of its scans sees them, which makes the
//  glasses announce "Connected" (and then "Disconnected" when the app drops it) even though the
//  user never chose them. The SDK has no switch for this, so the app filters the SDK's Bluetooth
//  discovery callback: sightings of the paired glasses only reach the SDK while the user is
//  connecting to them. Other glasses pass through untouched.
//

import CoreBluetooth
import ObjectiveC

enum DiscoveryGate {
    /// What the filter needs from the session, kept in a lock so the SDK's Bluetooth queue can read it.
    struct Policy {
        var pairedName: String?
        var pairedID: String?
        /// The paired glasses may connect (the user asked to connect to them, or they dropped unexpectedly).
        var allowPaired = false
        var isSearching = false
    }

    private static let lock = NSLock()
    private static var policy = Policy()
    /// Called on the main queue when the paired glasses are seen but held back from the SDK.
    static var onPairedSeen: ((_ rssi: Int) -> Void)?

    static func update(_ change: (inout Policy) -> Void) {
        lock.lock(); defer { lock.unlock() }
        change(&policy)
    }

    private static func snapshot() -> Policy {
        lock.lock(); defer { lock.unlock() }
        return policy
    }

    private(set) static var isInstalled = false

    /// Swaps in the filter. Call before the SDK starts scanning.
    static func install() {
        guard !isInstalled else { return }
        let selector = NSSelectorFromString("centralManager:didDiscoverPeripheral:advertisementData:RSSI:")
        guard let managerClass = NSClassFromString("_TtC13MLVisionM6SDK12MLBLEManager"),
              let method = class_getInstanceMethod(managerClass, selector) else {
            appLog("Couldn’t install the discovery filter; the SDK may connect to paired glasses on its own")
            return
        }
        typealias Discover = @convention(c) (AnyObject, Selector, CBCentralManager, CBPeripheral, NSDictionary, NSNumber) -> Void
        let original = unsafeBitCast(method_getImplementation(method), to: Discover.self)
        let filtered: @convention(block) (AnyObject, CBCentralManager, CBPeripheral, NSDictionary, NSNumber) -> Void = {
            manager, central, peripheral, advertisement, rssi in
            if shouldPass(peripheral: peripheral, advertisement: advertisement, rssi: rssi) {
                original(manager, selector, central, peripheral, advertisement, rssi)
            }
        }
        method_setImplementation(method, imp_implementationWithBlock(filtered))
        isInstalled = true
    }

    private static func shouldPass(peripheral: CBPeripheral, advertisement: NSDictionary, rssi: NSNumber) -> Bool {
        let current = snapshot()
        guard let pairedName = current.pairedName, !pairedName.isEmpty else { return true }
        let name = (advertisement[CBAdvertisementDataLocalNameKey] as? String) ?? peripheral.name ?? ""
        guard name == pairedName else { return true }   // not the paired glasses
        if current.allowPaired { return true }
        if current.isSearching {
            let level = rssi.intValue
            DispatchQueue.main.async { onPairedSeen?(level) }
        }
        return false
    }
}

/// Diagnostics: counts the bytes the glasses send over Bluetooth (without changing anything) and logs the
/// rate while data is streaming, so it's visible whether microphone audio is arriving.
enum BluetoothTrafficProbe {
    private static let lock = NSLock()
    private static var bytes: [String: Int] = [:]
    private static var timer: DispatchSourceTimer?
    private static var installTime = Date()

    /// The SDK crashes (a Swift trap in MLBLEManager.handleAppInfo) on the app-status message the glasses send
    /// after a photo is taken with the camera app (app 25). That message only reports which glasses app is open,
    /// so it's logged and kept from the SDK. The photo itself is unaffected.
    private static func shouldDrop(_ value: Data) -> Bool {
        guard value.count < 4096 else { return false }   // audio and file data
        let text = String(decoding: value, as: UTF8.self)
        guard text.contains("\"appid\":1,") || text.contains("\"appid\":1}") else { return false }
        let compact = text.replacingOccurrences(of: " ", with: "")
        guard compact.contains("\"02\":25") else { return false }
        let printable = text.unicodeScalars.map { $0.value >= 0x20 && $0.value < 0x7F ? Character($0) : "·" }
        appLog("Kept camera status message from the SDK (it crashes on it): " + String(printable))
        return true
    }

    static func install() {
        let selector = NSSelectorFromString("peripheral:didUpdateValueForCharacteristic:error:")
        guard timer == nil,
              let managerClass = NSClassFromString("_TtC13MLVisionM6SDK12MLBLEManager"),
              let method = class_getInstanceMethod(managerClass, selector) else { return }
        typealias Update = @convention(c) (AnyObject, Selector, CBPeripheral, CBCharacteristic, NSError?) -> Void
        let original = unsafeBitCast(method_getImplementation(method), to: Update.self)
        let counted: @convention(block) (AnyObject, CBPeripheral, CBCharacteristic, NSError?) -> Void = {
            manager, peripheral, characteristic, error in
            if let value = characteristic.value {
                lock.lock(); bytes[characteristic.uuid.uuidString, default: 0] += value.count; lock.unlock()
                if shouldDrop(value) { return }
            }
            original(manager, selector, peripheral, characteristic, error)
        }
        method_setImplementation(method, imp_implementationWithBlock(counted))

        installTime = Date()
        let interval = 5.0
        let source = DispatchSource.makeTimerSource(queue: .main)
        source.schedule(deadline: .now() + interval, repeating: interval)
        source.setEventHandler {
            lock.lock(); let snapshot = bytes; bytes = [:]; lock.unlock()
            let total = snapshot.values.reduce(0, +)
            // Control messages are a few hundred bytes; only report when something is streaming.
            guard total > 2_000 else { return }
            let parts = snapshot.sorted { $0.value > $1.value }
                .map { String(format: "%@ %.1f KB/s", $0.key, Double($0.value) / 1024 / interval) }
            appLog("Bluetooth data from glasses: " + parts.joined(separator: ", "))
        }
        source.resume()
        timer = source
    }
}
