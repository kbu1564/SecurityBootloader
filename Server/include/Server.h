#ifndef SERVER_H_
#define SERVER_H_

class Server
{
protected:
    int           mSock;
    int           mPort;
    vector<Group> mGroups;
public:
    bool receiveLoop(PacketExecuteQueue& q);

    int  createServer(const int port);
    int  shutdownServer();
    void shutdownAllThreads(ThreadPool& p);
private:
    // 객체 복사 방지
    Server(const Server& obj);
    Server& operator=(const Server& obj);
};

#endif

