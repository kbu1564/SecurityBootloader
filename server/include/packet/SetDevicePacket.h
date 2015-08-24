#ifndef SETDEVICEPACKET_H_
#define SETDEVICEPACKET_H_

class SetDevicePacket : public Packet
{
<<<<<<< HEAD
=======
private:
    string mMacAddr;
    int    mDeviceType;
>>>>>>> develop
public:
    int   parser(char* buff, int size);
    char* encode(int* size);
    int   execute();
};

#endif

