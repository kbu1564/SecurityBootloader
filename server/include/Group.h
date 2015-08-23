#ifndef GROUP_H_
#define GROUP_H_

class Group
{
private:
    vector<Device> mDevices;
public:
    int     addDevice(Device* dev);
    Device* getDevice(int idx);
};

#endif

