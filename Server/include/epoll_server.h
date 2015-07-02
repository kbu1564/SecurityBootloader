#ifndef EPOLL_SERVER_H_
#define EPOLL_SERVER_H_

class EpollServer
{
protected:
	const int mPort;
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
};

#endif

