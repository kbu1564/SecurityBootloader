#ifndef SERVER_HANDLER_H_
#define SERVER_HANDLER_H_

class ServerHandler
{
public:
    ServerHandler()  {}
    virtual ~ServerHandler() {}

    virtual void accept(epoll_event& event, const char* hbuf, const char* sbuf) = 0;
    virtual void disconnect(epoll_event& event) = 0;
    virtual void recv(epoll_event& event, const char* buffer, int readlen) = 0;
    virtual void send(epoll_event& event) = 0;
};

#endif

