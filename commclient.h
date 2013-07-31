#ifndef COMMCLIENT_H
#define COMMCLIENT_H

#include <QSharedPointer>
#include <QObject>

#include "commpacket.h"

// P = CommPacket, R = CommPacketProcessor
template <class P, class R>
class CommClient
{
public:
    inline void sendPacket(CommPacket& packet) {sendData(packet.rawData());}

protected:
    inline CommClient(R* processor =0) : _processor(processor ? processor : new R()) {}
    inline virtual ~CommClient() {delete _processor;}

    virtual void processPacket(P&) =0;
    virtual void sendData(QByteArray&) =0;

private:
    R* _processor;
};

#endif // COMMCLIENT_H
