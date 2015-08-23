#ifndef PACKETPARSER_H_
#define PACKETPARSER_H_

class PacketParser
{
public:
    Packet*  decode(const char* buff);
    Protocol decodeProtocol(const char* buff);

private:
    Packet*  __getPacketObject(Protocol protocol);
};

#endif

