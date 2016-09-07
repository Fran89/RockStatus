#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QDateTime>
#include "include/ew_packet.h"
#include "include/TableDef.h"
#include "msgprocessor.h"

class UdpClient : public QUdpSocket
{
    Q_OBJECT
public:
    UdpClient(QObject *parent = 0);

public slots:
    void setDebug(bool);

private slots:
    void proccessData();
    void retreiveData(QString sta, QString net,dataType dt, qint32 value, QDateTime time);

private:
    bool debug;

signals:
    void dataReceived(QString sta, QString net,dataType dt, qint32 value, QDateTime time);

};

#endif // UDPCLIENT_H
