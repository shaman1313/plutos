#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additemsform.h"
#include "bdsettings.h"
#include "viewform.h"
#include "pcore.h"
#include "sellform.h"
#include "zvit.h"
#include <QMessageBox>
#include <QObject>
#include <QString>



//Переведите кодировку в UTF-8




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createDBconnection("view_connection");  //Creating connection to DB for different forms
    createDBconnection("add_connection");
}

MainWindow::~MainWindow()
{
    closeDBconnection("view_connection");   //closing connection with database
    closeDBconnection("add_connection");
    delete ui;

}

//for adding cases to DB
void MainWindow::on_pushButton_main_entering_clicked()
{
    addItemsForm *addForm = new addItemsForm;
    addForm -> show();
}
//open DB settings
void MainWindow::on_pushButton_main_BDsettings_clicked()
{
//    BDsettings *settingsForm = new BDsettings;
//    settingsForm->show();
}
//adding transactions (selling)
void MainWindow::on_pushButton_main_extering_clicked()
{
    sellForm *sellF = new sellForm;
    sellF->show();


}
//view database form opening
void MainWindow::on_pushButton_main_view_clicked()
{
    viewForm *view = new viewForm;
    view->show();
}

void MainWindow::on_pushButton_main_reports_clicked()
{
    zvit *zvitForm = new zvit;
    zvitForm->show();
}
