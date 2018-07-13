#include "viewform.h"
#include "ui_viewform.h"
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QObject>
#include <QList>
#include <QComboBox>
#include <Qt>
#include <QFlags>


viewForm::viewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewForm)
{
    ui->setupUi(this);
    //in this case QTableView stay in memory after closing form and database warning were occured
    //deleting connection is impossible
    //with this attribute all is OK
    setAttribute(Qt::WA_DeleteOnClose);
    //loading view on start
    if(!getContent()){
        QMessageBox::critical(0, "Error", "Unenabel to read content");
    }
    //catching 'ENTER key pressed' in search line
    connect(ui->lineEdit_viewForm_search, ui->lineEdit_viewForm_search->returnPressed, this, viewForm::on_pushButton_viewform_search_clicked);
}

viewForm::~viewForm()
{
    delete ui;
}
//function of loading table
//parameter f is empty for default
//and function will load all records in a database
//filter is for search
bool viewForm::getContent(QString f){

    QSqlDatabase db = QSqlDatabase::database("view_connection");
    //check if DB is alive
    if (!db.isOpen()){
        if(!db.open()){
            QMessageBox::critical(0, "Database error", db.lastError().text());
            return false;
        }

    }
    //Model is SQL model of table in DB
    QSqlTableModel *model = new QSqlTableModel(this, db);
    //setting table to model
    model->setTable("stuff_list");
    //filter for model
    //filter is statement 'WHERE' without word where
    //'name LIKE %abc%' for example
    if(!f.isEmpty()){
        model->setFilter(f);
    }
    //select query
    model->select();
    //denied record to DB automaticly
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //model to table
    ui->tableView_viewForm->setModel(model);
    //header to window size
    ui->tableView_viewForm->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //hiding ID column
    ui->tableView_viewForm->hideColumn(0);

    return true;
}

void viewForm::on_pushButton_viewForm_cancel_clicked()
{
    QWidget::close();
}
//search button or Enter key pressed
void viewForm::on_pushButton_viewform_search_clicked()
{
    //get a search phrase from searchline
    QString searchPhrase = ui->lineEdit_viewForm_search->text();
    //sph is preparing filter for function 'getContent'
    QString sph = "";
    int searchType = ui->comboBox_viewForm_serchType->currentIndex();
    int sizeS;

    //all construction down is filter preparing
    //if search phrase is empty? all record are in a table
    //otherwise
    if(!searchPhrase.isEmpty()){
        //search by type: name or number of things or price ... other maybe
        switch (searchType) {
        //if search by name, searching will be out records contains searchphrase
        case 0:
            sph = "name ";
            sph += "LIKE '%";
            sph+=searchPhrase;
            sph+="%'";
            break;
        //if by number, we may use signs like = >= <= != > <
        //we check first 2 element in phrase, and if it`s filter signs we add it to query
        //by default, using '=' sign
        case 1:
            sph = "number ";
            if (searchPhrase[0]==">" || searchPhrase[0]=="<" || searchPhrase[0]=="=" || searchPhrase=="!"){
                sph+= searchPhrase[0];//get first filter sign if it is
                sizeS = searchPhrase.size() - 1;//excluding this sign from phrase
                if(searchPhrase[1] == "=" && searchPhrase[0]!="="){
                    sph+=searchPhrase[1];//get second sign if first was not '=' (second were only '=')
                    sizeS -= 1;//excluding from phrase
                }
                sph += " ";
                sph += searchPhrase.right(sizeS); //get phrase without filter sign
            }
            else
            {
                sph += "= ";//default filter sign
                sph += searchPhrase;//clearly phrase without any moves and preparing
            }
            break;
        //sell price search use the same signs
        //the same algorithm
        case 2:
            sph = "sellprice ";
            if (searchPhrase[0]==">" || searchPhrase[0]=="<" || searchPhrase[0]=="=" || searchPhrase=="!"){
                sph+= searchPhrase[0];
                sizeS = searchPhrase.size() - 1;
                if(searchPhrase[1] == "=" && searchPhrase[0]!="="){
                    sph+=searchPhrase[1];
                    sizeS -= 1;
                }
                sph += " ";
                sph += searchPhrase.right(sizeS);
            }
            else
            {
                sph += "= ";
                sph += searchPhrase;
            }
            break;
        default:
            break;
        }
    }
    //and finally executing query with filter
    getContent(sph);

}

//export to exel
void viewForm::on_pushButton_viewForm_exel_clicked()
{
    QModelIndex index;
    QVariant dataset;
    QString name;
    int num;
    QString unit;
    double buyp;
    double sell;
//forward next
    int rowC = ui->tableView_viewForm->model()->rowCount();
    for (int i = 0; i<rowC; i++){
        index = ui->tableView_viewForm->model()->index(i,1);
        dataset = ui->tableView_viewForm->model()->data(index);
        name = dataset.toString();
        index = ui->tableView_viewForm->model()->index(i,2);
        dataset = ui->tableView_viewForm->model()->data(index);
        num = dataset.toInt();
        index = ui->tableView_viewForm->model()->index(i,2);
        dataset = ui->tableView_viewForm->model()->data(index);
        unit = dataset.toString();
        index = ui->tableView_viewForm->model()->index(i,2);
    }
}
