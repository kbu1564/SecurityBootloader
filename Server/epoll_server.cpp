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
	return E_OK;
}

/**
 * 서버 소켓 닫기
 */
int EpollServer::shutdown()
{
	return E_OK;
}

/**
 * 비동기 및 서버 소켓의 EPOOL 옵션값들을 설정
 */
int EpollServer::setOpts()
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

