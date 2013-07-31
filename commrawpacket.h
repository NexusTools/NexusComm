#ifndef RAWPACKET_H
#define RAWPACKET_H

#include "commclient.h"
#include "commpacketprocessor.h"

class RawPacketProcessor : public CommPacketProcessor<RawCommPacket>
{
protected:
    void processData(QByteArray&, quint64 id);
};

class RawCommPacket : public CommPacket, public QDataStream
{
    friend class RawPacketProcessor;
public:
    virtual ~RawCommPacket() {}
    QByteArray& rawData() {return _data;}

protected:
    inline RawCommPacket(QByteArray data =QByteArray()) : _data(data), QDataStream(&_data, QIODevice::ReadWrite) {}


private:
    QByteArray _data;
};

typedef CommClient<RawCommPacket, RawPacketProcessor> RawCommClient;

#endif // RAWPACKET_H
