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
        int nwrite = write(this->mSock, buff, bufflen);
        delete buff;

        return nwrite;
    }
    return -1;
}

