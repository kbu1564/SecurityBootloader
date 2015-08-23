#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "packet/PingDevicePacket.h"

int PingDevicePacket::parser(const char* buff, const int size)
{
    return 0;
}

char* PingDevicePacket::encode(int* size)
{
    //int ping = 0xFFFF;
    char buff[100];
    sprintf(buff, "Yujoo 류주");

    int protocol = PING_DEVICE;
    // 전체 패킷 길이
    int bufflen = 8 + strlen(buff) + 1;//sizeof(ping);
    char *buff = new char[100];
    memcpy(buff + 0, (char *)&protocol, 4);
    memcpy(buff + 4, (char *)&bufflen, 4);
    memcpy(buff + 8, (char *)&ping, bufflen - 8);

    *size = bufflen;

    return buff;
}

int PingDevicePacket::execute()
{
    return 0;
}

