#ifndef FINDDEVICEPACKET_H_
#define FINDDEVICEPACKET_H_

class FindDevicePacket : public Packet
{
public:
    int   parser(const char* buff, const int size);
    char* encode(int* size);
    int   execute();
};

#endif

