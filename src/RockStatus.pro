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
    udpconfig.cpp

HEADERS  += rockstatus.h \
    udpconfig.h

FORMS    += rockstatus.ui \
    udpconfig.ui
