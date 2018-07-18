#include "sellform.h"
#include "ui_sellform.h"
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

    //setting table to model
    model->setTable("stuff_list");
    model->setFilter(filter);
    //select query
    model->select();
    //denied record to DB automaticly
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //autocompleter for searchline
    QCompleter* completer = new QCompleter(this);
    //binding completer with model
    completer->setModel(model);
    completer->setCompletionColumn(1);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    ui->lineEdit_sellForm_serarch->setCompleter(completer);
    //catching ENTER PRESSED
    //QObject::connect(ui->lineEdit_sellForm_serarch, ui->lineEdit_sellForm_serarch->returnPressed, this, sellForm::on_pushButton_sellForm_search_clicked);
    QObject::connect(ui->comboBox_sellForm_place, ui->comboBox_sellForm_place->currentTextChanged, this, sellForm::changeFilter);

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


void sellForm::on_pushButton_sellform_cancel_clicked()
{
    QWidget::close();
}

void sellForm::on_pushButton_sellForm_search_clicked()
{
    QString nameStr = ui->lineEdit_sellForm_serarch->text();

    QTableWidgetItem *name = new QTableWidgetItem;


    ui->lineEdit_sellForm_serarch->clear();
    qDebug() << nameStr;

    int curRow = ui->tableWidget_sellForm_table->rowCount();
    ui->tableWidget_sellForm_table->insertRow(curRow);

    ui->tableWidget_sellForm_table->scrollToBottom();
    name->setText(nameStr);
    ui->tableWidget_sellForm_table->setItem(curRow,0,name);















}
