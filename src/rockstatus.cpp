#include "rockstatus.h"
#include "ui_rockstatus.h"

RockStatus::RockStatus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RockStatus)
{
    // Setup UI
    ui->setupUi(this);
    ui->mainToolBar->hide();

    // UdpConfig
    myConfig = new UdpConfig;
}

RockStatus::~RockStatus()
{
    delete ui;
}
