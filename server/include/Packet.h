#ifndef PACKET_H_
#define PACKET_H_

class Packet
{
protected:
    Device *                         mDev;
    hash_map<string, vector<Device>> mGroups;
public:
    Packet() : mDev(NULL) {}
    virtual ~Packet() {}

    void          setDevice(Device* dev) { this->mDev = dev; }
    void          setGroups(hash_map<string, vector<Device>>* groups) { this->mGroups = groups; }

    virtual int   parser(const char* buff, const int size) { }
    virtual char* encode(int* size) { }
    virtual int   execute() { }
};

#endif

