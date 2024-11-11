#include "fake_mqtt.h"
#include "ui_fake_mqtt.h"
#include "QTime"

fake_mqtt::fake_mqtt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fake_mqtt)
{
    ui->setupUi(this);
    setFixedSize(size());
    setWindowFlag(Qt::WindowCloseButtonHint, false);
    ui->listWidget_log->setWordWrap(true);

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

void fake_mqtt::on_showLog(QString msg)
{
    QTime::currentTime().toString();
    QListWidgetItem *item = new QListWidgetItem(QTime::currentTime().toString() + ": " + msg);
    ui->listWidget_log->addItem(item);
    if(ui->checkBox_auto_roll->isChecked()){
        ui->listWidget_log->scrollToBottom();
    }
}

