#include "Global.h"
#include "Protocol.h"

#include "Packet.h"
#include "Device.h"
#include "Group.h"
#include "PingThread.h"

void PingThread::run(void* obj)
{
    while (1) {
        sleep(2);
        cout << "PingThread::run()" << endl;
    }
}

