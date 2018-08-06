#include "additemsform.h"
#include "ui_additemsform.h"
#include "yascompleter.h"
#include "delegates.h"
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
#include <QLineEdit>


/*      SOME STUFF FOR TESTING

//Переведите кодировку в UTF-8


QMessageBox::information(0,"Connection is success","All is good. Just close this window");

*/


addItemsForm::addItemsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addItemsForm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
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
    //if profit will be 0 ore less, cell will paint in red color
    QBrush redAlert;
    redAlert.setStyle(Qt::Dense4Pattern);
    redAlert.setColor("red");
    //loadinf data and calculating
    double number =(ui->tableWidget_additemsform_table->item(row, 1)->text()).replace(",", ".").toDouble();
    double buyPrice = (ui->tableWidget_additemsform_table->item(row, 3)->text().replace(",", ".")).toDouble();
    double sellPrice = (ui->tableWidget_additemsform_table->item(row, 4)->text().replace(",", ".")).toDouble();
    double profit = 0.0;
    QString profitStr;
    int profitPers;
    profit = (sellPrice - buyPrice)*number;
    //to show percentage in profit
    profitPers = int(((sellPrice - buyPrice)/buyPrice)*100);
    profitStr = QString::number(profit);
    profitStr += " (";
    profitStr += QString::number(profitPers);
    profitStr += " %)";
    //colorise profit cell
    ui->tableWidget_additemsform_table->item(row, 6)->setText(profitStr);
    if(profit<=0.0){
        ui->tableWidget_additemsform_table->item(row,6)->setBackground(redAlert);
    }
    else{
        ui->tableWidget_additemsform_table->item(row,6)->setBackground(Qt::NoBrush);
    }

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




    QSqlDatabase db = QSqlDatabase::database("add_connection");
    //check if DB is alive
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Помилка БД", db.lastError().text());
        }
    }

    QSqlTableModel *cModel = new QSqlTableModel(this, db);
    this->pModel = cModel;
    this->complRowIndex = -1;
//    //Model is SQL model of table in DB
//       //setting table to model
    cModel->setTable("stuff");

    //select query
    cModel->select();
    //denied record to DB automaticly
    cModel->setEditStrategy(QSqlTableModel::OnManualSubmit);


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
    //creating the delegate for table cell (QLineEdit)
    //and setting it to cell
    LineEditDelegate *tLineEdit = new LineEditDelegate;
    ui->tableWidget_additemsform_table->setItemDelegateForColumn(0, tLineEdit);


    //setting unitbox to cell "units"
    QComboBox *unitBox = new QComboBox;
    unitBox->insertItem(0, "Пак.");
    unitBox->insertItem(1, "Кг.");
    unitBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->tableWidget_additemsform_table->setCellWidget(curRow,2,unitBox);

    //setting placebox to cell "place"
    QComboBox *placeBox = new QComboBox;
    placeBox->insertItem(0, "Центр");
    //placeBox->insertItem(1, "Сонечко");
    placeBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->tableWidget_additemsform_table->setCellWidget(curRow,5,placeBox);



    //setting profit cell uneditable
    ui->tableWidget_additemsform_table->item(curRow,6)->setFlags((ui->tableWidget_additemsform_table->item(curRow,6)->flags()) & ~Qt::ItemIsEditable);
    //connecting SIGNAL cellChanged for refreshing profit cell
    connect(ui->tableWidget_additemsform_table, ui->tableWidget_additemsform_table->cellChanged, this, addItemsForm::recalculate);
    //thos SIGNAL for catching autocompleter index from autocompleter model
    //by this index we can load data from model but in another cells, rather autocomplete column
    connect(tLineEdit, LineEditDelegate::completeDone, this, catchCompleterIndex);
    //and when user choised record from autocompleter, we load data from other fields of this record
    connect(ui->tableWidget_additemsform_table, ui->tableWidget_additemsform_table->cellChanged, this, addItemsForm::loadAutocompleteData);

}


//exit if cancel
void addItemsForm::on_pushButton_additemsform_cancel_clicked()
{
    QWidget::close();
}
//this is index (row index) of model, were autocompleter find record
//we use this index in loadAutocomplete Data
void addItemsForm::catchCompleterIndex(int row){
    this->complRowIndex = row;
}

