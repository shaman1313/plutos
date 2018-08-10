/********************************************************************************
** Form generated from reading UI file 'actionform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONFORM_H
#define UI_ACTIONFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_actionForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView_actionForm_table;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_actionForm_exel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_actionForm_close;

    void setupUi(QWidget *actionForm)
    {
        if (actionForm->objectName().isEmpty())
            actionForm->setObjectName(QStringLiteral("actionForm"));
        actionForm->resize(879, 537);
        verticalLayout_2 = new QVBoxLayout(actionForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView_actionForm_table = new QTableView(actionForm);
        tableView_actionForm_table->setObjectName(QStringLiteral("tableView_actionForm_table"));

        verticalLayout->addWidget(tableView_actionForm_table);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_actionForm_exel = new QPushButton(actionForm);
        pushButton_actionForm_exel->setObjectName(QStringLiteral("pushButton_actionForm_exel"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/ico/exel_256x256.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_actionForm_exel->setIcon(icon);

        horizontalLayout->addWidget(pushButton_actionForm_exel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_actionForm_close = new QPushButton(actionForm);
        pushButton_actionForm_close->setObjectName(QStringLiteral("pushButton_actionForm_close"));

        horizontalLayout->addWidget(pushButton_actionForm_close);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(actionForm);

        QMetaObject::connectSlotsByName(actionForm);
    } // setupUi

    void retranslateUi(QWidget *actionForm)
    {
        actionForm->setWindowTitle(QApplication::translate("actionForm", "\320\222\320\270\320\272\320\276\320\275\320\260\320\275\321\226 \320\264\321\226\321\227", nullptr));
        pushButton_actionForm_exel->setText(QApplication::translate("actionForm", "\320\225\320\272\321\201\320\277\320\276\321\200\321\202 \320\262 Exel", nullptr));
        pushButton_actionForm_close->setText(QApplication::translate("actionForm", "\320\227\320\260\320\272\321\200\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class actionForm: public Ui_actionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONFORM_H
