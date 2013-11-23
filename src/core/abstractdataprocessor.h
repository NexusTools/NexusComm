#ifndef ABSTRACTDATAPROCESSOR_H
#define ABSTRACTDATAPROCESSOR_H

#include <QThread>

namespace NexusComm {

class AbstractDataProcessor : public QThread
{
public:
    inline explicit AbstractDataProcessor() {
        start();
    }

protected:
    virtual void processDataImpl(QByteArray);

private slots:
    void pushData(QByteArray);

signals:
    void decodedPacket(QByteArray, QVariant meta);

protected:
    QByteArray dataBuffer;
    AbstractClientBackend* _backend;
};

}

#endif // ABSTRACTDATAPROCESSOR_H
