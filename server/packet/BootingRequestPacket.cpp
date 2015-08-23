#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "packet/BootingRequestPacket.h"

int BootingRequestPacket::parser(const char* buff, const int size)
{
    DeviceType deviceType = *((int *) buff);
    char* macAddr = buff + 4;

    this->mGroupMacAddr = macAddr;

    return 0;
}

char* BootingRequestPacket::encode(int* size)
{
    return NULL;
}

int BootingRequestPacket::execute()
{
    vector<Device> &devs = this->mGroups[this->mGroupMacAddr];

    return 0;
}

