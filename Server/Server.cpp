#include "Global.h"
#include "ThreadPool.h"

#include "Protocol.h"
#include "Group.h"
#include "PacketExecuteQueue.h"
#include "PacketParser.h"
#include "Server.h"

bool Server::receiveLoop(PacketExecuteQueue& q)
{
    return true;
}

int Server::createServer(const int port)
{
    return 0;
}

int Server::shutdownServer()
{
    return 0;
}

void Server::shutdownAllThreads(ThreadPool& p)
{
}

