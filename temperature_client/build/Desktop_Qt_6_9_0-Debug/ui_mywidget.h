/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QPushButton *singleshot_button;
    QPushButton *automode_button;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *loopback_button;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName("MyWidget");
        MyWidget->resize(598, 507);
        singleshot_button = new QPushButton(MyWidget);
        singleshot_button->setObjectName("singleshot_button");
        singleshot_button->setGeometry(QRect(430, 400, 93, 28));
        automode_button = new QPushButton(MyWidget);
        automode_button->setObjectName("automode_button");
        automode_button->setGeometry(QRect(30, 400, 93, 28));
        comboBox = new QComboBox(MyWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(210, 200, 101, 26));
        comboBox->setAcceptDrops(false);
        comboBox->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        label = new QLabel(MyWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 202, 66, 18));
        loopback_button = new QPushButton(MyWidget);
        loopback_button->setObjectName("loopback_button");
        loopback_button->setGeometry(QRect(230, 400, 93, 28));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        singleshot_button->setText(QCoreApplication::translate("MyWidget", "PushButton", nullptr));
        automode_button->setText(QCoreApplication::translate("MyWidget", "PushButton", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MyWidget", "Udp", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MyWidget", "Tcp", nullptr));

        comboBox->setPlaceholderText(QString());
        label->setText(QCoreApplication::translate("MyWidget", "\345\217\221\351\200\201\346\250\241\345\274\217", nullptr));
        loopback_button->setText(QCoreApplication::translate("MyWidget", "\345\205\263\351\227\255\347\216\257\345\233\236\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
