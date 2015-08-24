#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "Device.h"
#include "packet/BootingDevicePacket.h"

int BootingDevicePacket::parser(char* buff, int size)
{
    cout << "BootingDevicePacket::parser()" << endl;
    cout << "Booting MAC : " << buff << endl;
    return 0;
}

char* BootingDevicePacket::encode(int* size)
{
    cout << "BootingDevicePacket::encode()" << endl;
    return NULL;
}

int BootingDevicePacket::execute()
{
    cout << "BootingDevicePacket::execute()" << endl;
    return 0;
}

