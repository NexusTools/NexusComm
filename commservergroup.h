#ifndef COMMSERVERGROUP_H
#define COMMSERVERGROUP_H

#include <QObject>

#include "commserver.h"
#include "def.h"

class CommServerGroup : public QObject
{
    Q_OBJECT
public:
    explicit CommServerGroup() {}

    inline void addServer(CommServer* srv) {
        connect(srv, SIGNAL(clientConnected(CommClientRef)), this, SLOT(passClient(CommClientRef)));
    }
    inline void removeServer(CommServer* srv) {
        connect(srv, SIGNAL(clientConnected(CommClientRef)), this, SLOT(passClient(CommClientRef)));
    }

    CommServer* listen(QString desc);

protected slots:
    inline void passClient(CommClientRef client) {emit clientConnected(client);}

signals:
    void clientConnected(CommClientRef client);

};

#endif // COMMSERVERGROUP_H
