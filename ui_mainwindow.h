/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_caseMap;
    QAction *action_fakeMqtt;
    QWidget *centralwidget;
    QPushButton *pushButton_openMap;
    QLabel *label;
    QComboBox *comboBox_comList;
    QPushButton *pushButton_scanCabinet;
    QPushButton *pushButton_refresh;
    QFrame *line;
    QFrame *line_2;
    QStackedWidget *stackedWidget_connect;
    QWidget *page_notConnect;
    QLabel *label_5;
    QWidget *page_setting;
    QLineEdit *lineEdit_settingSn;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit_settingThreadHold;
    QLabel *label_3;
    QStackedWidget *stackedWidget_auto;
    QWidget *page_auto;
    QTimeEdit *timeEdit_timeStart;
    QTimeEdit *timeEdit_timeStop;
    QLabel *label_7;
    QWidget *page_manual;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_on;
    QRadioButton *radioButton_off;
    QLabel *label_6;
    QLineEdit *lineEdit_settingSyncTime;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_auto;
    QRadioButton *radioButton_manual;
    QPushButton *pushButton_sendConfig;
    QPushButton *pushButton_connectCabinet;
    QPushButton *pushButton_import;
    QPushButton *pushButton_export;
    QMenuBar *menubar;
    QMenu *menuT_y_ch_n;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(644, 607);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: beige; /* m\303\240u v\303\242n g\341\273\227 Burlywood */\n"
"    color: black; /* m\303\240u ch\341\273\257 n\341\273\225i b\341\272\255t */\n"
"}"));
        action_caseMap = new QAction(MainWindow);
        action_caseMap->setObjectName("action_caseMap");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::HelpFaq));
        action_caseMap->setIcon(icon1);
        action_fakeMqtt = new QAction(MainWindow);
        action_fakeMqtt->setObjectName("action_fakeMqtt");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::CameraWeb));
        action_fakeMqtt->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_openMap = new QPushButton(centralwidget);
        pushButton_openMap->setObjectName("pushButton_openMap");
        pushButton_openMap->setGeometry(QRect(500, 400, 120, 120));
        pushButton_openMap->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: lightgreen;\n"
"    color: white;\n"
"	border-radius: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: limegreen;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 91, 44));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: lightgreen;\n"
"border-radius: 8px;\n"
""));
        label->setFrameShape(QFrame::Shape::NoFrame);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBox_comList = new QComboBox(centralwidget);
        comboBox_comList->setObjectName("comboBox_comList");
        comboBox_comList->setGeometry(QRect(130, 20, 251, 44));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        comboBox_comList->setFont(font1);
        comboBox_comList->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background-color: #66CC66;\n"
"	border-radius: 8px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: limegreen; /* M\303\240u n\341\273\201n khi hover */\n"
"}"));
        pushButton_scanCabinet = new QPushButton(centralwidget);
        pushButton_scanCabinet->setObjectName("pushButton_scanCabinet");
        pushButton_scanCabinet->setGeometry(QRect(30, 70, 401, 51));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        pushButton_scanCabinet->setFont(font2);
        pushButton_scanCabinet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5BC0FE; /* M\303\240u n\341\273\201n ban \304\221\341\272\247u */\n"
"    color: black;              /* M\303\240u ch\341\273\257 */\n"
"    border-radius: 8px;        /* Bo g\303\263c */\n"
"    padding: 10px;             /* Kho\341\272\243ng c\303\241ch b\303\252n trong n\303\272t */\n"
"    font: bold 20px;           /* Ki\341\273\203u ch\341\273\257 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: limegreen; /* M\303\240u n\341\273\201n khi hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3e8e41; /* M\303\240u n\341\273\201n khi \341\272\245n */\n"
"}"));
        pushButton_refresh = new QPushButton(centralwidget);
        pushButton_refresh->setObjectName("pushButton_refresh");
        pushButton_refresh->setGeometry(QRect(390, 20, 44, 44));
        pushButton_refresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5BC0FE;\n"
