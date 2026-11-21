//
//  Form.swift
//  MLDemo
//
//  A small declarative wrapper around an inset-grouped UITableView so each screen
//  can describe itself as sections of standard iOS rows.
//

import UIKit

struct FormSection {
    var header: String? = nil
    var footer: String? = nil
    var rows: [FormRow]
}

enum FormRow {
    /// Headline with secondary text and an optional symbol. Not tappable.
    case status(title: String, subtitle: String?, symbol: String? = nil, tint: UIColor = Theme.textSecondary)
    /// Tinted, tappable command.
    case action(title: String, symbol: String? = nil, destructive: Bool = false, enabled: Bool = true, handler: () -> Void)
    /// Pushes another screen. `value` appears on the right.
    case navigation(title: String, subtitle: String? = nil, symbol: String? = nil, value: String? = nil, handler: () -> Void)
    /// Label with a value on the right.
    case value(title: String, value: String, symbol: String? = nil)
    /// List item with optional tap, swipe-to-delete, and a spinner while `busy`.
    case item(title: String, subtitle: String? = nil, symbol: String? = nil, disclosure: Bool = false, busy: Bool = false,
              onTap: (() -> Void)? = nil, onDelete: (() -> Void)? = nil)
    case toggle(title: String, symbol: String? = nil, isOn: Bool, enabled: Bool = true, onChange: (Bool) -> Void)
    case stepper(title: String, symbol: String? = nil, value: Int, range: ClosedRange<Int>, step: Int = 1,
                 format: (Int) -> String = { "\($0)" }, enabled: Bool = true, onChange: (Int) -> Void)
    /// Pull-down menu. `display` turns an option into the title shown to the user.
    case menu(title: String, symbol: String? = nil, selected: String, options: [String],
              display: (String) -> String = { $0 }, enabled: Bool = true, onSelect: (String) -> Void)
    /// Multi-line text.
    case text(String, monospaced: Bool = false, secondary: Bool = false)
    case textField(placeholder: String, text: String, secure: Bool = false, onChange: (String) -> Void)
    /// A custom view inside a standard cell (the view is kept by the screen, so its state survives reloads).
    case view(UIView)

    var isTextField: Bool {
        if case .textField = self { return true }
        return false
    }

    var isTappable: Bool {
        switch self {
        case let .action(_, _, _, enabled, _): return enabled
        case .navigation: return true
        case let .item(_, _, _, _, busy, onTap, _): return onTap != nil && !busy
        default: return false
        }
    }
}

class FormViewController: UITableViewController {
    static let iconColumnWidth: CGFloat = 24
    static let iconTextSpacing: CGFloat = 14
    /// Row icons render a size smaller than the row text, and still scale with Dynamic Type.
    static let iconConfiguration = UIImage.SymbolConfiguration(textStyle: .subheadline, scale: .medium)
    private(set) var sections: [FormSection] = []
    private var observerTokens: [NSObjectProtocol] = []

    init() { super.init(style: .insetGrouped) }
    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    deinit {
        observerTokens.forEach(NotificationCenter.default.removeObserver)
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
        tableView.register(TextFieldCell.self, forCellReuseIdentifier: "field")
        tableView.register(UITableViewHeaderFooterView.self, forHeaderFooterViewReuseIdentifier: "header")
        tableView.keyboardDismissMode = .interactive
        reload()
    }

    /// Subclasses describe their screen here.
    func buildSections() -> [FormSection] { [] }

    /// Rebuilds the table. While the user is typing, sections containing text fields are left
    /// untouched so the keyboard stays up.
    func reload() {
        guard isViewLoaded else { return }
        let new = buildSections()
        let isEditingField = tableView.visibleCells.contains { ($0 as? TextFieldCell)?.field.isFirstResponder == true }
        if isEditingField && new.count == sections.count {
            let old = sections
            sections = new
            let safe = IndexSet((0..<new.count).filter { index in
                !new[index].rows.contains(where: \.isTextField) && !old[index].rows.contains(where: \.isTextField)
            })
            UIView.performWithoutAnimation { tableView.reloadSections(safe, with: .none) }
        } else {
            sections = new
            tableView.reloadData()
        }
    }

