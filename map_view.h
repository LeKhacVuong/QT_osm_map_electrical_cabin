#ifndef MAP_VIEW_H
#define MAP_VIEW_H

#include <QDialog>
#include <QVector>
#include <QMetaObject>
#include <QQuickWidget>
#include <QQuickItem>
#include <QVariant>
#include <QtCore>
#include <QtGui>
#include <QtQuick>
#include "electric_case_add.h"
#include "case_data_define.h"
#include "case_setting.h"

namespace Ui {
class map_view;
}

class map_view : public QDialog
{
    Q_OBJECT

protected:
    void closeEvent (QCloseEvent *event);

public:
    explicit map_view(QWidget *parent = nullptr);
    ~map_view();

    int mapViewAddCaseMark(QString _name, float _lat, float _lon, QString _color, QString _desScrip);

    int mapViewChangeCenter(float _lat, float _lon);

    int mapViewRemoveCaseMark(QString _name);

    int mapViewChangeColorCaseMark(QString _name, QString _color);

    int mapViewRemoveAllCaseMark();

public slots:
    void on_newCaseMsg(QString name, caseData_t data);

signals:
    void addNewMarkSig(QVariant, QVariant, QVariant, QVariant);
    void removeMarkSig(QVariant);
    void changeMarkColorSig(QVariant, QVariant);
    void moveMapCenterSig(QVariant, QVariant);
    void removeAllMarkSig();
    void configCaseInfo(QString name, caseData_t data);

private slots:
    void on_userConfirmAddCase(QString _name, float _lat, float _lon, QString _des);

    void on_pushButton_addCase_pressed();

    void on_pushButton_removeCase_clicked();

    void on_pushButton_caseDetail_clicked();

    void on_listWidget_caseList_currentTextChanged(const QString &currentText);


private:
    caseGet_t getCaseByName(QString name);

    Ui::map_view *ui;
    QVector<caseInfo_t> m_caseList;
    electric_case_add m_addDialog;
    case_setting m_settingDialog;
};

#endif // MAP_VIEW_H
