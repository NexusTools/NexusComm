#ifndef COMMPACKET_H
#define COMMPACKET_H

#pragma GCC diagnostic ignored "-Wreorder"

#include <QSharedPointer>
#include <QDataStream>

class CommPacket
{
public:
    virtual QByteArray& rawData() =0;
    virtual ~CommPacket() {}

protected:
    inline CommPacket() {}

};

#endif // COMMPACKET_H
