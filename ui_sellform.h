/********************************************************************************
** Form generated from reading UI file 'sellform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLFORM_H
#define UI_SELLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sellForm
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_sellForm_serarch;
    QPushButton *pushButton_sellForm_search;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_sellForm_place;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget_sellForm_table;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_sellform_ok;
    QPushButton *pushButton_sellform_cancel;

    void setupUi(QWidget *sellForm)
    {
        if (sellForm->objectName().isEmpty())
            sellForm->setObjectName(QStringLiteral("sellForm"));
        sellForm->resize(855, 526);
        horizontalLayout_4 = new QHBoxLayout(sellForm);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(sellForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_sellForm_serarch = new QLineEdit(sellForm);
        lineEdit_sellForm_serarch->setObjectName(QStringLiteral("lineEdit_sellForm_serarch"));

        horizontalLayout->addWidget(lineEdit_sellForm_serarch);

        pushButton_sellForm_search = new QPushButton(sellForm);
        pushButton_sellForm_search->setObjectName(QStringLiteral("pushButton_sellForm_search"));

        horizontalLayout->addWidget(pushButton_sellForm_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comboBox_sellForm_place = new QComboBox(sellForm);
        comboBox_sellForm_place->addItem(QString());
        comboBox_sellForm_place->setObjectName(QStringLiteral("comboBox_sellForm_place"));

        horizontalLayout->addWidget(comboBox_sellForm_place);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget_sellForm_table = new QTableWidget(sellForm);
        if (tableWidget_sellForm_table->columnCount() < 5)
            tableWidget_sellForm_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_sellForm_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_sellForm_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_sellForm_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_sellForm_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_sellForm_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_sellForm_table->setObjectName(QStringLiteral("tableWidget_sellForm_table"));

        horizontalLayout_2->addWidget(tableWidget_sellForm_table);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_sellform_ok = new QPushButton(sellForm);
        pushButton_sellform_ok->setObjectName(QStringLiteral("pushButton_sellform_ok"));

        horizontalLayout_3->addWidget(pushButton_sellform_ok);

        pushButton_sellform_cancel = new QPushButton(sellForm);
        pushButton_sellform_cancel->setObjectName(QStringLiteral("pushButton_sellform_cancel"));

        horizontalLayout_3->addWidget(pushButton_sellform_cancel);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(sellForm);

        QMetaObject::connectSlotsByName(sellForm);
    } // setupUi

    void retranslateUi(QWidget *sellForm)
    {
        sellForm->setWindowTitle(QApplication::translate("sellForm", "Form", nullptr));
        label->setText(QApplication::translate("sellForm", "\320\237\320\276\321\210\321\203\320\272", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_sellForm_serarch->setToolTip(QApplication::translate("sellForm", "\320\262\320\260\321\200\320\277\320\260\321\200", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_sellForm_serarch->setInputMask(QString());
        lineEdit_sellForm_serarch->setText(QString());
        lineEdit_sellForm_serarch->setPlaceholderText(QApplication::translate("sellForm", "\320\237\320\276\321\207\320\275\321\226\321\202\321\214 \320\262\320\262\320\276\320\264\320\270\321\202\320\270 \320\275\320\260\320\267\320\262\321\203", nullptr));
        pushButton_sellForm_search->setText(QApplication::translate("sellForm", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
        comboBox_sellForm_place->setItemText(0, QApplication::translate("sellForm", "\320\246\320\265\320\275\321\202\321\200", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget_sellForm_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("sellForm", "\320\235\320\260\320\267\320\262\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_sellForm_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("sellForm", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_sellForm_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("sellForm", "\320\246\321\226\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_sellForm_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("sellForm", "\320\222\321\201\321\214\320\276\320\263\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_sellForm_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("sellForm", "\320\237\321\200\320\270\320\261\321\203\321\202\320\276\320\272", nullptr));
        pushButton_sellform_ok->setText(QApplication::translate("sellForm", "\320\236\320\232", nullptr));
        pushButton_sellform_cancel->setText(QApplication::translate("sellForm", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sellForm: public Ui_sellForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLFORM_H
