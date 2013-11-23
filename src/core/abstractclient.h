#ifndef CLIENT_H
#define CLIENT_H

#include <taskpool.h>

using namespace TaskScheduler;

namespace NexusComm {

class AbstractClientBackend;
class AbstractDataPacket;

class AbstractClient : public TaskPool
{
    Q_OBJECT
public:
    ~AbstractClient();

protected:
    explicit AbstractClient(AbstractClientBackend*);

public slots:
    void processData(QByteArray&);

signals:
    void packetReceived(AbstractDataPacket*);

private:
    AbstractClientBackend* _acb;
};

}

#endif // CLIENT_H
