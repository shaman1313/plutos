/********************************************************************************
** Form generated from reading UI file 'zvit.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZVIT_H
#define UI_ZVIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zvit
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_zvit_sell;
    QRadioButton *radioButton_zvit_buy;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *dateEdit_zvit_begin;
    QDateEdit *dateEdit_zvit_end;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_zvit_name;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_graph;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_zvit_build;
    QPushButton *pushButton_zvit_cancel;

    void setupUi(QWidget *zvit)
    {
        if (zvit->objectName().isEmpty())
            zvit->setObjectName(QStringLiteral("zvit"));
        zvit->resize(363, 476);
        verticalLayout_2 = new QVBoxLayout(zvit);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(zvit);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_zvit_sell = new QRadioButton(groupBox);
        radioButton_zvit_sell->setObjectName(QStringLiteral("radioButton_zvit_sell"));
        radioButton_zvit_sell->setChecked(true);

        verticalLayout->addWidget(radioButton_zvit_sell);

        radioButton_zvit_buy = new QRadioButton(groupBox);
        radioButton_zvit_buy->setObjectName(QStringLiteral("radioButton_zvit_buy"));

        verticalLayout->addWidget(radioButton_zvit_buy);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(zvit);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        dateEdit_zvit_begin = new QDateEdit(groupBox_2);
        dateEdit_zvit_begin->setObjectName(QStringLiteral("dateEdit_zvit_begin"));

        gridLayout->addWidget(dateEdit_zvit_begin, 0, 1, 1, 1);

        dateEdit_zvit_end = new QDateEdit(groupBox_2);
        dateEdit_zvit_end->setObjectName(QStringLiteral("dateEdit_zvit_end"));

        gridLayout->addWidget(dateEdit_zvit_end, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(zvit);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_zvit_name = new QLineEdit(groupBox_3);
        lineEdit_zvit_name->setObjectName(QStringLiteral("lineEdit_zvit_name"));

        horizontalLayout->addWidget(lineEdit_zvit_name);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox_graph = new QCheckBox(zvit);
        checkBox_graph->setObjectName(QStringLiteral("checkBox_graph"));

        horizontalLayout_2->addWidget(checkBox_graph);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_zvit_build = new QPushButton(zvit);
        pushButton_zvit_build->setObjectName(QStringLiteral("pushButton_zvit_build"));

        horizontalLayout_2->addWidget(pushButton_zvit_build);

        pushButton_zvit_cancel = new QPushButton(zvit);
        pushButton_zvit_cancel->setObjectName(QStringLiteral("pushButton_zvit_cancel"));

        horizontalLayout_2->addWidget(pushButton_zvit_cancel);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(zvit);

        QMetaObject::connectSlotsByName(zvit);
    } // setupUi

    void retranslateUi(QWidget *zvit)
    {
        zvit->setWindowTitle(QApplication::translate("zvit", "\320\227\320\262\321\226\321\202\320\275\321\226\321\201\321\202\321\214", nullptr));
        groupBox->setTitle(QApplication::translate("zvit", "\320\236\320\277\320\265\321\200\320\260\321\206\321\226\321\227", nullptr));
        radioButton_zvit_sell->setText(QApplication::translate("zvit", "\320\237\321\200\320\276\320\264\320\260\320\266", nullptr));
        radioButton_zvit_buy->setText(QApplication::translate("zvit", "\320\227\320\260\320\272\321\203\320\277\320\272\320\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("zvit", "\320\227\320\260 \320\277\320\265\321\200\321\226\320\276\320\264", nullptr));
        label->setText(QApplication::translate("zvit", "\320\237\320\276\321\207\320\260\321\202\320\276\320\272 \320\277\320\265\321\200\321\226\320\276\320\264\321\203", nullptr));
        label_2->setText(QApplication::translate("zvit", "\320\232\321\226\320\275\320\265\321\206\321\214 \320\277\320\265\321\200\321\226\320\276\320\264\321\203", nullptr));
        groupBox_3->setTitle(QApplication::translate("zvit", "\320\224\320\276\320\264\320\260\321\202\320\272\320\276\320\262\321\226 \321\203\320\274\320\276\320\262\320\270", nullptr));
        label_3->setText(QApplication::translate("zvit", "\320\235\320\260\320\267\320\262\320\260 \320\274\321\226\321\201\321\202\320\270\321\202\321\214", nullptr));
        checkBox_graph->setText(QApplication::translate("zvit", "\320\223\321\200\320\260\321\204\321\226\320\272", nullptr));
        pushButton_zvit_build->setText(QApplication::translate("zvit", "\320\237\320\276\320\261\321\203\320\264\321\203\320\262\320\260\321\202\320\270", nullptr));
        pushButton_zvit_cancel->setText(QApplication::translate("zvit", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zvit: public Ui_zvit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZVIT_H
