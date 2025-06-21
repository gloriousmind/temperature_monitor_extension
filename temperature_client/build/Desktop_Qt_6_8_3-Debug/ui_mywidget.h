/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_2;
    QComboBox *SerialPort_box;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *BaudRate_box;
    QComboBox *FlowControl_box;
    QComboBox *Parity_box;
    QComboBox *StopBits_box;
    QLabel *label_9;
    QComboBox *DataBits_box;
    QPushButton *update_serialPort_button;
    QWidget *tab_2;
    QLabel *label;
    QPushButton *loopback_button;
    QPushButton *singleshot_button;
    QPushButton *automode_button;
    QComboBox *comboBox;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName("MyWidget");
        MyWidget->resize(598, 507);
        tabWidget = new QTabWidget(MyWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(-10, 0, 601, 491));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 40, 85, 18));
        SerialPort_box = new QComboBox(tab);
        SerialPort_box->setObjectName("SerialPort_box");
        SerialPort_box->setGeometry(QRect(180, 40, 140, 26));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 80, 85, 18));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 160, 85, 18));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(70, 200, 85, 18));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(70, 240, 85, 18));
        BaudRate_box = new QComboBox(tab);
        BaudRate_box->addItem(QString());
        BaudRate_box->addItem(QString());
        BaudRate_box->addItem(QString());
        BaudRate_box->addItem(QString());
        BaudRate_box->addItem(QString());
        BaudRate_box->addItem(QString());
        BaudRate_box->addItem(QString());
        BaudRate_box->addItem(QString());
        BaudRate_box->setObjectName("BaudRate_box");
        BaudRate_box->setGeometry(QRect(180, 80, 140, 26));
        FlowControl_box = new QComboBox(tab);
        FlowControl_box->addItem(QString());
        FlowControl_box->addItem(QString());
        FlowControl_box->addItem(QString());
        FlowControl_box->setObjectName("FlowControl_box");
        FlowControl_box->setGeometry(QRect(180, 160, 140, 26));
        Parity_box = new QComboBox(tab);
        Parity_box->addItem(QString());
        Parity_box->addItem(QString());
        Parity_box->addItem(QString());
        Parity_box->addItem(QString());
        Parity_box->addItem(QString());
        Parity_box->setObjectName("Parity_box");
        Parity_box->setGeometry(QRect(180, 200, 140, 26));
        StopBits_box = new QComboBox(tab);
        StopBits_box->addItem(QString());
        StopBits_box->addItem(QString());
        StopBits_box->addItem(QString());
        StopBits_box->setObjectName("StopBits_box");
        StopBits_box->setGeometry(QRect(180, 240, 140, 26));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(70, 120, 85, 18));
        DataBits_box = new QComboBox(tab);
        DataBits_box->addItem(QString());
        DataBits_box->addItem(QString());
        DataBits_box->addItem(QString());
        DataBits_box->addItem(QString());
        DataBits_box->setObjectName("DataBits_box");
        DataBits_box->setGeometry(QRect(180, 120, 140, 26));
        update_serialPort_button = new QPushButton(tab);
        update_serialPort_button->setObjectName("update_serialPort_button");
        update_serialPort_button->setGeometry(QRect(350, 40, 140, 26));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 150, 66, 18));
        loopback_button = new QPushButton(tab_2);
        loopback_button->setObjectName("loopback_button");
        loopback_button->setGeometry(QRect(260, 270, 93, 28));
        singleshot_button = new QPushButton(tab_2);
        singleshot_button->setObjectName("singleshot_button");
        singleshot_button->setGeometry(QRect(460, 270, 93, 28));
        automode_button = new QPushButton(tab_2);
        automode_button->setObjectName("automode_button");
        automode_button->setGeometry(QRect(60, 270, 93, 28));
        comboBox = new QComboBox(tab_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(250, 150, 101, 26));
        comboBox->setAcceptDrops(false);
        comboBox->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(MyWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        label_2->setText(QCoreApplication::translate("MyWidget", "Serial Port", nullptr));
        label_5->setText(QCoreApplication::translate("MyWidget", "Baud Rate", nullptr));
        label_6->setText(QCoreApplication::translate("MyWidget", "Flow Control", nullptr));
        label_7->setText(QCoreApplication::translate("MyWidget", "Parity", nullptr));
        label_8->setText(QCoreApplication::translate("MyWidget", "StopBits", nullptr));
        BaudRate_box->setItemText(0, QCoreApplication::translate("MyWidget", "1200", nullptr));
        BaudRate_box->setItemText(1, QCoreApplication::translate("MyWidget", "2400", nullptr));
        BaudRate_box->setItemText(2, QCoreApplication::translate("MyWidget", "4800", nullptr));
        BaudRate_box->setItemText(3, QCoreApplication::translate("MyWidget", "9600", nullptr));
        BaudRate_box->setItemText(4, QCoreApplication::translate("MyWidget", "19200", nullptr));
        BaudRate_box->setItemText(5, QCoreApplication::translate("MyWidget", "38400", nullptr));
        BaudRate_box->setItemText(6, QCoreApplication::translate("MyWidget", "57600", nullptr));
        BaudRate_box->setItemText(7, QCoreApplication::translate("MyWidget", "115200", nullptr));

        FlowControl_box->setItemText(0, QCoreApplication::translate("MyWidget", "No FlowControl", nullptr));
        FlowControl_box->setItemText(1, QCoreApplication::translate("MyWidget", "Hardware FlowControl", nullptr));
        FlowControl_box->setItemText(2, QCoreApplication::translate("MyWidget", "Software FlowControl", nullptr));

        Parity_box->setItemText(0, QCoreApplication::translate("MyWidget", "No Parity", nullptr));
        Parity_box->setItemText(1, QCoreApplication::translate("MyWidget", "Even Parity", nullptr));
        Parity_box->setItemText(2, QCoreApplication::translate("MyWidget", "Odd Parity", nullptr));
        Parity_box->setItemText(3, QCoreApplication::translate("MyWidget", "Space Parity", nullptr));
        Parity_box->setItemText(4, QCoreApplication::translate("MyWidget", "Mark Parity", nullptr));

        StopBits_box->setItemText(0, QCoreApplication::translate("MyWidget", "OneStop", nullptr));
        StopBits_box->setItemText(1, QCoreApplication::translate("MyWidget", "OneAndHalfStop", nullptr));
        StopBits_box->setItemText(2, QCoreApplication::translate("MyWidget", "TwoStop", nullptr));

        label_9->setText(QCoreApplication::translate("MyWidget", "DataBits", nullptr));
        DataBits_box->setItemText(0, QCoreApplication::translate("MyWidget", "5", nullptr));
        DataBits_box->setItemText(1, QCoreApplication::translate("MyWidget", "6", nullptr));
        DataBits_box->setItemText(2, QCoreApplication::translate("MyWidget", "7", nullptr));
        DataBits_box->setItemText(3, QCoreApplication::translate("MyWidget", "8", nullptr));

        update_serialPort_button->setText(QCoreApplication::translate("MyWidget", "\346\233\264\346\226\260\344\270\262\345\217\243\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MyWidget", "\344\270\262\345\217\243\351\200\232\344\277\241", nullptr));
        label->setText(QCoreApplication::translate("MyWidget", "\345\217\221\351\200\201\346\250\241\345\274\217", nullptr));
        loopback_button->setText(QCoreApplication::translate("MyWidget", "\345\205\263\351\227\255\347\216\257\345\233\236\346\265\213\350\257\225", nullptr));
        singleshot_button->setText(QCoreApplication::translate("MyWidget", "\345\215\225\350\257\215\345\217\221\351\200\201", nullptr));
        automode_button->setText(QCoreApplication::translate("MyWidget", "\350\207\252\345\212\250\345\217\221\351\200\201", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MyWidget", "Udp", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MyWidget", "Tcp", nullptr));

        comboBox->setPlaceholderText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MyWidget", "\347\275\221\347\273\234\351\200\232\344\277\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
