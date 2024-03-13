#ifndef DEVICE_H
#define DEVICE_H

#include"DeviceDriver.h"
#include"DeviceType.h"
#include <string>


class Device {
public:
    std::string _device_id;
    DeviceType _device_type;
    int _device_battery_level;
    DeviceDriver* _device_driver;

    Device(std::string id, DeviceType type, int battery_level, DeviceDriver* driver);
    float findBatteryDrainFactor() const;
};

#endif // DEVICE_H
