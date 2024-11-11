#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sm_logger.h"
#include "QMessageBox"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <string>
#include <QSerialPortInfo>
#include "qt_utils.h"
#include "QInputDialog"

#define TAG "main"

MainWindow* g_mainWindow = nullptr;

int64_t get_tick_count(){
    return GetTickCount();
}

void log_put(const char* _log){
    qDebug() << _log << "\n";
    emit g_mainWindow->showLogSig(QString::fromUtf8(_log) + "\n");
}

int32_t MainWindow::mb_master_send_if(const uint8_t* _data, int32_t _len, int32_t _timeout, void* _arg){
    MainWindow* _this = (MainWindow*)_arg;
    return _this->m_serialPort->send(_data, _len, _timeout);
}

int32_t MainWindow::mb_master_recv_if(uint8_t* _buf, int32_t _len, int32_t _timeout, void* _arg){
    MainWindow* _this = (MainWindow*)_arg;
    return _this->m_serialPort->read(_buf, _len, _timeout);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    g_mainWindow = this;

    ui->setupUi(this);
    sm_logger_init(log_put, LOG_LEVEL_DEBUG);
    LOG_INF(TAG, "Start application");
    setWindowIcon(QIcon(":/Resource/images/logo_cty.jpg"));

    ui->pushButton_openMap->setIcon(QIcon(":/Resource/images/map_icon_btn.png"));
    ui->pushButton_openMap->setIconSize(ui->pushButton_openMap->size());

    ui->pushButton_refresh->setIcon(QIcon(":/Resource/images/refresh_btn.png"));
    ui->pushButton_refresh->setIconSize(ui->pushButton_refresh->size());

    ui->pushButton_export->setIcon(QIcon(":/Resource/images/export.png"));
    ui->pushButton_export->setIconSize(ui->pushButton_export->size()/1.5);

    ui->pushButton_import->setIcon(QIcon(":/Resource/images/import.png"));
    ui->pushButton_import->setIconSize(ui->pushButton_import->size()/1.5);

    setFixedSize(size());

    // m_mapView->show();
    // m_fakeMqtt->show();
    sm_mqtt_client_connection_info_t info = {.broker_addr = "test.mosquitto.org", .port = "1883"};

    connect(this, &MainWindow::mqttOnConnecting, m_mapView, &map_view::on_mqttConnecting);
    connect(ui->radioButton_manual ,&QRadioButton::clicked, this, [&]{ui->stackedWidget_auto->setCurrentIndex(1);});
    connect(ui->radioButton_auto ,&QRadioButton::clicked, this, [&]{ui->stackedWidget_auto->setCurrentIndex(0);});

    setLineEditNumberIntergerOnly(ui->lineEdit_settingThreadHold, 0, 100*10000);
    setLineEditNumberIntergerOnly(ui->lineEdit_settingSyncTime, 0, 60*60*24);
    setLineEditSnFomartOnly(ui->lineEdit_settingSn, 32);

    m_mqttClient = sm_mqtt_client_create(info, publish_cb);
    if(!m_mqttClient){
        LOG_ERR(TAG, "Mqtt client error, recreate it");
        m_mqttClient = sm_mqtt_client_create(info, publish_cb);
        emit mqttOnConnecting(0);
    }else{
        elapsed_timer_pass(&m_connect_timer);
        timer->setInterval(1);
        connect(timer, &QTimer::timeout, [&]() {
            if(!m_isSubscribed && !elapsed_timer_get_remain(&m_connect_timer)){
                if(sm_mqtt_client_subscribe(m_mqttClient, MQTT_SYNC_TOPIC) >= 0){
                    emit mqttOnConnecting(1);
                    m_isSubscribed = true;
                }else{
                    m_isSubscribed = false;
                    emit mqttOnConnecting(0);
                    LOG_ERR(TAG, "Cannot subscribe to topic %s", MQTT_SYNC_TOPIC);
                }
                elapsed_timer_resetz(&m_connect_timer, 2000);
                return;
            }
            sm_mqtt_client_process(m_mqttClient);
        });
        timer->start();
    }

    connect(m_fakeMqtt, &fake_mqtt::mqttReceiveMsg, this, &MainWindow::on_mqttReiceive);
    connect(this, &MainWindow::mqttSendMsgSig, m_fakeMqtt, &fake_mqtt::on_mqttSendMsg);
    connect(this, &MainWindow::showLogSig, m_fakeMqtt, &fake_mqtt::on_showLog);

    connect(this, &MainWindow::mqttSendMsgSig, this, &MainWindow::on_mqttSend);

    connect(this, &MainWindow::newCaseInfoMsg, m_mapView, &map_view::on_newCaseMsg);
    connect(m_mapView, &map_view::configCaseInfo, this, &MainWindow::on_configCaseInfo);

    m_mb_master = sm_mb_master_create(mb_master_send_if, mb_master_recv_if, this);

    ui->pushButton_connectCabinet->setEnabled(0);
    ui->pushButton_sendConfig->setEnabled(0);
    ui->stackedWidget_connect->setCurrentIndex(0);
    ui->stackedWidget_auto->setCurrentIndex(0);

    if(!m_mb_master){
        LOG_ERR(TAG, "Cannot create modbus master");
    }

    on_pushButton_refresh_clicked();

}

