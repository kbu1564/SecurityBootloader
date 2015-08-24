#include "Global.h"
#include "Protocol.h"

#include "Packet.h"
#include "PacketExecuteQueue.h"
#include "Device.h"
#include "ExecuteThread.h"

void ExecuteThread::run(void* obj)
{
    PacketExecuteQueue* q = (PacketExecuteQueue *) obj;
    while (1) {
        Packet* p = q->pop();
<<<<<<< HEAD
        if (p != NULL) {
=======

        if (p != NULL) {
            cout << "Packet Pop!!" << endl;
>>>>>>> develop
            p->execute();
        }
    }
}

