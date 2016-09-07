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
    ui->actionDisconnect->setDisabled(true);
    connect(ui->actionDisconnect,SIGNAL(triggered(bool)),this,SLOT(onDisconnect()));

    // Sta Information
    myInfo = new StnInfo;
    connect(myClient,SIGNAL(dataReceived(QString,QString,dataType,qint32,QDateTime)),
            myInfo,SLOT(addData(QString,QString,dataType,qint32,QDateTime)));

    // Metadata Table
    myTable = new MetadataTable;
    myTable->setStationInfo(myInfo);
    connect(myInfo,SIGNAL(addedStn()),myTable,SLOT(addStaInformation()));
    connect(myInfo,SIGNAL(updatedStn()),myTable,SLOT(updateMetadata()));
    connect(myInfo,SIGNAL(updatedStn()),ui->tableView,SLOT(resizeColumnsToContents()));
    ui->tableView->setModel(myTable);

    // Status
    status = new QLabel;
    ui->statusBar->addWidget(status);
    setStatus("Welcome to RockStatus");

    //Debug Info
    debug = false;
    ui->textBrowser->hide();
    connect(ui->actionDebugMode,SIGNAL(triggered(bool)),this,SLOT(DebugToggle()));

}

// Toggle Debug Mode
void RockStatus::DebugToggle()
{
    if(debug){
        debug = false;
        emit sendDebug(debug);
        ui->textBrowser->hide();
        setStatus("Debug mode is off");
    } else {
        debug = true;
        emit sendDebug(debug);
        ui->textBrowser->show();
        setStatus("Debug mode is on");
    }
}

RockStatus::~RockStatus()
{
    delete ui;
}

void RockStatus::on_actionConnection_triggered()
{
    myConfig->show();
    connect(myConfig,SIGNAL(accepted()),this,SLOT(sockConfig()));
    connect(myConfig,SIGNAL(rejected()),this,SLOT(nothing()));
}

void RockStatus::setStatus(QString mstatus){
    status->setText(mstatus);
}

// Append to Debug Browser
void RockStatus::appendToDebugBrowser(const QString message)
{
    ui->textBrowser->append(message);
}

void RockStatus::nothing(){
    setStatus("Not Connected");
}

void RockStatus::onDisconnect(){
    if(connected){
        myClient->close();
        setStatus("Disconnected");
        connected = false;
        ui->actionConnection->setEnabled(true);
        ui->actionDisconnect->setDisabled(true);
    }
}

void RockStatus::sockConfig(){
    configured = true;
    if(!connected){
        quint16 Port = myConfig->config.Port.toUInt();
        QHostAddress IP(myConfig->config.MyIPAddress.toString());
        if (myClient->bind(IP,Port)) {
            connected = true;
            ui->actionConnection->setDisabled(true);
            ui->actionDisconnect->setEnabled(true);
            setStatus("Connected!");
            appendToDebugBrowser("RockStatus Connected to UDP");
        }
        else {
            connected = false;
            setStatus("Could not connect, is the port being used?");
            appendToDebugBrowser("RockStatus could not connect");
        }
    }

}
