#include "sellform.h"
#include "ui_sellform.h"
#include "yascompleter.h"
#include <QtSql>
#include <QMessageBox>
#include <QCompleter>
#include <QDebug>
#include <QObject>

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
    //catching ENTER PRESSED
    //QObject::connect(ui->lineEdit_sellForm_serarch, ui->lineEdit_sellForm_serarch->returnPressed, this, sellForm::on_pushButton_sellForm_search_clicked);
    QObject::connect(ui->comboBox_sellForm_place, ui->comboBox_sellForm_place->currentTextChanged, this, sellForm::changeFilter);
    QObject::connect(completer, YAScompleter::sendNaturalIndex, this, sellForm::index_of_activated);
    //QObject::connect(completer, QOverload<const QModelIndex &>::of(&QCompleter::activated), [=](const QModelIndex &index){mIndex = index;});   //QTdoc example
    //connect(completer, QCompleter::activated, this, sellForm::index_of_activated);

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

void sellForm::recalculate(int row){

    //if one of data cell is unset don`t recalculate profit
    if(ui->tableWidget_sellForm_table->item(row,1)==0 || ui->tableWidget_sellForm_table->item(row,2)==0
            || ui->tableWidget_sellForm_table->item(row,3)==0 || ui->tableWidget_sellForm_table->item(row,4)==0)
    {
        return;
    }

    QBrush redAlert;
    redAlert.setStyle(Qt::Dense4Pattern);
    redAlert.setColor("red");
    //loadinf data and calculating
    double number =(ui->tableWidget_sellForm_table->item(row, 1)->text().replace(",", ".")).toDouble();
    double sellprice = (ui->tableWidget_sellForm_table->item(row, 2)->text().replace(",", ".")).toDouble();
    //double buyprice = this->pmodel-> ;
    double profit = 0.0;
    double allprice = 0.0;
    allprice = sellprice * number;

    ui->tableWidget_sellForm_table->item(row, 3)->setText(QString::number(allprice));
    /*
    if(profit<=0.0){
        ui->tableWidget_additemsform_table->item(row,6)->setBackground(redAlert);
    }
    else{
        ui->tableWidget_additemsform_table->item(row,6)->setBackground(Qt::NoBrush);
    }*/

}



void sellForm::on_pushButton_sellForm_search_clicked()
{
    QString nameStr = ui->lineEdit_sellForm_serarch->text();

    if(nameStr.isEmpty()){
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


















    ui->tableWidget_sellForm_table->item(curRow,3)->setFlags((ui->tableWidget_sellForm_table->item(curRow,3)->flags()) & ~Qt::ItemIsEditable);
    ui->tableWidget_sellForm_table->item(curRow,4)->setFlags((ui->tableWidget_sellForm_table->item(curRow,4)->flags()) & ~Qt::ItemIsEditable);

    connect(ui->tableWidget_sellForm_table, ui->tableWidget_sellForm_table->cellChanged, this, sellForm::recalculate);




}
