#include "include/global.h"
#include "include/server_handler.h"
#include "include/epoll_server.h"

EpollServer::EpollServer(ServerHandler* handler)
{
    this->mHandler = handler;
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
	int retval = 0;
    this->mEpfd = epoll_create(epollsize);
    if (epfd == -1) {
        this->__reporting("epoll_create", "can't create epoll events");
		return -1;
    }

    epoll_event event;
    event.data.fd = this->mSfd;
    event.events  = EPOLLIN | EPOLLET;
    retval = epoll_ctl(epfd, EPOLL_CTL_ADD, this->mSfd, &event);
    if (retval == -1) {
        this->__reporting("epoll_ctl", "can't create epoll events");
        return -1;
    }
    return E_OK;
}

/**
 * 소켓 루프 관련 부분
 */
int EpollServer::loop()
{
    int retval = 0;
    epoll_event event, current_event;

    for (;;) {
        int n = epoll_wait(this->mEpfd, this->mEvents, MAX_EVENTS, -1);
        for (int i = 0; i < n; i++) {
            current_event = this->mEvents[i];

            if ((current_event.events & EPOLLERR) ||
                (current_event.events & EPOLLHUP) ||
               !(current_event.events & EPOLLIN)) {
                // epoll error!!
                this->mHandler->disconnect(current_event);
            } else if (current_event.events & EPOLLRDHUP) {
                // closed connection on descriptor via EPOLLRDHUP
                this->mHandler->disconnect(current_event);
            } else if (this->mSfd == current_event.data.fd) {
                // listening socket
                for (;;) {
                    sockaddr in_addr;
                    sockaddr sa;
                    socklen_t in_len;
                    int infd;
                    char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];

                    in_len = sizeof(in_addr);
                    infd = accept4(this->mSfd, &in_addr, &in_len, SOCK_NONBLOCK, SOCK_CLOEXEC);
                    if (infd == -1) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK)
                            break;
                        else {
                            // accept!!
                            break;
                        }
                    }

                    retval = getnameinfo(&sa, in_len, hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV);
                    if (retval == 0) {
                        // host = hbuf, serv = sbuf
                    }

                    event.data.fd = infd;
                    event.events  = EPOLLIN | EPOLLRDHUP | EPOLLET;
                    retval = epoll_ctl(this->mEpfd, EPOLL_CTL_ADD, infd, &event);
                    if (retval == -1) {
                        this->__reporting("epoll_ctl", "Register for read events error");
                        return -1;
                    }

                    // accept handler
                    this->mHandler->accept(event, hbuf, sbuf);
                }
            } else if (current_event.events & EPOLLIN) {
                // read data
                char buf[MAX_BUFFER_SIZE];
                int nread = read(current_event.data.fd, buf, MAX_BUFFER_SIZE);
                if (nread < 1) {
                    // closed connection on descriptor
                    this->mHandler->disconnect(current_event);
                } else {
                    // NULL value setting
                    if (nread < MAX_BUFFER_SIZE) buf[nread] = 0;

                    // recv event!!
                    this->mHandler->recv(current_event, buf, nread);
                }
            } else if (current_event.events & EPOLLOUT) {
                // write event!!
            }
        }
    }
    return E_OK;
}

void EpollServer::__reporting(char* funcname, int retval) const
{
    char buff[256];
    sprintf(buff, "%s: %s", funcname, gai_strerror(retval));
    fprintf(stderr, "%s\n", buff);
}

