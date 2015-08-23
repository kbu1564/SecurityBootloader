#include "Global.h"
#include "Protocol.h"

#include "Packet.h"
#include "PacketParser.h"
#include "Device.h"
#include "Group.h"

int Device::send(Packet* p)
{
    int bufflen = 0;
    char* buff = p->encode(&bufflen);

    if (this->mSock != 0) {
        int nsend = 0;
        while (nsend < bufflen) {
            nsend += send(this->mSock, (char *)(buff + nsend), bufflen - nsend);
        }
    }
    return 0;
}

