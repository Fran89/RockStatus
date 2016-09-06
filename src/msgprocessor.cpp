#include "msgprocessor.h"

msgProcessor::msgProcessor(QByteArray myData):
    data(myData)
{
    memcpy(&packet,data,data.size());
}

void msgProcessor::run(){
    // If the Packet is Complete
    if (packet.lastOfMsg && packet.fragNum == 0 ) {

        // Put data in new tracebuff struct
        TracePacket *myTrace = new TracePacket;
        memcpy(myTrace,packet.text,sizeof(packet.text));

        if(!TRACE2_HEADER_VERSION_IS_VALID(&myTrace->trh2)){
            qDebug() << "Exit: header not good";
            return;
        }
        if(WaveMsg2MakeLocal(&myTrace->trh2) < 0){
           qDebug() << "Error making local";
           return;
        }
        QString sta(myTrace->trh2.sta);
        QString net(myTrace->trh2.net);
        QString chan(myTrace->trh2.chan);
        if(chan == "deg" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, Temperature, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }
        if(chan == "hum" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, Humidity, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }
        if(chan == "cpu" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, CPU, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }
        if(chan == "dsk" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, Disk, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }
        if(chan == "vvb" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, VoltageB, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }
        if(chan == "lcq" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, ClockQuality, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }
        if(chan == "lce" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, ClockPhase, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }
        if(chan == "vep" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, VoltageS, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }
        if(chan == "vec" ){
            char *tracedata;
            qint32 val;
            tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
            memcpy(&val,tracedata,sizeof(qint32));
            emit dataOut(sta, net, CurrentS, val, QDateTime::fromTime_t((time_t) myTrace->trh2.starttime));
            return;
        }

        return;
    }
}
