#ifndef PACKETEXECUTEQUEUE_H_
#define PACKETEXECUTEQUEUE_H_

// 원형큐 방식
// 큐 데이터 배열 크기
const int QUEUE_SIZE = 100;

class PacketExecuteQueue
{
private:
    Packet mPacketData[SIZE];
    int    mFront;
    int    mRear;
public:
    PacketExecuteQueue();
    ~PacketExecuteQueue();

    void push(const Packet* p);
    int  popExecute();
};

#endif

