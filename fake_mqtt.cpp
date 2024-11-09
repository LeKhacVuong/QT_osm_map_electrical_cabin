#include "fake_mqtt.h"
#include "ui_fake_mqtt.h"

fake_mqtt::fake_mqtt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fake_mqtt)
{
    ui->setupUi(this);
    setFixedSize(size());
    setWindowFlag(Qt::WindowCloseButtonHint, false);

}

fake_mqtt::~fake_mqtt()
{
    delete ui;
}

void fake_mqtt::on_pushButton_publish_clicked()
{
    emit mqttReceiveMsg(ui->lineEdit_topic->text(), ui->textEdit_msg->toPlainText());
}

void fake_mqtt::on_mqttSendMsg(QString topic, QString msg)
{
    QListWidgetItem *item = new QListWidgetItem("Topic: " + topic + "\nMsg: " + msg + "\n\n");
    ui->listWidget->addItem(item);
}

