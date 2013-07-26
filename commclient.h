#ifndef COMMCLIENT_H
#define COMMCLIENT_H

#include <QSharedPointer>
#include <QObject>

#include "commpacket.h"

class CommClient : public QObject
{
    Q_OBJECT
public:
    inline void sendPacket(CommPacket& packet) {sendData(packet.rawData());}

protected:
    inline CommClient() {}

    void processPacket(CommPacketRef);
    virtual void sendData(QByteArray);

};

typedef QSharedPointer<CommClient> CommClientRef;

#endif // COMMCLIENT_H
