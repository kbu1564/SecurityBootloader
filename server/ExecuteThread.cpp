#include "Global.h"
#include "Protocol.h"

#include "Packet.h"
#include "PacketExecuteQueue.h"
#include "Device.h"
#include "Group.h"
#include "ExecuteThread.h"

void ExecuteThread::run(void* obj)
{
    PacketExecuteQueue* q = (PacketExecuteQueue *) obj;
    while (1) {
        Packet* p = q->pop();
        if (p != NULL) {
            p->execute();
        }
    }
}

