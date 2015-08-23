#ifndef DEVICE_H_
#define DEVICE_H_

// 장치 종류에 대한 enum 상수
enum DeviceType { UNKNOWN, PHONE, PC };

class Device
{
protected:
    int        mSock;
    char*      mIpAddr;
    int        mPort;
    char*      mMacAddr;

    DeviceType mType;
public:
    Device() : mSock(0), mIpAddr(NULL), mPort(0), mMacAddr(NULL) {}
    virtual ~Device() {}

    void    setSock(int sock)              { this->mSock = sock; }
    void    setIpAddr(char* ipAddr)        { this->mIpAddr = ipAddr; }
    void    setPort(const int port)        { this->mPort = port; }
    void    setMacAddr(char* macAddr)      { this->mMacAddr = macAddr; }
    void    setDeviceType(DeviceType type) { this->mType = type; }

    int     getSock()    { return this->mSock; }
    char*   getIpAddr()  { return this->mIpAddr; }
    int     getPort()    { return this->mPort; }
    char*   getMacAddr() { return this->mMacAddr; }

    int     send(Packet* p);
};

#endif

