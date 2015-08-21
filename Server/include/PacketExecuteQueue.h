#ifndef PACKETEXECUTEQUEUE_H_
#define PACKETEXECUTEQUEUE_H_

// 원형큐 방식
// 큐 데이터 배열 크기

template<const int SIZE = 100>
class PacketExecuteQueue
{
private:
    // Member Variable
    Packet mPacketDataList[SIZE];
    int    mFront;
    int    mRear;

    // Private Function
    bool isEmpty()
    {
        if (mFront == mRear)
            return true;
        
        return false;
    }

    int getNextIndex(int index)
    {
        if (index == SIZE-1)
            return 0;
        
        return index+1;   
    }

public:
    PacketExecuteQueue()
    {
        this->mFront = 0;
        this->mRear = 0;
    }

    ~PacketExecuteQueue() 
    {
        delete mPacketDataList;
    }

    int push(Packet p)
    {
        if (getNextIndex(mRear) == mFront)
            return -1;
                
        mRear = getNextIndex(mRear);
        mPacketDataList[mRear] = p;
        
        return 0;
    }
    
    int  popExecute()
    {
        // Not exist packet
        if (isEmpty()) 
            return -1;
        
        // Execute packet execute function
        Packet p = mPacketDataList[mFront];
        mFront = getNextIndex(mFront);   

        p.execute(); 
    
        return 0;
    }
};

#endif

