#ifndef RECENTFILES_H
#define RECENTFILES_H

#include <QObject>

class QMenu;
class QSettings;

namespace Arc {

	class RecentFiles : public QObject
	{
		Q_OBJECT
	public:
		explicit RecentFiles(QMenu *menu, QObject *parent = nullptr);
		void appendFileName(const QString& fileName);

		void load(QSettings *settings);
		void save(QSettings *settings);

		void setMaxRecent(int maxRecent);

		QString last() const;

		bool isEmpty() const;

	signals:
		void openFileTriggered(const QString&);

	private slots:
		void actionTriggered();
	private:
		QMenu *menu;
		Q_DECL_CONSTEXPR static int DEFAULT_MAX_RECENT = 5;
		int m_maxRecent;
		void addAction(const QString& name);
	};

} //end namespace Arc


#endif // RECENTFILES_H
