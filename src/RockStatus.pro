#-------------------------------------------------
#
# Project created by QtCreator 2016-09-04T14:28:10
#
#-------------------------------------------------

QT       += core gui network xml printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RockStatus
TEMPLATE = app


SOURCES += main.cpp\
        rockstatus.cpp \
    udpconfig.cpp \
    udpclient.cpp \
    msgprocessor.cpp \
    swap.cpp \
    stninfo.cpp \
    metadatatable.cpp

HEADERS  += rockstatus.h \
    udpconfig.h \
    udpclient.h \
    msgprocessor.h \
    include/trace_buf.h \
    include/TableDef.h \
    include/ew_packet.h \
    swap.h \
    stninfo.h \
    metadatatable.h

FORMS    += rockstatus.ui \
    udpconfig.ui
