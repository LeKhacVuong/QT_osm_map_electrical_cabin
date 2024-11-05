#include "case_setting.h"
#include "ui_case_setting.h"
#include "qt_utils.h"

case_setting::case_setting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::case_setting)
{
    ui->setupUi(this);
    setFixedSize(size());
    setModal(true);

    setLineEditNumberIntergerOnly(ui->lineEdit_syncTime, 0, 60*60*24);
    setLineEditNumberIntergerOnly(ui->lineEdit_threadHold, 0, 100*1000);
}

case_setting::~case_setting()
{
    delete ui;
}

void case_setting::startSetting(caseInfo_t _caseInfo)
{
    ui->label_caseName->setText(_caseInfo.m_name);
    ui->lineEdit_syncTime->setText(QString::number(_caseInfo.m_data.m_syncTime));
    ui->comboBox_opMode->setCurrentIndex(_caseInfo.m_data.m_isAuto > 0);
    ui->comboBox_state->setCurrentIndex(_caseInfo.m_data.m_state > 0);


}

void case_setting::on_pushButton_confirm_clicked()
{

}

