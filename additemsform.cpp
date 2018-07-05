#include "additemsform.h"
#include "ui_additemsform.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QList>
#include <QComboBox>
#include <Qt>
#include <QDebug>
#include <QFlags>
#include <QtSql>


/*      SOME STUFF FOR TESTING


QMessageBox::information(0,"Connection is success","All is good. Just close this window");


*/


using namespace std;

addItemsForm::addItemsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addItemsForm)
{
    ui->setupUi(this);
}
addItemsForm::~addItemsForm()
{
    delete ui;
}
void addItemsForm::recalculate(int row){
    if(ui->tableWidget_additemsform_table->item(row,1)==0 || ui->tableWidget_additemsform_table->item(row,3)==0 ||
            ui->tableWidget_additemsform_table->item(row,4)==0 || ui->tableWidget_additemsform_table->item(row,5)==0)
    {
        return;
    }
    int number =(ui->tableWidget_additemsform_table->item(row, 1)->text()).toInt();
    double buyPrice = (ui->tableWidget_additemsform_table->item(row, 3)->text()).toDouble();
    double sellPrice = (ui->tableWidget_additemsform_table->item(row, 4)->text()).toDouble();
    double profit = 0.0;

    profit = (sellPrice - buyPrice)*number;
    ui->tableWidget_additemsform_table->item(row, 5)->setText(QString::number(profit));

}
void addItemsForm::on_pushButton_additemsform_add_clicked()
{

    QTableWidgetItem *name = new QTableWidgetItem;
    QTableWidgetItem *number = new QTableWidgetItem;
    QTableWidgetItem *units = new QTableWidgetItem;
    QTableWidgetItem *buyprice = new QTableWidgetItem;
    QTableWidgetItem *sellprice = new QTableWidgetItem;
    QTableWidgetItem *profit = new QTableWidgetItem;

    int curRow = ui->tableWidget_additemsform_table->rowCount();

    ui->tableWidget_additemsform_table->insertRow(curRow);
    ui->tableWidget_additemsform_table->scrollToBottom();
    ui->tableWidget_additemsform_table->setItem(curRow, 0, name);
    ui->tableWidget_additemsform_table->setItem(curRow, 1, number);
    ui->tableWidget_additemsform_table->setItem(curRow, 2, units);
    ui->tableWidget_additemsform_table->setItem(curRow, 3, buyprice);
    ui->tableWidget_additemsform_table->setItem(curRow, 4, sellprice);
    ui->tableWidget_additemsform_table->setItem(curRow, 5, profit);

    QComboBox *unitBox = new QComboBox;
    unitBox->insertItem(0, "kg");
    unitBox->insertItem(1, "pack");
    unitBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->tableWidget_additemsform_table->setCellWidget(curRow,2,unitBox);



    ui->tableWidget_additemsform_table->item(curRow,5)->setFlags((ui->tableWidget_additemsform_table->item(curRow,5)->flags()) & ~Qt::ItemIsEditable);

    connect(ui->tableWidget_additemsform_table, ui->tableWidget_additemsform_table->cellChanged, this, addItemsForm::recalculate);


}
void addItemsForm::on_pushButton_additemsform_cancel_clicked()
{
    QWidget::close();
}
void addItemsForm::on_pushButton_additemsform_delete_clicked()
{
    int currentRow = ui->tableWidget_additemsform_table->currentRow();
    ui->tableWidget_additemsform_table->removeRow(currentRow);
}

static bool createDBconnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("test");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("1111");
    if(!db.open()){
        //qDebug() << "Can`t open database. " << db.lastError();
        QMessageBox::critical(0, "Database error", db.lastError().text());
        return false;
    }
    else
    {
        QMessageBox::information(0,"Connection is success","All is good. Just close this window");
        return true;
    }
}

static void closeDBconnection(){
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(db.connectionName());
}

void addItemsForm::on_pushButton_additemsform_ok_clicked()
{
    if(ui->tableWidget_additemsform_table->rowCount() == 0){
        QMessageBox::warning(0, "Warning!", "Table is empty. You must have one row at least.");
        return;
    }
    if (!createDBconnection()){
        return;
    }


    int maxRow = ui->tableWidget_additemsform_table->rowCount();

    QString nameIt;
    int numIt;
    QString unitIt;
    double buypIt;
    double sellIt;
    QComboBox *ubox = new QComboBox;

    for (int row = maxRow-1; row>=0; row--){
        nameIt = ui->tableWidget_additemsform_table->item(row, 0)->text();
        numIt = ui->tableWidget_additemsform_table->item(row, 1)->text().toInt();
        ubox =  qobject_cast<QComboBox*>(ui->tableWidget_additemsform_table->cellWidget(row,2));
        unitIt = ubox->currentText();
        buypIt = ui->tableWidget_additemsform_table->item(row, 3)->text().toDouble();
        sellIt = ui->tableWidget_additemsform_table->item(row, 4)->text().toDouble();

        QSqlQuery query;
        query.prepare("INSERT INTO stuff_list (name, number,units, buyprice, sellprice) VALUES (:name, :number, :units, :buyprice, :sellprice);");
        query.bindValue(":name", nameIt);
        query.bindValue(":number", numIt);
        query.bindValue(":units", unitIt);
        query.bindValue(":buyprice", buypIt);
        query.bindValue(":sellprice", sellIt);
        if(!query.exec()){
            qDebug()<< "Can`t do INSERT operation. " << query.lastError();
            continue;
        }
        ui->tableWidget_additemsform_table->removeRow(row);
    }
    QMessageBox::information(0, "Done!", "All records were saved.");
    closeDBconnection();

}
