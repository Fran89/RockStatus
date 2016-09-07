#ifndef STNINFO_H
#define STNINFO_H

#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QMap>
#include "include/TableDef.h"

class Stn : public QObject {
    Q_OBJECT
public:
    Stn(QObject *parent = 0);
    Stn(QString name, QObject *parent = 0);
    Stn(QString name, QString netw, QObject *parent = 0);

    QString stnname;
    QString net;

    QDateTime latest;

    double deg;
    double hum;
    qint32 cpu;
    qint32 dsk;
    double vvb;
    qint32 lcq;
    qint32 lce;
    double vep;
    double vec;

    void setName(QString name);
    void setNet(QString netw);

public slots:

    void addData(dataType dt, qint32 value, QDateTime time);
};

class StnInfo : public QObject
{
    Q_OBJECT
public:
    explicit StnInfo(QObject *parent = 0);
    void addStation(QString sta, QString net);
    bool searchStation(QString sta, QString net);
    QMap<QString,Stn*> stations;

signals:
   void addedStn();
   void updatedStn();

public slots:
    void addData(QString sta, QString net,dataType dt, qint32 value, QDateTime time);
};

#endif // STNINFO_H
