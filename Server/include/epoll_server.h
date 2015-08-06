#ifndef EPOLL_SERVER_H_
#define EPOLL_SERVER_H_

class EpollServer
{
private:
    enum Config {
        MAX_EVENTS = 64,
        MAX_BUFFER_SIZE = 512
    };
protected:
    int mPort;
    int mSfd;
    int mEpfd;

    epoll_event mEvents[MAX_EVENTS];

    ServerHandler* mHandler;

public:
    EpollServer(ServerHandler* handler);
    ~EpollServer();

    int open(const int port);
    int shutdown();
    int setOpts();
    int listen();
    int loop();

protected:
    int _epoll_init(const int epollsize);

private:
    EpollServer(const EpollServer& es);
    EpollServer& operator=(const EpollServer& es);

    void __reporting(char* funcname, int retval) const;
};

#endif

