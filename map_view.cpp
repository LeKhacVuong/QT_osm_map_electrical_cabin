#include "map_view.h"
#include "ui_map_view.h"
#include "QGeoCoordinate"
#include "sm_logger.h"
#include "QMessageBox"
#include "qt_utils.h"

#define TAG "mapView"

#define NOT_ACTIVE_COLOR "black"
#define NOMAR_COLOR      "lightgreen"
#define ERROR_COLOR      "red"

static QString buildCaseDataDes(const caseData &data) {
    QDateTime receivedTime = QDateTime::currentDateTime();
    return QString("\n\nMã lỗi: %1\n"
                   "Thời gian nhận: %2\n"
                   "Pha A: %3\n"
                   "Pha B: %4\n"
                   "Pha C: %5\n"
                   "Ngưỡng cảnh báo: %6"
                   "Thời gian bật: %7\n"
                   "Thời gian tắt: %8")
        .arg(data.m_err)
        .arg(receivedTime.toString("HH:mm:ss"))
        .arg(data.m_phaseA)
        .arg(data.m_phaseB)
        .arg(data.m_phaseC)
        .arg(data.m_threadHold)
        .arg(data.m_startTime)
        .arg(data.m_stopTime);
}

void map_view::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this, "Xác nhận đóng ứng dung", "Dữ liệu về tủ điện sẽ được lưu") == QMessageBox::No){
        event->ignore();
        return;
    }

    QSettings settings("YourCompany", "YourApp");
    settings.beginGroup("Vuong");

    settings.beginWriteArray("caseList");
    for (int i = 0; i < m_caseList.size(); ++i) {
        settings.setArrayIndex(i);
        settings.setValue("name", m_caseList.at(i).m_name);
        settings.setValue("lat", m_caseList.at(i).m_location.m_lat);
        settings.setValue("lon", m_caseList.at(i).m_location.m_lon);
        settings.setValue("des", m_caseList.at(i).m_description);
    }
    settings.endArray();
    settings.endGroup();
}

map_view::map_view(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::map_view)
{
    ui->setupUi(this);
    setFixedSize(size());

    ui->quickWidget_mapView->setSource(QUrl("qrc:/QmlMap.qml"));
    ui->quickWidget_mapView->show();
    connect(&m_addDialog, &electric_case_add::addCaseInfoSig, this, &map_view::on_userConfirmAddCase);

    auto rootObject = ui->quickWidget_mapView->rootObject();
    if (rootObject) {
        connect(this, SIGNAL(addNewMarkSig(QVariant,QVariant,QVariant)), rootObject, SLOT(addNewMark(QVariant,QVariant,QVariant)));
        connect(this, SIGNAL(removeAllMarkSig()), rootObject, SLOT(removeAllMark()));
        connect(this, SIGNAL(removeMarkSig(QVariant)), rootObject, SLOT(removeMark(QVariant)));
        connect(this, SIGNAL(changeMarkColorSig(QVariant,QVariant)), rootObject, SLOT(changeMarkColor(QVariant,QVariant)));
        connect(this, SIGNAL(moveMapCenterSig(QVariant,QVariant)), rootObject, SLOT(moveMapCenterTo(QVariant,QVariant)));
    } else {
        qWarning() << "Failed to find root object in QML";
    }

    QSettings settings("YourCompany", "YourApp");
    settings.beginGroup("Vuong");

    int size = settings.beginReadArray("caseList");
    m_caseList.clear(); // Xóa dữ liệu hiện có để load dữ liệu mới

    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        caseInfo newCase;
        newCase.m_name = settings.value("name").toString();
        newCase.m_location.m_lat = settings.value("lat").toDouble();
        newCase.m_location.m_lon = settings.value("lon").toDouble();
        newCase.m_description = settings.value("des").toString();
        mapViewAddCaseMark(newCase.m_name, newCase.m_location.m_lat, newCase.m_location.m_lon, NOT_ACTIVE_COLOR, newCase.m_description);
    }
    settings.endArray();
    settings.endGroup();

    LOG_INF(TAG, "Created map service");
}

map_view::~map_view()
{
    delete ui;
}

