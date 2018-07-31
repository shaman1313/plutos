#ifndef DELEGATES_H
#define DELEGATES_H

#include <QWidget>
#include <QStyledItemDelegate>
#include <QCompleter>

//this is delegate for cell in table with autocomplete from DB


class LineEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    LineEditDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const override;
private slots:

    void retranslateModelIndex(int);
signals:
    void completeDone(int);
};



#endif // DELEGATES_H
