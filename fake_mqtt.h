#ifndef FAKE_MQTT_H
#define FAKE_MQTT_H

#include <QDialog>

namespace Ui {
class fake_mqtt;
}

class fake_mqtt : public QDialog
{
    Q_OBJECT

public:
    explicit fake_mqtt(QWidget *parent = nullptr);
    ~fake_mqtt();

signals:

    void mqttReceiveMsg(QString _topic, QString _msg);

private slots:
    void on_pushButton_publish_clicked();

    void on_mqttSendMsg(QString topic, QString msg);

private:
    Ui::fake_mqtt *ui;
};

#endif // FAKE_MQTT_H