MainWindow::~MainWindow()
{
    delete m_fakeMqtt;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this, "Thoát ứng dụng", "Dữ liệu của bạn sẽ được lưu") == QMessageBox::No){
        event->ignore();
        return;
    }
    m_mapView->saveConfig();
    delete m_fakeMqtt;
}

void MainWindow::on_action_caseMap_triggered()
{
    // m_mapView->show();
}


void MainWindow::on_action_fakeMqtt_triggered()
{
    bool ok;
    QString password = QInputDialog::getText(
        nullptr,
        "Yêu cầu nhập mật khẩu",
        "Vui lòng nhập mật khẩu:",
        QLineEdit::Password, // Cách hiển thị để nhập mật khẩu (ẩn ký tự)
        "",
        &ok
        );

    if (ok && !password.isEmpty()) {
        qDebug() << "Mật khẩu đã nhập là:" << password;
        if(password == QString("vuonglk123")){
            m_fakeMqtt->show();
        }

    } else {
        qDebug() << "Người dùng đã hủy hoặc không nhập mật khẩu.";
    }
}

void MainWindow::on_mqttReiceive(QString _topic, QString _msg)
{
    LOG_INF(TAG, "Reiceive msg - topic %s, msg: %s", _topic.toStdString().c_str(), _msg.toStdString().c_str());

    QJsonDocument jsonDoc = QJsonDocument::fromJson(_msg.toUtf8());

    if (!jsonDoc.isObject()) {
            LOG_INF(TAG, "Msg is not valid json");
        return;
    }

    int trim_size = QString(MQTT_SYNC_TOPIC).size() -1;
    QString name = _topic.mid(trim_size, _topic.size() - trim_size);
    QJsonObject jsonObj = jsonDoc.object();

    caseData_t data;
    data.m_err = jsonObj.value("err_code").toInt();
    data.m_syncTime = jsonObj.value("sync_time").toInt();
    data.m_isAuto = jsonObj.value("auto").toInt();
    data.m_phaseA = jsonObj.value("phase_1").toInt();
    data.m_phaseB = jsonObj.value("phase_2").toInt();
    data.m_phaseC = jsonObj.value("phase_3").toInt();
    data.m_threadHold = jsonObj.value("thread_hold").toInt();
    data.m_startTime = jsonObj.value("start_time").toString();
    data.m_stopTime = jsonObj.value("stop_time").toString();

    emit newCaseInfoMsg(name, data);
}

