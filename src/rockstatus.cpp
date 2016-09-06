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
    configured = false;

    // UdpClient
    myClient = new UdpClient;
    connected = false;

    // Status
    status = new QLabel;
    ui->statusBar->addWidget(status);
    setStatus("Welcome to RockStatus");


}

RockStatus::~RockStatus()
{
    delete ui;
}

void RockStatus::on_actionConnection_triggered()
{
    myConfig->show();
    connect(myConfig,SIGNAL(accepted()),this,SLOT(sockConfig()));
}

void RockStatus::setStatus(QString mstatus){
    status->setText(mstatus);
}

void RockStatus::sockConfig(){
    configured = true;
    if(!connected){
        quint16 Port = myConfig->config.Port.toUInt();
        QHostAddress IP(myConfig->config.MyIPAddress.toString());
        if (myClient->bind(IP,Port)) {
            connected = true;
            setStatus("Connected!");

            //appendToDebugBrowser("K2Status connected");
        }
        else {
            connected = false;
            setStatus("Could not connect, is the port being used?");
            //appendToDebugBrowser("K2Status could not connect");
        }
    }

}
