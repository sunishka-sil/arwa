//
//  InterpretingTap.swift
//  MLDemo
//
//  The SDK only hands the app a translation once Azure finalizes a sentence (after a pause), and it drops
//  anything that arrives after Stop. Its live, in-progress results go only to its log, which it writes
//  through CocoaLumberjack. This logger listens for those lines so the app can show text as you speak.
//

import Foundation
import CocoaLumberjack

extension Notification.Name {
    /// userInfo: "source" (spoken text), "translation", "microphone" ("glasses" or "phone").
    static let interpretingPartial = Notification.Name("InterpretingTap.partial")
}

final class InterpretingTap: DDAbstractLogger {
    static let shared = InterpretingTap()
    private static var installed = false

    static func install() {
        guard !installed else { return }
        installed = true
        DDLog.add(shared, with: .all)
    }

    // Lines look like: MLVisionSDK:Optional("[蓝牙]翻译中: hello there -> 你好")
    // 蓝牙 = Bluetooth (the glasses' microphone), 麦克风 = this phone's microphone, 翻译中 = translating.
    override func log(message logMessage: DDLogMessage) {
        let text = logMessage.message
        guard text.contains("翻译中: ") else { return }
        let microphone = text.contains("[麦克风]") ? "phone" : "glasses"
        guard let start = text.range(of: "翻译中: ") else { return }
        var body = String(text[start.upperBound...])
        if body.hasSuffix("\")") { body.removeLast(2) }
        body = body.replacingOccurrences(of: "\\\"", with: "\"")
        let parts = body.components(separatedBy: " -> ")
        let source = parts.first ?? body
        let translation = parts.count > 1 ? parts.dropFirst().joined(separator: " -> ") : ""
        DispatchQueue.main.async {
            NotificationCenter.default.post(name: .interpretingPartial, object: nil,
                                            userInfo: ["source": source, "translation": translation, "microphone": microphone])
        }
    }
}
