//
//  Theme.swift
//  MLDemo
//
//  Restrained, native look: iOS dark grouped surfaces, system type, and a single tint color.
//

import UIKit

enum Theme {
    // MARK: Colors (the app runs in dark mode)

    static let background    = UIColor.systemGroupedBackground
    static let surface       = UIColor.secondarySystemGroupedBackground
    static let surfaceRaised = UIColor.tertiarySystemGroupedBackground
    static let separator     = UIColor.separator

    static let text          = UIColor.label
    static let textSecondary = UIColor.secondaryLabel
    static let textTertiary  = UIColor.tertiaryLabel

    static let accent        = UIColor(hex: 0xF07A35)
    static let danger        = UIColor.systemRed
    static let warning       = UIColor.systemOrange

    // MARK: Type

    static func ui(_ size: CGFloat, _ weight: UIFont.Weight = .regular, style: UIFont.TextStyle = .body) -> UIFont {
        UIFontMetrics(forTextStyle: style).scaledFont(for: .systemFont(ofSize: size, weight: weight))
    }

    /// System font with fixed-width digits, for values that change (volume, battery).
    static func digits(_ size: CGFloat, _ weight: UIFont.Weight = .regular, style: UIFont.TextStyle = .body) -> UIFont {
        UIFontMetrics(forTextStyle: style).scaledFont(for: .monospacedDigitSystemFont(ofSize: size, weight: weight))
    }

    /// Monospaced font. Used only for the event log.
    static func mono(_ size: CGFloat, _ weight: UIFont.Weight = .regular, style: UIFont.TextStyle = .body) -> UIFont {
        UIFontMetrics(forTextStyle: style).scaledFont(for: .monospacedSystemFont(ofSize: size, weight: weight))
    }

    // MARK: Global appearance

    static func apply(to window: UIWindow) {
        window.overrideUserInterfaceStyle = .dark
        window.tintColor = accent

        let standard = UINavigationBarAppearance()
        standard.configureWithDefaultBackground()
        let edge = UINavigationBarAppearance()
        edge.configureWithTransparentBackground()
        for appearance in [standard, edge] {
            appearance.titleTextAttributes = [.foregroundColor: UIColor.label]
            appearance.largeTitleTextAttributes = [.foregroundColor: UIColor.label]
        }
        let navBar = UINavigationBar.appearance()
        navBar.standardAppearance = standard
        navBar.compactAppearance = standard
        navBar.scrollEdgeAppearance = edge

        UISwitch.appearance().onTintColor = accent
    }
}

extension UIColor {
    convenience init(hex: UInt32, alpha: CGFloat = 1) {
        self.init(red: CGFloat((hex >> 16) & 0xFF) / 255,
                  green: CGFloat((hex >> 8) & 0xFF) / 255,
                  blue: CGFloat(hex & 0xFF) / 255,
                  alpha: alpha)
    }
}

enum Haptics {
    static func tap() { UIImpactFeedbackGenerator(style: .light).impactOccurred() }
    static func select() { UISelectionFeedbackGenerator().selectionChanged() }
    static func success() { UINotificationFeedbackGenerator().notificationOccurred(.success) }
    static func warning() { UINotificationFeedbackGenerator().notificationOccurred(.warning) }
    static func error() { UINotificationFeedbackGenerator().notificationOccurred(.error) }
}
