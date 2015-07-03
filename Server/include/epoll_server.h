#ifndef EPOLL_SERVER_H_
#define EPOLL_SERVER_H_

class EpollServer
{
protected:
	int mPort;
    int mSfd;
public:
	EpollServer();
	~EpollServer();

	int open(const int port);
	int shutdown();
	int setOpts();
	int loop();
private:
	EpollServer(const EpollServer& es);
	EpollServer& operator=(const EpollServer& es);

    void __reporting(char* funcname, int retval) const;
};

#endif

