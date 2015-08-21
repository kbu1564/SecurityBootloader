#ifndef PACKETPARSER_H_
#define PACKETPARSER_H_

class PacketParser
{
public:
    char*    encode(Packet& p);
    Packet   decode(const char* buff);
    int      decodeProtocol(const char* buff);
};

#endif

