#ifndef COMMSERVER_H
#define COMMSERVER_H

#include <QVariantMap>
#include <QObject>

#include "commpacketprocessor.h"
#include "commclient.h"
#include "def.h"


class CommServer : public QObject
{
    Q_OBJECT
public:
    virtual NexusComm::SocketType type() const =0;
    inline bool isRunning() const{return running;}
    inline void setConfig(QVariantMap config) {initConfig(config);}

public slots:
    inline void reloadConfig() {
        setRunning(config<bool>("enabled", true));
        reloadConfigImpl();
    }

    inline bool start() {
        if(running)
            return true;
        running = startImpl();
        if(running)
            emit started();
        return running;
    }
    inline bool stop() {
        if(!running)
            return true;
        running = !stopImpl();
        if(!running)
            emit stopped();
        return running;
    }
    inline bool setRunning(bool r) {
        if(r)
            return start();
        else
            return stop();
    }
    
signals:
    void clientConnected(CommClientRef);
    void started();
    void stopped();

protected:
    inline CommServer() {}

    template<typename T>
    inline T config(QString key, T def =T()) const
    {
        QVariant variant = currentConfig.value(key);
        if(variant.canConvert<T>())
            return variant.value<T>();
        variant = defaults.value(key);
        if(variant.canConvert<T>())
            return variant.value<T>();
        return def;
    }
    void initConfig(QVariantMap config) {
        currentConfig = config;
    }
    void setDefaults(QVariantMap def) {
        defaults = def;
    }

    inline virtual void reloadConfigImpl() {}
    virtual bool startImpl() =0;
    virtual bool stopImpl() =0;

protected slots:
    inline void receivedData(QByteArray data) {processor->processData(data);}

private:
    bool running;
    QString error;
    QVariantMap defaults;
    QVariantMap currentConfig;
    CommPacketProcessor* processor;
};

#endif // COMMSERVER_H
