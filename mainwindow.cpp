#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sm_logger.h"
#include "QMessageBox"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <string>

#define TAG "main"

void log_put(const char* _log){
    qDebug() << _log << "\n";
}

MainWindow* g_mainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sm_logger_init(log_put, LOG_LEVEL_DEBUG);
    LOG_INF(TAG, "Start application");
    m_mapView.show();
    m_fakeMqtt->show();
    g_mainWindow = this;
    sm_mqtt_client_connection_info_t info = {.broker_addr = "test.mosquitto.org", .port = "1883"};

    m_mqttClient = sm_mqtt_client_create(info, publish_cb);

    sm_mqtt_client_subscribe(m_mqttClient, MQTT_SYNC_TOPIC);

    timer->setInterval(1);
    connect(timer, &QTimer::timeout, [&]() {
        sm_mqtt_client_process(m_mqttClient);
    });
    timer->start();

    connect(m_fakeMqtt, &fake_mqtt::mqttReceiveMsg, this, &MainWindow::on_mqttReiceive);
    connect(this, &MainWindow::mqttSendMsgSig, m_fakeMqtt, &fake_mqtt::on_mqttSendMsg);

    connect(this, &MainWindow::newCaseInfoMsg, &m_mapView, &map_view::on_newCaseMsg);
    connect(&m_mapView, &map_view::configCaseInfo, this, &MainWindow::on_configCaseInfo);


    connect(&m_mapView, &map_view::hide, this, [&]{delete this;});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this, "Exit app ?", "App will be close") == QMessageBox::No){
        event->ignore();
        return;
    }
    delete m_fakeMqtt;
}

void MainWindow::on_action_caseMap_triggered()
{
    m_mapView.show();
}


void MainWindow::on_action_fakeMqtt_triggered()
{
    m_fakeMqtt->show();
}

void MainWindow::on_mqttReiceive(QString _topic, QString _msg)
{
    LOG_INF(TAG, "Reiceive msg - topic %s, msg: %s", _topic.toStdString().c_str(), _msg.toStdString().c_str());

    QJsonDocument jsonDoc = QJsonDocument::fromJson(_msg.toUtf8());

    if (!jsonDoc.isObject()) {
            LOG_INF(TAG, "Msg is not valid json");
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    caseData_t data;
    QString name = jsonObj.value("sn").toString();
    data.m_err = jsonObj.value("err_code").toInt();
    data.m_syncTime = jsonObj.value("sync_time").toInt();
    data.m_isAuto = jsonObj.value("auto").toInt();
    data.m_phaseA = jsonObj.value("phase_a").toInt();
    data.m_phaseB = jsonObj.value("phase_b").toInt();
    data.m_phaseC = jsonObj.value("phase_c").toInt();
    data.m_threadHold = jsonObj.value("thread_hold").toInt();
    data.m_startTime = jsonObj.value("start_time").toInt();
    data.m_stopTime = jsonObj.value("stop_time").toInt();

    emit newCaseInfoMsg(name, data);
}

void MainWindow::on_configCaseInfo(QString name, caseData_t data)
{
    LOG_INF(TAG, "Now config case via mqtt !!");
    QString topic = "electric_cabinet/" + name + "/control";

    QString jsonString = QString(
                             "{\n"
                             "    \"thread_hold\": %1,\n"
                             "    \"state\": %2,\n"
                             "    \"auto\": %3,\n"
                             "    \"start_time\": %4,\n"
                             "    \"stop_time\": %5,\n"
                             "    \"sync_time\": %6\n"
                             "}"
                             ).arg(data.m_threadHold)
                             .arg(data.m_state)
                             .arg(data.m_isAuto)
                             .arg(data.m_startTime)
                             .arg(data.m_stopTime)
                             .arg(data.m_syncTime);

    emit mqttSendMsgSig(topic, jsonString);
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

