#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "packet/FindDevicePacket.h"

int FindDevicePacket::parser(const char* buff, const int size)
{
    return 0;
}

char* FindDevicePacket::encode(int* size)
{
    char *buff = new char[100];

    sprintf(buff, "This packet is FindDevicePacket!");
    *size = strlen(buff);

    return buff;
}

int FindDevicePacket::execute()
{
    return 0;
}

