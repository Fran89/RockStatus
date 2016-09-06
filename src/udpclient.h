#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <include/ew_packet.h>
#include <msgprocessor.h>

class UdpClient : public QUdpSocket
{
    Q_OBJECT
public:
    UdpClient(QObject *parent = 0);

private slots:
    void proccessData();

};

#endif // UDPCLIENT_H