void MainWindow::on_configCaseInfo(QString name, caseData_t data)
{
    LOG_INF(TAG, "Now config case via mqtt !!");
    QString topic = "electric_cabinet/command/" + name + "";

    QString jsonString = QString(
                             "{\n"
                             "    \"auto\": %1,\n"
                             "    \"state\": %2,\n"
                             "    \"thread_hold\": %3,\n"
                             "    \"start_time\": \"%4\",\n"
                             "    \"stop_time\": \"%5\",\n"
                             "    \"sync_time\": %6\n"
                             "}"
                             )
                             .arg(data.m_isAuto)
                             .arg(data.m_state)
                             .arg(data.m_threadHold)
                             .arg(data.m_startTime)
                             .arg(data.m_stopTime)
                             .arg(data.m_syncTime);

    emit mqttSendMsgSig(topic, jsonString);
}

void MainWindow::on_mqttSend(QString _topic, QString _msg)
{
    LOG_INF(TAG, "Send mqtt: topic %s, msg %s", _topic.toStdString().c_str(), _msg.toStdString().c_str());


    if(sm_mqtt_client_publish(m_mqttClient, _topic.toStdString().c_str(), _msg.toStdString().c_str(), _msg.size()) >= 0){
        QMessageBox::information(this, "Xác nhận điều khiển", "Gửi lệnh điều khiển thành công");
    }else{
        QMessageBox::critical(this, "Xác nhận điều khiển", "Gửi lệnh điều khiển thất bại");
    }
}

void MainWindow::publish_cb(void **state, mqtt_response_publish *publish)
{
    char msg_buff[publish->application_message_size];
    char topic_buff[publish->topic_name_size];

    memcpy(msg_buff, publish->application_message, publish->application_message_size);
    memcpy(topic_buff, publish->topic_name, publish->topic_name_size);


    QString msg, topic;

    for(int i = 0; i < publish->topic_name_size; i++){
        topic.append(topic_buff[i]);
    }

    for(int i = 0; i < publish->application_message_size; i++){
        msg.append(msg_buff[i]);
    }

    LOG_INF(TAG, "Real mqtt recv topic %s, msg %s", topic.toStdString().c_str(), msg.toStdString().c_str());

    emit g_mainWindow->on_mqttReiceive(topic, msg);
}

void MainWindow::enable_config_ui(bool _enable)
{

}


void MainWindow::on_pushButton_openMap_clicked()
{
    m_mapView->showMaximized();
    if(!m_mqttClient){
        QMessageBox::warning(this, "Kết nối mạng bị mất", "Vui lòng khởi động lại ứng dụng");
    }
}


void MainWindow::on_pushButton_refresh_clicked()
{
    LOG_INF(TAG, "Load com list");
    ui->comboBox_comList->clear();
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        ui->comboBox_comList->addItem(port.portName());
    }
}


void MainWindow::on_pushButton_scanCabinet_clicked()
{
    if(!m_serialPort){
        QString com = ui->comboBox_comList->currentText();
        if(ui->comboBox_comList->currentText().isEmpty()){
            LOG_WRN(TAG, "Not select com yet");
            return;
        }
        m_serialPort = new SerialPort(com.toStdString());
        if(m_serialPort->open() < 0){
            QMessageBox::critical(this, "Lỗi", "Không thể mở " + com);
            delete m_serialPort;
            m_serialPort = nullptr;
            return;
        }

        ui->pushButton_scanCabinet->setText("Ngắt kết nối cổng COM");
        ui->pushButton_connectCabinet->setEnabled(1);
        ui->pushButton_sendConfig->setEnabled(0);
        ui->stackedWidget_connect->setCurrentIndex(0);
        ui->stackedWidget_auto->setCurrentIndex(0);
    }else{
        m_serialPort->close();
        delete m_serialPort;
        m_serialPort = nullptr;

        ui->pushButton_scanCabinet->setText("Kết nối cổng COM");
        ui->pushButton_connectCabinet->setEnabled(0);
        ui->pushButton_sendConfig->setEnabled(0);
        ui->stackedWidget_connect->setCurrentIndex(0);
        ui->stackedWidget_auto->setCurrentIndex(0);
    }
}


