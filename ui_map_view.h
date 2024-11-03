/********************************************************************************
** Form generated from reading UI file 'map_view.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_VIEW_H
#define UI_MAP_VIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_map_view
{
public:
    QListWidget *listWidget_caseList;
    QQuickWidget *quickWidget_mapView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_addCase;
    QPushButton *pushButton_removeCase;
    QPushButton *pushButton_caseDetail;

    void setupUi(QDialog *map_view)
    {
        if (map_view->objectName().isEmpty())
            map_view->setObjectName("map_view");
        map_view->resize(1254, 735);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ZoomFitBest));
        map_view->setWindowIcon(icon);
        listWidget_caseList = new QListWidget(map_view);
        listWidget_caseList->setObjectName("listWidget_caseList");
        listWidget_caseList->setGeometry(QRect(20, 10, 271, 451));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        listWidget_caseList->setFont(font);
        quickWidget_mapView = new QQuickWidget(map_view);
        quickWidget_mapView->setObjectName("quickWidget_mapView");
        quickWidget_mapView->setGeometry(QRect(310, 10, 931, 711));
        quickWidget_mapView->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);
        layoutWidget = new QWidget(map_view);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 480, 231, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_addCase = new QPushButton(layoutWidget);
        pushButton_addCase->setObjectName("pushButton_addCase");
        pushButton_addCase->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        pushButton_addCase->setFont(font1);

        verticalLayout->addWidget(pushButton_addCase);

        pushButton_removeCase = new QPushButton(layoutWidget);
        pushButton_removeCase->setObjectName("pushButton_removeCase");
        pushButton_removeCase->setMaximumSize(QSize(16777215, 50));
        pushButton_removeCase->setFont(font1);

        verticalLayout->addWidget(pushButton_removeCase);

        pushButton_caseDetail = new QPushButton(layoutWidget);
        pushButton_caseDetail->setObjectName("pushButton_caseDetail");
        pushButton_caseDetail->setMaximumSize(QSize(16777215, 50));
        pushButton_caseDetail->setFont(font1);

        verticalLayout->addWidget(pushButton_caseDetail);


        retranslateUi(map_view);

        QMetaObject::connectSlotsByName(map_view);
    } // setupUi

    void retranslateUi(QDialog *map_view)
    {
        map_view->setWindowTitle(QCoreApplication::translate("map_view", "B\341\272\243n \304\221\341\273\223 t\341\273\247 \304\221i\341\273\207n", nullptr));
        pushButton_addCase->setText(QCoreApplication::translate("map_view", "Th\303\252m t\341\273\247 \304\221i\341\273\207n", nullptr));
        pushButton_removeCase->setText(QCoreApplication::translate("map_view", "X\303\263a t\341\273\247 \304\221i\341\273\207n", nullptr));
        pushButton_caseDetail->setText(QCoreApplication::translate("map_view", "\304\220i\341\273\201u khi\341\273\203n t\341\273\247 \304\221i\341\273\207n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class map_view: public Ui_map_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_VIEW_H
