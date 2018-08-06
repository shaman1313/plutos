#include "sellform.h"
#include "ui_sellform.h"
#include "yascompleter.h"
#include <QtSql>
#include <QMessageBox>
#include <QCompleter>
#include <QDebug>
#include <QObject>

//Переведите кодировку в UTF-8


sellForm::sellForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sellForm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    QSqlDatabase db = QSqlDatabase::database("view_connection");
    //check if DB is alive
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Помилка БД", db.lastError().text());
        }
    }

    //Model is SQL model of table in DB
    QSqlTableModel *model = new QSqlTableModel(this, db);
    this->pmodel = model;
    QString filter = "place = '";
    filter += ui->comboBox_sellForm_place->currentText();
    filter += "'";
    filter += " AND number > 0.0";

    //setting table to model
    model->setTable("stuff");
    model->setFilter(filter);
    //select query
    model->select();
    //denied record to DB automaticly
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //autocompleter for searchline
    YAScompleter *completer = new YAScompleter(this);
    //QCompleter* completer = new QCompleter(this);
    //binding completer with model
    completer->setModel(model);
    completer->setCompletionColumn(1);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    ui->lineEdit_sellForm_serarch->setCompleter(completer);


    QObject::connect(ui->comboBox_sellForm_place, ui->comboBox_sellForm_place->currentTextChanged, this, sellForm::changeFilter);
    QObject::connect(completer, YAScompleter::sendNaturalIndex, this, sellForm::index_of_activated);
    QObject::connect(ui->tableWidget_sellForm_table, ui->tableWidget_sellForm_table->cellChanged, this, sellForm::recalculate);

}

sellForm::~sellForm()
{
    delete ui;
}

void sellForm::changeFilter()
{
    QString filter = "place = '";
    filter += ui->comboBox_sellForm_place->currentText();
    filter += "'";
    this->pmodel->setFilter(filter);
    this->pmodel->select();
}

void sellForm::index_of_activated(int index)
{
    this->rowIndex = index;
}


void sellForm::on_pushButton_sellform_cancel_clicked()
{
    QWidget::close();
}

void sellForm::recalculate(int row, int col){



    int currentRow = ui->tableWidget_sellForm_table->currentRow();
    if (currentRow!=row || (col!=1 && col!=2)){

        return;
    }

    //if one of data cell is unset don`t recalculate profit
    if(ui->tableWidget_sellForm_table->item(row,1)==0 || ui->tableWidget_sellForm_table->item(row,2)==0
            || ui->tableWidget_sellForm_table->item(row,3)==0 || ui->tableWidget_sellForm_table->item(row,4)==0)
    {

        return;
    }

    QBrush redAlert;
    redAlert.setStyle(Qt::Dense4Pattern);
    redAlert.setColor("red");

    QSqlDatabase db = QSqlDatabase::database("view_connection");
    //check if DB is alive
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Помилка БД", db.lastError().text());
        }
    }
    QSqlTableModel *rModel = new QSqlTableModel(this, db);
    rModel->setTable("stuff");

    //loadinf data and calculating
    //calculating profit, we seek all stuff with 'name',
    //add them, sell lowcost firstly and calculate frofit

    QModelIndex index;
    QVariant dataset;
    QString f = "name = '";
    f += ui->tableWidget_sellForm_table->item(row, 0)->text();
    f += "'";
    rModel->setFilter(f);
    rModel->setSort(3, Qt::AscendingOrder);
    rModel->select();
    int count = rModel->rowCount();

    double allNumber = 0.0;
    double buyPrice = 0.0;
    double sellprice = (ui->tableWidget_sellForm_table->item(row, 2)->text().replace(",", ".")).toDouble();
    double profit = 0.0;
    double tempNumber = 0.0;
    double allprice = 0.0;
    double number =(ui->tableWidget_sellForm_table->item(row, 1)->text().replace(",", ".")).toDouble();

    if(count!=0){
        ui->tableWidget_sellForm_table->item(row, 0)->setBackground(Qt::NoBrush);
        for (int i=0; i<count; i++){
            index = rModel->index(i, 2);
            dataset = rModel->data(index);
            allNumber += dataset.toDouble();
        }
    }
    else{
        QMessageBox::warning(0, "Увага!", "Такий товар не знайдено в БД");
        ui->tableWidget_sellForm_table->item(row, 0)->setBackground(redAlert);

        return;
    }


    if (number > allNumber){
        QMessageBox::critical(0, "Помилка!", "Такої кількості товару немає у БД.");
        ui->tableWidget_sellForm_table->item(row, 1)->setBackground(redAlert);

        return;
    }
    else{
        allprice = sellprice * number;
        ui->tableWidget_sellForm_table->item(row, 3)->setText(QString::number(allprice));
        ui->tableWidget_sellForm_table->item(row, 1)->setBackground(Qt::NoBrush);
        for (int i=0; i<count; i++){
            index = rModel->index(i, 3);
            dataset = rModel->data(index);
            buyPrice = dataset.toDouble();
            index = rModel->index(i, 2);
            dataset = rModel->data(index);
            tempNumber = dataset.toDouble();
            if(number > tempNumber){
                profit += (tempNumber * sellprice)-(tempNumber * buyPrice);
                number -= tempNumber;
                continue;
            }
            else{
                profit += (number * sellprice)-(number * buyPrice);
                break;
            }
        }
    }

    ui->tableWidget_sellForm_table->item(row, 4)->setText(QString::number(profit));
    if(profit<=0.0){
        ui->tableWidget_sellForm_table->item(row,4)->setBackground(redAlert);
    }
    else{
        ui->tableWidget_sellForm_table->item(row,4)->setBackground(Qt::NoBrush);
    }



    delete rModel;
}


