#include "additemsform.h"
#include "ui_additemsform.h"
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

//function for refreshing data in sell 'profit' in a table
//if one of sell were changed, data of profit will change

void addItemsForm::recalculate(int row){

    //if one of data cell is unset don`t recalculate profit
    if(ui->tableWidget_additemsform_table->item(row,1)==0 || ui->tableWidget_additemsform_table->item(row,3)==0 ||
            ui->tableWidget_additemsform_table->item(row,4)==0 || ui->tableWidget_additemsform_table->item(row,6)==0)
    {
        return;
    }

    //loadinf data and calculating
    int number =(ui->tableWidget_additemsform_table->item(row, 1)->text()).toInt();
    double buyPrice = (ui->tableWidget_additemsform_table->item(row, 3)->text()).toDouble();
    double sellPrice = (ui->tableWidget_additemsform_table->item(row, 4)->text()).toDouble();
    double profit = 0.0;

    profit = (sellPrice - buyPrice)*number;
    ui->tableWidget_additemsform_table->item(row, 6)->setText(QString::number(profit));

}



//Add row in a table
void addItemsForm::on_pushButton_additemsform_add_clicked()
{

    QTableWidgetItem *name = new QTableWidgetItem;
    QTableWidgetItem *number = new QTableWidgetItem;
    QTableWidgetItem *units = new QTableWidgetItem;
    QTableWidgetItem *buyprice = new QTableWidgetItem;
    QTableWidgetItem *sellprice = new QTableWidgetItem;
    QTableWidgetItem *place = new QTableWidgetItem;
    QTableWidgetItem *profit = new QTableWidgetItem;


    //for add row next after the curent
    int curRow = ui->tableWidget_additemsform_table->rowCount();

    ui->tableWidget_additemsform_table->insertRow(curRow);
    ui->tableWidget_additemsform_table->scrollToBottom();
    //setting item in a row
    ui->tableWidget_additemsform_table->setItem(curRow, 0, name);
    ui->tableWidget_additemsform_table->setItem(curRow, 1, number);
    ui->tableWidget_additemsform_table->setItem(curRow, 2, units);
    ui->tableWidget_additemsform_table->setItem(curRow, 3, buyprice);
    ui->tableWidget_additemsform_table->setItem(curRow, 4, sellprice);
    ui->tableWidget_additemsform_table->setItem(curRow, 5, place);
    ui->tableWidget_additemsform_table->setItem(curRow, 6, profit);
    //setting unitbox to cell "units"
    QComboBox *unitBox = new QComboBox;
    QString unitText[2];
    unitText[0] = "Кг.";
    unitText[1] = "Пак.";
    unitBox->insertItem(0, unitText[0].toUtf8());
    unitBox->insertItem(1, unitText[1].toUtf8());
    unitBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->tableWidget_additemsform_table->setCellWidget(curRow,2,unitBox);
    //setting placebox to cell "place"
    QComboBox *placeBox = new QComboBox;
    placeBox->insertItem(0, "Центр");
    placeBox->insertItem(1, "Сонечко");
    placeBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->tableWidget_additemsform_table->setCellWidget(curRow,5,placeBox);

    //setting profit cell uneditable
    ui->tableWidget_additemsform_table->item(curRow,6)->setFlags((ui->tableWidget_additemsform_table->item(curRow,6)->flags()) & ~Qt::ItemIsEditable);
    //connecting SIGNAL cellChanged for refreshing profit cell
    connect(ui->tableWidget_additemsform_table, ui->tableWidget_additemsform_table->cellChanged, this, addItemsForm::recalculate);

}


//exit if cancel
void addItemsForm::on_pushButton_additemsform_cancel_clicked()
{
    QWidget::close();
}

//deleting selected row
void addItemsForm::on_pushButton_additemsform_delete_clicked()
{
    int currentRow = ui->tableWidget_additemsform_table->currentRow();
    ui->tableWidget_additemsform_table->removeRow(currentRow);
}

//parsing a table and set data to DB
void addItemsForm::on_pushButton_additemsform_ok_clicked()
{
    //dont work if table is empty
    if(ui->tableWidget_additemsform_table->rowCount() == 0){
        QMessageBox::warning(0, "Warning!", "Table is empty. You must have one row at least.");
        return;
    }
    //connecting to DB slot (creating on start program) via connection name
    //and check DB state
    QSqlDatabase db = QSqlDatabase::database("add_connection");
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Database error", db.lastError().text());
            return;
        }
    }

    int maxRow = ui->tableWidget_additemsform_table->rowCount();




    QString nameIt;
    int numIt;
    QString unitIt;
    QString placeIt;
    double buypIt;
    double sellIt;
    QComboBox *ubox = new QComboBox;
    QComboBox *pbox = new QComboBox;
    //main loop to read row by row in a table
    for (int row = maxRow-1; row>=0; row--){
        //loading data from table
        nameIt = ui->tableWidget_additemsform_table->item(row, 0)->text();
        numIt = ui->tableWidget_additemsform_table->item(row, 1)->text().toInt();

        ubox = qobject_cast<QComboBox*>(ui->tableWidget_additemsform_table->cellWidget(row,2)); //I don`t know WTF, this is advice from StackOverflow
        unitIt = ubox->currentText();
        pbox = qobject_cast<QComboBox*>(ui->tableWidget_additemsform_table->cellWidget(row,5));
        placeIt = pbox->currentText();
        buypIt = ui->tableWidget_additemsform_table->item(row, 3)->text().toDouble();
        sellIt = ui->tableWidget_additemsform_table->item(row, 4)->text().toDouble();
        //query to DB
        QSqlQuery query (db);
        //it`s for adding values to query by names
        query.prepare("INSERT INTO stuff_list (name, number,units, buyprice, sellprice, place) VALUES (:name, :number, :units, :buyprice, :sellprice, :place);");
        //and adding values
        query.bindValue(":name", nameIt.toUtf8());
        query.bindValue(":number", numIt);
        query.bindValue(":units", unitIt);
        query.bindValue(":buyprice", buypIt);
        query.bindValue(":sellprice", sellIt);
        query.bindValue(":place", placeIt);
        //execution of query and check for errors
        if(!query.exec()){
            qDebug()<< "Can`t do INSERT operation. " << query.lastError();
            continue;
        }
        //remove row after success operation
        ui->tableWidget_additemsform_table->removeRow(row);
    }
    QMessageBox::information(0, "Done!", "All records were saved.");
}
