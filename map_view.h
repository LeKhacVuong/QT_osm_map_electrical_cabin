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

typedef struct{
    int8_t m_err;
    int32_t m_phaseA;
    int32_t m_phaseB;
    int32_t m_phaseC;
    int32_t m_threadHold;
    uint32_t m_startTime;
    uint32_t m_stopTime;
}caseData;

typedef struct{
    QString m_name;
    struct{
        float m_lat;
        float m_lon;
    }m_location;
    QString m_color;
    QString m_description;
    bool m_isOnline;
}caseInfo;


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
    void on_newCaseMsg(QString name, caseData data);

signals:
    void addNewMarkSig(QVariant, QVariant, QVariant);
    void removeMarkSig(QVariant);
    void changeMarkColorSig(QVariant, QVariant);
    void moveMapCenterSig(QVariant, QVariant);

    void removeAllMarkSig();

private slots:
    void on_userConfirmAddCase(QString _name, float _lat, float _lon, QString _des);

    void on_pushButton_addCase_pressed();

    void on_pushButton_removeCase_clicked();

    void on_pushButton_caseDetail_clicked();

    void on_listWidget_caseList_currentTextChanged(const QString &currentText);

private:
    Ui::map_view *ui;
    QVector<caseInfo> m_caseList;
    electric_case_add m_addDialog;
};

#endif // MAP_VIEW_H
