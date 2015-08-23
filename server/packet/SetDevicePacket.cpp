#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "packet/SetDevicePacket.h"

int SetDevicePacket::parser(const char* buff, const int size)
{
    return 0;
}

char* SetDevicePacket::encode(int* size)
{
    return NULL;
}

int SetDevicePacket::execute()
{
    return 0;
}