int map_view::mapViewAddCaseMark(QString _name, float _lat, float _lon, QString _color, QString _desScrip)
{
    for(auto item : m_caseList){
        if(_name == item.m_name){
            LOG_ERR(TAG, "Duplicate electric case, reject request!");
            QMessageBox::critical(this, "Lỗi", "Tên trạm đã tồn tại");
            return -1;
        }
    }

    caseInfo info = {.m_name = _name, .m_location = {.m_lat = _lat, .m_lon = _lon}, .m_color = _color, .m_description = _desScrip};
    m_caseList.push_back(info);

    QListWidgetItem *item = new QListWidgetItem(_name);
    item->setForeground(QColor(_color));
    item->setToolTip(_desScrip + "\n Chưa kết nối !!!");

    ui->listWidget_caseList->addItem(item);
    ui->listWidget_caseList->setCurrentItem(item);

    emit addNewMarkSig(_lat, _lon, _color);
    return 0;
}

int map_view::mapViewChangeCenter(float _lat, float _lon)
{
    emit moveMapCenterSig(_lat, _lon);
    return 0;
}

int map_view::mapViewRemoveCaseMark(QString _name)
{
    for(int index = 0; index < m_caseList.size(); index++){
        if(_name == m_caseList[index].m_name){
            m_caseList.erase(m_caseList.begin() + index);
            emit removeMarkSig(index);
            LOG_INF(TAG, "Just remove case name %s", _name.toStdString().c_str());
            return 0;
        }
    }

    LOG_ERR(TAG, "Cannot find case name %s to remove", _name.toStdString().c_str());
    return -1;
}

int map_view::mapViewChangeColorCaseMark(QString _name, QString _color)
{
    for(int index = 0; index < m_caseList.size(); index++){
        if(_name == m_caseList[index].m_name){
            emit changeMarkColorSig(index, _color);

            for (int i = 0; i < ui->listWidget_caseList->count(); ++i) {
                QListWidgetItem *item = ui->listWidget_caseList->item(i);
                if(item->text() == _name){
                    item->setForeground(QColor(_color));
                }
            }

            LOG_INF(TAG, "Just change case name %s to color %s", _name.toStdString().c_str(), _color.toStdString().c_str());
            return 0;
        }
    }

    LOG_ERR(TAG, "Cannot find case name %s to change color", _name.toStdString().c_str());
    return -1;
}

int map_view::mapViewRemoveAllCaseMark()
{

}

void map_view::on_newCaseMsg(QString name, caseData data)
{
    LOG_INF(TAG, "New msg from %s, err %d", name.toStdString().c_str(), data.m_err);

    for(auto item: m_caseList){
        if(item.m_name == name){
            if(data.m_err){
                mapViewChangeColorCaseMark(name, ERROR_COLOR);
            }else{
                mapViewChangeColorCaseMark(name, NOMAR_COLOR);
            }

            for (int i = 0; i < ui->listWidget_caseList->count(); ++i) {
                QListWidgetItem *child = ui->listWidget_caseList->item(i);
                if(child->text() == name){
                    child->setToolTip(item.m_description + buildCaseDataDes(data));
                }
            }
            item.m_isOnline = true;
        }
    }
}

void map_view::on_userConfirmAddCase(QString _name, float _lat, float _lon, QString _des)
{
    mapViewAddCaseMark(_name, _lat, _lon, NOT_ACTIVE_COLOR, "Mô tả: " + _des);
}

void map_view::on_pushButton_addCase_pressed()
{
    m_addDialog.show();
}


void map_view::on_pushButton_removeCase_clicked()
{
    QString name = ui->listWidget_caseList->currentItem()->text();

    if(QMessageBox::question(this, "Xác nhận xóa tủ điện", "Xóa tủ điện: " + name) == QMessageBox::No){
        return;
    }
    QListWidgetItem *item = ui->listWidget_caseList->takeItem(ui->listWidget_caseList->currentRow());
    delete item;
    mapViewRemoveCaseMark(name);
}

void map_view::on_pushButton_caseDetail_clicked()
{

}


void map_view::on_listWidget_caseList_currentTextChanged(const QString &currentText)
{
    for(auto item : m_caseList){
        if(item.m_name == currentText){
            mapViewChangeCenter(item.m_location.m_lat, item.m_location.m_lon);
        }
    }
}

