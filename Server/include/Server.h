#ifndef SERVER_H_
#define SERVER_H_

class Server
{
protected:
    int  mSock;
    int  mPort;
public:
    bool receiveLoop(PacketExecuteQueue& q);

    int  createServer(const int port);
    int  shutdownServer();
    void shutdownAllThreads(ThreadPool& p);
};

#endif

