//
//  SavedNetworks.swift
//  MLDemo
//
//  Wi-Fi networks the glasses have joined, so they can rejoin with one tap.
//  Names are kept in UserDefaults; passwords in the Keychain (this device only).
//

import Foundation
import Security
import MLVisionM6SDK

struct SavedNetwork: Codable, Equatable {
    var ssid: String
    var bssid: String
    var lastUsed: Date
}

enum SavedNetworks {
    private static let listKey = "SavedGlassesWifiNetworks"
    private static let keychainService = "MLDemo.glasses-wifi"

    static var all: [SavedNetwork] {
        importFromSDKIfNeeded()
        guard let data = UserDefaults.standard.data(forKey: listKey),
              let list = try? JSONDecoder().decode([SavedNetwork].self, from: data) else { return [] }
        return list.sorted { $0.lastUsed > $1.lastUsed }
    }

    static func save(ssid: String, bssid: String, password: String) {
        var list = all.filter { $0.ssid != ssid }
        list.append(SavedNetwork(ssid: ssid, bssid: bssid, lastUsed: Date()))
        store(list)
        setPassword(password, for: ssid)
    }

    static func forget(ssid: String) {
        store(all.filter { $0.ssid != ssid })
        let query: [String: Any] = [kSecClass as String: kSecClassGenericPassword,
                                    kSecAttrService as String: keychainService,
                                    kSecAttrAccount as String: ssid]
        SecItemDelete(query as CFDictionary)
    }

    static func password(for ssid: String) -> String {
        let query: [String: Any] = [kSecClass as String: kSecClassGenericPassword,
                                    kSecAttrService as String: keychainService,
                                    kSecAttrAccount as String: ssid,
                                    kSecReturnData as String: true,
                                    kSecMatchLimit as String: kSecMatchLimitOne]
        var result: AnyObject?
        guard SecItemCopyMatching(query as CFDictionary, &result) == errSecSuccess,
              let data = result as? Data else { return "" }
        return String(data: data, encoding: .utf8) ?? ""
    }

    private static func setPassword(_ password: String, for ssid: String) {
        let query: [String: Any] = [kSecClass as String: kSecClassGenericPassword,
                                    kSecAttrService as String: keychainService,
                                    kSecAttrAccount as String: ssid]
        SecItemDelete(query as CFDictionary)
        var item = query
        item[kSecValueData as String] = Data(password.utf8)
        item[kSecAttrAccessible as String] = kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly
        SecItemAdd(item as CFDictionary, nil)
    }

    private static func store(_ list: [SavedNetwork]) {
        if let data = try? JSONEncoder().encode(list) { UserDefaults.standard.set(data, forKey: listKey) }
    }

    /// The SDK remembers the last network the glasses joined (including its password); keep it as a saved network.
    private static var didImport = false
    private static func importFromSDKIfNeeded() {
        guard !didImport else { return }
        didImport = true
        guard let info = MLVisionM6OCSDK.getWifiConnectInfo(),
              let ssid = info["ssid"] as? String, !ssid.isEmpty else { return }
        let existing = (UserDefaults.standard.data(forKey: listKey))
            .flatMap { try? JSONDecoder().decode([SavedNetwork].self, from: $0) } ?? []
        guard !existing.contains(where: { $0.ssid == ssid }) else { return }
        var list = existing
        list.append(SavedNetwork(ssid: ssid, bssid: info["bssid"] as? String ?? "", lastUsed: .distantPast))
        store(list)
        if let password = info["password"] as? String { setPassword(password, for: ssid) }
    }
}
