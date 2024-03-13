// DeviceDriver.h
#ifndef DEVICEDRIVER_H
#define DEVICEDRIVER_H

#include <string>

class DeviceDriver {
public:
    std::string _version_number;
    std::string _release_quarter;
    float _size_in_bytes;

    DeviceDriver(std::string version, std::string quarter, float size);
};

#endif // DEVICEDRIVER_H
