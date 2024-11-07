#include "map_view.h"
#include "ui_map_view.h"
#include "QGeoCoordinate"
#include "sm_logger.h"
#include "QMessageBox"
#include "qt_utils.h"
#include <QPixmap>
#include <QPainter>
#include <QBrush>
#include <QColor>


#define TAG "mapView"

#define NOT_ACTIVE_COLOR "red"
#define NOMAR_COLOR      "lightgreen"
#define ERROR_COLOR      "yellow"

static QIcon createCircleIcon(const QColor& color, int diameter = 16) {
    QPixmap pixmap(diameter, diameter);
    pixmap.fill(Qt::transparent); // Đảm bảo nền trong suốt

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(color));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(0, 0, diameter, diameter);

    return QIcon(pixmap);
}

static void changeCircleColor(QListWidgetItem* item, const QColor& newColor) {
    QIcon newIcon = createCircleIcon(newColor);
    item->setIcon(newIcon);
}

static QString buildCaseDataDes(const caseData_t &data) {
    QDateTime receivedTime = QDateTime::currentDateTime();
    return QString("\n\n"
                   "Trạng thái: %1\n"
                   "Chế độ hoạt động: %2\n"
                   "Mã lỗi: %3\n"
                   "Thời gian nhận: %4\n"
                   "Pha A: %5\n"
                   "Pha B: %6\n"
                   "Pha C: %7\n"
                   "Ngưỡng cảnh báo: %8\n"
                   "Thời gian bật: %9\n"
                   "Thời gian tắt: %10")
        .arg(data.m_state?"Bật":"Tắt")
        .arg(data.m_isAuto?"Tự động":"Thủ công")
        .arg(data.m_err)
        .arg(receivedTime.toString("HH:mm:ss"))
        .arg(data.m_phaseA)
        .arg(data.m_phaseB)
        .arg(data.m_phaseC)
        .arg(data.m_threadHold)
        .arg(SecToQTime(data.m_startTime).toString("HH:mm:ss"))
        .arg(SecToQTime(data.m_stopTime).toString("HH:mm:ss"));
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
    connect(&m_settingDialog, &case_setting::confirmSetting, this, &map_view::configCaseInfo);

    auto rootObject = ui->quickWidget_mapView->rootObject();
    if (rootObject) {
        connect(this, SIGNAL(addNewMarkSig(QVariant,QVariant,QVariant,QVariant)), rootObject, SLOT(addNewMark(QVariant,QVariant,QVariant,QVariant)));
        connect(this, SIGNAL(removeAllMarkSig()), rootObject, SLOT(removeAllMark()));
        connect(this, SIGNAL(removeMarkSig(QVariant)), rootObject, SLOT(removeMark(QVariant)));
        connect(this, SIGNAL(changeMarkColorSig(QVariant,QVariant)), rootObject, SLOT(changeMarkColor(QVariant,QVariant)));
        connect(this, SIGNAL(moveMapCenterSig(QVariant,QVariant)), rootObject, SLOT(moveMapCenterTo(QVariant,QVariant)));
    } else {
        qWarning() << "Failed to find root object in QML";
    }

    setWindowIcon(QIcon(":/Resource/images/logo_cty.jpg"));

    QSettings settings("YourCompany", "YourApp");
    settings.beginGroup("Vuong");

    int size = settings.beginReadArray("caseList");
    m_caseList.clear(); // Xóa dữ liệu hiện có để load dữ liệu mới

    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        caseInfo_t newCase;
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

    caseInfo_t info = {.m_name = _name, .m_location = {.m_lat = _lat, .m_lon = _lon}, .m_color = _color, .m_description = _desScrip};
    m_caseList.push_back(info);

    QListWidgetItem* item = new QListWidgetItem(createCircleIcon(QColor(_color)), _name);
    item->setForeground(QColor("black"));
    item->setToolTip(_desScrip + "\n Chưa kết nối !!!");

    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);

    ui->listWidget_caseList->addItem(item);
    ui->listWidget_caseList->setCurrentItem(item);

    emit addNewMarkSig(_lat, _lon, _color, _name);
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
                    changeCircleColor(item, QColor(_color));
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

void map_view::on_newCaseMsg(QString name, caseData_t data)
{
    LOG_INF(TAG, "New msg from %s, err %d", name.toStdString().c_str(), data.m_err);


    auto caseInfo = getCaseByName(ui->listWidget_caseList->currentItem()->text());
    if(!caseInfo.m_info){
        return;
    }

    for(auto &item: m_caseList){
        if(item.m_name == name){
            item.m_data = data;
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
            LOG_INF(TAG, "Cabin %s is online!!!", name.toStdString().c_str());
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
    auto caseInfo = getCaseByName(ui->listWidget_caseList->currentItem()->text());
    if(!caseInfo.m_info){
        return;
    }

    if(!caseInfo.m_info->m_isOnline){
        if(QMessageBox::question(this, "Xác nhận điều khiển", "Tủ điện "+caseInfo.m_info->m_name+" chưa được kết nối, có muốn tiếp tục") == QMessageBox::No){
            return;
        }
    }
    m_settingDialog.startSetting(*caseInfo.m_info);
}


void map_view::on_listWidget_caseList_currentTextChanged(const QString &currentText)
{
    for(auto item : m_caseList){
        if(item.m_name == currentText){
            mapViewChangeCenter(item.m_location.m_lat, item.m_location.m_lon);
        }
    }
    for (int i = 0; i < ui->listWidget_caseList->count(); ++i) {
        QListWidgetItem* currentItem = ui->listWidget_caseList->item(i);
        QFont font = currentItem->font();
        if (ui->listWidget_caseList->currentItem() == currentItem) {
            font.setUnderline(true); // Gạch chân mục đang chọn
        } else {
            font.setUnderline(false); // Bỏ gạch chân mục không chọn
        }
        currentItem->setFont(font);
    }
}

caseGet_t map_view::getCaseByName(QString name)
{
    caseGet_t caseGet;
    for(int index = 0; index < m_caseList.size(); index++){
        if(name == m_caseList[index].m_name){
            caseGet.m_info = &m_caseList[index];
            caseGet.m_index = index;
        }
    }
    for (int i = 0; i < ui->listWidget_caseList->count(); ++i) {
        QListWidgetItem *child = ui->listWidget_caseList->item(i);
        if(child->text() == name){
            caseGet.m_display = child;
        }
    }
    return caseGet;
}


