import Foundation

/// Bonjour finds endpoints, but never decides which glasses belong to the user.
final class GuideDiscovery: NSObject, NetServiceBrowserDelegate, NetServiceDelegate {
    struct Device {
        let name: String
        let deviceID: String
        let url: URL
    }
    var onChange: (([Device]) -> Void)?
    var onError: ((String) -> Void)?
    private let browser = NetServiceBrowser()
    private var services: [NetService] = []
    private var devices: [String: Device] = [:]
    private var searching = false

    func start() {
        guard !searching else { return }
        searching = true
        browser.delegate = self
        browser.searchForServices(ofType: "_arwa-guide._tcp.", inDomain: "local.")
    }

    func stop() {
        browser.stop()
        services.forEach { $0.stop() }
        services.removeAll()
        devices.removeAll()
        searching = false
        publish()
    }

    func netServiceBrowser(_ browser: NetServiceBrowser, didFind service: NetService, moreComing: Bool) {
        services.append(service)
        service.delegate = self
        service.resolve(withTimeout: 8)
    }

    func netServiceBrowser(_ browser: NetServiceBrowser, didRemove service: NetService, moreComing: Bool) {
        services.removeAll { $0 == service }
        devices.removeValue(forKey: service.name)
        publish()
    }

    func netServiceDidResolveAddress(_ sender: NetService) {
        guard let host = sender.hostName, sender.port > 0,
              let url = URL(string: "http://\(host):\(sender.port)") else { return }
        let txt = sender.txtRecordData().map(NetService.dictionary(fromTXTRecord:)) ?? [:]
        guard let raw = txt["deviceId"], let id = String(data: raw, encoding: .utf8), !id.isEmpty else { return }
        devices[sender.name] = Device(name: sender.name, deviceID: id, url: url)
        publish()
    }

    func netServiceBrowser(_ browser: NetServiceBrowser, didNotSearch errorDict: [String: NSNumber]) {
        searching = false
        onError?("Couldn’t find glasses. Allow Local Network access in iPhone Settings and check that both devices are on the same Wi-Fi.")
    }

    private func publish() { onChange?(devices.values.sorted { $0.name < $1.name }) }
}
