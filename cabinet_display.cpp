#include "cabinet_display.h"
#include "ui_cabinet_display.h"

cabinet_display::cabinet_display(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cabinet_display)
{
    ui->setupUi(this);
}

cabinet_display::~cabinet_display()
{
    delete ui;
}