"    color: white;\n"
"	border-radius: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: limegreen;\n"
"}"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(460, 10, 20, 531));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(30, 130, 431, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        stackedWidget_connect = new QStackedWidget(centralwidget);
        stackedWidget_connect->setObjectName("stackedWidget_connect");
        stackedWidget_connect->setGeometry(QRect(30, 150, 411, 301));
        stackedWidget_connect->setFrameShape(QFrame::Shape::NoFrame);
        page_notConnect = new QWidget();
        page_notConnect->setObjectName("page_notConnect");
        label_5 = new QLabel(page_notConnect);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 401, 301));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        label_5->setFont(font3);
        label_5->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        label_5->setStyleSheet(QString::fromUtf8("background-color: lightgreen;\n"
"border-radius: 10px;\n"
"font 15px"));
        label_5->setFrameShape(QFrame::Shape::NoFrame);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_connect->addWidget(page_notConnect);
        page_setting = new QWidget();
        page_setting->setObjectName("page_setting");
        lineEdit_settingSn = new QLineEdit(page_setting);
        lineEdit_settingSn->setObjectName("lineEdit_settingSn");
        lineEdit_settingSn->setGeometry(QRect(200, 0, 201, 44));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        lineEdit_settingSn->setFont(font4);
        lineEdit_settingSn->setStyleSheet(QString::fromUtf8("background-color: #66CC66;\n"
"border-radius: 8px;\n"
""));
        label_4 = new QLabel(page_setting);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 150, 221, 44));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("background-color: lightgreen;\n"
"border-radius: 8px;\n"
""));
        label_4->setFrameShape(QFrame::Shape::NoFrame);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(page_setting);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 196, 44));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("background-color: lightgreen;\n"
"border-radius: 8px;\n"
""));
        label_2->setFrameShape(QFrame::Shape::NoFrame);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_settingThreadHold = new QLineEdit(page_setting);
        lineEdit_settingThreadHold->setObjectName("lineEdit_settingThreadHold");
        lineEdit_settingThreadHold->setGeometry(QRect(200, 50, 201, 44));
        lineEdit_settingThreadHold->setFont(font4);
        lineEdit_settingThreadHold->setStyleSheet(QString::fromUtf8("background-color: #66CC66;\n"
"border-radius: 8px;\n"
""));
        label_3 = new QLabel(page_setting);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 50, 196, 44));
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("background-color: lightgreen;\n"
"border-radius: 8px;\n"
""));
        label_3->setFrameShape(QFrame::Shape::NoFrame);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_auto = new QStackedWidget(page_setting);
        stackedWidget_auto->setObjectName("stackedWidget_auto");
        stackedWidget_auto->setGeometry(QRect(0, 250, 411, 61));
        stackedWidget_auto->setFrameShape(QFrame::Shape::NoFrame);
        page_auto = new QWidget();
        page_auto->setObjectName("page_auto");
        timeEdit_timeStart = new QTimeEdit(page_auto);
        timeEdit_timeStart->setObjectName("timeEdit_timeStart");
        timeEdit_timeStart->setGeometry(QRect(0, 0, 141, 44));
        timeEdit_timeStart->setFont(font2);
        timeEdit_timeStart->setStyleSheet(QString::fromUtf8("QTimeEdit {\n"
"    background-color: #66CC66;\n"
"    border-radius: 8px;\n"
"    font: 15px;\n"
"    font-weight: bold; /* L\303\240m cho v\304\203n b\341\272\243n in \304\221\341\272\255m */\n"
"    padding: 5px; /* T\304\203ng kho\341\272\243ng c\303\241ch b\303\252n trong \304\221\341\273\203 d\341\273\205 click */\n"
"}\n"
"\n"
"QTimeEdit::up-button, QTimeEdit::down-button {\n"
"    width: 20px; /* T\304\203ng k\303\255ch th\306\260\341\273\233c chi\341\273\201u r\341\273\231ng */\n"
"    height: 20px; /* T\304\203ng k\303\255ch th\306\260\341\273\233c chi\341\273\201u cao */\n"
"}\n"
"\n"
"QTimeEdit::up-arrow, QTimeEdit::down-arrow {\n"
"    width: 15px; /* T\304\203ng k\303\255ch th\306\260\341\273\233c m\305\251i t\303\252n */\n"
"    height: 15px;\n"
"}\n"
""));
        timeEdit_timeStop = new QTimeEdit(page_auto);
        timeEdit_timeStop->setObjectName("timeEdit_timeStop");
        timeEdit_timeStop->setGeometry(QRect(260, 0, 141, 44));
        timeEdit_timeStop->setFont(font2);
        timeEdit_timeStop->setStyleSheet(QString::fromUtf8("QTimeEdit {\n"
"    background-color: #66CC66;\n"
"    border-radius: 8px;\n"
"    font: 15px;\n"
"    font-weight: bold; /* L\303\240m cho v\304\203n b\341\272\243n in \304\221\341\272\255m */\n"
"    padding: 5px; /* T\304\203ng kho\341\272\243ng c\303\241ch b\303\252n trong \304\221\341\273\203 d\341\273\205 click */\n"
"}\n"
"\n"
"QTimeEdit::up-button, QTimeEdit::down-button {\n"
"    width: 20px; /* T\304\203ng k\303\255ch th\306\260\341\273\233c chi\341\273\201u r\341\273\231ng */\n"
"    height: 20px; /* T\304\203ng k\303\255ch th\306\260\341\273\233c chi\341\273\201u cao */\n"
"}\n"
"\n"
"QTimeEdit::up-arrow, QTimeEdit::down-arrow {\n"
"    width: 15px; /* T\304\203ng k\303\255ch th\306\260\341\273\233c m\305\251i t\303\252n */\n"
"    height: 15px;\n"
"}\n"
""));
        label_7 = new QLabel(page_auto);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(150, 0, 91, 44));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-color: lightgreen;\n"
