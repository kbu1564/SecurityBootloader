#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "Device.h"
#include "packet/BootingDevicePacket.h"

int BootingDevicePacket::parser(char* buff, int size)
{
    this->mMacAddr = buff;

    return 0;
}

char* BootingDevicePacket::encode(int* size)
{
    int protocol = BOOTING_DEVICE;
    const char* buf = this->mMacAddr.c_str();
    int buffSize = 8 + this->mMacAddr.length() + 1;

    char* buff = new char[512];
    memcpy(buff + 0, &protocol, 4);
    memcpy(buff + 4, &buffSize, 4);
    memcpy(buff + 8, buf, buffSize - 8);

    *size = buffSize;

    return buff;
}

int BootingDevicePacket::execute()
{
    cout << "BootingDevicePacket::execute()" << endl;

    if (this->mGroups == NULL) {
        cout << "multimap< string, vector<Device> >* is nullptr!" << endl;
        return -1;
    }

    cout << "Booting MAC : " << this->mMacAddr << endl;

    multimap< string, vector<Device> >::iterator devs = this->mGroups->find(this->mMacAddr);
    if (devs != this->mGroups->end()) {
        vector<Device> *members = &(devs->second);
        // send to client -> BOOTING_DEVICE
        for (vector<Device>::iterator iter = members->begin(); iter != members->end(); iter++) {
            if (iter->getDeviceType() == PC) {
                if (iter->send(this) == -1)
                    return -1;
            }
        }
    }

    return 0;
}

