#ifndef COMMSERVER_H
#define COMMSERVER_H

#include <QObject>
#include "def.h"

class CommClient;

class CommServer : public QObject
{
    Q_OBJECT
public:
    virtual NexusComm::SocketType type() const =0;
    
signals:
    void clientConnected(CommClient*);
    
private:
    QList<QObject*> _listeningPorts;
};

#endif // COMMSERVER_H
