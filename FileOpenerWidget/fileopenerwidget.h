#ifndef FILEOPENERWIDGET_H
#define FILEOPENERWIDGET_H

#include <QObject>
#include <QWidget>
#include "../widgets_global.h"

class QLineEdit;
class WIDGETS_EXPORT FileOpenerWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath)
public:

    enum TYPE
    {
        OPEN_FILE,
        SAVE_FILE,
        OPEN_PATH
    };

    explicit FileOpenerWidget(QWidget *parent = nullptr);

    void setPath(const QString& path);
    QString path() const;

    TYPE type() const;
    void setType(const TYPE &type);

    QLineEdit *lineEdit() const;

    void setFilter(const QString &filter);

signals:
    void editingFinished();
    void textChanged(const QString&);
private slots:
    void showOpenFileDialog();

private:
    QLineEdit *m_lineEdit;
    class QPushButton *m_button;
    TYPE m_type;
    QString m_filter;
};

#endif // FILEOPENERWIDGET_H
