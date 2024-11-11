#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map_view.h"
#include "fake_mqtt.h"
#include <QCloseEvent>
#include "sm_mqtt_client.h"
#include "sm_mb_master_impl.h"
#include "SerialPort.h"
#include "elapsed_timer.h"

#define MQTT_SYNC_TOPIC "electric_cabinet/update/#"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

typedef struct{
    char m_sn[32];
    uint32_t m_cur_thread_hold;
    uint32_t m_sync_time;
    uint8_t m_start_time[8];
    uint8_t m_stop_time[8];
    uint8_t m_auto;
    uint8_t m_state;
}setting_info_t;

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void newCaseInfoMsg(QString name, caseData_t data);
    void mqttSendMsgSig(QString topic, QString msg);
    void mqttOnConnecting(uint8_t stt);
    void showLogSig(QString log);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static int32_t mb_master_send_if(const uint8_t* _data, int32_t _len, int32_t _timeout, void* _arg);

    static int32_t mb_master_recv_if(uint8_t* _buf, int32_t _len, int32_t _timeout, void* _arg);

protected:
    void closeEvent (QCloseEvent *event);

private slots:
    void on_action_caseMap_triggered();

    void on_action_fakeMqtt_triggered();

    void on_mqttReiceive(QString _topic, QString _msg);

    void on_configCaseInfo(QString name, caseData_t data);

    void on_mqttSend(QString _topic, QString _msg);

    void on_pushButton_openMap_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_scanCabinet_clicked();

    void on_pushButton_connectCabinet_clicked();

    void on_pushButton_sendConfig_clicked();

private:
    static void publish_cb(void** state, struct mqtt_response_publish *publish);

    void enable_config_ui(bool _enable);

    Ui::MainWindow *ui;

    map_view* m_mapView = new map_view(this);
    fake_mqtt* m_fakeMqtt = new fake_mqtt();

    sm_mqtt_client_t* m_mqttClient = nullptr;

    QTimer* timer = new QTimer(this);

    uint8_t m_isSubscribed = 0;

    SerialPort* m_serialPort = nullptr;

    sm_mb_master_t* m_mb_master = nullptr;

    elapsed_timer_t m_connect_timer;

};
#endif // MAINWINDOW_H
