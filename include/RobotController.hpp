/*
 * RobotController.hpp
 *
 *  Created on: Dec 30, 2017
 *      Author: stoffer
 */

#pragma once

#include <iostream>
#include <mutex>
#include <vector>
#include <array>
#include <queue>
#include <unordered_map>
#include "actuators/HeartBeat.hpp"
#include "actuators/Motor.hpp"
#include "sensors/AccelerometerSensor.hpp"
#include "sensors/BumperSensor.hpp"
#include "sensors/CompassSensor.hpp"
#include "RobotWorldMap.hpp"
#include "RobotAction.hpp"

namespace RobotController
{
class RobotController
{
public:
  RobotController();
  int init();
  const RobotWorldMap::RobotWorldMap &getRobotWorldMap();
  void updateWorldMap();
  void setAction(RobotAction::RobotAction &&action);
  void setDriveDirection(const std::vector<int> &vector);
  void setDriveRotate(const double &rotate);
  void setDrivingState(const bool &state);
  bool isBumperActivated();
  static RobotController &Instance();

private:
  std::unique_ptr<RobotWorldMap::RobotWorldMap> robotWorldMap;
  std::unique_ptr<std::queue<RobotAction::RobotAction>> actions;
  std::unordered_map<std::string, std::unique_ptr<RobotDevice::Device>> *devices;

  bool initialized = false;
  bool execution = false;
  std::thread *executionThread = nullptr;
  static std::unique_ptr<RobotController> instance;
  static std::once_flag onceFlag;
  std::unordered_map<std::string, std::unique_ptr<RobotDevice::Device>> *getDevices();
  void executeActions();  
  bool isInitialized() const;
  static void NofityInit();
};
} /* namespace RobotController */
