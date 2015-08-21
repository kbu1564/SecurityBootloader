#ifndef DEVICE_H_
#define DEVICE_H_

// 장치 종류에 대한 enum 상수
enum DeviceType { UNKNOWN, PHONE, PC };

class Device
{
protected:
    int   mSock;
    char* mIpAddr;
    int   mPort;
    char* mMacAddr;

    int   mType;
public:
    Device() {}
    virtual ~Device() {}

    virtual int send(Packet& p) {}
};

#endif

