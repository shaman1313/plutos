#include "pcore.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QSqlError>
/************************************************************
/   some functions for DB
/
/
/
*************************************************************/
bool createDBconnection(QString cName){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", cName);
    db.setDatabaseName("test");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("1111");
    if(!db.open()){
        qDebug() << "Can`t open database. " << db.lastError();
        QMessageBox::critical(0, "Database error", db.lastError().text());
        return false;
    }
    else
    {
        //QMessageBox::information(0,"Connection is success","All is good. Just close this window");
        return true;
    }
}

void closeDBconnection(QString cName){

    {
    QSqlDatabase db = QSqlDatabase::database(cName);
    db.close();
    db = QSqlDatabase();
    }
    QSqlDatabase::removeDatabase(cName);
}
