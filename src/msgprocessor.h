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
#include <include/TableDef.h>

class msgProcessor : public QThread
{
    Q_OBJECT
public:
    msgProcessor(QByteArray myData);
    ~msgProcessor();

    void run();
    PACKET *packet;
    QByteArray data;

signals:
    void dataOut(QString sta, QString net,dataType dt, qint32 value, QDateTime time);
};

#endif // MSGPROCESSOR_H
