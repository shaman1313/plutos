#ifndef VIEWFORM_H
#define VIEWFORM_H

#include <QWidget>

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

private:
    Ui::viewForm *ui;
};

#endif // VIEWFORM_H
