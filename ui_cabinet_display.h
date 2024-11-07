/********************************************************************************
** Form generated from reading UI file 'cabinet_display.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CABINET_DISPLAY_H
#define UI_CABINET_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_cabinet_display
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *cabinet_display)
    {
        if (cabinet_display->objectName().isEmpty())
            cabinet_display->setObjectName("cabinet_display");
        cabinet_display->resize(400, 292);
        pushButton = new QPushButton(cabinet_display);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 20, 31, 24));

        retranslateUi(cabinet_display);

        QMetaObject::connectSlotsByName(cabinet_display);
    } // setupUi

    void retranslateUi(QDialog *cabinet_display)
    {
        cabinet_display->setWindowTitle(QCoreApplication::translate("cabinet_display", "Dialog", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cabinet_display: public Ui_cabinet_display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CABINET_DISPLAY_H
