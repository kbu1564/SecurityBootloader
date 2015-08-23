#ifndef BOOTINGREQUESTPACKET_H_
#define BOOTINGREQUESTPACKET_H_

class BootingRequestPacket : public Packet
{
private:
    string mGroupMacAddr;
public:
    int   parser(const char* buff, const int size);
    char* encode(int* size);
    int   execute();
};

#endif

