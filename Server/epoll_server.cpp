#include "include/global.h"
#include "include/epoll_server.h"

EpollServer::EpollServer()
{
}

EpollServer::~EpollServer()
{
}

/**
 * 소켓 생성
 */
int EpollServer::open(const int port)
{
    struct addrinfo hints;
    struct addrinfo* result;
    struct addrinfo* rp;
    int sfd;
    int retval;
    char strPort[6] = { 0, };
    sprintf(strPort, "%d", port);

    // set server socket port
    this->mPort = port;

    memset(&hints, 0, sizeof(struct addrinfo));
    // IPv4 & IPv6 둘중 하나를 선택해서 리턴
    hints.ai_family = AF_UNSPEC;
    // TCP
    hints.ai_socktype = SOCK_STREAM;
    // ALL Interfaces
    hints.ai_flags = AI_PASSIVE;

    retval = getaddrinfo(NULL, strPort, &hints, &result);
    if (retval != 0) {
        this->__reporting("getaddrinfo", retval);
        return retval;
    }

    // create socket
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd != -1)
            continue;

        retval = bind(sfd, rp->ai_addr, rp->ai_addrlen);
        if (retval == 0) {
            break;
        }

        close(sfd);
    }

    // bind error
    if (rp == NULL) {
        this->__reporting("bind", retval);
        return -1;
    }

    freeaddrinfo(result);

    // server socket setting
    this->mSfd = sfd;

    return E_OK;
}

/**
 * 서버 소켓 닫기
 */
int EpollServer::shutdown()
{
	close(this->mSfd);
    return E_OK;
}

/**
 * 비동기 및 서버 소켓의 EPOOL 옵션값들을 설정
 */
int EpollServer::setOpts()
{
	int flags, s;
	flags = fcntl(this->mSfd, FGETFL, 0);
	if (flags == -1) {
		this->__reporting("fcntl", "none-blocking socket option getting error");
		return -1;
	}

	flags |= O_NONBLOCK;
	s = fcntl(this->mSfd, F_SETFL, flags);
	if (s == -1) {
		this->__reporting("1:fcntl", "none-blocking socket change error");
		return -1;
	}
    return E_OK;
}
/**
 * Socket Listen
 */
int EpollServer::listen()
{
	int ret = listen(this->mSfd, SOMAXCONN);
	return E_OK;
}

/**
 * Epoll 초기화
 */
int EpollServer::_epoll_init(const int epollsize)
{
	return E_OK;
}

/**
 * 소켓 루프 관련 부분
 */
int EpollServer::loop()
{
    return E_OK;
}

void EpollServer::__reporting(char* funcname, int retval) const
{
    char buff[256];
    sprintf(buff, "%s: %s", funcname, gai_strerror(retval));
    fprintf(stderr, "%s\n", buff);
}

