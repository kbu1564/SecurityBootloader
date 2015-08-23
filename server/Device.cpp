#include "Global.h"
#include "Protocol.h"

#include "Packet.h"
#include "PacketParser.h"
#include "Device.h"
#include "Group.h"

int Device::send(Packet* p)
{
    if (this->mSock != 0) {
        int bufflen = 0;
        char* buff = p->encode(&bufflen);

        int nwrite = write(this->mSock, buff, bufflen);
        delete buff;

        return nwrite;
    }
    return -1;
}

