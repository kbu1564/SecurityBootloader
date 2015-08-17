#include "Global.h"
#include "Protocol.h"
#include "Packet.h"

PacketExecuteQueue::PacketExecuteQueue() : mFront(0), mRear(0)
{
}

PacketExecuteQueue::~PacketExecuteQueue()
{
}

void PacketExecuteQueue::push(const Packet* p)
{
}

int PacketExecuteQueue::popExecute()
{
    return 0;
}

