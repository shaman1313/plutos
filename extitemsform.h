#ifndef EXTITEMSFORM_H
#define EXTITEMSFORM_H

#include <QObject>
#include <QWidget>
#include "additemsform.h"
#include "ui_additemsform.h"


namespace Ui {
class extItemsForm;
}

class extItemsForm : public addItemsForm
{
public:
    explicit extItemsForm(QWidget *parent=0);
private:
    Ui::extItemsForm *ui;

};


#endif // EXTITEMSFORM_H
