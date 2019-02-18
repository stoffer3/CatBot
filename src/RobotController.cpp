
/*
 * RobotController.cpp
 *
 *  Created on: Dec 30, 2017
 *      Author: stoffer
 */

#include "RobotController.hpp"
#include "DeviceFactory.hpp"
#include <wiringPi.h>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

namespace RobotController
{
RobotController::RobotController()
{
  robotWorldMap = std::make_unique<RobotWorldMap::RobotWorldMap>();
  actions = std::make_unique<std::queue<RobotAction::RobotAction>>();
  devices = RobotController::getDevices();
}

int RobotController::init()
{
  // Init Raspberry PI
  int error = wiringPiSetupGpio();
  if (error)
    return error;

  // Init all devices
  std::for_each(devices->begin(), devices->end(), [&error](const auto &device) { error &= device.second->init(); });
  // Start heartBeat
  dynamic_cast<RobotDevice::Actuator::HeartBeat &>(*devices->find("heartBeat")->second).start();

  // Start Sensors
  dynamic_cast<RobotDevice::Sensor::BumperSensor &>(*devices->find("frontBumper")->second).start();

  // Start execute Actions
  execution = true;

  executionThread = new std::thread([&]() {
    while (execution)
    {
      executeActions();
      std::this_thread::sleep_for(std::chrono::milliseconds(DEFAULT_THREAD_SLEEP_TIME));
    }
  });

  initialized = error == 0 ? true : false;
  return error;
}

void RobotController::executeActions()
{
  while (!actions->empty())
  {
    auto action = actions->front();
    //do something
    switch (action.type)
    {
    case RobotAction::RobotAction::START:
      setDrivingState(true);
      break;
    case RobotAction::RobotAction::STOP:
      //setDrivingState(false);
      break;
    case RobotAction::RobotAction::ROTATE:
      //setDriveRotate(action.rotate);
      break;
    case RobotAction::RobotAction::DIRECTION:
      setDriveDirection(*(action.driveDirection));
      break;
    default:
      break;
    }

    actions->pop();
  }
}

const RobotWorldMap::RobotWorldMap &RobotController::getRobotWorldMap()
{
  return *(robotWorldMap.get());
}

void RobotController::updateWorldMap()
{
  robotWorldMap->frontBumperActivated = isBumperActivated();
}

void RobotController::setAction(RobotAction::RobotAction &&action)
{
  actions->push(action); // Call with rvalue
}

void RobotController::setDriveDirection(const std::vector<int> &vector)
{
  // Have to do something much more cleaver
  dynamic_cast<RobotDevice::Actuator::Motor &>(*devices->find("leftMotor")->second).setSpeed(100);
  dynamic_cast<RobotDevice::Actuator::Motor &>(*devices->find("rightMotor")->second).setSpeed(100);
}

void RobotController::setDriveRotate(const double &rotate)
{
}

void RobotController::setDrivingState(const bool &state)
{
  if (state)
  {
    dynamic_cast<RobotDevice::Actuator::Motor &>(*devices->find("leftMotor")->second).start();
    dynamic_cast<RobotDevice::Actuator::Motor &>(*devices->find("rightMotor")->second).start();
  }
  else
  {
    dynamic_cast<RobotDevice::Actuator::Motor &>(*devices->find("leftMotor")->second).stop();
    dynamic_cast<RobotDevice::Actuator::Motor &>(*devices->find("rightMotor")->second).stop();
  }
}

bool RobotController::isBumperActivated()
{
  auto value = false;
  if (!robotWorldMap->frontBumperActivated)
  {
    value = dynamic_cast<RobotDevice::Sensor::BumperSensor &>(*devices->find("frontBumper")->second).getReading();
    dynamic_cast<RobotDevice::Sensor::BumperSensor &>(*devices->find("frontBumper")->second).reset();
  }
  return value;
}

void RobotController::NofityInit()
{
  std::cout << "Initializing RobotController" << '\n';
}

RobotController &RobotController::RobotController::Instance()
{
  std::call_once(RobotController::onceFlag, []() {
    NofityInit();
    instance.reset(new RobotController);
  });

  std::cout << "Getting  Singleton instance" << '\n';
  return *(instance.get());
}

std::unique_ptr<RobotController> RobotController::instance;
std::once_flag RobotController::onceFlag;

bool RobotController::isInitialized() const
{
  return initialized;
}

std::unordered_map<std::string, std::unique_ptr<RobotDevice::Device>> *RobotController::getDevices()
{
  auto devices = new std::unordered_map<std::string, std::unique_ptr<RobotDevice::Device>>;
  // Create devices
  devices->insert(std::make_pair("frontBumper", RobotDevice::DeviceFactory::Instance().CreateDevice(RobotDevice::DeviceFactory::DeviceType::FrontBumper)));
  devices->insert(std::make_pair("frontDistance", RobotDevice::DeviceFactory::Instance().CreateDevice(RobotDevice::DeviceFactory::DeviceType::FrontDistance)));
  devices->insert(std::make_pair("heartBeat", RobotDevice::DeviceFactory::Instance().CreateDevice(RobotDevice::DeviceFactory::DeviceType::HeartBeat)));
  devices->insert(std::make_pair("leftMotor", RobotDevice::DeviceFactory::Instance().CreateDevice(RobotDevice::DeviceFactory::DeviceType::LeftMotor)));
  devices->insert(std::make_pair("rightMotor", RobotDevice::DeviceFactory::Instance().CreateDevice(RobotDevice::DeviceFactory::DeviceType::RightMotor)));

  return devices;
}

} /* namespace RobotController */
