#include "aboutwidget.h"

#include <QLabel>
#include <QVBoxLayout>

using namespace Arc;

void AboutWidget::showAboutWindow(const QString &appName,
								  const QString &version,
								  const int year,
								  QWidget *parent)
{
	AboutWidget about(appName, version, year, parent);
	about.exec();
}

AboutWidget::AboutWidget(const QString &appName,
						 const QString &version,
						 const int year,
						 QWidget *parent) :
	QDialog(parent)
{
	const QString developerName = "SWS TEAM";

	this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
	this->setWindowTitle(tr("About"));

	QLabel *lbl_logo = new QLabel(this);
	QLabel *lbl_name = new QLabel(this);
	QLabel *lbl_text = new QLabel(this);

	QPixmap logo;
	logo.load(":/about/logo.jpg");
	lbl_logo->setPixmap(logo);

	lbl_name->setText(appName);

	QString text;
	text += tr("Version: %1").arg(version);
	text += "\n";
	text += tr("Developed by: %1").arg(developerName);
	text += "\n";
	text += tr("© %1 SWS TEAM").arg(year);
	lbl_text->setText(text);

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(lbl_logo);
	layout->addWidget(lbl_name);
	layout->addWidget(lbl_text);
	this->setLayout(layout);

	adjustSize();
	setFixedSize(this->size());
}

