#ifndef BDSETTINGS_H
#define BDSETTINGS_H

#include <QWidget>

//Переведите кодировку в UTF-8


namespace Ui {
class BDsettings;
}

class BDsettings : public QWidget
{
    Q_OBJECT

public:
    explicit BDsettings(QWidget *parent = 0);
    ~BDsettings();


private slots:
    void on_pushButton_bdsettings_newBD_clicked();

    void on_pushButton_bdsettings_connect_clicked();


private:
    Ui::BDsettings *ui;
};

#endif // BDSETTINGS_H
