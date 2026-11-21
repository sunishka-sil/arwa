//
//  SpeechLanguages.swift
//  MLDemo
//
//  The speech languages used by Live Interpreting ("Speak in" / "Translate to") and Record and Transcribe.
//  The SDK only keeps them in memory and starts with its own defaults, so the app applies a default of
//  English on first launch, then remembers whatever the user picks.
//

import Foundation
import MLVisionM6SDK

enum SpeechLanguages {
    private static let sourceKey = "SpeechSourceLanguage"
    private static let targetKey = "SpeechTargetLanguage"

    /// Call once after the SDK is initialized.
    static func applyAtStartup() {
        let defaults = UserDefaults.standard
        let sources = MLVisionM6OCSDK.getSupportedSourceLanguages()
        let targets = MLVisionM6OCSDK.getSupportedTargetLanguages()

        if let saved = defaults.string(forKey: sourceKey), isSupported(saved, in: sources) {
            MLVisionM6OCSDK.setSourceLanguage(language: saved)
        } else if let english = englishCode(in: sources), !isEnglish(MLVisionM6OCSDK.getSourceLanguage()) {
            // First launch: speak in English. If the SDK's target was English, translate into the SDK's
            // original source language instead, so the default pair isn't English to English.
            let original = MLVisionM6OCSDK.getSourceLanguage()
            MLVisionM6OCSDK.setSourceLanguage(language: english)
            if defaults.string(forKey: targetKey) == nil, isEnglish(MLVisionM6OCSDK.getTargetLanguage()),
               !original.isEmpty, isSupported(original, in: targets) {
                MLVisionM6OCSDK.setTargetLanguage(language: original)
            }
        }

        if let saved = defaults.string(forKey: targetKey), isSupported(saved, in: targets) {
            MLVisionM6OCSDK.setTargetLanguage(language: saved)
        }
        appLog("Speech languages: \(MLVisionM6OCSDK.getSourceLanguage()) → \(MLVisionM6OCSDK.getTargetLanguage())")
    }

    static func setSource(_ code: String) {
        MLVisionM6OCSDK.setSourceLanguage(language: code)
        UserDefaults.standard.set(code, forKey: sourceKey)
    }

    static func setTarget(_ code: String) {
        MLVisionM6OCSDK.setTargetLanguage(language: code)
        UserDefaults.standard.set(code, forKey: targetKey)
    }

    static func swap() {
        MLVisionM6OCSDK.swapLanguages()
        UserDefaults.standard.set(MLVisionM6OCSDK.getSourceLanguage(), forKey: sourceKey)
        UserDefaults.standard.set(MLVisionM6OCSDK.getTargetLanguage(), forKey: targetKey)
    }

    private static func isEnglish(_ code: String) -> Bool { code.lowercased().hasPrefix("en") }

    /// Prefers US English, then any English variant. An empty list means the SDK didn't report its options.
    private static func englishCode(in supported: [String]) -> String? {
        if supported.isEmpty { return "en-US" }
        return supported.first { $0.lowercased().replacingOccurrences(of: "_", with: "-") == "en-us" }
            ?? supported.first(where: isEnglish)
    }

    private static func isSupported(_ code: String, in supported: [String]) -> Bool {
        supported.isEmpty || supported.contains(code)
    }
}
