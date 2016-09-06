#include "udpclient.h"

UdpClient::UdpClient(QObject *parent):
    QUdpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(proccessData()));
}

// Pass pending datagram to EW Message Manager for proccessing
void UdpClient::proccessData(){
    // To be executed if we have recieved a UDP Packet
    while (this->hasPendingDatagrams()) {
        // Declare some QByteArrays
        QByteArray data;
        data.resize(this->pendingDatagramSize());

        // Get the Packet put the data in an Array
        this->readDatagram(data.data(),data.size());

        //qDebug() << sizeof(data);
        msgProcessor *proc = new msgProcessor(data);
        connect(proc,SIGNAL(finished()),proc,SLOT(deleteLater()));
        proc->run();
        data.clear();
    }
}