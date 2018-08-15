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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_info;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_main_entering;
    QPushButton *pushButton_main_extering;
    QPushButton *pushButton_main_sending;
    QPushButton *pushButton_main_view;
    QPushButton *pushButton_main_reports;
    QPushButton *pushButton_main_BDsettings;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(350, 670);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(350, 670));
        MainWindow->setMaximumSize(QSize(350, 670));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/ico/res/drawable-xxxhdpi/round_monetization_on_black_18.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(250, 250, 250);"));
        MainWindow->setDockNestingEnabled(false);
        action_info = new QAction(MainWindow);
        action_info->setObjectName(QStringLiteral("action_info"));
        action_info->setChecked(false);
        action_info->setEnabled(true);
        action_info->setMenuRole(QAction::PreferencesRole);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_main_entering = new QPushButton(centralWidget);
        pushButton_main_entering->setObjectName(QStringLiteral("pushButton_main_entering"));
        pushButton_main_entering->setEnabled(true);
        pushButton_main_entering->setMinimumSize(QSize(96, 96));
        pushButton_main_entering->setMaximumSize(QSize(96, 96));
        pushButton_main_entering->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/ico/res/drawable-xxxhdpi/outline_add_black_24.png);\n"
""));

        verticalLayout_2->addWidget(pushButton_main_entering);

        pushButton_main_extering = new QPushButton(centralWidget);
        pushButton_main_extering->setObjectName(QStringLiteral("pushButton_main_extering"));
        pushButton_main_extering->setEnabled(true);
        pushButton_main_extering->setMinimumSize(QSize(96, 96));
        pushButton_main_extering->setMaximumSize(QSize(96, 96));
        pushButton_main_extering->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/ico/res/drawable-xxxhdpi/outline_attach_money_black_24.png);"));

        verticalLayout_2->addWidget(pushButton_main_extering);

        pushButton_main_sending = new QPushButton(centralWidget);
        pushButton_main_sending->setObjectName(QStringLiteral("pushButton_main_sending"));
        pushButton_main_sending->setEnabled(true);
        pushButton_main_sending->setMinimumSize(QSize(96, 96));
        pushButton_main_sending->setMaximumSize(QSize(96, 96));
        pushButton_main_sending->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/ico/res/drawable-xxxhdpi/outline_swap_horiz_black_24.png);"));

        verticalLayout_2->addWidget(pushButton_main_sending);

        pushButton_main_view = new QPushButton(centralWidget);
        pushButton_main_view->setObjectName(QStringLiteral("pushButton_main_view"));
        pushButton_main_view->setEnabled(true);
        pushButton_main_view->setMinimumSize(QSize(96, 96));
        pushButton_main_view->setMaximumSize(QSize(96, 96));
        pushButton_main_view->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/ico/res/drawable-xxxhdpi/outline_youtube_searched_for_black_24.png);"));

        verticalLayout_2->addWidget(pushButton_main_view);

        pushButton_main_reports = new QPushButton(centralWidget);
        pushButton_main_reports->setObjectName(QStringLiteral("pushButton_main_reports"));
        pushButton_main_reports->setEnabled(true);
        pushButton_main_reports->setMinimumSize(QSize(96, 96));
        pushButton_main_reports->setMaximumSize(QSize(96, 96));
        pushButton_main_reports->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/ico/res/drawable-xxxhdpi/outline_timeline_black_24.png);"));

        verticalLayout_2->addWidget(pushButton_main_reports);

        pushButton_main_BDsettings = new QPushButton(centralWidget);
        pushButton_main_BDsettings->setObjectName(QStringLiteral("pushButton_main_BDsettings"));
        pushButton_main_BDsettings->setEnabled(true);
        pushButton_main_BDsettings->setMinimumSize(QSize(96, 96));
        pushButton_main_BDsettings->setMaximumSize(QSize(96, 96));
        pushButton_main_BDsettings->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/ico/res/drawable-xxxhdpi/outline_storage_black_24.png);\n"
""));

        verticalLayout_2->addWidget(pushButton_main_BDsettings);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 350, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_info);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Plutos", nullptr));
        action_info->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\321\203", nullptr));
#ifndef QT_NO_SHORTCUT
        action_info->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_main_entering->setText(QString());
        pushButton_main_extering->setText(QString());
        pushButton_main_sending->setText(QString());
        pushButton_main_view->setText(QString());
        pushButton_main_reports->setText(QString());
        pushButton_main_BDsettings->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \321\202\320\276\320\262\320\260\321\200", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\266", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\260\321\207\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\263\320\273\321\217\320\264 \320\221\320\224", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\227\320\262\321\226\321\202\320\275\321\226\321\201\321\202\321\214", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217 \320\221\320\224", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\236\320\277\321\206\321\226\321\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
