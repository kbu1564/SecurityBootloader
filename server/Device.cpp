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
    cout << "sendto : " << buff << endl;
    cout << this->getIpAddr() << ":" << this->getPort() << endl;

    if (this->mSock != 0) {
        int nwrite = 0;
        while (nwrite < bufflen) {
            nwrite += write(this->mSock, (char *)(buff + nwrite), bufflen - nwrite);
        }
        cout << "sendto : " << nwrite << "bytes" << endl;
    }
    return 0;
}

