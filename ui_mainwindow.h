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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_caseMap;
    QAction *action_fakeMqtt;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuT_y_ch_n;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(920, 541);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        MainWindow->setWindowIcon(icon);
        action_caseMap = new QAction(MainWindow);
        action_caseMap->setObjectName("action_caseMap");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ZoomIn));
        action_caseMap->setIcon(icon1);
        action_fakeMqtt = new QAction(MainWindow);
        action_fakeMqtt->setObjectName("action_fakeMqtt");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 920, 22));
        menuT_y_ch_n = new QMenu(menubar);
        menuT_y_ch_n->setObjectName("menuT_y_ch_n");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuT_y_ch_n->menuAction());
        menuT_y_ch_n->addAction(action_caseMap);
        menuT_y_ch_n->addAction(action_fakeMqtt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qu\341\272\243n l\303\275 t\341\273\247 \304\221i\341\273\207n", nullptr));
        action_caseMap->setText(QCoreApplication::translate("MainWindow", "B\341\272\243n \304\221\341\273\223 l\341\272\257p \304\221\341\272\267t", nullptr));
        action_fakeMqtt->setText(QCoreApplication::translate("MainWindow", "Fake mqtt", nullptr));
#if QT_CONFIG(shortcut)
        action_fakeMqtt->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        menuT_y_ch_n->setTitle(QCoreApplication::translate("MainWindow", "T\303\271y ch\341\273\215n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
