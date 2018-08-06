#ifndef ACTIONFORM_H
#define ACTIONFORM_H

#include <QWidget>

namespace Ui {
class actionForm;
}

class actionForm : public QWidget
{
    Q_OBJECT

public:
    explicit actionForm(QWidget *parent = 0);
    ~actionForm();
public slots:
    void build(int, QString, QString, QString);

private slots:
    void on_pushButton_actionForm_close_clicked();

    void on_pushButton_actionForm_exel_clicked();

private:
    Ui::actionForm *ui;
    int opCode;
    QString beginDate;
    QString endDate;
};

#endif // ACTIONFORM_H
