#ifndef PACKETPARSER_H_
#define PACKETPARSER_H_

class PacketParser
{
public:
    char*    encode(Packet& p);
    Packet   decode(const char* buff);
    Protocol decodeProtocol(const char* buff);
};

#endif