    /// Reloads (or runs `handler`) on the main queue whenever `name` is posted.
    func observe(_ name: Notification.Name, handler: ((Notification) -> Void)? = nil) {
        let token = NotificationCenter.default.addObserver(forName: name, object: nil, queue: .main) { [weak self] note in
            if let handler { handler(note) } else { self?.reload() }
        }
        observerTokens.append(token)
    }

    func push(_ viewController: UIViewController) {
        navigationController?.pushViewController(viewController, animated: true)
    }

    // MARK: Table view

    override func numberOfSections(in tableView: UITableView) -> Int { sections.count }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        sections[section].rows.count
    }

    override func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        guard let title = sections[section].header else { return nil }
        let view = tableView.dequeueReusableHeaderFooterView(withIdentifier: "header")
        var content = UIListContentConfiguration.groupedHeader()
        content.text = title
        content.textProperties.transform = .none
        view?.contentConfiguration = content
        return view
    }

    override func tableView(_ tableView: UITableView, titleForFooterInSection section: Int) -> String? {
        sections[section].footer
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let row = sections[indexPath.section].rows[indexPath.row]

        if case let .textField(placeholder, text, secure, onChange) = row {
            let cell = tableView.dequeueReusableCell(withIdentifier: "field", for: indexPath) as! TextFieldCell
            cell.configure(placeholder: placeholder, text: text, secure: secure, onChange: onChange)
            return cell
        }

        if case let .view(custom) = row {
            let cell = UITableViewCell(style: .default, reuseIdentifier: nil)
            cell.selectionStyle = .none
            custom.removeFromSuperview()
            custom.translatesAutoresizingMaskIntoConstraints = false
            cell.contentView.addSubview(custom)
            let margins = cell.contentView.layoutMarginsGuide
            NSLayoutConstraint.activate([
                custom.leadingAnchor.constraint(equalTo: margins.leadingAnchor),
                custom.trailingAnchor.constraint(equalTo: margins.trailingAnchor),
                custom.topAnchor.constraint(equalTo: cell.contentView.topAnchor, constant: 12),
                custom.bottomAnchor.constraint(equalTo: cell.contentView.bottomAnchor, constant: -12),
            ])
            return cell
        }

        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        cell.accessoryView = nil
        cell.accessoryType = .none
        cell.selectionStyle = row.isTappable ? .default : .none
        var content = UIListContentConfiguration.cell()

        switch row {
        case let .status(title, subtitle, symbol, tint):
            content = .subtitleCell()
            content.text = title
            content.textProperties.font = .preferredFont(forTextStyle: .headline)
            content.secondaryText = subtitle
            content.secondaryTextProperties.color = Theme.textSecondary
            content.secondaryTextProperties.font = .preferredFont(forTextStyle: .subheadline)
            content.image = symbol.flatMap { UIImage(systemName: $0) }
            content.imageProperties.tintColor = tint
            content.textToSecondaryTextVerticalPadding = 3

        case let .action(title, symbol, destructive, enabled, _):
            let color: UIColor = !enabled ? Theme.textTertiary : (destructive ? Theme.danger : Theme.accent)
            content.text = title
            content.textProperties.color = color
            content.image = symbol.flatMap { UIImage(systemName: $0) }
            content.imageProperties.tintColor = color

        case let .navigation(title, subtitle, symbol, value, _):
            content = value != nil ? .valueCell() : (subtitle == nil ? .cell() : .subtitleCell())
            content.text = title
            content.secondaryText = value ?? subtitle
            content.secondaryTextProperties.color = Theme.textSecondary
            content.image = symbol.flatMap { UIImage(systemName: $0) }
            content.imageProperties.tintColor = Theme.textSecondary
            cell.accessoryType = .disclosureIndicator

        case let .value(title, value, symbol):
            content = .valueCell()
            content.text = title
            content.secondaryText = value
            content.secondaryTextProperties.font = Theme.digits(17)
            content.image = symbol.flatMap { UIImage(systemName: $0) }
            content.imageProperties.tintColor = Theme.textSecondary

        case let .item(title, subtitle, symbol, disclosure, busy, _, _):
            content = .subtitleCell()
            content.text = title
            content.secondaryText = subtitle
            content.secondaryTextProperties.color = Theme.textSecondary
            content.secondaryTextProperties.numberOfLines = 2
            content.image = symbol.flatMap { UIImage(systemName: $0) }
            content.imageProperties.tintColor = Theme.textSecondary
            if busy {
                let spinner = UIActivityIndicatorView(style: .medium)
                spinner.startAnimating()
                cell.accessoryView = spinner
            } else {
                cell.accessoryType = disclosure ? .disclosureIndicator : .none
            }

        case let .toggle(title, symbol, isOn, enabled, onChange):
            content.text = title
            content.textProperties.color = enabled ? Theme.text : Theme.textTertiary
            content.image = symbol.flatMap { UIImage(systemName: $0) }
            content.imageProperties.tintColor = Theme.textSecondary
            let toggle = UISwitch()
            toggle.isOn = isOn
            toggle.isEnabled = enabled
            toggle.addAction(UIAction { [weak toggle] _ in
                Haptics.select()
                onChange(toggle?.isOn ?? false)
            }, for: .valueChanged)
            cell.accessoryView = toggle

        case let .stepper(title, symbol, value, range, step, format, enabled, onChange):
            content = .valueCell()
            content.text = title
            content.textProperties.color = enabled ? Theme.text : Theme.textTertiary
            content.secondaryText = format(value)
            content.secondaryTextProperties.font = Theme.digits(17)
            content.image = symbol.flatMap { UIImage(systemName: $0) }
            content.imageProperties.tintColor = Theme.textSecondary
            let stepper = UIStepper()
            stepper.minimumValue = Double(range.lowerBound)
            stepper.maximumValue = Double(range.upperBound)
            stepper.stepValue = Double(step)
            stepper.value = Double(value)
            stepper.isEnabled = enabled
            stepper.addAction(UIAction { [weak stepper] _ in onChange(Int(stepper?.value ?? 0)) }, for: .valueChanged)
            cell.accessoryView = stepper

        case let .menu(title, symbol, selected, options, display, enabled, onSelect):
            content.text = title
            content.textProperties.color = enabled ? Theme.text : Theme.textTertiary
            content.image = symbol.flatMap { UIImage(systemName: $0) }
            content.imageProperties.tintColor = Theme.textSecondary
            var config = UIButton.Configuration.plain()
            config.title = display(selected)
            config.baseForegroundColor = enabled ? Theme.textSecondary : Theme.textTertiary
            config.image = UIImage(systemName: "chevron.up.chevron.down")
            config.preferredSymbolConfigurationForImage = UIImage.SymbolConfiguration(pointSize: 11, weight: .medium)
            config.imagePlacement = .trailing
            config.imagePadding = 4
            config.contentInsets = NSDirectionalEdgeInsets(top: 6, leading: 8, bottom: 6, trailing: 0)
            let button = UIButton(configuration: config)
            button.menu = UIMenu(children: options.map { option in
                UIAction(title: display(option), state: option == selected ? .on : .off) { _ in
                    Haptics.select()
                    onSelect(option)
                }
            })
            button.showsMenuAsPrimaryAction = true
            button.isEnabled = enabled
            // Keep the row title whole: the selected value gets at most half the row and truncates.
            button.configuration?.titleLineBreakMode = .byTruncatingTail
            button.sizeToFit()
            let maxWidth = max(120, tableView.bounds.width * 0.5)
            if button.frame.width > maxWidth { button.frame.size.width = maxWidth }
            content.textProperties.numberOfLines = 1
            cell.accessoryView = button

        case let .text(string, monospaced, secondary):
            content.text = string
            content.textProperties.numberOfLines = 0
            content.textProperties.font = monospaced ? Theme.mono(13, style: .footnote) : .preferredFont(forTextStyle: .body)
            content.textProperties.color = secondary ? Theme.textSecondary : Theme.text

        case .textField, .view:
            break
        }

        if content.image != nil {
            // Same icon column on every row, so labels line up.
            content.imageProperties.preferredSymbolConfiguration = Self.iconConfiguration
            content.imageProperties.reservedLayoutSize = CGSize(width: Self.iconColumnWidth, height: 0)
            content.imageToTextPadding = Self.iconTextSpacing
        }
        cell.contentConfiguration = content
        return cell
    }

    override func tableView(_ tableView: UITableView, shouldHighlightRowAt indexPath: IndexPath) -> Bool {
        sections[indexPath.section].rows[indexPath.row].isTappable
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        let row = sections[indexPath.section].rows[indexPath.row]
        guard row.isTappable else { return }
        switch row {
        case let .action(_, _, _, _, handler):
            Haptics.tap()
            handler()
        case let .navigation(_, _, _, _, handler):
            handler()
        case let .item(_, _, _, _, _, onTap?, _):
            Haptics.tap()
            onTap()
        default:
            break
        }
    }

    override func tableView(_ tableView: UITableView,
                            trailingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        guard case let .item(_, _, _, _, _, _, onDelete?) = sections[indexPath.section].rows[indexPath.row] else { return nil }
        let delete = UIContextualAction(style: .destructive, title: "Delete") { _, _, done in
            onDelete()
            done(true)
        }
        return UISwipeActionsConfiguration(actions: [delete])
    }
}

