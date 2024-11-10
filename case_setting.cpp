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

    connect(ui->radioButton_manual ,&QRadioButton::clicked, this, [&]{ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->radioButton_auto ,&QRadioButton::clicked, this, [&]{ui->stackedWidget->setCurrentIndex(1);});

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

    if(_caseInfo.m_data.m_isAuto){
        ui->radioButton_auto->setChecked(1);
    }else{
        ui->radioButton_manual->setChecked(1);
    }

    if(_caseInfo.m_data.m_state){
        ui->radioButton_on->setChecked(1);
    }else{
        ui->radioButton_of->setChecked(1);
    }

    ui->stackedWidget->setCurrentIndex(_caseInfo.m_data.m_isAuto);
    ui->timeEdit_start->setTime(QTime::fromString(_caseInfo.m_data.m_startTime, "HH:mm"));
    ui->timeEdit_stop->setTime(QTime::fromString(_caseInfo.m_data.m_stopTime, "HH:mm"));
    ui->lineEdit_syncTime->setText(QString::number(_caseInfo.m_data.m_syncTime));
    show();
}

void case_setting::on_pushButton_confirm_clicked()
{
    caseInfo_t info;
    QString name = m_caseSetting.m_name;
    bool ok;
    info.m_data.m_isAuto = ui->stackedWidget->currentIndex();
    info.m_data.m_state = ui->radioButton_on->isChecked();
    info.m_data.m_threadHold = ui->lineEdit_threadHold->text().toInt(&ok);
    info.m_data.m_syncTime = ui->lineEdit_syncTime->text().toInt(&ok);
    info.m_data.m_startTime = ui->timeEdit_start->time().toString("HH:mm");
    info.m_data.m_stopTime = ui->timeEdit_stop->time().toString("HH:mm");

    if(QMessageBox::question(this, "Xác nhận điều khiển", "Gửi lệnh điều khiển đến tủ: " + name) == QMessageBox::No){
        return;
    }
    hide();
    emit confirmSetting(name, info.m_data);
}

