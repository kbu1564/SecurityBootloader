#include "Global.h"
#include "Protocol.h"
#include "Packet.h"
#include "Device.h"
#include "packet/ShutdownDevicePacket.h"

int ShutdownDevicePacket::parser(char* buff, int size)
{
    cout << "ShutdownDevicePacket::parser()" << endl;
    cout << "Shutdown MAC : " << buff << endl;
    return 0;
}

char* ShutdownDevicePacket::encode(int* size)
{
    cout << "ShutdownDevicePacket::encode()" << endl;
    return NULL;
}

int ShutdownDevicePacket::execute()
{
    cout << "ShutdownDevicePacket::execute()" << endl;
    return 0;
}

