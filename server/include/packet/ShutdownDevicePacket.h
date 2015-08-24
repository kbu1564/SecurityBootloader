#ifndef SHUTDOWNDEVICEPACKET_H_
#define SHUTDOWNDEVICEPACKET_H_

class ShutdownDevicePacket : public Packet
{
public:
    int   parser(char* buff, int size);
    char* encode(int* size);
    int   execute();
};

#endif

