#include "zvit.h"
#include "ui_zvit.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlError>
#include "actionform.h"

zvit::zvit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zvit)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

zvit::~zvit()
{
    delete ui;
}

void zvit::on_pushButton_zvit_cancel_clicked()
{
    QWidget::close();
}

void zvit::on_pushButton_zvit_build_clicked()
{
    //loading options
    bool opSell = ui->radioButton_zvit_sell->isChecked();
    bool opBuy = ui->radioButton_zvit_buy->isChecked();

    int opCode;
    if (opSell){
        opCode = 0;
    }
    else if(opBuy)
    {
        opCode = 1;
    }
    else{
        QMessageBox::warning(0, "Увага!", "Виберіть тип операції");
    }

    QDate beginDate = ui->dateEdit_zvit_begin->date();
    QString beginDateStr = beginDate.toString("yyyy-MM-dd");
    QDate endDate = ui->dateEdit_zvit_end->date();
    QString endDateStr = endDate.toString("yyyy-MM-dd");

    QString name = ui->lineEdit_zvit_name->text();



    actionForm *actionF = new actionForm;
    actionF->show();
    connect(this, startBuildingreport, actionF, actionForm::build);
    emit startBuildingreport(opCode, beginDateStr, endDateStr, name);
}
