/********************************************************************************
** Form generated from reading UI file 'infoform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOFORM_H
#define UI_INFOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infoForm
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_info;

    void setupUi(QWidget *infoForm)
    {
        if (infoForm->objectName().isEmpty())
            infoForm->setObjectName(QStringLiteral("infoForm"));
        infoForm->resize(240, 320);
        infoForm->setMinimumSize(QSize(240, 320));
        infoForm->setMaximumSize(QSize(240, 320));
        verticalLayout = new QVBoxLayout(infoForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(infoForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 100));
        widget->setStyleSheet(QStringLiteral("image: url(:/new/prefix1/ico/res/drawable-xxxhdpi/round_monetization_on_black_24.png);"));

        verticalLayout->addWidget(widget);

        label = new QLabel(infoForm);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(infoForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(infoForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_info = new QPushButton(infoForm);
        pushButton_info->setObjectName(QStringLiteral("pushButton_info"));

        verticalLayout->addWidget(pushButton_info);


        retranslateUi(infoForm);

        QMetaObject::connectSlotsByName(infoForm);
    } // setupUi

    void retranslateUi(QWidget *infoForm)
    {
        infoForm->setWindowTitle(QApplication::translate("infoForm", "\320\237\321\200\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\321\203", nullptr));
        label->setText(QApplication::translate("infoForm", "Plutos \320\262\320\265\321\200\321\201\321\226\321\217 0.4", nullptr));
        label_2->setText(QApplication::translate("infoForm", "2018  \302\251 Olexandr Berezensky", nullptr));
        label_3->setText(QApplication::translate("infoForm", "E-mail: kaifatdd@gmail.com", nullptr));
        pushButton_info->setText(QApplication::translate("infoForm", "\320\227\320\260\320\272\321\200\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infoForm: public Ui_infoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOFORM_H
