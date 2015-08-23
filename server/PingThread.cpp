#include "Global.h"
#include "Protocol.h"

#include "Packet.h"
#include "packet/FindDevicePacket.h"
#include "Device.h"
#include "Group.h"
#include "PingThread.h"

void PingThread::run(void* obj)
{
    vector<Device>* devs = (vector<Device> *) obj;
    while (1) {
        sleep(5);
        cout << "Ping Thread!! : " << devs->size() << endl;
        if (devs->size() > 0) {
            Device &dev = (*devs)[0];
            dev.send(new FindDevicePacket());
        }
    }
}

