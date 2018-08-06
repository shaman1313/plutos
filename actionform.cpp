#include "actionform.h"
#include "ui_actionform.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlError>
#include <QFileDialog>
#include <QTextCodec>
#include <QTextStream>

actionForm::actionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::actionForm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

actionForm::~actionForm()
{
    delete ui;
}

void actionForm::build(int opCode, QString begin, QString end, QString name){
    this->opCode = opCode;
    this->beginDate = begin;
    this->endDate = end;


    QSqlDatabase db = QSqlDatabase::database("view_connection");
    //check if DB is alive
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Помилка БД", db.lastError().text());
            return;
        }

    }

    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("action");
    QString filter = "";
    filter += "DATE(time) BETWEEN '";
    filter += begin;
    filter += "' AND '";
    filter += end;
    filter += "' ";
    filter += "AND type = ";
    filter += QString::number(opCode);

    if(!name.isEmpty()){
        filter += " AND name LIKE '%";
        filter += name;
        filter += "%'";
    }

    model->setFilter(filter);

    if(!model->select()){
        QMessageBox::critical(0, "Помилка!","Неможливо обробити запит: " + db.lastError().text());
        return;
    }

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(1, Qt::Horizontal, "Дата/час");
    model->setHeaderData(2, Qt::Horizontal, "Тип операції");
    model->setHeaderData(3, Qt::Horizontal, "Назва товару");
    model->setHeaderData(4, Qt::Horizontal, "Кількість");
    model->setHeaderData(5, Qt::Horizontal, "Ціна");
    model->setHeaderData(6, Qt::Horizontal, "Сума");
    model->setHeaderData(7, Qt::Horizontal, "Прибуток");

    ui->tableView_actionForm_table->setModel(model);
    ui->tableView_actionForm_table->hideColumn(0);
    ui->tableView_actionForm_table->hideColumn(2);

    int rowCount = ui->tableView_actionForm_table->model()->rowCount();
    double finalProfit = 0.0;
    double finalPrice = 0.0;
    QString allSum = "Всього:";
    QModelIndex index;
    QVariant dataset;
    for (int i=0; i<rowCount; i++){
        index = ui->tableView_actionForm_table->model()->index(i, 6);
        dataset = ui->tableView_actionForm_table->model()->data(index);
        finalPrice += dataset.toDouble();
        index = ui->tableView_actionForm_table->model()->index(i, 7);
        dataset = ui->tableView_actionForm_table->model()->data(index);
        finalProfit += dataset.toDouble();
    }
    ui->tableView_actionForm_table->model()->insertRow(rowCount);
    index = ui->tableView_actionForm_table->model()->index(rowCount, 3);
    dataset.setValue(allSum);
    ui->tableView_actionForm_table->model()->setData(index, dataset);
    index = ui->tableView_actionForm_table->model()->index(rowCount, 6);
    dataset.setValue(finalPrice);
    ui->tableView_actionForm_table->model()->setData(index, dataset);
    index = ui->tableView_actionForm_table->model()->index(rowCount, 7);
    dataset.setValue(finalProfit);
    ui->tableView_actionForm_table->model()->setData(index, dataset);

}

void actionForm::on_pushButton_actionForm_close_clicked()
{
    QWidget::close();
}

void actionForm::on_pushButton_actionForm_exel_clicked()
{
    QModelIndex index;
    QVariant dataset;
    QString name;
    QString num;
    QString date;
    QString sellp;
    QString allp;
    QString profit;


    QByteArray tableRowString;
    QString npp;

    //codec for translation from utf-8 to unicode
    QTextCodec* BDtextCodec = QTextCodec::codecForName("UTF-8");
    //count of all records in a table
    int rowC = ui->tableView_actionForm_table->model()->rowCount();
    //save file window
    QString filename = QFileDialog::getSaveFileName(
    this,
    tr("Save Document"),
    QDir::currentPath(),
    tr("Documents (*.csv)") );
    //creating file
    QFile f(filename);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::critical(0, "Помилка", "Файл не знайдено");
        return;
    }
    //text stream for writing to the file
    QTextStream out(&f);
    //charset for file, windows because MS EXEL don`t work with utf-8 and unicode
    out.setCodec("Windows-1251");
    //writing header

    if(this->opCode == 0){
        tableRowString = "Продано;";
    }
    else{
        tableRowString = "Закуплено;";
    }
    tableRowString += "з " + this->beginDate;
    tableRowString += ";";
    tableRowString += "по " + this->endDate;
    tableRowString += ";\n";
    QString unicodeStr = BDtextCodec->toUnicode(tableRowString);
    QString unicodeTableStr;
    out << unicodeStr;
    tableRowString = "№пп;Дата/час;Назва товару;Кількість;Ціна;Сума;Прибуток\n";
    unicodeStr = BDtextCodec->toUnicode(tableRowString);

    out << unicodeStr;
    //loop for writing records from table to *.csv
    for (int i = 0; i<rowC-1; i++){

        tableRowString = "";
        //number (starts from 1)
        npp = QString::number(i+1);

        //date
        index = ui->tableView_actionForm_table->model()->index(i, 1);
        dataset = ui->tableView_actionForm_table->model()->data(index);
        date = dataset.toString();

        //name
        index = ui->tableView_actionForm_table->model()->index(i,3);
        dataset = ui->tableView_actionForm_table->model()->data(index);
        name = dataset.toString();
        //number of things, replase . by , because EXEL work with comma as a decimal point
        index = ui->tableView_actionForm_table->model()->index(i,4);
        dataset = ui->tableView_actionForm_table->model()->data(index);
        num = dataset.toString().replace(".",",");

        //sell price
        index = ui->tableView_actionForm_table->model()->index(i,5);
        dataset = ui->tableView_actionForm_table->model()->data(index);
        sellp = dataset.toString().replace(".",",");
        //allprice
        index = ui->tableView_actionForm_table->model()->index(i, 6);
        dataset = ui->tableView_actionForm_table->model()->data(index);
        allp = dataset.toString().replace(".",",");
        //profit
        index = ui->tableView_actionForm_table->model()->index(i, 7);
        dataset = ui->tableView_actionForm_table->model()->data(index);
        profit = dataset.toString().replace(".",",");



        //prepare and write string to CSV format
        tableRowString +=npp;
        tableRowString +=";";
        tableRowString += date;
        tableRowString +=";";
        tableRowString += name;
        tableRowString += ";";
        tableRowString += num;
        tableRowString += ";";
        tableRowString += sellp;
        tableRowString += ";";
        tableRowString += allp;
        tableRowString += ";";
        tableRowString += profit;
        tableRowString += ";\n";
        unicodeTableStr = tableRowString.data();
        out << unicodeTableStr;

    }

    index = ui->tableView_actionForm_table->model()->index(rowC-1, 6);
    dataset = ui->tableView_actionForm_table->model()->data(index);

    tableRowString = " ; ;Всього; ; ;";
    tableRowString += dataset.toString().replace(".",",");
    tableRowString += ";";

    index=ui->tableView_actionForm_table->model()->index(rowC-1, 7);
    dataset = ui->tableView_actionForm_table->model()->data(index);
    tableRowString += dataset.toString().replace(".",",");
    tableRowString += ";\n";

    unicodeStr = BDtextCodec->toUnicode(tableRowString);

    out << unicodeStr;

    QMessageBox::information(0, "Виконано!", "Експорт здійснено успішно");
    f.close();
}
