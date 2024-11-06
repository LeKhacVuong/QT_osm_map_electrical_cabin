/********************************************************************************
** Form generated from reading UI file 'case_setting.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASE_SETTING_H
#define UI_CASE_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_case_setting
{
public:
    QPushButton *pushButton_confirm;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_caseName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_threadHold;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *comboBox_opMode;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *comboBox_state;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QTimeEdit *timeEdit_start;
    QLabel *label_4;
    QTimeEdit *timeEdit_stop;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_syncTime;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *case_setting)
    {
        if (case_setting->objectName().isEmpty())
            case_setting->setObjectName("case_setting");
        case_setting->resize(505, 249);
        pushButton_confirm = new QPushButton(case_setting);
        pushButton_confirm->setObjectName("pushButton_confirm");
        pushButton_confirm->setGeometry(QRect(310, 200, 75, 24));
        layoutWidget = new QWidget(case_setting);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 11, 461, 186));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        label_caseName = new QLabel(layoutWidget);
        label_caseName->setObjectName("label_caseName");
        label_caseName->setMaximumSize(QSize(16777215, 35));
        QFont font1;
        font1.setBold(true);
        label_caseName->setFont(font1);
        label_caseName->setFrameShape(QFrame::Shape::Box);

        horizontalLayout_2->addWidget(label_caseName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(150, 16777215));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_threadHold = new QLineEdit(layoutWidget);
        lineEdit_threadHold->setObjectName("lineEdit_threadHold");
        lineEdit_threadHold->setMinimumSize(QSize(0, 0));
        lineEdit_threadHold->setFont(font1);

        horizontalLayout_3->addWidget(lineEdit_threadHold);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(150, 16777215));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        comboBox_opMode = new QComboBox(layoutWidget);
        comboBox_opMode->addItem(QString());
        comboBox_opMode->addItem(QString());
        comboBox_opMode->setObjectName("comboBox_opMode");
        comboBox_opMode->setFont(font1);
        comboBox_opMode->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        horizontalLayout_6->addWidget(comboBox_opMode);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMaximumSize(QSize(150, 16777215));
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);

        comboBox_state = new QComboBox(layoutWidget);
        comboBox_state->addItem(QString());
        comboBox_state->addItem(QString());
        comboBox_state->setObjectName("comboBox_state");
        comboBox_state->setFont(font1);
        comboBox_state->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        horizontalLayout_7->addWidget(comboBox_state);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(150, 16777215));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        timeEdit_start = new QTimeEdit(layoutWidget);
        timeEdit_start->setObjectName("timeEdit_start");
        timeEdit_start->setFont(font1);
        timeEdit_start->setDateTime(QDateTime(QDate(1999, 12, 30), QTime(6, 0, 0)));
        timeEdit_start->setMaximumTime(QTime(23, 59, 59));
        timeEdit_start->setTimeSpec(Qt::TimeSpec::UTC);
        timeEdit_start->setTime(QTime(6, 0, 0));

        horizontalLayout->addWidget(timeEdit_start);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        timeEdit_stop = new QTimeEdit(layoutWidget);
        timeEdit_stop->setObjectName("timeEdit_stop");
        timeEdit_stop->setFont(font1);
        timeEdit_stop->setTime(QTime(18, 0, 0));

        horizontalLayout->addWidget(timeEdit_stop);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(150, 16777215));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        lineEdit_syncTime = new QLineEdit(layoutWidget);
        lineEdit_syncTime->setObjectName("lineEdit_syncTime");
        lineEdit_syncTime->setMinimumSize(QSize(0, 0));
        lineEdit_syncTime->setFont(font1);

        horizontalLayout_5->addWidget(lineEdit_syncTime);


        verticalLayout->addLayout(horizontalLayout_5);

        pushButton_cancel = new QPushButton(case_setting);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(400, 200, 75, 24));

        retranslateUi(case_setting);

        QMetaObject::connectSlotsByName(case_setting);
    } // setupUi

    void retranslateUi(QDialog *case_setting)
    {
        case_setting->setWindowTitle(QCoreApplication::translate("case_setting", "Dialog", nullptr));
        pushButton_confirm->setText(QCoreApplication::translate("case_setting", "X\303\241c nh\341\272\255n", nullptr));
        label->setText(QCoreApplication::translate("case_setting", "T\303\252n t\341\273\247 \304\221i\341\273\207n", nullptr));
        label_caseName->setText(QString());
        label_2->setText(QCoreApplication::translate("case_setting", "Ng\306\260\341\273\241ng c\341\272\243nh b\303\241o (mA)", nullptr));
        label_6->setText(QCoreApplication::translate("case_setting", "Ch\341\272\277 \304\221\341\273\231 ho\341\272\241t \304\221\341\273\231ng", nullptr));
        comboBox_opMode->setItemText(0, QCoreApplication::translate("case_setting", "T\341\273\261 \304\221\341\273\231ng", nullptr));
        comboBox_opMode->setItemText(1, QCoreApplication::translate("case_setting", "Th\341\273\247 c\303\264ng", nullptr));

        label_7->setText(QCoreApplication::translate("case_setting", "Tr\341\272\241ng th\303\241i hi\341\273\207n t\341\272\241i", nullptr));
        comboBox_state->setItemText(0, QCoreApplication::translate("case_setting", "T\341\272\257t", nullptr));
        comboBox_state->setItemText(1, QCoreApplication::translate("case_setting", "B\341\272\255t", nullptr));

        label_3->setText(QCoreApplication::translate("case_setting", "Th\341\273\235i gian b\341\272\255t", nullptr));
        label_4->setText(QCoreApplication::translate("case_setting", "\304\220\341\272\277n", nullptr));
        label_5->setText(QCoreApplication::translate("case_setting", "Th\341\273\235i gian \304\221\341\273\223ng b\341\273\231 (gi\303\242y)", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("case_setting", "H\341\273\247y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class case_setting: public Ui_case_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASE_SETTING_H
