#ifndef DEF_H
#define DEF_H

namespace NexusComm {

    enum SocketType {
        UnknownSocketType,
        TcpSocket,
        UdpSocket,
        LocalSocket,

        UserSocketType = 0x50
    };

    enum CommunicationType {
        DataStream,
        BasicPacket,
        DetailedPacket,

        UserCommType = 0x50
    };

}

#endif // DEF_H
