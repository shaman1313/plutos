#ifndef SELLFORM_H
#define SELLFORM_H

#include <QWidget>
#include <QtSql>

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

    void on_pushButton_sellForm_search_clicked();
public slots:

    void changeFilter();

private:
    Ui::sellForm *ui;
    QSqlTableModel* pmodel = nullptr;
};

#endif // SELLFORM_H
