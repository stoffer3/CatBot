#include "DeviceFactory.hpp"
#include <iostream>
#include <mutex>
#include <exception>
#include "sensors/DistanceSensor.hpp"
#include "sensors/BumperSensor.hpp"
#include "actuators/HeartBeat.hpp"
#include "actuators/Motor.hpp"


namespace RobotDevice
{

void DeviceFactory::NofityInit()
{
    std::cout << "Initializing DeviceFactory" << '\n';
}
DeviceFactory &DeviceFactory::Instance()
{
    std::call_once(DeviceFactory::onceFlag, []() {
        NofityInit();
        instance.reset(new DeviceFactory);
    });

    std::cout << "Getting  DeviceFactory instance" << '\n';
    return *(instance.get());
}

std::unique_ptr<Device> DeviceFactory::CreateDevice(const DeviceType &deviceType)
{
    switch (deviceType)
    {
    case DeviceType::FrontBumper:
        if(!frontBumperConstructed)
        {
            frontBumperConstructed = true;
            return std::make_unique<Sensor::BumperSensor>(17);
        }
        else
        {
            std::cout << "not allowed" << std::endl;
            std::set_unexpected([]{
                std::cout << "Not allowed to have more then one: " << typeid(Sensor::BumperSensor).name() << std::endl;
                std::abort();
                });
        }
    case DeviceType::FrontDistance:
        return std::make_unique<Sensor::DistanceSensor>(11, 10);
    case DeviceType::HeartBeat:
        return std::make_unique<Actuator::HeartBeat>(4);
    case DeviceType::LeftMotor:
        return std::make_unique<Actuator::Motor>(26, 20, 21);
    case DeviceType::RightMotor:
        return std::make_unique<Actuator::Motor>(12, 6, 13);
    default:
        return nullptr;
    }
}

std::unique_ptr<DeviceFactory> DeviceFactory::instance;
std::once_flag DeviceFactory::onceFlag;
} // RobotDevice
