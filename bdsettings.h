#ifndef BDSETTINGS_H
#define BDSETTINGS_H

#include <QWidget>

namespace Ui {
class BDsettings;
}

class BDsettings : public QWidget
{
    Q_OBJECT

public:
    explicit BDsettings(QWidget *parent = 0);
    ~BDsettings();

public slots:

    void receiveBDStatus(bool);

private slots:
    void on_pushButton_bdsettings_newBD_clicked();

    void on_pushButton_bdsettings_connect_clicked();

signals:

    void getDBStatus();

private:
    Ui::BDsettings *ui;
};

#endif // BDSETTINGS_H