/// A row containing a single text field. Secure fields get a show/hide button.
final class TextFieldCell: UITableViewCell, UITextFieldDelegate {
    let field = UITextField()
    private var onChange: ((String) -> Void)?

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        selectionStyle = .none
        field.translatesAutoresizingMaskIntoConstraints = false
        field.font = .preferredFont(forTextStyle: .body)
        field.adjustsFontForContentSizeCategory = true
        field.clearButtonMode = .whileEditing
        field.autocorrectionType = .no
        field.autocapitalizationType = .none
        field.spellCheckingType = .no
        field.returnKeyType = .done
        field.delegate = self
        field.addAction(UIAction { [weak self] _ in
            guard let self else { return }
            self.onChange?(self.field.text ?? "")
        }, for: .editingChanged)
        contentView.addSubview(field)
        NSLayoutConstraint.activate([
            field.leadingAnchor.constraint(equalTo: contentView.layoutMarginsGuide.leadingAnchor),
            field.trailingAnchor.constraint(equalTo: contentView.layoutMarginsGuide.trailingAnchor),
            field.topAnchor.constraint(equalTo: contentView.topAnchor),
            field.bottomAnchor.constraint(equalTo: contentView.bottomAnchor),
            field.heightAnchor.constraint(greaterThanOrEqualToConstant: 44),
        ])
    }

    required init?(coder: NSCoder) { fatalError("init(coder:) has not been implemented") }

    func configure(placeholder: String, text: String, secure: Bool, onChange: @escaping (String) -> Void) {
        field.placeholder = placeholder
        if !field.isFirstResponder { field.text = text }
        field.isSecureTextEntry = secure
        field.textContentType = secure ? .password : nil
        self.onChange = onChange
        if secure {
            var config = UIButton.Configuration.plain()
            config.image = UIImage(systemName: "eye")
            config.baseForegroundColor = Theme.textSecondary
            let reveal = UIButton(configuration: config, primaryAction: UIAction { [weak self] action in
                guard let self, let button = action.sender as? UIButton else { return }
                self.field.isSecureTextEntry.toggle()
                button.configuration?.image = UIImage(systemName: self.field.isSecureTextEntry ? "eye" : "eye.slash")
            })
            reveal.accessibilityLabel = "Show password"
            field.rightView = reveal
            field.rightViewMode = .always
            field.clearButtonMode = .never
        } else {
            field.rightView = nil
            field.clearButtonMode = .whileEditing
        }
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
}

extension UIViewController {
    func showAlert(title: String, message: String?) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default))
        present(alert, animated: true)
    }

    func confirm(title: String, message: String?, actionTitle: String, destructive: Bool = true, handler: @escaping () -> Void) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        alert.addAction(UIAlertAction(title: actionTitle, style: destructive ? .destructive : .default) { _ in handler() })
        present(alert, animated: true)
    }
}
