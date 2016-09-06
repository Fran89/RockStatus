#ifndef MSGPROCESSOR_H
#define MSGPROCESSOR_H

#include <QObject>
#include <QThread>
#include <QByteArray>
#include <QDebug>
#include <QtEndian>
#include <QDateTime>
#include <swap.h>
#include <include/ew_packet.h>
#include <include/trace_buf.h>

class msgProcessor : public QThread
{
public:
    msgProcessor(QByteArray myData);
    void run();
    PACKET packet;
    QByteArray data;
};

#endif // MSGPROCESSOR_H