void MainWindow::on_pushButton_connectCabinet_clicked()
{
    if(!m_serialPort){
        QMessageBox::critical(this, "Lỗi", "Chưa mở cổng COM");
        return;
    }

    uint16_t reg[35];

    int ret = sm_sv_mb_master_read_hold_regs(m_mb_master, 1, 0, 35, reg);
    if(ret != MODBUS_ERROR_NONE){
        QMessageBox::warning(this, "Không thể kết nối đến tủ điện", "Vui lòng kiểm tra lại kết nối");
        ui->stackedWidget_connect->setCurrentIndex(0);
        ui->pushButton_sendConfig->setEnabled(0);
        return;
    }

    ui->stackedWidget_connect->setCurrentIndex(1);
    setting_info_t info;

    memcpy(&info, reg, sizeof(setting_info_t));

    ui->lineEdit_settingSn->setText(QString::fromUtf8(info.m_sn));
    ui->lineEdit_settingSyncTime->setText(QString::number(info.m_sync_time));
    ui->lineEdit_settingThreadHold->setText(QString::number(info.m_cur_thread_hold));
    if(info.m_auto){
        ui->radioButton_auto->setChecked(1);
        ui->stackedWidget_auto->setCurrentIndex(0);
    }else{
        ui->stackedWidget_auto->setCurrentIndex(1);
        ui->radioButton_manual->setChecked(1);
    }


    ui->timeEdit_timeStart->setTime(QTime::fromString(QString::fromUtf8((char*)info.m_start_time, 5), "HH:mm"));
    ui->timeEdit_timeStop->setTime(QTime::fromString(QString::fromUtf8((char*)info.m_stop_time, 5), "HH:mm"));
    if(info.m_state){
        ui->radioButton_on->setChecked(1);
    }else{
        ui->radioButton_off->setChecked(1);
    }

    ui->pushButton_sendConfig->setEnabled(1);
}


void MainWindow::on_pushButton_sendConfig_clicked()
{
    if(!m_serialPort){
        QMessageBox::critical(this, "Lỗi", "Chưa mở cổng COM");
        return;
    }

    bool ok;

    setting_info_t info;
    info.m_auto = ui->radioButton_auto->isChecked();
    info.m_cur_thread_hold = ui->lineEdit_settingThreadHold->text().toInt(&ok);
    memcpyFromLineEdit(ui->lineEdit_settingSn, (uint8_t*)info.m_sn, 32);
    info.m_state = ui->radioButton_on->isChecked();
    info.m_sync_time = ui->lineEdit_settingSyncTime->text().toInt(&ok);

    QString time;
    memset(info.m_start_time, 0, 8);
    memset(info.m_stop_time, 0, 8);
    time = ui->timeEdit_timeStart->time().toString("HH:mm");
    memcpy(info.m_start_time, time.toStdString().c_str(), qMin(8, time.size()));
    time = ui->timeEdit_timeStop->time().toString("HH:mm");
    memcpy(info.m_stop_time, time.toStdString().c_str(), qMin(8, time.size()));


    LOG_INF(TAG, "Setting to cabinet %s", info.m_sn);
    LOG_INF(TAG, "Thread hold: %d", info.m_cur_thread_hold);
    LOG_INF(TAG, "Mode: %s", info.m_auto?"Auto":"Manual");
    LOG_INF(TAG, "State: %s", info.m_state?"On":"Off");
    LOG_INF(TAG, "Auto from: %s to %s", info.m_start_time, info.m_stop_time);
    LOG_INF(TAG, "Sync time: %d", info.m_sync_time);


    if(QMessageBox::question(this, "Xác nhận cài đặt", QString("Bạn có muốn cài đặt tủ điện %1").arg(info.m_sn)) == QMessageBox::No){
        return;
    }


    uint16_t reg[35] = {0,};
    memcpy(reg, &info, sizeof(setting_info_t));

    int ret = sm_sv_mb_master_write_multi_regs(m_mb_master, 1, 0, 35, reg);
    if(ret != MODBUS_ERROR_NONE){
        QMessageBox::warning(this, "Cài đặt thất bại", QString("Kiểm tra kết nối với tủ điện %1").arg(info.m_sn));
    }else{
        QMessageBox::information(this, "Cài đặt thành công", QString("Cài đặt thành công tủ điện %1").arg(info.m_sn));
    }
}

