
#pragma once

#include <iostream>
#include <mutex>
#include <memory>
#include <vector>
#include <map>
#include "Device.hpp"
#include <atomic>

namespace RobotDevice
{
class DeviceFactory
{
  private:
    DeviceFactory() = default;
    DeviceFactory(const DeviceFactory &) = delete;
    DeviceFactory &operator=(const DeviceFactory &) = delete;
    std::atomic_bool frontBumperConstructed{false}, frontDistanceConstructed{false}, heartbeatConstructed{false}, leftMotorConstructed{false}, RightMotorConstructed{false};
    std::map<std::string, std::shared_ptr<Device>> devices;
    static std::unique_ptr<DeviceFactory> instance;
    static std::once_flag onceFlag;
  public:
    enum struct DeviceType {FrontBumper, FrontDistance, HeartBeat, LeftMotor, RightMotor};
    static void NofityInit();
    static DeviceFactory &Instance();
    std::unique_ptr<Device> CreateDevice(const DeviceType &deviceType);
};
} // RobotDevice