//load data from autocompleter model
void addItemsForm::loadAutocompleteData(int row, int col){
    //if cell 'name' did`nt changed or autocomplete index not valid - do nothing
    if (col!=0 || ui->tableWidget_additemsform_table->item(row, 0)==0 || this->complRowIndex<0){
        return;
    }

    QModelIndex index;
    QVariant dataset;
    QComboBox *ubox = new QComboBox;
    int rowInd = this->complRowIndex;
    //load data: units, buy price and sell price
    index = this->pModel->index(rowInd, 5);
    dataset = this->pModel->data(index);
    ubox = qobject_cast<QComboBox*>(ui->tableWidget_additemsform_table->cellWidget(row, 2));
    ubox->setCurrentIndex(dataset.toInt());
    ui->tableWidget_additemsform_table->setCellWidget(row, 2, ubox);

    index = this->pModel->index(rowInd, 3);
    dataset = this->pModel->data(index);
    ui->tableWidget_additemsform_table->item(row, 3)->setData(0, dataset);

    index = this->pModel->index(rowInd, 4);
    dataset = this->pModel->data(index);
    ui->tableWidget_additemsform_table->item(row, 4)->setData(0, dataset);
    //invalidation of autocomplete index
    this->complRowIndex = -1;
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
        QMessageBox::warning(0, "Увага!", "Таблиця порожня. Необхідно мати щонайменше один запис.");
        return;
    }
    //connecting to DB slot (creating on start program) via connection name
    //and check DB state
    QSqlDatabase db = QSqlDatabase::database("add_connection");
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Помилка БД", db.lastError().text());
            return;
        }
    }

    int maxRow = ui->tableWidget_additemsform_table->rowCount();

    QString nameIt;
    double numIt;
    int unitIt;

    int placeIt;
    double buypIt;
    double sellIt;
    QComboBox *ubox = new QComboBox;
    QComboBox *pbox = new QComboBox;

    //query to DB
    QSqlQuery query (db);
    bool success = true;

    //Model is SQL model of table in DB
    QSqlTableModel *addModel = new QSqlTableModel(this, db);
    QString f = ""; //filter for model
    QModelIndex index;
    QVariant dataset;
    double lastNumber;
    double lastBuyprice;
    double allprice;
    int typeOp = 1;
    QDateTime currentDate = QDateTime::currentDateTime();
    QString dateTimeStr = currentDate.toString("yyyy-MM-dd hh:mm:ss");


    //setting table to model
    addModel->setTable("stuff");

    //denied record to DB automaticly
    addModel->setEditStrategy(QSqlTableModel::OnManualSubmit);




    //main loop to read row by row in a table
    for (int row = maxRow-1; row>=0; row--){
        //loading data from table
        //name
        index = ui->tableWidget_additemsform_table->model()->index(row, 0);
        nameIt = ui->tableWidget_additemsform_table->model()->data(index).toString() ;

        if (nameIt.isEmpty()){
            QMessageBox::warning(0, "Увага!", "Поле 'НАЗВА' не повинно бути порожнім!");
            success = false;
            continue;
        }
        //number
        numIt = ui->tableWidget_additemsform_table->item(row, 1)->text().replace(",", ".").toDouble();
        //units
        ubox = qobject_cast<QComboBox*>(ui->tableWidget_additemsform_table->cellWidget(row,2)); //It is a TYPE converting
        unitIt = ubox->currentIndex();
        //place
        pbox = qobject_cast<QComboBox*>(ui->tableWidget_additemsform_table->cellWidget(row,5));
        placeIt = pbox->currentIndex();
        //prices
        buypIt = ui->tableWidget_additemsform_table->item(row, 3)->text().replace(",", ".").toDouble();
        sellIt = ui->tableWidget_additemsform_table->item(row, 4)->text().replace(",", ".").toDouble();

        //filter for model by name
        f+= "name = '";
        f+= nameIt;
        f+= "'";

        //filter for model
        //filter is statement 'WHERE' without word where
        //'name LIKE %abc%' for example
        if(!f.isEmpty()){
            addModel->setFilter(f);
            addModel->select();
        }
        //check if stuff is in database, and how much records have such name
        int numRow = addModel->rowCount();

        switch (numRow) {
        //if stuff is not in DB, we create new record in DB
        case 0:
            //it`s for adding values to query by names
            query.prepare("INSERT INTO stuff (name, number,units, buyprice, sellprice, place) VALUES (:name, :number, :units, :buyprice, :sellprice, :place);");
            //and adding values
            query.bindValue(":name", nameIt.toUtf8());
            query.bindValue(":number", numIt);
            query.bindValue(":units", unitIt);
            query.bindValue(":buyprice", buypIt);
            query.bindValue(":sellprice", sellIt);
            query.bindValue(":place", placeIt);
            //execution of query and check for errors
            //qDebug() << query.boundValues();
            if(!query.exec()){
                success = false;
                continue;
            }
            //remove row after success operation
            ui->tableWidget_additemsform_table->removeRow(row);
            break;
        //if stuff(s) in DB
        default:
            //we seek record with equal buyprice and update this record
            for(int i = 0; i<numRow; i++ ){
                index = addModel->index(i, 3);
                dataset = addModel->data(index);
                lastBuyprice = dataset.toDouble();
                if (lastBuyprice == buypIt){
                    index = addModel->index(i, 2);
                    dataset = addModel->data(index);
                    lastNumber = dataset.toDouble();


                    query.prepare("UPDATE stuff SET number=:number, units=:units, sellprice=:sellprice, place=:place WHERE name=:name AND buyprice=:buyprice;");
                    //and adding values
                    query.bindValue(":name", nameIt.toUtf8());
                    query.bindValue(":number", numIt+lastNumber);
                    query.bindValue(":units", unitIt);
                    query.bindValue(":buyprice", buypIt);
                    query.bindValue(":sellprice", sellIt);
                    query.bindValue(":place", placeIt);
                    //execution of query and check for errors
                    //qDebug() << query.boundValues();
                    if(!query.exec()){
                        success = false;
                        break;
                    }
                    //remove row after success operation
                    ui->tableWidget_additemsform_table->removeRow(row);
                    break;
                }
                //otherwise we create new record in DB
                else{
                    //if this is last record with name 'name' we create new record
                    if(i == numRow-1){
                        //it`s for adding values to query by names
                        query.prepare("INSERT INTO stuff (name, number,units, buyprice, sellprice, place) VALUES (:name, :number, :units, :buyprice, :sellprice, :place);");
                        //and adding values
                        query.bindValue(":name", nameIt.toUtf8());
                        query.bindValue(":number", numIt);
                        query.bindValue(":units", unitIt);
                        query.bindValue(":buyprice", buypIt);
                        query.bindValue(":sellprice", sellIt);
                        query.bindValue(":place", placeIt);
                        //execution of query and check for errors
                        //qDebug() << query.boundValues();
                        if(!query.exec()){
                            success = false;
                            break;
                        }
                        //remove row after success operation
                        ui->tableWidget_additemsform_table->removeRow(row);
                        break;
                    }
                    continue;
                }

            }
            query.prepare("UPDATE stuff SET sellprice=:sellprice WHERE name=:name;");
            query.bindValue(":name", nameIt.toUtf8());
            query.bindValue(":sellprice", sellIt);
            if(!query.exec()){
                success = false;
                continue;
            }
            break;
        }
        allprice = numIt * buypIt;
        query.prepare("INSERT INTO action (time, type, name, number, sellprice, allprice, profit) "
                                "VALUES (:time, :type, :name, :number, :sellprice, :allprice, :profit);");
        query.bindValue(":time", dateTimeStr);
        query.bindValue(":type", typeOp);
        query.bindValue(":name", nameIt.toUtf8());
        query.bindValue(":number", numIt);
        query.bindValue(":sellprice", buypIt);
        query.bindValue(":allprice", allprice);
        query.bindValue(":profit", 0);
        if(!query.exec()){
            success = false;
            continue;
        }

    }

    if (!success){
        QMessageBox::warning(0, "Увага!", query.lastError().text()+=" \nДеякі записи не були збережені в БД");
    }
    else{
        QMessageBox::information(0, "Виконано!", "Всі записи збережено в БД.");
    }

}
