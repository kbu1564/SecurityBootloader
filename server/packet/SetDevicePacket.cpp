#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "Device.h"
#include "packet/SetDevicePacket.h"

int SetDevicePacket::parser(char* buff, int size)
{
    int deviceType = *((int *) buff);
    char* macAddr = buff + 4;

    this->mMacAddr = macAddr;
    this->mDeviceType = deviceType;

    return 0;
}

char* SetDevicePacket::encode(int* size)
{
    return NULL;
}

int SetDevicePacket::execute()
{
    if (this->mDev == NULL) {
        cout << "Device Object is nullptr!" << endl;
        return -1;
    }

    string macAddr = this->mMacAddr;
    int deviceType = this->mDeviceType;

    if (this->mGroups == NULL) {
        cout << "multimap< string, vector<Device> >* is nullptr!" << endl;
        return -1;
    }

    multimap< string, vector<Device> >::iterator memIter = this->mGroups->find(macAddr);
    if (memIter == this->mGroups->end()) {
        vector<Device> devGroup;
        this->mGroups->insert(pair< string, vector<Device> >(macAddr, devGroup));

        memIter = this->mGroups->find(macAddr);
    }

    vector<Device> *devs = &(memIter->second);
    devs->push_back(*this->mDev);

    cout << "Group ID : " << macAddr << endl;
    cout << "This DeviceType : " << deviceType << endl;
    for (vector<Device>::iterator iter = devs->begin(); iter != devs->end(); iter++) {
        cout << "DeviceType : " << iter->getDeviceType() << endl;
        cout << "IP:PORT : " << iter->getIpAddr() << ":" << iter->getPort() << endl << endl;
    }

    this->mGroups->insert(pair< string, vector<Device> >(macAddr, *devs));

    return 0;
}

