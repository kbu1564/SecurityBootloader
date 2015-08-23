#ifndef PACKET_H_
#define PACKET_H_

class Packet
{
public:
    virtual int   parser(const char* buff, const int size) {}
    virtual char* encode(int* size) {}
    virtual int   execute() {}
};

#endif

