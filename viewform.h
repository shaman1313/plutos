#ifndef VIEWFORM_H
#define VIEWFORM_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class viewForm;
}

class viewForm : public QWidget
{
    Q_OBJECT

public:
    explicit viewForm(QWidget *parent = 0);
    ~viewForm();

private slots:
    bool getContent(QString f="");
    void on_pushButton_viewForm_cancel_clicked();
    void on_pushButton_viewform_search_clicked();
    void on_pushButton_viewForm_exel_clicked();

    void on_pushButton_viewForm_ok_clicked();

private:
    Ui::viewForm *ui;
    QSqlTableModel *pmodel=0;
};

#endif // VIEWFORM_H
