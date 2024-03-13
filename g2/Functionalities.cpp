// Functionalities.cpp
#include "Functionalities.h"


void createObjects(std::vector<Device*>& devices) {
    // Create DeviceDriver instances
    DeviceDriver* driver1 = new DeviceDriver("1.0", "Q1", 1024.0);
    DeviceDriver* driver2 = new DeviceDriver("2.0", "Q2", 2048.0);
    // Add more drivers as needed...

    // Create Device instances using raw pointers
    devices.push_back(new Device("ID1", DeviceType::SAFETY, 70, driver1));
    devices.push_back(new Device("ID2", DeviceType::INFOTAINMENT, 30, driver2));
    // Add more devices as needed...
}

std::vector<std::string> findDeviceIdsBelowBatteryFactor(const std::vector<Device*>& devices) {
    std::vector<std::string> result;
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->findBatteryDrainFactor() < 0.4) {
            result.push_back(devices[i]->_device_id);
        }
    }
    return result;
}

bool areAllDevicesOfSameType(const std::vector<Device*>& devices) {
    if (devices.empty()) {
        throw std::runtime_error("No devices to check");
    }

    DeviceType firstType = devices[0]->_device_type;
    for (size_t i = 1; i < devices.size(); ++i) {
        if (devices[i]->_device_type != firstType) {
            return false;
        }
    }
    return true;
}

void displayMinMaxSizeInBytes(const std::vector<Device*>& devices) {
    float minSize = std::numeric_limits<float>::max();
    float maxSize = std::numeric_limits<float>::min();

    for (size_t i = 0; i < devices.size(); ++i) {
        if ((devices[i]->_device_driver->_release_quarter == "Q1" || devices[i]->_device_driver->_release_quarter == "Q4")) {
            float size = devices[i]->_device_driver->_size_in_bytes;
            minSize = (size < minSize) ? size : minSize;
            maxSize = (size > maxSize) ? size : maxSize;
        }
    }

    std::cout << "Min Size: " << minSize << ", Max Size: " << maxSize << std::endl;
}

std::vector<std::string> findVersionNumbersByDeviceId(const std::vector<Device*>& devices, const std::string& id) {
    std::vector<std::string> result;
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->_device_id == id) {
            result.push_back(devices[i]->_device_driver->_version_number);
        }
    }
    return result;
}

void deleteHeapAllocations(std::vector<Device*>& devices) {
    for (size_t i = 0; i < devices.size(); ++i) {
        delete devices[i];
    }
    devices.clear();
}
