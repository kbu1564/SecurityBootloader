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

    DeviceType mType;
public:
    Device(DeviceType type): mType(type) {}
    virtual ~Device();

    virtual int send(Packet& p) = 0;
};

#endif

