#include "Global.h"
#include "Protocol.h"

#include "Packet.h"
#include "Device.h"
#include "Group.h"
#include "ExecuteThread.h"

void ExecuteThread::run(void* obj)
{
    while (1) {
        sleep(1);
    }
}

