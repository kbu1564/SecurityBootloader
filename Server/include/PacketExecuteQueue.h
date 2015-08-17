#ifndef PACKETEXECUTEQUEUE_H_
#define PACKETEXECUTEQUEUE_H_

class PacketExecuteQueue
{
public:
    void push(const Packet* p);
    int  popExecute();
};

#endif