"border-radius: 8px;\n"
""));
        label_7->setFrameShape(QFrame::Shape::NoFrame);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_auto->addWidget(page_auto);
        page_manual = new QWidget();
        page_manual->setObjectName("page_manual");
        layoutWidget = new QWidget(page_manual);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 401, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_on = new QRadioButton(layoutWidget);
        radioButton_on->setObjectName("radioButton_on");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButton_on->sizePolicy().hasHeightForWidth());
        radioButton_on->setSizePolicy(sizePolicy);
        radioButton_on->setMinimumSize(QSize(0, 44));
        QFont font5;
        font5.setBold(true);
        radioButton_on->setFont(font5);
        radioButton_on->setStyleSheet(QString::fromUtf8("\n"
"QRadioButton {\n"
"    font-size: 16px;               /* K\303\255ch th\306\260\341\273\233c ch\341\273\257 */\n"
"    padding: 5px;                  /* Kho\341\272\243ng c\303\241ch b\303\252n trong */\n"
"	background-color: #66CC66;\n"
"	border-radius: 8px;  /* Bo g\303\263c \304\221\341\273\203 tr\303\264ng m\341\273\201m m\341\272\241i */\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 20px;            /* Chi\341\273\201u r\341\273\231ng c\341\273\247a ph\341\272\247n ch\341\273\211 b\303\241o */\n"
"    height: 20px;           /* Chi\341\273\201u cao c\341\273\247a ph\341\272\247n ch\341\273\211 b\303\241o */\n"
"}"));
        radioButton_on->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(radioButton_on);

        radioButton_off = new QRadioButton(layoutWidget);
        radioButton_off->setObjectName("radioButton_off");
        sizePolicy.setHeightForWidth(radioButton_off->sizePolicy().hasHeightForWidth());
        radioButton_off->setSizePolicy(sizePolicy);
        radioButton_off->setMinimumSize(QSize(0, 44));
        radioButton_off->setFont(font5);
        radioButton_off->setStyleSheet(QString::fromUtf8("\n"
"QRadioButton {\n"
"    font-size: 16px;               /* K\303\255ch th\306\260\341\273\233c ch\341\273\257 */\n"
"    padding: 5px;                  /* Kho\341\272\243ng c\303\241ch b\303\252n trong */\n"
"	background-color: #66CC66;\n"
"	border-radius: 8px;  /* Bo g\303\263c \304\221\341\273\203 tr\303\264ng m\341\273\201m m\341\272\241i */\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 20px;            /* Chi\341\273\201u r\341\273\231ng c\341\273\247a ph\341\272\247n ch\341\273\211 b\303\241o */\n"
"    height: 20px;           /* Chi\341\273\201u cao c\341\273\247a ph\341\272\247n ch\341\273\211 b\303\241o */\n"
"}"));
        radioButton_off->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(radioButton_off);

        stackedWidget_auto->addWidget(page_manual);
        label_6 = new QLabel(page_setting);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 100, 196, 44));
        label_6->setFont(font4);
        label_6->setStyleSheet(QString::fromUtf8("background-color: lightgreen;\n"
"border-radius: 8px;\n"
""));
        label_6->setFrameShape(QFrame::Shape::NoFrame);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_settingSyncTime = new QLineEdit(page_setting);
        lineEdit_settingSyncTime->setObjectName("lineEdit_settingSyncTime");
        lineEdit_settingSyncTime->setGeometry(QRect(200, 100, 201, 44));
        lineEdit_settingSyncTime->setFont(font4);
        lineEdit_settingSyncTime->setStyleSheet(QString::fromUtf8("background-color: #66CC66;\n"
"border-radius: 8px;\n"
""));
        layoutWidget1 = new QWidget(page_setting);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 200, 401, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_auto = new QRadioButton(layoutWidget1);
        radioButton_auto->setObjectName("radioButton_auto");
        sizePolicy.setHeightForWidth(radioButton_auto->sizePolicy().hasHeightForWidth());
        radioButton_auto->setSizePolicy(sizePolicy);
        radioButton_auto->setMinimumSize(QSize(0, 44));
        radioButton_auto->setFont(font5);
        radioButton_auto->setStyleSheet(QString::fromUtf8("\n"
"QRadioButton {\n"
"    font-size: 16px;               /* K\303\255ch th\306\260\341\273\233c ch\341\273\257 */\n"
"    padding: 5px;                  /* Kho\341\272\243ng c\303\241ch b\303\252n trong */\n"
"	background-color: #66CC66;\n"
"	border-radius: 8px;  /* Bo g\303\263c \304\221\341\273\203 tr\303\264ng m\341\273\201m m\341\272\241i */\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 20px;            /* Chi\341\273\201u r\341\273\231ng c\341\273\247a ph\341\272\247n ch\341\273\211 b\303\241o */\n"
"    height: 20px;           /* Chi\341\273\201u cao c\341\273\247a ph\341\272\247n ch\341\273\211 b\303\241o */\n"
"}"));
        radioButton_auto->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(radioButton_auto);

        radioButton_manual = new QRadioButton(layoutWidget1);
        radioButton_manual->setObjectName("radioButton_manual");
        sizePolicy.setHeightForWidth(radioButton_manual->sizePolicy().hasHeightForWidth());
        radioButton_manual->setSizePolicy(sizePolicy);
        radioButton_manual->setMinimumSize(QSize(0, 44));
        radioButton_manual->setFont(font5);
        radioButton_manual->setStyleSheet(QString::fromUtf8("\n"
"QRadioButton {\n"
"    font-size: 16px;               /* K\303\255ch th\306\260\341\273\233c ch\341\273\257 */\n"
"    padding: 5px;                  /* Kho\341\272\243ng c\303\241ch b\303\252n trong */\n"
"	background-color: #66CC66;\n"
"	border-radius: 8px;  /* Bo g\303\263c \304\221\341\273\203 tr\303\264ng m\341\273\201m m\341\272\241i */\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 20px;            /* Chi\341\273\201u r\341\273\231ng c\341\273\247a ph\341\272\247n ch\341\273\211 b\303\241o */\n"
"    height: 20px;           /* Chi\341\273\201u cao c\341\273\247a ph\341\272\247n ch\341\273\211 b\303\241o */\n"
"}"));
        radioButton_manual->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(radioButton_manual);

        stackedWidget_connect->addWidget(page_setting);
        pushButton_sendConfig = new QPushButton(centralwidget);
        pushButton_sendConfig->setObjectName("pushButton_sendConfig");
        pushButton_sendConfig->setGeometry(QRect(240, 460, 191, 51));
        pushButton_sendConfig->setFont(font2);
        pushButton_sendConfig->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5BC0FE; /* M\303\240u n\341\273\201n ban \304\221\341\272\247u */\n"
