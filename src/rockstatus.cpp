#include "rockstatus.h"
#include "ui_rockstatus.h"

RockStatus::RockStatus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RockStatus)
{
    ui->setupUi(this);
}

RockStatus::~RockStatus()
{
    delete ui;
}
