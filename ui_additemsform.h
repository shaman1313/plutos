/********************************************************************************
** Form generated from reading UI file 'additemsform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMSFORM_H
#define UI_ADDITEMSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addItemsForm
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_additemsform_add;
    QPushButton *pushButton_additemsform_delete;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidget_additemsform_table;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_additemsform_ok;
    QPushButton *pushButton_additemsform_cancel;

    void setupUi(QWidget *addItemsForm)
    {
        if (addItemsForm->objectName().isEmpty())
            addItemsForm->setObjectName(QStringLiteral("addItemsForm"));
        addItemsForm->resize(1081, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addItemsForm->sizePolicy().hasHeightForWidth());
        addItemsForm->setSizePolicy(sizePolicy);
        addItemsForm->setMinimumSize(QSize(640, 500));
        addItemsForm->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_7 = new QHBoxLayout(addItemsForm);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_additemsform_add = new QPushButton(addItemsForm);
        pushButton_additemsform_add->setObjectName(QStringLiteral("pushButton_additemsform_add"));

        horizontalLayout->addWidget(pushButton_additemsform_add);

        pushButton_additemsform_delete = new QPushButton(addItemsForm);
        pushButton_additemsform_delete->setObjectName(QStringLiteral("pushButton_additemsform_delete"));

        horizontalLayout->addWidget(pushButton_additemsform_delete);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        horizontalLayout_6->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableWidget_additemsform_table = new QTableWidget(addItemsForm);
        if (tableWidget_additemsform_table->columnCount() < 7)
            tableWidget_additemsform_table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_additemsform_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_additemsform_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_additemsform_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_additemsform_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_additemsform_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_additemsform_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_additemsform_table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_additemsform_table->setObjectName(QStringLiteral("tableWidget_additemsform_table"));
        tableWidget_additemsform_table->setEnabled(true);
        sizePolicy.setHeightForWidth(tableWidget_additemsform_table->sizePolicy().hasHeightForWidth());
        tableWidget_additemsform_table->setSizePolicy(sizePolicy);
        tableWidget_additemsform_table->setMinimumSize(QSize(627, 405));
        tableWidget_additemsform_table->setMaximumSize(QSize(16777215, 16777215));
        tableWidget_additemsform_table->setSizeIncrement(QSize(10, 10));
        tableWidget_additemsform_table->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget_additemsform_table->setTabletTracking(true);
        tableWidget_additemsform_table->setFocusPolicy(Qt::TabFocus);
        tableWidget_additemsform_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget_additemsform_table->setAutoScroll(true);
        tableWidget_additemsform_table->setAutoScrollMargin(16);
        tableWidget_additemsform_table->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tableWidget_additemsform_table->setTabKeyNavigation(true);
        tableWidget_additemsform_table->setProperty("showDropIndicator", QVariant(false));
        tableWidget_additemsform_table->setDragDropOverwriteMode(false);
        tableWidget_additemsform_table->setAlternatingRowColors(true);
        tableWidget_additemsform_table->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_additemsform_table->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget_additemsform_table->setRowCount(0);
        tableWidget_additemsform_table->horizontalHeader()->setVisible(true);
        tableWidget_additemsform_table->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_additemsform_table->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget_additemsform_table->horizontalHeader()->setMinimumSectionSize(31);
        tableWidget_additemsform_table->horizontalHeader()->setStretchLastSection(true);
        tableWidget_additemsform_table->verticalHeader()->setVisible(true);
        tableWidget_additemsform_table->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget_additemsform_table->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_2->addWidget(tableWidget_additemsform_table);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_additemsform_ok = new QPushButton(addItemsForm);
        pushButton_additemsform_ok->setObjectName(QStringLiteral("pushButton_additemsform_ok"));

        horizontalLayout_3->addWidget(pushButton_additemsform_ok);

        pushButton_additemsform_cancel = new QPushButton(addItemsForm);
        pushButton_additemsform_cancel->setObjectName(QStringLiteral("pushButton_additemsform_cancel"));

        horizontalLayout_3->addWidget(pushButton_additemsform_cancel);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_7->addLayout(verticalLayout);


        retranslateUi(addItemsForm);

        QMetaObject::connectSlotsByName(addItemsForm);
    } // setupUi

    void retranslateUi(QWidget *addItemsForm)
    {
        addItemsForm->setWindowTitle(QApplication::translate("addItemsForm", "\320\224\320\276\320\264\320\260\320\262\320\260\320\275\320\275\321\217 \321\202\320\276\320\262\320\260\321\200\321\203", nullptr));
        pushButton_additemsform_add->setText(QApplication::translate("addItemsForm", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
        pushButton_additemsform_delete->setText(QApplication::translate("addItemsForm", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_additemsform_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addItemsForm", "\320\235\320\260\320\267\320\262\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_additemsform_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addItemsForm", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_additemsform_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("addItemsForm", "\320\236\320\264\320\270\320\275\320\270\321\206\321\226", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_additemsform_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("addItemsForm", "\320\227\320\260\320\272\321\203\320\277\321\226\320\262\320\273\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_additemsform_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("addItemsForm", "\320\237\321\200\320\276\320\264\320\260\320\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_additemsform_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("addItemsForm", "\320\242\320\276\321\207\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_additemsform_table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("addItemsForm", "\320\237\321\200\320\270\320\261\321\203\321\202\320\276\320\272", nullptr));
        pushButton_additemsform_ok->setText(QApplication::translate("addItemsForm", "\320\236\320\232", nullptr));
        pushButton_additemsform_cancel->setText(QApplication::translate("addItemsForm", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addItemsForm: public Ui_addItemsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMSFORM_H
