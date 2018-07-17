/********************************************************************************
** Form generated from reading UI file 'viewform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWFORM_H
#define UI_VIEWFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_viewForm
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_viewForm_serchType;
    QLineEdit *lineEdit_viewForm_search;
    QPushButton *pushButton_viewform_search;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox_viewForm_place;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView_viewForm;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_viewForm_exel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_viewForm_ok;
    QPushButton *pushButton_viewForm_cancel;

    void setupUi(QWidget *viewForm)
    {
        if (viewForm->objectName().isEmpty())
            viewForm->setObjectName(QStringLiteral("viewForm"));
        viewForm->resize(988, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(viewForm->sizePolicy().hasHeightForWidth());
        viewForm->setSizePolicy(sizePolicy);
        viewForm->setMinimumSize(QSize(640, 500));
        viewForm->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_7 = new QHBoxLayout(viewForm);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(viewForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_viewForm_serchType = new QComboBox(viewForm);
        comboBox_viewForm_serchType->addItem(QString());
        comboBox_viewForm_serchType->addItem(QString());
        comboBox_viewForm_serchType->addItem(QString());
        comboBox_viewForm_serchType->setObjectName(QStringLiteral("comboBox_viewForm_serchType"));

        horizontalLayout->addWidget(comboBox_viewForm_serchType);

        lineEdit_viewForm_search = new QLineEdit(viewForm);
        lineEdit_viewForm_search->setObjectName(QStringLiteral("lineEdit_viewForm_search"));

        horizontalLayout->addWidget(lineEdit_viewForm_search);

        pushButton_viewform_search = new QPushButton(viewForm);
        pushButton_viewform_search->setObjectName(QStringLiteral("pushButton_viewform_search"));

        horizontalLayout->addWidget(pushButton_viewform_search);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        comboBox_viewForm_place = new QComboBox(viewForm);
        comboBox_viewForm_place->addItem(QString());
        comboBox_viewForm_place->addItem(QString());
        comboBox_viewForm_place->addItem(QString());
        comboBox_viewForm_place->setObjectName(QStringLiteral("comboBox_viewForm_place"));

        horizontalLayout->addWidget(comboBox_viewForm_place);


        horizontalLayout_6->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView_viewForm = new QTableView(viewForm);
        tableView_viewForm->setObjectName(QStringLiteral("tableView_viewForm"));
        tableView_viewForm->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableView_viewForm->setAutoScroll(false);
        tableView_viewForm->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        tableView_viewForm->setAlternatingRowColors(true);
        tableView_viewForm->setSelectionMode(QAbstractItemView::NoSelection);
        tableView_viewForm->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_viewForm->setSortingEnabled(true);
        tableView_viewForm->horizontalHeader()->setCascadingSectionResizes(false);
        tableView_viewForm->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(tableView_viewForm);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_viewForm_exel = new QPushButton(viewForm);
        pushButton_viewForm_exel->setObjectName(QStringLiteral("pushButton_viewForm_exel"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/ico/exel_256x256.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_viewForm_exel->setIcon(icon);

        horizontalLayout_3->addWidget(pushButton_viewForm_exel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_viewForm_ok = new QPushButton(viewForm);
        pushButton_viewForm_ok->setObjectName(QStringLiteral("pushButton_viewForm_ok"));

        horizontalLayout_3->addWidget(pushButton_viewForm_ok);

        pushButton_viewForm_cancel = new QPushButton(viewForm);
        pushButton_viewForm_cancel->setObjectName(QStringLiteral("pushButton_viewForm_cancel"));

        horizontalLayout_3->addWidget(pushButton_viewForm_cancel);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_7->addLayout(verticalLayout);


        retranslateUi(viewForm);

        QMetaObject::connectSlotsByName(viewForm);
    } // setupUi

    void retranslateUi(QWidget *viewForm)
    {
        viewForm->setWindowTitle(QApplication::translate("viewForm", "\320\237\320\265\321\200\320\265\320\263\320\273\321\217\320\264 \321\202\320\276\320\262\320\260\321\200\321\203", nullptr));
        label->setText(QApplication::translate("viewForm", "\320\237\320\276\321\210\321\203\320\272", nullptr));
        comboBox_viewForm_serchType->setItemText(0, QApplication::translate("viewForm", "\320\227\320\260 \320\275\320\260\320\267\320\262\320\276\321\216", nullptr));
        comboBox_viewForm_serchType->setItemText(1, QApplication::translate("viewForm", "\320\227\320\260 \320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\216", nullptr));
        comboBox_viewForm_serchType->setItemText(2, QApplication::translate("viewForm", "\320\267\320\260 \321\206\321\226\320\275\320\276\321\216", nullptr));

        pushButton_viewform_search->setText(QApplication::translate("viewForm", "\320\237\320\276\321\210\321\203\320\272", nullptr));
        comboBox_viewForm_place->setItemText(0, QApplication::translate("viewForm", "\320\222\321\201\321\226...", nullptr));
        comboBox_viewForm_place->setItemText(1, QApplication::translate("viewForm", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        comboBox_viewForm_place->setItemText(2, QApplication::translate("viewForm", "\320\241\320\276\320\275\320\265\321\207\320\272\320\276", nullptr));

        pushButton_viewForm_exel->setText(QApplication::translate("viewForm", "\320\225\320\272\321\201\320\277\320\276\321\200\321\202 \320\262 Exel", nullptr));
        pushButton_viewForm_ok->setText(QApplication::translate("viewForm", "\320\236\320\232", nullptr));
        pushButton_viewForm_cancel->setText(QApplication::translate("viewForm", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewForm: public Ui_viewForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWFORM_H