"    color: black;              /* M\303\240u ch\341\273\257 */\n"
"    border-radius: 8px;        /* Bo g\303\263c */\n"
"    padding: 10px;             /* Kho\341\272\243ng c\303\241ch b\303\252n trong n\303\272t */\n"
"    font: bold 20px;           /* Ki\341\273\203u ch\341\273\257 */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    color: black;                   /* M\303\240u ch\341\273\257 khi disable */\n"
"    background-color: lightgray;     /* M\303\240u n\341\273\201n khi disable */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: limegreen; /* M\303\240u n\341\273\201n khi hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3e8e41; /* M\303\240u n\341\273\201n khi \341\272\245n */\n"
"}"));
        pushButton_connectCabinet = new QPushButton(centralwidget);
        pushButton_connectCabinet->setObjectName("pushButton_connectCabinet");
        pushButton_connectCabinet->setGeometry(QRect(30, 460, 191, 51));
        pushButton_connectCabinet->setFont(font2);
        pushButton_connectCabinet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5BC0FE; /* M\303\240u n\341\273\201n ban \304\221\341\272\247u */\n"
"    color: black;              /* M\303\240u ch\341\273\257 */\n"
"    border-radius: 8px;        /* Bo g\303\263c */\n"
"    padding: 10px;             /* Kho\341\272\243ng c\303\241ch b\303\252n trong n\303\272t */\n"
"    font: bold 20px;           /* Ki\341\273\203u ch\341\273\257 */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    color: black;                   /* M\303\240u ch\341\273\257 khi disable */\n"
"    background-color: lightgray;     /* M\303\240u n\341\273\201n khi disable */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: limegreen; /* M\303\240u n\341\273\201n khi hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3e8e41; /* M\303\240u n\341\273\201n khi \341\272\245n */\n"
"}"));
        pushButton_import = new QPushButton(centralwidget);
        pushButton_import->setObjectName("pushButton_import");
        pushButton_import->setGeometry(QRect(500, 210, 120, 120));
        pushButton_import->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: lightgreen;\n"
