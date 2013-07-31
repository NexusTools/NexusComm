#-------------------------------------------------
#
# Project created by QtCreator 2013-07-26T10:10:05
#
#-------------------------------------------------

# Qt Modules
QT       += network

QT       -= gui

# Project Information
TARGET = NexusComm
TEMPLATE = lib

# Versioning
include(version.pri)

# Project Files
DEFINES += NEXUSCOMM_LIBRARY

SOURCES +=

HEADERS += \
    commclient.h \
    commpacketprocessor.h \
	commpacket.h \
    commrawpacket.h
