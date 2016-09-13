#ifndef TABLEDEF_H
#define TABLEDEF_H

#define Tnet 0
#define Tsta 1
#define Ttim 2
#define Ttcq 3
#define Ttph 4
#define Tvol 5
#define Tvos 6
#define Tcur 7
#define Ttem 8
#define Thum 9
#define Tcpu 10
#define Tdsk 11

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

#define Ncol 12

#endif // TABLEDEF_H