void sellForm::on_pushButton_sellForm_search_clicked()
{
    QString nameStr = ui->lineEdit_sellForm_serarch->text();

    if(nameStr.isEmpty()){
        return;
    }

    QSqlDatabase db = QSqlDatabase::database("view_connection");
    //check if DB is alive
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Помилка БД", db.lastError().text());
        }
    }
    QSqlTableModel *rModel = new QSqlTableModel(this, db);
    rModel->setTable("stuff");

    QString f = "name = '";
    f += nameStr;
    f += "'";
    rModel->setFilter(f);

    rModel->select();
    int count = rModel->rowCount();
    if(count==0){
        QMessageBox::warning(0, "Увага!", "Такий товар не знайдено в БД");
        delete rModel;
        return;
    }

    int curRow = ui->tableWidget_sellForm_table->rowCount();
    QVariant dataset;
    QModelIndex index;

    ui->lineEdit_sellForm_serarch->clear();
    QString sellprise;

    ui->tableWidget_sellForm_table->insertRow(curRow);
    ui->tableWidget_sellForm_table->scrollToBottom();

    QTableWidgetItem *nameIt = new QTableWidgetItem;
    QTableWidgetItem *numberIt = new QTableWidgetItem;
    QTableWidgetItem *sellpriseIt = new QTableWidgetItem;
    QTableWidgetItem *allpriceIt = new QTableWidgetItem;
    QTableWidgetItem *profitIt = new QTableWidgetItem;

    nameIt->setText(nameStr);
    ui->tableWidget_sellForm_table->setItem(curRow, 0, nameIt);
    ui->tableWidget_sellForm_table->setItem(curRow, 1, numberIt);
    index = this->pmodel->index(this->rowIndex, 4);
    dataset = this->pmodel->data(index);
    sellprise = dataset.toString();
    sellpriseIt->setText(sellprise);
    ui->tableWidget_sellForm_table->setItem(curRow, 2, sellpriseIt);
    ui->tableWidget_sellForm_table->setItem(curRow, 3, allpriceIt);
    ui->tableWidget_sellForm_table->setItem(curRow, 4, profitIt);

    ui->tableWidget_sellForm_table->item(curRow,0)->setFlags((ui->tableWidget_sellForm_table->item(curRow,0)->flags()) & ~Qt::ItemIsEditable);
    ui->tableWidget_sellForm_table->item(curRow,3)->setFlags((ui->tableWidget_sellForm_table->item(curRow,3)->flags()) & ~Qt::ItemIsEditable);
    ui->tableWidget_sellForm_table->item(curRow,4)->setFlags((ui->tableWidget_sellForm_table->item(curRow,4)->flags()) & ~Qt::ItemIsEditable);



    delete rModel;

}

