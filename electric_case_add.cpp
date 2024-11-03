#include "electric_case_add.h"
#include "ui_electric_case_add.h"
#include "qt_utils.h"
#include "QMessageBox"
#include "QTimer"
#include "qt_utils.h"

electric_case_add::electric_case_add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::electric_case_add)
{
    ui->setupUi(this);
    setFixedSize(size());
    setModal(true);

    setLineEditSnFomartOnly(ui->lineEdit_caseName, 32);
    setLineEditNumberFloatOnly(ui->lineEdit_caseLat, -90, 90, 15);
    setLineEditNumberFloatOnly(ui->lineEdit_caseLon, -180, 180, 15);

    connect(ui->pushButton_cancel, &QPushButton::clicked, this, [&]{hide();});
}

electric_case_add::~electric_case_add()
{
    delete ui;
}

void electric_case_add::on_pushButton_confirm_clicked()
{
    bool ok;

    if(ui->lineEdit_caseLat->text().isEmpty() || ui->lineEdit_caseLon->text().isEmpty() || ui->lineEdit_caseName->text().isEmpty()){

        QMessageBox::critical(this, "Lỗi", "Vui long nhập đủ thông tin");
        return;
    }
    QString name = ui->lineEdit_caseName->text();
    float lat = ui->lineEdit_caseLat->text().toFloat(&ok);
    float lon = ui->lineEdit_caseLon->text().toFloat(&ok);
    QString des = ui->textEdit_caseDes->toPlainText();
    ui->pushButton_confirm->setEnabled(0);
    QTimer::singleShot(3000, [&](){
        ui->pushButton_confirm->setEnabled(1);
    });

    if(QMessageBox::question(this, "Xác nhận thêm tủ điện mới", "Tên: " + name + "\nĐịa chỉ: " + getAddressFromLatLon(lat, lon)) == QMessageBox::No){
        return;
    }

    emit addCaseInfoSig(name, lat, lon, des);
    hide();
}

