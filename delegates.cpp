#include "delegates.h"
#include "yascompleter.h"
#include <QWidget>
#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>

LineEditDelegate::LineEditDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *LineEditDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    QSqlDatabase db = QSqlDatabase::database("add_connection");
    //check if DB is alive
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Помилка БД", db.lastError().text());
        }
    }
    YAScompleter *completer = new YAScompleter(parent);
    QSqlTableModel *cModel = new QSqlTableModel(parent, db);

    //Model is SQL model of table in DB
       //setting table to model
    cModel->setTable("stuff");

    //select query
    cModel->select();
    //denied record to DB automaticly
    cModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //binding completer with model
    completer->setModel(cModel);
    completer->setCompletionColumn(1);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);

    editor->setCompleter(completer);
    connect(completer, YAScompleter::sendNaturalIndex, this, retranslateModelIndex);
    return editor;
}

void LineEditDelegate::retranslateModelIndex(int row)
{
    emit completeDone(row);
}


void LineEditDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();

    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    lineEdit->setText(value);
}

void LineEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    QString value = lineEdit->text();

    model->setData(index, value, Qt::EditRole);
}

void LineEditDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
