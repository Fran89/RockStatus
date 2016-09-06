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
        qDebug() << myTrace->trh2.net << myTrace->trh2.sta << myTrace->trh2.chan
                 << QDateTime::fromTime_t((time_t) myTrace->trh2.starttime).toString("yyyy/MM/dd HH:mm:ss")
                 << QDateTime::fromTime_t((time_t) myTrace->trh2.endtime).toString("yyyy/MM/dd HH:mm:ss")
                 << myTrace->trh2.datatype;


        char *tracedata;
        int test;
        tracedata = (char*) myTrace + sizeof(TRACE2_HEADER);
        memcpy(&test,tracedata,4);
        qDebug() << test;
    }
}
