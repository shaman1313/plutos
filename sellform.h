#ifndef SELLFORM_H
#define SELLFORM_H

#include <QWidget>
#include <QtSql>

//Переведите кодировку в UTF-8


namespace Ui {
class sellForm;
}

class sellForm : public QWidget
{
    Q_OBJECT

public:
    explicit sellForm(QWidget *parent = 0);
    ~sellForm();

private slots:
    void on_pushButton_sellform_cancel_clicked();
    void index_of_activated(int);
    void recalculate(int, int);
    void on_pushButton_sellForm_search_clicked();
    void on_pushButton__sellForm_delete_clicked();

    void on_pushButton_sellform_ok_clicked();

public slots:

    void changeFilter();

private:
    Ui::sellForm *ui;
    QSqlTableModel* pmodel = nullptr;
    //QModelIndex mIndex;
    int rowIndex;

};

#endif // SELLFORM_H
