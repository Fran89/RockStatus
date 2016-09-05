#include "udpconfig.h"
#include "ui_udpconfig.h"

UdpConfig::UdpConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UdpConfig)
{
    ui->setupUi(this);
    myFolder = new QFileDialog(this);
    myFolder->setFileMode(QFileDialog::Directory);
    myFolder->setOption(QFileDialog::ShowDirsOnly);
    myFolder->setDirectory(QDir::home());
    QHostAddress localhost;
    localhost = QHostAddress::AnyIPv4;
    connect(ui->foldttrig,SIGNAL(pressed()),myFolder,SLOT(show()));
    //connect(myFolder,SIGNAL(currentChanged(QString)),ui->folderName,SLOT(setText(QString)));
    connect(myFolder,SIGNAL(directoryEntered(QString)),ui->folderName,SLOT(setText(QString)));
    connect(myFolder,SIGNAL(accepted()),myFolder,SLOT(hide()));
    ui->UDPIP->setText(localhost.toString());
    ui->UDPPort->setText("16005");
    ui->folderName->setText(QDir::home().path());
    this->setWindowTitle("UDP Configuration");
}

UdpConfig::~UdpConfig()
{
    delete ui;
}

void UdpConfig::accept(){

    config.MyIPAddress = ui->UDPIP->text();
    config.Port = ui->UDPPort->text();
    config.LogFolder = ui->folderName->text();
    QDialog::accept();
}
