#ifndef GROUP_H_
#define GROUP_H_

// 하나의 그룹에 등록 가능한 클라이언트의 수
const int MAX_DEVICE = 10;

class Group
{
private:
    Device mDevices[MAX_DEVICE];
public:
    int     addDevice(Device* dev);
    Device* getDevice(int idx);
};

#endif

