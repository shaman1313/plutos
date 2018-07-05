#include "form.h"
#include "ui_form.h"

Form::Form(addItemsForm *parent) :
    addItemsForm(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
