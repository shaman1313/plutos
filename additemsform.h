#ifndef ADDITEMSFORM_H
#define ADDITEMSFORM_H

#include <QWidget>
#include <string>
#include <QSqlTableModel>

//Переведите кодировку в UTF-8

namespace Ui {
class addItemsForm;
}

class addItemsForm : public QWidget
{
    Q_OBJECT

public:
    explicit addItemsForm(QWidget *parent = 0);
    ~addItemsForm();

private slots:

    void on_pushButton_additemsform_add_clicked();

    void on_pushButton_additemsform_cancel_clicked();

    void on_pushButton_additemsform_delete_clicked();
    void catchCompleterIndex(int);
    void loadAutocompleteData(int, int);
    void recalculate(int);

    void on_pushButton_additemsform_ok_clicked();


private:
    Ui::addItemsForm *ui;
    int complRowIndex;
    QSqlTableModel * pModel = nullptr;
};

#endif // ADDITEMSFORM_H
