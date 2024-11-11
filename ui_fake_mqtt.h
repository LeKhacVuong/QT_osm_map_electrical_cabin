/********************************************************************************
** Form generated from reading UI file 'fake_mqtt.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAKE_MQTT_H
#define UI_FAKE_MQTT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_fake_mqtt
{
public:
    QLineEdit *lineEdit_topic;
    QTextEdit *textEdit_msg;
    QPushButton *pushButton_publish;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listWidget;
    QListWidget *listWidget_log;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_clearLog;
    QPushButton *pushButton_clearMsg;
    QCheckBox *checkBox_auto_roll;

    void setupUi(QDialog *fake_mqtt)
    {
        if (fake_mqtt->objectName().isEmpty())
            fake_mqtt->setObjectName("fake_mqtt");
        fake_mqtt->resize(1161, 455);
        lineEdit_topic = new QLineEdit(fake_mqtt);
        lineEdit_topic->setObjectName("lineEdit_topic");
        lineEdit_topic->setGeometry(QRect(90, 20, 271, 22));
        textEdit_msg = new QTextEdit(fake_mqtt);
        textEdit_msg->setObjectName("textEdit_msg");
        textEdit_msg->setGeometry(QRect(90, 60, 271, 341));
        pushButton_publish = new QPushButton(fake_mqtt);
        pushButton_publish->setObjectName("pushButton_publish");
        pushButton_publish->setGeometry(QRect(280, 410, 75, 24));
        label = new QLabel(fake_mqtt);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 49, 16));
        label_2 = new QLabel(fake_mqtt);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 49, 16));
        listWidget = new QListWidget(fake_mqtt);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(370, 60, 281, 341));
        listWidget_log = new QListWidget(fake_mqtt);
        listWidget_log->setObjectName("listWidget_log");
        listWidget_log->setGeometry(QRect(660, 60, 471, 341));
        listWidget_log->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        label_3 = new QLabel(fake_mqtt);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(470, 20, 101, 20));
        label_4 = new QLabel(fake_mqtt);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(860, 20, 101, 20));
        pushButton_clearLog = new QPushButton(fake_mqtt);
        pushButton_clearLog->setObjectName("pushButton_clearLog");
        pushButton_clearLog->setGeometry(QRect(1050, 410, 75, 24));
        pushButton_clearMsg = new QPushButton(fake_mqtt);
        pushButton_clearMsg->setObjectName("pushButton_clearMsg");
        pushButton_clearMsg->setGeometry(QRect(570, 410, 75, 24));
        checkBox_auto_roll = new QCheckBox(fake_mqtt);
        checkBox_auto_roll->setObjectName("checkBox_auto_roll");
        checkBox_auto_roll->setGeometry(QRect(920, 410, 93, 26));
        checkBox_auto_roll->setChecked(true);
        checkBox_auto_roll->setTristate(false);

        retranslateUi(fake_mqtt);

        QMetaObject::connectSlotsByName(fake_mqtt);
    } // setupUi

    void retranslateUi(QDialog *fake_mqtt)
    {
        fake_mqtt->setWindowTitle(QCoreApplication::translate("fake_mqtt", "B\341\272\243n tin \304\221i\341\273\201u khi\341\273\203n", nullptr));
        lineEdit_topic->setText(QCoreApplication::translate("fake_mqtt", "electric_cabinet/update/xuan_thuy", nullptr));
        textEdit_msg->setHtml(QCoreApplication::translate("fake_mqtt", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">{</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;state&quot; : 1,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;auto&quot; : 1,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\">&quot;err_code&quot; : 0,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;phase_1&quot; : 1000,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;phase_2&quot; : 9000,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;phase_3&quot; : 5000,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;thread_hold&quot; : 7000,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;start_time&quot; : &quot;6:30&quot;,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;stop_time&quot; : &quot;18:30&"
                        "quot;,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;sync_time&quot; : 30</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">}</p></body></html>", nullptr));
        pushButton_publish->setText(QCoreApplication::translate("fake_mqtt", "G\341\273\255i", nullptr));
        label->setText(QCoreApplication::translate("fake_mqtt", "Topic", nullptr));
        label_2->setText(QCoreApplication::translate("fake_mqtt", "Msg", nullptr));
        label_3->setText(QCoreApplication::translate("fake_mqtt", "B\341\272\243n tin nh\341\272\255n", nullptr));
        label_4->setText(QCoreApplication::translate("fake_mqtt", "Log \341\273\251ng d\341\273\245ng", nullptr));
        pushButton_clearLog->setText(QCoreApplication::translate("fake_mqtt", "X\303\263a", nullptr));
        pushButton_clearMsg->setText(QCoreApplication::translate("fake_mqtt", "X\303\263a", nullptr));
        checkBox_auto_roll->setText(QCoreApplication::translate("fake_mqtt", "T\341\273\261 cu\341\273\231n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fake_mqtt: public Ui_fake_mqtt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAKE_MQTT_H
