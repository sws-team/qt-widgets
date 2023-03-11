#include "styles.h"

#include <QApplication>

using namespace Arc;

const QString Style::STYLE_NAME = QApplication::tr("Style");
const QStringList Style::STYLE_NAMES = QStringList() << QApplication::tr("Classic") << QApplication::tr("Dark");

Style::Style()
	: m_type(CLASSIC)
{
	fillStyles();
}

Style::STYLE_TYPE Style::currentStyleType() const
{
	return m_type;
}

void Style::setStyle(Style::STYLE_TYPE type)
{
	if (!styles.contains(type))
		return;
	m_type = type;
	qApp->setPalette(styles.value(type));
}

void Style::addStyle(int type, const QPalette &palette)
{
	styles.insert(static_cast<STYLE_TYPE>(type), palette);
}

void Style::fillStyles()
{
	addStyle(CLASSIC, qApp->palette());

	//dark theme
	QPalette darkPalette;
	const QColor darkColor = Qt::darkGray;
	const QColor disabledColor = Qt::gray;
	darkPalette.setColor(QPalette::Window, darkColor);
	darkPalette.setColor(QPalette::WindowText, Qt::white);
	darkPalette.setColor(QPalette::Base, QColor(Qt::darkGray).darker());
	darkPalette.setColor(QPalette::AlternateBase, darkColor);
	darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
	darkPalette.setColor(QPalette::ToolTipText, Qt::white);
	darkPalette.setColor(QPalette::Text, Qt::white);
	darkPalette.setColor(QPalette::Disabled, QPalette::Text, disabledColor);
	darkPalette.setColor(QPalette::Button, darkColor);
	darkPalette.setColor(QPalette::ButtonText, Qt::white);
	darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, disabledColor);
	darkPalette.setColor(QPalette::BrightText, Qt::red);
	darkPalette.setColor(QPalette::Link, QColor(104,151,187));

	darkPalette.setColor(QPalette::Highlight, QColor(51,102,102));
	darkPalette.setColor(QPalette::HighlightedText, Qt::black);
	darkPalette.setColor(QPalette::Disabled, QPalette::HighlightedText, disabledColor);

	addStyle(DARK, darkPalette);
}
