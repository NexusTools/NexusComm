#-------------------------------------------------
#
# Project created by QtCreator 2013-07-26T10:10:05
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = NexusComm
TEMPLATE = lib

DEFINES += NEXUSCOMM_LIBRARY

SOURCES += \
    commservergroup.cpp

HEADERS += \
    commserver.h \
    def.h \
    commservergroup.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
