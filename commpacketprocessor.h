#ifndef COMMPACKETPROCESSOR_H
#define COMMPACKETPROCESSOR_H

#include <QSharedPointer>
#include <QObject>

#include "commpacket.h"

class CommServer;

class CommPacketProcessor : public QObject
{
    Q_OBJECT

    friend class CommServer;
protected:
    inline CommPacketProcessor() {}

    virtual void processData(QByteArray) =0;

signals:
    void packetParsed(CommPacketRef);
    
};

class RawPacketProcessor : public CommPacketProcessor
{
protected:
    inline void processData(QByteArray data) {
        emit packetParsed(CommPacketRef((CommPacket*)new RawCommPacket(data)));
    }
};

#endif // COMMPACKETPROCESSOR_H
