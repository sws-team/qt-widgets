#include "recentfiles.h"

#include <QSettings>
#include <QMenu>

using namespace Arc;

RecentFiles::RecentFiles(QMenu *menu, QObject *parent) :
	QObject(parent)
	,menu(menu)
	,m_maxRecent(DEFAULT_MAX_RECENT)
{

}

void RecentFiles::appendFileName(const QString &fileName)
{
	const QList<QAction*> actions = menu->actions();
	foreach(QAction* action, actions)
		if (action->text() == fileName)
		{
			menu->removeAction(action);
			break;
		}
	addAction(fileName);
}

void RecentFiles::load(QSettings *settings)
{
	settings->beginGroup("Recent");
	const QStringList recentFileNames = settings->value("RecentList").toStringList();
	settings->endGroup();

	for (int i = recentFileNames.size() - 1; i >= 0; --i)
		addAction(recentFileNames.value(i));
}

void RecentFiles::save(QSettings *settings)
{
	settings->beginGroup("Recent");
	const QList<QAction*> actions = menu->actions();
	QStringList recentFileNames;
	foreach(QAction* action, actions)
		recentFileNames.push_back(action->text());
	settings->setValue("RecentList", recentFileNames);
	settings->endGroup();
}

void RecentFiles::setMaxRecent(int maxRecent)
{
	m_maxRecent = maxRecent;
}

QString RecentFiles::last() const
{
	if (!menu->actions().isEmpty())
		return menu->actions().first()->text();
	return QString();
}

bool RecentFiles::isEmpty() const
{
	return menu->actions().isEmpty();
}

void RecentFiles::actionTriggered()
{
	QAction *action = dynamic_cast<QAction*>(sender());
	if (action == Q_NULLPTR)
		return;
	emit openFileTriggered(action->text());
}

void RecentFiles::addAction(const QString &name)
{
	QAction *action = new QAction(name, menu);
	connect(action, &QAction::triggered, this, &RecentFiles::actionTriggered);
	const QList<QAction*> actions = menu->actions();
	if (actions.isEmpty())
	{
		menu->addAction(action);
		return;
	}
	menu->insertAction(actions.first(), action);
	if (actions.size() >= m_maxRecent)
		menu->removeAction(actions.last());
}
