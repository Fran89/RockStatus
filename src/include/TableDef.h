#ifndef TABLEDEF_H
#define TABLEDEF_H

#define Tnet 0
#define Tsta 1
#define Ttim 3
#define Ttcq 4
#define Tvol 5
#define Ttem 6
#define Thum 7
#define Tcpu 8
#define Tdsk 9

enum dataType {
    ClockQuality,
    ClockPhase,
    VoltageB,
    VoltageS,
    CurrentS,
    Temperature,
    Humidity,
    CPU,
    Disk
};

#define Ncol 10

#endif // TABLEDEF_H