"    color: white;\n"
"	border-radius: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: limegreen;\n"
"}"));
        pushButton_export = new QPushButton(centralwidget);
        pushButton_export->setObjectName("pushButton_export");
        pushButton_export->setGeometry(QRect(500, 20, 120, 120));
        pushButton_export->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: lightgreen;\n"
"    color: white;\n"
"	border-radius: 15px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: limegreen;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 644, 25));
        menuT_y_ch_n = new QMenu(menubar);
        menuT_y_ch_n->setObjectName("menuT_y_ch_n");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuT_y_ch_n->menuAction());
        menuT_y_ch_n->addAction(action_caseMap);
        menuT_y_ch_n->addAction(action_fakeMqtt);

        retranslateUi(MainWindow);

        stackedWidget_connect->setCurrentIndex(1);
        stackedWidget_auto->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qu\341\272\243n l\303\275 t\341\273\247 \304\221i\341\273\207n", nullptr));
        action_caseMap->setText(QCoreApplication::translate("MainWindow", "Phi\303\252n b\341\272\243n ph\341\272\247n m\341\273\201m", nullptr));
        action_fakeMqtt->setText(QCoreApplication::translate("MainWindow", "Nh\303\240 ph\303\241t tri\341\273\203n", nullptr));
#if QT_CONFIG(shortcut)
        action_fakeMqtt->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_openMap->setToolTip(QCoreApplication::translate("MainWindow", "B\341\272\243n \304\221\341\273\223 t\341\273\247 \304\221i\341\273\207n", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_openMap->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "C\341\273\225ng USB", nullptr));
        pushButton_scanCabinet->setText(QCoreApplication::translate("MainWindow", "K\341\272\277t n\341\273\221i c\341\273\225ng COM", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_refresh->setToolTip(QCoreApplication::translate("MainWindow", "L\303\240m m\341\273\233i ", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_refresh->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Ch\306\260a k\341\272\277t n\341\273\221i v\341\273\233i t\341\273\247 \304\221i\341\273\207n...</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ch\341\272\277 \304\221\341\273\231 ho\341\272\241t \304\221\341\273\231ng", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "T\303\252n t\341\273\247", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ng\306\260\341\273\241ng c\303\240nh b\303\241o", nullptr));
        timeEdit_timeStart->setDisplayFormat(QCoreApplication::translate("MainWindow", "h:mm", nullptr));
        timeEdit_timeStop->setDisplayFormat(QCoreApplication::translate("MainWindow", "h:mm", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\304\221\341\272\277n", nullptr));
        radioButton_on->setText(QCoreApplication::translate("MainWindow", "B\341\272\255t", nullptr));
        radioButton_off->setText(QCoreApplication::translate("MainWindow", "T\341\272\257t", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Th\341\273\235i gian \304\221\341\273\223ng b\341\273\231", nullptr));
        radioButton_auto->setText(QCoreApplication::translate("MainWindow", "T\341\273\261 \304\221\341\273\231ng", nullptr));
        radioButton_manual->setText(QCoreApplication::translate("MainWindow", "Th\341\273\247 c\303\264ng", nullptr));
        pushButton_sendConfig->setText(QCoreApplication::translate("MainWindow", "C\303\240i \304\221\341\272\267t", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_connectCabinet->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_connectCabinet->setText(QCoreApplication::translate("MainWindow", "K\341\272\277t n\341\273\221i", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_import->setToolTip(QCoreApplication::translate("MainWindow", "N\341\272\241p file d\341\273\257 li\341\273\207u t\341\273\247 \304\221i\341\273\207n", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_import->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_export->setToolTip(QCoreApplication::translate("MainWindow", "Xu\341\272\245t file d\341\273\257 li\341\273\207u t\341\273\247 \304\221i\341\273\207n", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_export->setText(QString());
        menuT_y_ch_n->setTitle(QCoreApplication::translate("MainWindow", "T\303\271y ch\341\273\215n", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
