#ifndef INFOFORM_H
#define INFOFORM_H

#include <QWidget>

namespace Ui {
class infoForm;
}

class infoForm : public QWidget
{
    Q_OBJECT

public:
    explicit infoForm(QWidget *parent = 0);
    ~infoForm();

private slots:
    void on_pushButton_info_clicked();

private:
    Ui::infoForm *ui;
};

#endif // INFOFORM_H
