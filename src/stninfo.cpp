#include "stninfo.h"

Stn::Stn(QObject *parent):
    QObject(parent)
{
    deg = hum = cpu = dsk = vvb
    = lcq = lce = vep = vec = -1;
    latest.setTime_t(-1);
}

Stn::Stn(QString name, QObject *parent):
    QObject(parent), stnname(name)
{
    deg = hum = cpu = dsk = vvb
    = lcq = lce = vep = vec = -1;
    latest.setTime_t(-1);
}

Stn::Stn(QString name, QString netw, QObject *parent):
    QObject(parent), stnname(name), net(netw)
{
    deg = hum = cpu = dsk = vvb
    = lcq = lce = vep = vec = -1;
    latest.setTime_t(-1);
}

void Stn::addData(dataType dt, qint32 value, QDateTime time){
    if(dt == Temperature){
        deg = value/10.0;
    }
    if(dt == Humidity){
        hum = value/10.0;
    }
    if(dt == VoltageB){
        vvb = value/1000.0;
    }
    if(dt == VoltageS){
        vep = value/1000.0;
    }
    if(dt == CurrentS){
        vec = value/1000.0;
    }
    if(dt == CPU){
        cpu = value;
    }
    if(dt == Disk){
        dsk = value;
    }
    if(dt == ClockQuality){
        lcq = value;
    }
    if(dt == ClockPhase){
        lce = value/10.0;
    }

    latest = time;
}

void Stn::setName(QString name){
    stnname = name;
}

void Stn::setNet(QString netw){
    net = netw;
}

//==============================================================//

StnInfo::StnInfo(QObject *parent) : QObject(parent)
{

}

void StnInfo::addStation(QString sta, QString net){
    Stn *temp = new Stn;
    temp->setName(sta);
    temp->setNet(net);
    stations.insert(sta,temp);
    emit addedStn();
}

bool StnInfo::searchStation(QString sta, QString net){
    if(stations.contains(sta))
        return true;
    else {
        addStation(sta, net);
        return stations.contains(sta);
    }
    // We shouldn't reach here, there is an error;
    return false;
}

void StnInfo::addData(QString sta, QString net, dataType dt, qint32 value, QDateTime time){

    if(searchStation(sta, net)){
        Stn *current;
        current = stations.value(sta);
        current->addData(dt,value,time);
        emit updatedStn();
    }
}
