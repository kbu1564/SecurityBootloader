#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "Device.h"
#include "packet/BootingRequestPacket.h"

int BootingRequestPacket::parser(char* buff, int size)
{
    int deviceType = *((int *) buff);
    char* macAddr = buff + 4;

    this->mGroupMacAddr = macAddr;

    return 0;
}

char* BootingRequestPacket::encode(int* size)
{
    int protocol = BOOTING_REQUEST;
    const char* macAddr = this->mGroupMacAddr.c_str();
    int buffSize = 8 + this->mGroupMacAddr.length() + 1;

    char* buff = new char[512];
    memcpy(buff + 0, &protocol, 4);
    memcpy(buff + 4, &buffSize, 4);
    memcpy(buff + 8, macAddr, buffSize - 8);

    return buff;
}

int BootingRequestPacket::execute()
{
    vector<Device> *devs = &(this->mGroups->find(this->mGroupMacAddr)->second);

    // 부모 클라이언트 찾기
    for (vector<Device>::iterator iter = devs->begin(); iter != devs->end(); iter++) {
        if (iter->getDeviceType() == PHONE) {
            if (iter->send(this) == -1) {
                return -1;
            }
            break;
        }
    }
    return 0;
}

