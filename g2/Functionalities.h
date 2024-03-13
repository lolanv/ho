// Functionalities.h
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <string>
#include "Device.h"
#include "DeviceDriver.h"
#include <iostream>


void createObjects(std::vector<Device*>& devices);
std::vector<std::string> findDeviceIdsBelowBatteryFactor(const std::vector<Device*>& devices);
bool areAllDevicesOfSameType(const std::vector<Device*>& devices);
void displayMinMaxSizeInBytes(const std::vector<Device*>& devices);
std::vector<std::string> findVersionNumbersByDeviceId(const std::vector<Device*>& devices, const std::string& id);
void deleteHeapAllocations(std::vector<Device*>& devices);

#endif // FUNCTIONALITIES_H
