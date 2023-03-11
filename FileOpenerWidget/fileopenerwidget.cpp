#include "fileopenerwidget.h"

#include <QPushButton>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLineEdit>

FileOpenerWidget::FileOpenerWidget(QWidget *parent) :
    QWidget(parent)
  ,m_type(OPEN_FILE)
{
    m_button = new QPushButton(this);
    m_lineEdit = new QLineEdit(this);
    m_button->setIcon(QIcon(":/resources/browse.png"));
    m_button->setToolTip(tr("Browse..."));
    connect(m_button, &QPushButton::clicked, this, &FileOpenerWidget::showOpenFileDialog);
    connect(m_lineEdit, &QLineEdit::editingFinished, this, &FileOpenerWidget::editingFinished);
    connect(m_lineEdit, &QLineEdit::textChanged, this, &FileOpenerWidget::textChanged);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_lineEdit);
    layout->addWidget(m_button);
	layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(1);
    this->setLayout(layout);
}

void FileOpenerWidget::setPath(const QString &path)
{
    m_lineEdit->setText(path);
}

QString FileOpenerWidget::path() const
{
    return m_lineEdit->text();
}

void FileOpenerWidget::showOpenFileDialog()
{
    QString resultPath;
    switch (m_type)
    {
    case OPEN_FILE:
        resultPath = QFileDialog::getOpenFileName(this, tr("Choose file"), path(), m_filter);
         break;
    case OPEN_PATH:
        resultPath = QFileDialog::getExistingDirectory(this, tr("Choose path"), path());
         break;
    case SAVE_FILE:
        resultPath = QFileDialog::getSaveFileName(this, tr("Choose file"), path(), m_filter);
         break;
    default:
        break;
    }
    if (!resultPath.isEmpty())
    {
        m_lineEdit->setText(resultPath);
        emit editingFinished();
    }
}

void FileOpenerWidget::setFilter(const QString &filter)
{
    m_filter = filter;
}

QLineEdit *FileOpenerWidget::lineEdit() const
{
    return m_lineEdit;
}

FileOpenerWidget::TYPE FileOpenerWidget::type() const
{
    return m_type;
}

void FileOpenerWidget::setType(const TYPE &type)
{
    m_type = type;
}
