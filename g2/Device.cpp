// Device.cpp
#include "Device.h"


Device::Device(std::string id, DeviceType type, int battery_level, DeviceDriver* driver)
    : _device_id(id), _device_type(type), _device_battery_level(battery_level), _device_driver(driver) {}

float Device::findBatteryDrainFactor() const {
    float factor = 0.0;
    if (_device_type == DeviceType::INFOTAINMENT || _device_type == DeviceType::ACCESSORY) {
        factor = 0.25;
    } else if (_device_type == DeviceType::SAFETY) {
        factor = (_device_battery_level > 50) ? 0.5 : 0.4;
    }
    return factor;
}
