#ifndef TCPCOMMSERVER_H
#define TCPCOMMSERVER_H

#include "commserver.h"

#include <QTcpServer>

class TcpCommServer : public CommServer
{
    Q_OBJECT
protected:
    inline void reloadConfigImpl() {}

private:
    QTcpServer server;
};

#endif // TCPCOMMSERVER_H
