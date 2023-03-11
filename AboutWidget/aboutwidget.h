#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QDialog>

namespace Arc {

	class AboutWidget : public QDialog
	{
		Q_OBJECT

	public:
		static void showAboutWindow(const QString &appName,
									const QString &version,
									const int year,
									QWidget *parent = nullptr);

	private:
		explicit AboutWidget(const QString &appName,
							 const QString &version,
							 const int year,
							 QWidget *parent = nullptr);
	};

} //end namespace Arc

#endif // ABOUTWIDGET_H
