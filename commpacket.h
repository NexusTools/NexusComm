#ifndef COMMPACKET_H
#define COMMPACKET_H

#pragma GCC diagnostic ignored "-Wreorder"

#include <QSharedPointer>
#include <QDataStream>

class CommPacket
{
public:
    virtual QByteArray rawData() =0;
    virtual ~CommPacket() {}

protected:
    inline CommPacket() {}

};

class RawCommPacket : public CommPacket, public QDataStream
{
    friend class RawPacketProcessor;
public:
    virtual ~RawCommPacket() {}
    QByteArray rawData() {return _data;}

protected:
    inline RawCommPacket(QByteArray data) : _data(data), QDataStream(&_data, QIODevice::ReadWrite) {}


private:
    QByteArray _data;
};

typedef QSharedPointer<CommPacket> CommPacketRef;

#endif // COMMPACKET_H
