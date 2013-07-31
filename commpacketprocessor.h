#ifndef COMMPACKETPROCESSOR_H
#define COMMPACKETPROCESSOR_H

#include <QByteArray>

class CommClient;
class CommServer;
class QIODevice;

template <class P>
class CommPacketProcessor
{

    friend class CommClient;
public:
    inline CommClient* client() const{return _client;}

protected:
    inline CommPacketProcessor() {}

    virtual void processData(QIODevice*, quint64 id) =0;
    void packetParsed(P&, quint64 id);

private:
    CommClient* _client;
};

#endif // COMMPACKETPROCESSOR_H
