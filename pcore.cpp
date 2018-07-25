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
///Переведите кодировку в UTF-8
/
*************************************************************/
bool createDBconnection(QString cName){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", cName);
    db.setDatabaseName("maindb");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("1111");
    if(!db.open()){
        qDebug() << "Can`t open database. " << db.lastError();
        QMessageBox::critical(0, "Помилка БД", db.lastError().text());
        return false;
    }
    else
    {
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
