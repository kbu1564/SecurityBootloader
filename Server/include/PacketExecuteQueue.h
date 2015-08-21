#ifndef PACKETEXECUTEQUEUE_H_
#define PACKETEXECUTEQUEUE_H_

// 원형큐 방식
// 큐 데이터 배열 크기
const int MAX_QUEUE_SIZE = 100;

class PacketExecuteQueue
{
private:
    // Member Variable
    Packet mPacketDataList[MAX_QUEUE_SIZE];
    int    mFront;
    int    mRear;

    // Private Function
    bool __isEmpty()
    {
        if (this->mFront == this->mRear)
            return true;
        
        return false;
    }

    int __getNextIndex(int index)
    {
        return index % MAX_QUEUE_SIZE;
    }

public:
    PacketExecuteQueue()
    {
        this->mFront = 0;
        this->mRear = 0;
    }

    ~PacketExecuteQueue() {}

    int push(Packet p)
    {
        if (this->__getNextIndex(this->mRear) == this->mFront)
            return -1;

        this->mRear = this->__getNextIndex(this->mRear);
        this->mPacketDataList[this->mRear] = p;

        return 0;
    }

    int  popExecute()
    {
        // Not exist packet
        if (this->__isEmpty())
            return -1;

        // Execute packet execute function
        Packet p = this->mPacketDataList[this->mFront];
        this->mFront = this->__getNextIndex(this->mFront);

        p.execute();

        return 0;
    }
};

#endif

