#include "infoform.h"
#include "ui_infoform.h"

infoForm::infoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infoForm)
{
    ui->setupUi(this);
}

infoForm::~infoForm()
{
    delete ui;
}

void infoForm::on_pushButton_info_clicked()
{
    QWidget::close();
}
