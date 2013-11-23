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

QMAKE_CXXFLAGS += -std=c++11

# Versioning
include(version.pri)

# Project Files
DEFINES += NEXUSCOMM_LIBRARY

HEADERS += \
    core/abstractclient.h \
    core/abstractclientbackend.h \
    core/abstractpacketprocessor.h \
    core/abstractdataprocessor.h \
    core/abstractserver.h

SOURCES += \
    core/abstractclient.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../extern/TaskScheduler/release/ -lTaskScheduler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../extern/TaskScheduler/debug/ -lTaskScheduler
else:unix: LIBS += -L$$OUT_PWD/../extern/TaskScheduler/ -lTaskScheduler

INCLUDEPATH += $$PWD/../extern/TaskScheduler
DEPENDPATH += $$PWD/../extern/TaskScheduler
