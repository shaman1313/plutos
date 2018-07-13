/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_main_view;
    QPushButton *pushButton_main_entering;
    QPushButton *pushButton_main_BDsettings;
    QPushButton *pushButton_main_reports;
    QPushButton *pushButton_main_extering;
    QPushButton *pushButton_main_sending;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_7;
    QCheckBox *checkBox_mainwindow_DBStat;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(400, 670);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(400, 670));
        MainWindow->setMaximumSize(QSize(400, 670));
        MainWindow->setDockNestingEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_main_view = new QPushButton(centralWidget);
        pushButton_main_view->setObjectName(QStringLiteral("pushButton_main_view"));
        pushButton_main_view->setEnabled(true);
        pushButton_main_view->setGeometry(QRect(20, 298, 96, 96));
        pushButton_main_entering = new QPushButton(centralWidget);
        pushButton_main_entering->setObjectName(QStringLiteral("pushButton_main_entering"));
        pushButton_main_entering->setEnabled(true);
        pushButton_main_entering->setGeometry(QRect(20, 16, 96, 96));
        pushButton_main_BDsettings = new QPushButton(centralWidget);
        pushButton_main_BDsettings->setObjectName(QStringLiteral("pushButton_main_BDsettings"));
        pushButton_main_BDsettings->setEnabled(true);
        pushButton_main_BDsettings->setGeometry(QRect(20, 486, 96, 96));
        pushButton_main_reports = new QPushButton(centralWidget);
        pushButton_main_reports->setObjectName(QStringLiteral("pushButton_main_reports"));
        pushButton_main_reports->setEnabled(true);
        pushButton_main_reports->setGeometry(QRect(20, 392, 96, 96));
        pushButton_main_extering = new QPushButton(centralWidget);
        pushButton_main_extering->setObjectName(QStringLiteral("pushButton_main_extering"));
        pushButton_main_extering->setEnabled(true);
        pushButton_main_extering->setGeometry(QRect(20, 110, 96, 96));
        pushButton_main_sending = new QPushButton(centralWidget);
        pushButton_main_sending->setObjectName(QStringLiteral("pushButton_main_sending"));
        pushButton_main_sending->setEnabled(true);
        pushButton_main_sending->setGeometry(QRect(20, 204, 96, 96));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(161, 21, 241, 561));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);

        checkBox_mainwindow_DBStat = new QCheckBox(centralWidget);
        checkBox_mainwindow_DBStat->setObjectName(QStringLiteral("checkBox_mainwindow_DBStat"));
        checkBox_mainwindow_DBStat->setEnabled(false);
        checkBox_mainwindow_DBStat->setGeometry(QRect(30, 610, 201, 17));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Plutos", nullptr));
        pushButton_main_view->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_main_entering->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_main_BDsettings->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_main_reports->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_main_extering->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_main_sending->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\262\320\276\320\267", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\266", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\260\321\207\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\263\320\273\321\217\320\264", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202\320\275\321\226\321\201\321\202\321\214", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217 \320\221\320\224", nullptr));
        checkBox_mainwindow_DBStat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
