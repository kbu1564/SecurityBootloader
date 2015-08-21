#include "Global.h"
#include "Protocol.h"

#include "Packet.h"
#include "PacketParser.h"

char* PacketParser::encode(Packet& p)
{
    return NULL;
}

Packet PacketParser::decode(const char* buff)
{
    Packet p;
    return p;
}

int PacketParser::decodeProtocol(const char* buff)
{
    return 0; 
}

