#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map_view.h"
#include "fake_mqtt.h"
#include <QCloseEvent>
#include "sm_mqtt_client.h"

#define MQTT_SYNC_TOPIC "electric_cabinet/reponse"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void newCaseInfoMsg(QString name, caseData_t data);
    void mqttSendMsgSig(QString topic, QString msg);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent (QCloseEvent *event);

private slots:
    void on_action_caseMap_triggered();

    void on_action_fakeMqtt_triggered();

    void on_mqttReiceive(QString _topic, QString _msg);

    void on_configCaseInfo(QString name, caseData_t data);

private:
    static void publish_cb(void** state, struct mqtt_response_publish *publish);
    Ui::MainWindow *ui;

    map_view m_mapView;
    fake_mqtt* m_fakeMqtt = new fake_mqtt(this);

    sm_mqtt_client_t* m_mqttClient = nullptr;

    QTimer* timer = new QTimer(this);
};
#endif // MAINWINDOW_H
