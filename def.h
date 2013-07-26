#ifndef DEF_H
#define DEF_H

namespace NexusComm {

    enum SocketType {
        Unknown,
        TcpSocket,
        UdpSocket,
        LocalSocket,

        User = 0x50
    };

    enum CommunicationType {
        Unknown,

        DataStream,
        BasicPacket,
        DetailedPacket,

        User = 0x50
    };

}

#endif // DEF_H
