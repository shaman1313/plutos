#include "bdsettings.h"
#include "ui_bdsettings.h"

//Переведите кодировку в UTF-8

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

