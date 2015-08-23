#ifndef SETDEVICEPACKET_H_
#define SETDEVICEPACKET_H_

class SetDevicePacket : public Packet
{
public:
    int   parser(const char* buff, const int size);
    char* encode(int* size);
    int   execute();
};

#endif

