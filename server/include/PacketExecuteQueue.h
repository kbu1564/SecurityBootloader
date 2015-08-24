#ifndef PACKETEXECUTEQUEUE_H_
#define PACKETEXECUTEQUEUE_H_

// 원형큐 방식
// 큐 데이터 배열 크기
const int MAX_QUEUE_SIZE = 1000;

class PacketExecuteQueue
{
private:
    // Member Variable
    pthread_mutex_t mPthMutex;

    Packet *mPacketDataList[MAX_QUEUE_SIZE];

    int     mFront;
    int     mRear;
    int     mCounts;

    // Private Function
    bool __isEmpty()
    {
        if (mCounts <= 0)
            return true;

        return false;
    }

    int __getNextIndex(int index)
    {
        return (index + 1) % MAX_QUEUE_SIZE;
    }

public:
    PacketExecuteQueue()
    {
        this->mFront = 0;
        this->mRear = 0;
        this->mCounts = 0;
        pthread_mutex_init(&this->mPthMutex, NULL);
    }

    ~PacketExecuteQueue() {}

    int push(Packet* p)
    {
        if (this->__getNextIndex(this->mRear) == this->mFront)
            return -1;

        pthread_mutex_lock(&this->mPthMutex);
        this->mRear = this->__getNextIndex(this->mRear);
        this->mPacketDataList[this->mRear] = p;
        this->mCounts++;
        pthread_mutex_unlock(&this->mPthMutex);

        return 0;
    }

    Packet* pop()
    {
        if (this->__isEmpty())
            return NULL;

        pthread_mutex_lock(&this->mPthMutex);
        Packet* packet = this->mPacketDataList[this->mFront];
        this->mFront = this->__getNextIndex(this->mFront);
        this->mCounts--;
        pthread_mutex_unlock(&this->mPthMutex);

        return packet;
    }
};

#endif

