/********************************************************************************
** Form generated from reading UI file 'electric_case_add.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELECTRIC_CASE_ADD_H
#define UI_ELECTRIC_CASE_ADD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_electric_case_add
{
public:
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_caseName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_caseLat;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_caseLon;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QTextEdit *textEdit_caseDes;

    void setupUi(QDialog *electric_case_add)
    {
        if (electric_case_add->objectName().isEmpty())
            electric_case_add->setObjectName("electric_case_add");
        electric_case_add->resize(455, 239);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        electric_case_add->setWindowIcon(icon);
        pushButton_confirm = new QPushButton(electric_case_add);
        pushButton_confirm->setObjectName("pushButton_confirm");
        pushButton_confirm->setGeometry(QRect(270, 200, 75, 24));
        pushButton_cancel = new QPushButton(electric_case_add);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(360, 200, 75, 24));
        layoutWidget = new QWidget(electric_case_add);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 431, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit_caseName = new QLineEdit(layoutWidget);
        lineEdit_caseName->setObjectName("lineEdit_caseName");
        lineEdit_caseName->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(lineEdit_caseName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_caseLat = new QLineEdit(layoutWidget);
        lineEdit_caseLat->setObjectName("lineEdit_caseLat");
        lineEdit_caseLat->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_2->addWidget(lineEdit_caseLat);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_caseLon = new QLineEdit(layoutWidget);
        lineEdit_caseLon->setObjectName("lineEdit_caseLon");
        lineEdit_caseLon->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_3->addWidget(lineEdit_caseLon);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_4->addWidget(label_3);

        textEdit_caseDes = new QTextEdit(layoutWidget);
        textEdit_caseDes->setObjectName("textEdit_caseDes");
        textEdit_caseDes->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_4->addWidget(textEdit_caseDes);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(electric_case_add);

        QMetaObject::connectSlotsByName(electric_case_add);
    } // setupUi

    void retranslateUi(QDialog *electric_case_add)
    {
        electric_case_add->setWindowTitle(QCoreApplication::translate("electric_case_add", "Th\303\252m t\341\273\247 \304\221i\341\273\207n", nullptr));
        pushButton_confirm->setText(QCoreApplication::translate("electric_case_add", "X\303\241c nh\341\272\255n", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("electric_case_add", "H\341\273\247y", nullptr));
        label->setText(QCoreApplication::translate("electric_case_add", "T\303\252n t\341\273\247 \304\221i\341\273\207n", nullptr));
        lineEdit_caseName->setText(QCoreApplication::translate("electric_case_add", "xuan_thuy", nullptr));
        label_2->setText(QCoreApplication::translate("electric_case_add", "Ho\303\240nh \304\221\341\273\231", nullptr));
        lineEdit_caseLat->setText(QCoreApplication::translate("electric_case_add", "21.0371", nullptr));
        label_4->setText(QCoreApplication::translate("electric_case_add", "Tung \304\221\341\273\231", nullptr));
        lineEdit_caseLon->setText(QCoreApplication::translate("electric_case_add", "105.788", nullptr));
        label_3->setText(QCoreApplication::translate("electric_case_add", "M\303\264 t\341\272\243", nullptr));
        textEdit_caseDes->setHtml(QCoreApplication::translate("electric_case_add", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">tu dien cao ap</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class electric_case_add: public Ui_electric_case_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELECTRIC_CASE_ADD_H