void sellForm::on_pushButton__sellForm_delete_clicked()
{
    int currentRow = ui->tableWidget_sellForm_table->currentRow();
    ui->tableWidget_sellForm_table->removeRow(currentRow);
}

void sellForm::on_pushButton_sellform_ok_clicked()
{
    //dont work if table is empty
    if(ui->tableWidget_sellForm_table->rowCount() == 0){
        QMessageBox::warning(0, "Увага!", "Таблиця порожня. Необхідно мати щонайменше один запис.");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database("add_connection");
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Помилка БД", db.lastError().text());
            return;
        }
    }

    //query to DB
    QSqlQuery query (db);
    bool success = true;

    QSqlTableModel *rModel = new QSqlTableModel(this, db);
    rModel->setTable("stuff");




    QString name;
    double number;
    double sellprise;
    double allprice;
    double profit;
    int typeOp = 0;
    QDateTime currentDate = QDateTime::currentDateTime();
    QString dateTimeStr = currentDate.toString("yyyy-MM-dd hh:mm:ss");


    int maxRows = ui->tableWidget_sellForm_table->rowCount();



    for(int row = maxRows-1; row>=0; row--){
        name = ui->tableWidget_sellForm_table->item(row, 0)->text();
        number = ui->tableWidget_sellForm_table->item(row, 1)->text().replace(",", ".").toDouble();
        sellprise = ui->tableWidget_sellForm_table->item(row, 2)->text().replace(",", ".").toDouble();
        allprice = ui->tableWidget_sellForm_table->item(row, 3)->text().replace(",", ".").toDouble();
        profit = ui->tableWidget_sellForm_table->item(row, 4)->text().replace(",", ".").toDouble();


        query.prepare("INSERT INTO action (time, type, name, number, sellprice, allprice, profit) "
                                "VALUES (:time, :type, :name, :number, :sellprice, :allprice, :profit);");
        query.bindValue(":time", dateTimeStr);
        query.bindValue(":type", typeOp);
        query.bindValue(":name", name.toUtf8());
        query.bindValue(":number", number);
        query.bindValue(":sellprice", sellprise);
        query.bindValue(":allprice", allprice);
        query.bindValue(":profit", profit);
        if(!query.exec()){
            success = false;
            continue;
        }
        ui->tableWidget_sellForm_table->removeRow(row);


        QModelIndex index;
        QVariant dataset;
        QString f = "name = '";
        f += name;
        f += "'";
        rModel->setFilter(f);
        rModel->setSort(3, Qt::AscendingOrder);
        rModel->select();
        int count = rModel->rowCount();

        double allNumber = 0.0;
        double buyPrice =0.0;
        double tempNumber = 0.0;


        if(count!=0){

            for (int i=0; i<count; i++){
                index = rModel->index(i, 2);
                dataset = rModel->data(index);
                allNumber += dataset.toDouble();
            }
        }
        else{
            QMessageBox::warning(0, "Увага!", "Такий товар не знайдено в БД");
            return;
        }


        if (number > allNumber){
            QMessageBox::critical(0, "Помилка!", "Такої кількості товару немає у БД.");
            return;
        }
        else{

            for (int i=0; i<count; i++){
                index = rModel->index(i, 3);
                dataset = rModel->data(index);
                buyPrice = dataset.toDouble();
                index = rModel->index(i, 2);
                dataset = rModel->data(index);
                tempNumber = dataset.toDouble();
                if(number > tempNumber){
                    query.prepare("UPDATE stuff SET number=:number WHERE name=:name AND buyprice=:buyprice;");
                    query.bindValue(":name", name);
                    query.bindValue(":buyprice", buyPrice);
                    query.bindValue(":number", 0);
                    if(!query.exec()){
                        success = false;
                        continue;
                    }
                    number -= tempNumber;
                    continue;
                }
                else{
                    query.prepare("UPDATE stuff SET number=:number WHERE name=:name AND buyprice=:buyprice;");
                    query.bindValue(":name", name);
                    query.bindValue(":buyprice", buyPrice);
                    query.bindValue(":number", (tempNumber-number));
                    if(!query.exec()){
                        success = false;
                        continue;
                    }
                    break;
                }
            }
        }




    }






































}
