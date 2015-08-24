#include "Global.h"
#include "ThreadPool.h"
#include "Protocol.h"
#include "Packet.h"
#include "PacketParser.h"

#include "Device.h"
#include "PacketExecuteQueue.h"
#include "Server.h"

int main(int argc, char* argv[])
{
    Server s;
    PacketExecuteQueue q;

<<<<<<< HEAD
    s.createServer(10883);
=======
    s.createServer(10880);
>>>>>>> develop
    s.createExecuteThread(q);

    while (s.run(q));

    s.shutdownServer();
    return 0;
}

