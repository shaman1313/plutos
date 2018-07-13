/********************************************************************************
** Form generated from reading UI file 'bdsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDSETTINGS_H
#define UI_BDSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDsettings
{
public:
    QPushButton *pushButton_bdsettings_newBD;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_bdsettings_serverName;
    QLabel *label;
    QLineEdit *lineEdit_bdsettings_username;
    QLineEdit *lineEdit_bdsettings_password;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_bdsettings_BDname;
    QLabel *label_4;
    QPushButton *pushButton_bdsettings_connect;
    QLabel *label_5;
    QCheckBox *checkBox_bdsettings_status;

    void setupUi(QWidget *BDsettings)
    {
        if (BDsettings->objectName().isEmpty())
            BDsettings->setObjectName(QStringLiteral("BDsettings"));
        BDsettings->resize(312, 493);
        pushButton_bdsettings_newBD = new QPushButton(BDsettings);
        pushButton_bdsettings_newBD->setObjectName(QStringLiteral("pushButton_bdsettings_newBD"));
        pushButton_bdsettings_newBD->setGeometry(QRect(220, 30, 75, 23));
        groupBox = new QGroupBox(BDsettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 291, 241));
        lineEdit_bdsettings_serverName = new QLineEdit(groupBox);
        lineEdit_bdsettings_serverName->setObjectName(QStringLiteral("lineEdit_bdsettings_serverName"));
        lineEdit_bdsettings_serverName->setGeometry(QRect(130, 20, 113, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 47, 13));
        lineEdit_bdsettings_username = new QLineEdit(groupBox);
        lineEdit_bdsettings_username->setObjectName(QStringLiteral("lineEdit_bdsettings_username"));
        lineEdit_bdsettings_username->setGeometry(QRect(130, 80, 113, 20));
        lineEdit_bdsettings_password = new QLineEdit(groupBox);
        lineEdit_bdsettings_password->setObjectName(QStringLiteral("lineEdit_bdsettings_password"));
        lineEdit_bdsettings_password->setGeometry(QRect(130, 110, 113, 20));
        lineEdit_bdsettings_password->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        lineEdit_bdsettings_password->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 71, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 47, 13));
        lineEdit_bdsettings_BDname = new QLineEdit(groupBox);
        lineEdit_bdsettings_BDname->setObjectName(QStringLiteral("lineEdit_bdsettings_BDname"));
        lineEdit_bdsettings_BDname->setGeometry(QRect(130, 170, 113, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 180, 47, 13));
        pushButton_bdsettings_connect = new QPushButton(groupBox);
        pushButton_bdsettings_connect->setObjectName(QStringLiteral("pushButton_bdsettings_connect"));
        pushButton_bdsettings_connect->setGeometry(QRect(210, 210, 75, 23));
        pushButton_bdsettings_connect->setStyleSheet(QStringLiteral("selection-color: rgb(255, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 220, 47, 13));
        checkBox_bdsettings_status = new QCheckBox(groupBox);
        checkBox_bdsettings_status->setObjectName(QStringLiteral("checkBox_bdsettings_status"));
        checkBox_bdsettings_status->setEnabled(false);
        checkBox_bdsettings_status->setGeometry(QRect(70, 220, 131, 17));

        retranslateUi(BDsettings);

        QMetaObject::connectSlotsByName(BDsettings);
    } // setupUi

    void retranslateUi(QWidget *BDsettings)
    {
        BDsettings->setWindowTitle(QApplication::translate("BDsettings", "Form", nullptr));
        pushButton_bdsettings_newBD->setText(QApplication::translate("BDsettings", "New BD", nullptr));
        groupBox->setTitle(QApplication::translate("BDsettings", "\320\227\"\321\224\320\264\320\275\320\260\321\202\320\270\321\201\321\214 \320\267 \320\221\320\224", nullptr));
        lineEdit_bdsettings_serverName->setText(QApplication::translate("BDsettings", "localhost", nullptr));
        label->setText(QApplication::translate("BDsettings", "\320\241\320\265\321\200\320\262\320\265\321\200", nullptr));
        lineEdit_bdsettings_password->setText(QString());
        label_2->setText(QApplication::translate("BDsettings", "\320\232\320\276\321\200\320\270\321\201\321\202\321\203\320\262\320\260\321\207", nullptr));
        label_3->setText(QApplication::translate("BDsettings", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_4->setText(QApplication::translate("BDsettings", "\320\206\320\274\"\321\217 \320\221\320\224", nullptr));
        pushButton_bdsettings_connect->setText(QApplication::translate("BDsettings", "\320\227\"\321\224\320\264\320\275\320\260\321\202\320\270\321\201\321\214", nullptr));
        label_5->setText(QApplication::translate("BDsettings", "\320\241\321\202\320\260\321\202\321\203\321\201:", nullptr));
        checkBox_bdsettings_status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BDsettings: public Ui_BDsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDSETTINGS_H
