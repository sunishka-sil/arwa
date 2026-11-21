import Foundation

struct Guide: Decodable {
    let id: String
    let title: String
    let summary: String
    let version: Int
    let steps: [Step]

    struct Step: Decodable {
        let k: String
        let h: String
        let d: String
        let hazard: String?
        let spec: Specification?
    }
    struct Specification: Decodable {
        let label: String
        let value: String
        let unit: String
    }

    static func bundled() throws -> Guide {
        guard let url = Bundle.main.url(forResource: "coupling", withExtension: "json") else {
            throw NSError(domain: "ARWA", code: 1, userInfo: [NSLocalizedDescriptionKey: "The bundled guide is missing. Rebuild the app."])
        }
        return try JSONDecoder().decode(Guide.self, from: Data(contentsOf: url))
    }
}

struct GuideSnapshot: Decodable {
    let app: String
    let `protocol`: Int
    let deviceId: String
    let deviceLabel: String
    let job: String
    let guideVersion: Int
    let started: Bool
    let step: Int
    let total: Int
    let hidden: Bool
    let revision: Int64
    let viewerReady: Bool
    let displayedRevision: Int64
    // Optional so the phone remains compatible with glasses builds made before voice navigation.
    let voiceEnabled: Bool?
    let voiceStatus: String?
    let lastVoiceCommand: String?
}

extension Notification.Name {
    static let guideConnectionDidChange = Notification.Name("ARWA.GuideConnection.didChange")
}
