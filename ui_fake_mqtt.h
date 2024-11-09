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

    void setupUi(QDialog *fake_mqtt)
    {
        if (fake_mqtt->objectName().isEmpty())
            fake_mqtt->setObjectName("fake_mqtt");
        fake_mqtt->resize(700, 462);
        lineEdit_topic = new QLineEdit(fake_mqtt);
        lineEdit_topic->setObjectName("lineEdit_topic");
        lineEdit_topic->setGeometry(QRect(90, 20, 211, 22));
        textEdit_msg = new QTextEdit(fake_mqtt);
        textEdit_msg->setObjectName("textEdit_msg");
        textEdit_msg->setGeometry(QRect(90, 60, 211, 341));
        pushButton_publish = new QPushButton(fake_mqtt);
        pushButton_publish->setObjectName("pushButton_publish");
        pushButton_publish->setGeometry(QRect(230, 410, 75, 24));
        label = new QLabel(fake_mqtt);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 49, 16));
        label_2 = new QLabel(fake_mqtt);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 49, 16));
        listWidget = new QListWidget(fake_mqtt);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(320, 20, 351, 381));

        retranslateUi(fake_mqtt);

        QMetaObject::connectSlotsByName(fake_mqtt);
    } // setupUi

    void retranslateUi(QDialog *fake_mqtt)
    {
        fake_mqtt->setWindowTitle(QCoreApplication::translate("fake_mqtt", "Dialog", nullptr));
        lineEdit_topic->setText(QCoreApplication::translate("fake_mqtt", "electric_cabinet/reponse", nullptr));
        textEdit_msg->setHtml(QCoreApplication::translate("fake_mqtt", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">{</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;sn&quot; : &quot;xuan_thuy&quot;,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;state&quot; : 1,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-ri"
                        "ght:0px; -qt-block-indent:0; text-indent:0px;\">&quot;auto&quot; : 1,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;err_code&quot; : 0,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;phase_a&quot; : 1000,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;phase_b&quot; : 9000,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;phase_c&quot; : 5000,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;thread_hold&quot; : 7000,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;start_time&quot; : 60,</p>\n"
"<p"
                        " style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;stop_time&quot; : 600,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&quot;sync_time&quot; : 30</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">}</p></body></html>", nullptr));
        pushButton_publish->setText(QCoreApplication::translate("fake_mqtt", "Publish", nullptr));
        label->setText(QCoreApplication::translate("fake_mqtt", "Topic", nullptr));
        label_2->setText(QCoreApplication::translate("fake_mqtt", "Message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fake_mqtt: public Ui_fake_mqtt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAKE_MQTT_H
