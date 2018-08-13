#ifndef ZVIT_H
#define ZVIT_H

#include <QWidget>

namespace Ui {
class zvit;
}

class zvit : public QWidget
{
    Q_OBJECT

public:
    explicit zvit(QWidget *parent = 0);
    ~zvit();

private slots:
    void on_pushButton_zvit_cancel_clicked();

    void on_pushButton_zvit_build_clicked();
signals:
    void startBuildingreport(int, QString, QString, QString, bool, int);
private:
    Ui::zvit *ui;
};

#endif // ZVIT_H
