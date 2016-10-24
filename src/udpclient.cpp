#include "udpclient.h"

UdpClient::UdpClient(QObject *parent):
    QUdpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(proccessData()));
    debug = false;
}

// Pass pending datagram to EW Message Manager for proccessing
void UdpClient::proccessData(){
    // To be executed if we have recieved a UDP Packet
    while (this->hasPendingDatagrams()) {
        // Declare some QByteArrays
        QByteArray data;
        data.resize(this->pendingDatagramSize());

        // Get the Packet put the data in an Arrayl
        this->readDatagram(data.data(),data.size());

        //qDebug() << sizeof(data);
        msgProcessor proc(data);
        connect(&proc,SIGNAL(finished()),&proc,SLOT(deleteLater()));
        connect(&proc,SIGNAL(dataOut(QString,QString,dataType,qint32,QDateTime)),this,SLOT(retreiveData(QString,QString,dataType,qint32,QDateTime)));
        proc.run();
        data.clear();
    }
}

void UdpClient::setDebug(bool dbg){
    debug = dbg;
}

void UdpClient::retreiveData(QString sta, QString net, dataType dt, qint32 value, QDateTime time){
    // re-emit basically... to lazy to do it another way
    //qDebug() << sta << dt << value;
    emit dataReceived(sta, net, dt, value, time);
}
