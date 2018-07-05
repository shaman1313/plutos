#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additemsform.h"
#include "bdsettings.h"
#include <QMessageBox>
#include <QObject>


/*      SOME STUFF FOR TESTING


QMessageBox::information(0,"Connection is success","All is good. Just close this window");


*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeStatus(bool stat){
    ui->checkBox_mainwindow_DBStat->setChecked(stat);
    if(stat){
        ui->checkBox_mainwindow_DBStat->setText("Connected");
    }
    else{
        ui->checkBox_mainwindow_DBStat->setText("Disconnected");
    }

}

void MainWindow::on_pushButton_main_entering_clicked()
{
    addItemsForm *addForm = new addItemsForm;
    addForm -> show();
}

void MainWindow::on_pushButton_main_BDsettings_clicked()
{
    BDsettings *settingsForm = new BDsettings;
    settingsForm->show();
}




void MainWindow::on_pushButton_main_extering_clicked()
{



}
