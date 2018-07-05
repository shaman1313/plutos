#ifndef ADDITEMSFORM_H
#define ADDITEMSFORM_H

#include <QWidget>
#include <string>


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

//    void on_pushButton_additemsform_edit_clicked();

    void recalculate(int);

    void on_pushButton_additemsform_ok_clicked();

public slots:

//    void receiving_item_informationE(QString, int, QString, double, double, int);

signals:

     void send_data(QString, int, QString, double, double, int);

private:
    Ui::addItemsForm *ui;
};

#endif // ADDITEMSFORM_H
