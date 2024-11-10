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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_case_setting
{
public:
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_caseName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_threadHold;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_syncTime;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *radioButton_auto;
    QRadioButton *radioButton_manual;
    QStackedWidget *stackedWidget;
    QWidget *page_1_manual;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *radioButton_on;
    QRadioButton *radioButton_of;
    QWidget *page_2_auto;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QTimeEdit *timeEdit_start;
    QLabel *label_4;
    QTimeEdit *timeEdit_stop;

    void setupUi(QDialog *case_setting)
    {
        if (case_setting->objectName().isEmpty())
            case_setting->setObjectName("case_setting");
        case_setting->resize(573, 290);
        case_setting->setStyleSheet(QString::fromUtf8(""));
        pushButton_confirm = new QPushButton(case_setting);
        pushButton_confirm->setObjectName("pushButton_confirm");
        pushButton_confirm->setGeometry(QRect(360, 240, 91, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        pushButton_confirm->setFont(font);
        pushButton_cancel = new QPushButton(case_setting);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(460, 240, 91, 31));
        pushButton_cancel->setFont(font);
        layoutWidget = new QWidget(case_setting);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(case_setting);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(case_setting);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(21, 14, 531, 221));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(220, 16777215));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        label_caseName = new QLabel(widget);
        label_caseName->setObjectName("label_caseName");
        label_caseName->setMinimumSize(QSize(0, 35));
        label_caseName->setMaximumSize(QSize(16777215, 35));
        QFont font1;
        font1.setBold(true);
        label_caseName->setFont(font1);
        label_caseName->setFrameShape(QFrame::Shape::Box);

        horizontalLayout_2->addWidget(label_caseName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(220, 16777215));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        lineEdit_threadHold = new QLineEdit(widget);
        lineEdit_threadHold->setObjectName("lineEdit_threadHold");
        lineEdit_threadHold->setMinimumSize(QSize(0, 35));
        lineEdit_threadHold->setFont(font1);

        horizontalLayout_3->addWidget(lineEdit_threadHold);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(220, 16777215));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        lineEdit_syncTime = new QLineEdit(widget);
        lineEdit_syncTime->setObjectName("lineEdit_syncTime");
        lineEdit_syncTime->setMinimumSize(QSize(0, 35));
        lineEdit_syncTime->setFont(font1);

        horizontalLayout_5->addWidget(lineEdit_syncTime);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(220, 16777215));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        radioButton_auto = new QRadioButton(widget);
        radioButton_auto->setObjectName("radioButton_auto");
        radioButton_auto->setMinimumSize(QSize(0, 35));
        radioButton_auto->setFont(font);

        horizontalLayout_8->addWidget(radioButton_auto);

        radioButton_manual = new QRadioButton(widget);
        radioButton_manual->setObjectName("radioButton_manual");
        radioButton_manual->setMinimumSize(QSize(0, 35));
        radioButton_manual->setFont(font);

        horizontalLayout_8->addWidget(radioButton_manual);


        horizontalLayout_6->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(horizontalLayout_6);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        stackedWidget->setFrameShape(QFrame::Shape::NoFrame);
        page_1_manual = new QWidget();
        page_1_manual->setObjectName("page_1_manual");
        layoutWidget2 = new QWidget(page_1_manual);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 0, 531, 39));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName("label_7");
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMaximumSize(QSize(220, 16777215));
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        radioButton_on = new QRadioButton(layoutWidget2);
        radioButton_on->setObjectName("radioButton_on");
        radioButton_on->setMinimumSize(QSize(0, 35));
        radioButton_on->setFont(font);
        radioButton_on->setIconSize(QSize(25, 25));

        horizontalLayout_9->addWidget(radioButton_on);

        radioButton_of = new QRadioButton(layoutWidget2);
        radioButton_of->setObjectName("radioButton_of");
        radioButton_of->setMinimumSize(QSize(0, 35));
        radioButton_of->setFont(font);
        radioButton_of->setIconSize(QSize(25, 25));

        horizontalLayout_9->addWidget(radioButton_of);


        horizontalLayout_7->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(page_1_manual);
        page_2_auto = new QWidget();
        page_2_auto->setObjectName("page_2_auto");
        widget1 = new QWidget(page_2_auto);
        widget1->setObjectName("widget1");
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(170, 16777215));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        timeEdit_start = new QTimeEdit(widget1);
        timeEdit_start->setObjectName("timeEdit_start");
        timeEdit_start->setMinimumSize(QSize(0, 35));
        timeEdit_start->setFont(font);
        timeEdit_start->setDateTime(QDateTime(QDate(1999, 12, 26), QTime(6, 0, 0)));
        timeEdit_start->setMaximumTime(QTime(23, 59, 59));
        timeEdit_start->setTimeSpec(Qt::TimeSpec::UTC);
        timeEdit_start->setTime(QTime(6, 0, 0));

        horizontalLayout->addWidget(timeEdit_start);

        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_4);

        timeEdit_stop = new QTimeEdit(widget1);
        timeEdit_stop->setObjectName("timeEdit_stop");
        timeEdit_stop->setMinimumSize(QSize(0, 35));
        timeEdit_stop->setFont(font);
        timeEdit_stop->setTime(QTime(18, 0, 0));

        horizontalLayout->addWidget(timeEdit_stop);


        horizontalLayout_4->addLayout(horizontalLayout);

        stackedWidget->addWidget(page_2_auto);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(case_setting);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(case_setting);
    } // setupUi

    void retranslateUi(QDialog *case_setting)
    {
        case_setting->setWindowTitle(QCoreApplication::translate("case_setting", "\304\220i\341\273\201u khi\341\273\203n t\341\273\247 \304\221i\341\273\207n", nullptr));
        pushButton_confirm->setText(QCoreApplication::translate("case_setting", "X\303\241c nh\341\272\255n", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("case_setting", "H\341\273\247y", nullptr));
        label->setText(QCoreApplication::translate("case_setting", "T\303\252n t\341\273\247 \304\221i\341\273\207n", nullptr));
        label_caseName->setText(QString());
        label_2->setText(QCoreApplication::translate("case_setting", "Ng\306\260\341\273\241ng c\341\272\243nh b\303\241o (mA)", nullptr));
        label_5->setText(QCoreApplication::translate("case_setting", "Th\341\273\235i gian \304\221\341\273\223ng b\341\273\231 (gi\303\242y)", nullptr));
        label_6->setText(QCoreApplication::translate("case_setting", "Ch\341\272\277 \304\221\341\273\231 ho\341\272\241t \304\221\341\273\231ng", nullptr));
        radioButton_auto->setText(QCoreApplication::translate("case_setting", "T\341\273\261 \304\221\341\273\231ng", nullptr));
        radioButton_manual->setText(QCoreApplication::translate("case_setting", "Th\341\273\247 c\303\264ng", nullptr));
        label_7->setText(QCoreApplication::translate("case_setting", "Tr\341\272\241ng th\303\241i", nullptr));
        radioButton_on->setText(QCoreApplication::translate("case_setting", "B\341\272\255t", nullptr));
        radioButton_of->setText(QCoreApplication::translate("case_setting", "T\341\272\257t", nullptr));
        label_3->setText(QCoreApplication::translate("case_setting", "Th\341\273\235i gian b\341\272\255t", nullptr));
        timeEdit_start->setDisplayFormat(QCoreApplication::translate("case_setting", "h:mm", nullptr));
        label_4->setText(QCoreApplication::translate("case_setting", "\304\220\341\272\277n", nullptr));
        timeEdit_stop->setDisplayFormat(QCoreApplication::translate("case_setting", "h:mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class case_setting: public Ui_case_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASE_SETTING_H
