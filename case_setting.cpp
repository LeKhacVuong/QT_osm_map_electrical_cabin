#include "case_setting.h"
#include "ui_case_setting.h"
#include "sm_logger.h"
#include "qt_utils.h"
#include "QMessageBox"

#define TAG "setting_dialog"

case_setting::case_setting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::case_setting)
{
    ui->setupUi(this);
    setFixedSize(size());
    setModal(true);

    connect(ui->pushButton_cancel, &QPushButton::clicked, this, [&]{hide();});

    setLineEditNumberIntergerOnly(ui->lineEdit_syncTime, 0, 60*60*24);
    setLineEditNumberIntergerOnly(ui->lineEdit_threadHold, 0, 100*1000);
}

case_setting::~case_setting()
{
    delete ui;
}

void case_setting::startSetting(caseInfo_t _caseInfo)
{

    m_caseSetting = _caseInfo;

    ui->label_caseName->setText(_caseInfo.m_name);
    ui->lineEdit_threadHold->setText(QString::number(_caseInfo.m_data.m_threadHold));
    ui->comboBox_opMode->setCurrentIndex(_caseInfo.m_data.m_isAuto > 0);
    ui->comboBox_state->setCurrentIndex(_caseInfo.m_data.m_state > 0);
    ui->timeEdit_start->setTime(SecToQTime(_caseInfo.m_data.m_startTime));
    ui->timeEdit_stop->setTime(SecToQTime(_caseInfo.m_data.m_stopTime));
    LOG_INF(TAG, "Setting time %d to %d", _caseInfo.m_data.m_startTime, _caseInfo.m_data.m_stopTime);
    ui->lineEdit_syncTime->setText(QString::number(_caseInfo.m_data.m_syncTime));

    show();
}

void case_setting::on_pushButton_confirm_clicked()
{
    caseInfo_t info;
    QString name = m_caseSetting.m_name;
    bool ok;

    info.m_data.m_isAuto = ui->comboBox_opMode->currentIndex();
    info.m_data.m_state = ui->comboBox_state->currentIndex();
    info.m_data.m_threadHold = ui->lineEdit_threadHold->text().toInt(&ok);
    info.m_data.m_syncTime = ui->lineEdit_syncTime->text().toInt(&ok);
    info.m_data.m_startTime = QTimeToSec(ui->timeEdit_start->time());
    info.m_data.m_stopTime = QTimeToSec(ui->timeEdit_stop->time());

    if(QMessageBox::question(this, "Xác nhận điều khiển", "Gửi lệnh điều khiển đến tủ: " + name) == QMessageBox::No){
        return;
    }

    emit confirmSetting(name, info.m_data);

    hide();
}

