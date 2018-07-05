#include "bdsettings.h"
#include "ui_bdsettings.h"
#include <QtSql>
#include <QAbstractButton>
#include <QSqlDatabase>


BDsettings::BDsettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BDsettings)
{
    ui->setupUi(this);
}

BDsettings::~BDsettings()
{
    delete ui;
}


void BDsettings::on_pushButton_bdsettings_newBD_clicked()
{

}

void BDsettings::on_pushButton_bdsettings_connect_clicked()
{

}

void BDsettings::receiveBDStatus(bool stat){
    ui->checkBox_bdsettings_status->setChecked(stat);
    if(stat){
        ui->checkBox_bdsettings_status->setText("Connected");
    }
    else{
        ui->checkBox_bdsettings_status->setText("Disconnected");
    }
}
