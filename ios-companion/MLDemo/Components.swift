//
//  Components.swift
//  MLDemo
//
//  Small view helpers.
//

import UIKit

enum ButtonStyle { case primary, secondary }

func makeButton(_ title: String, style: ButtonStyle, action: @escaping () -> Void) -> UIButton {
    var config: UIButton.Configuration = style == .primary ? .filled() : .gray()
    config.cornerStyle = .large
    config.buttonSize = .large
    config.title = title
    if style == .secondary { config.baseForegroundColor = Theme.accent }
    return UIButton(configuration: config, primaryAction: UIAction { _ in
        Haptics.tap()
        action()
    })
}

/// Flexible empty view that absorbs extra space in a stack.
func makeSpacer() -> UIView {
    let spacer = UIView()
    for axis in [NSLayoutConstraint.Axis.horizontal, .vertical] {
        spacer.setContentHuggingPriority(UILayoutPriority(1), for: axis)
        spacer.setContentCompressionResistancePriority(UILayoutPriority(1), for: axis)
    }
    return spacer
}

func makeLabel(_ text: String? = nil, font: UIFont, color: UIColor = Theme.text, lines: Int = 1) -> UILabel {
    let label = UILabel()
    label.text = text
    label.font = font
    label.textColor = color
    label.numberOfLines = lines
    label.adjustsFontForContentSizeCategory = true
    return label
}

func makeRow(_ views: [UIView], spacing: CGFloat = 8, alignment: UIStackView.Alignment = .center) -> UIStackView {
    let row = UIStackView(arrangedSubviews: views)
    row.axis = .horizontal
    row.spacing = spacing
    row.alignment = alignment
    return row
}

/// A labeled slider that snaps to `step` and reports the value when the finger lifts.
final class SliderRowView: UIView {
    let slider = UISlider()
    private let valueLabel = makeLabel(font: Theme.digits(17), color: Theme.textSecondary)
    private let format: (Int) -> String
    private let step: Int
    var onCommit: ((Int) -> Void)?

    init(title: String, symbol: String, range: ClosedRange<Int>, step: Int, format: @escaping (Int) -> String) {
        self.format = format
        self.step = step
        super.init(frame: .zero)

        let icon = UIImageView(image: UIImage(systemName: symbol))
        icon.tintColor = Theme.textSecondary
        icon.preferredSymbolConfiguration = FormViewController.iconConfiguration
        icon.contentMode = .center
        icon.widthAnchor.constraint(equalToConstant: FormViewController.iconColumnWidth).isActive = true
        let titleLabel = makeLabel(title, font: .preferredFont(forTextStyle: .body))
        valueLabel.setContentHuggingPriority(.required, for: .horizontal)
        let top = makeRow([icon, titleLabel, makeSpacer(), valueLabel], spacing: FormViewController.iconTextSpacing)

        slider.minimumValue = Float(range.lowerBound)
        slider.maximumValue = Float(range.upperBound)
        slider.minimumTrackTintColor = Theme.accent
        slider.accessibilityLabel = title
        var lastStep = Int.min
        slider.addAction(UIAction { [weak self] _ in
            guard let self else { return }
            let snapped = self.snapped(self.slider.value)
            self.slider.value = Float(snapped)
            self.valueLabel.text = format(snapped)
            if snapped != lastStep { lastStep = snapped; Haptics.select() }
        }, for: .valueChanged)
        let commit = UIAction { [weak self] _ in
            guard let self else { return }
            self.onCommit?(self.snapped(self.slider.value))
        }
        slider.addAction(commit, for: .touchUpInside)
        slider.addAction(commit, for: .touchUpOutside)

        let stack = UIStackView(arrangedSubviews: [top, slider])
        stack.axis = .vertical
        stack.spacing = 10
        stack.translatesAutoresizingMaskIntoConstraints = false
        addSubview(stack)
        NSLayoutConstraint.activate([
            stack.leadingAnchor.constraint(equalTo: leadingAnchor),
            stack.trailingAnchor.constraint(equalTo: trailingAnchor),
            stack.topAnchor.constraint(equalTo: topAnchor),
            stack.bottomAnchor.constraint(equalTo: bottomAnchor),
        ])
    }

    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    func update(value: Int, enabled: Bool) {
        if !slider.isTracking {
            slider.value = Float(value)
            valueLabel.text = format(value)
        }
        slider.isEnabled = enabled
        slider.minimumTrackTintColor = enabled ? Theme.accent : .systemGray3
        alpha = enabled ? 1 : 0.5
    }

    private func snapped(_ value: Float) -> Int {
        Int((value / Float(step)).rounded()) * step
    }
}
