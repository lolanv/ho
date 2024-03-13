// main.cpp
#include "Device.h"
#include "DeviceDriver.h"
#include "Functionalities.h"
#include <iostream>
#include <vector>

int main() {
    try {
        std::vector<Device*> devices;
        createObjects(devices);

        // Call functionalities
        auto idsBelowBatteryFactor = findDeviceIdsBelowBatteryFactor(devices);
        std::cout << "Device IDs below battery factor 0.4: ";
        for (size_t i = 0; i < idsBelowBatteryFactor.size(); ++i) {
            std::cout << idsBelowBatteryFactor[i] << " ";
        }
        std::cout << std::endl;

        bool allSameType = areAllDevicesOfSameType(devices);
        std::cout << "Are all devices of the same type? " << (allSameType ? "Yes" : "No") << std::endl;

        displayMinMaxSizeInBytes(devices);

        std::string deviceIdToFindVersions = "ID1";
        auto versions = findVersionNumbersByDeviceId(devices, deviceIdToFindVersions);
        std::cout << "Version numbers for device ID " << deviceIdToFindVersions << ": ";
        for (size_t i = 0; i < versions.size(); ++i) {
            std::cout << versions[i] << " ";
        }
        std::cout << std::endl;

        // Delete heap allocations
        deleteHeapAllocations(devices);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
