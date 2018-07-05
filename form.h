#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "additemsform.h"

namespace Ui {
class Form;
}

class Form : public addItemsForm
{
    Q_OBJECT

public:
    explicit Form(addItemsForm *parent = 0);
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
