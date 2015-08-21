#include "Global.h"
#include "ThreadPool.h"

#include "Device.h"
#include "Group.h"
#include "Protocol.h"
#include "Packet.h"
#include "PacketParser.h"
#include "PacketExecuteQueue.h"
#include "Server.h"

int main(int argc, char* argv[])
{
    Server s;
    PacketExecuteQueue q;

    s.createServer(10880);
    while (s.run(q)) {
    }
    s.shutdownServer();
    return 0;
}

