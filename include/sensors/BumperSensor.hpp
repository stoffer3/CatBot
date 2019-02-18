/*
 * BumperSensor.hpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#pragma once

#include <cstdint>

#include "../sensors/Sensor.hpp"
#include "DeviceFactory.hpp"

namespace RobotDevice::Sensor
{
class BumperSensor final: public Sensor<bool>
{
public:
  BumperSensor(uint8_t triggerPin);
  virtual ~BumperSensor();
  int init();
  bool getReading();
  void reset();
  int start();
  void stop();

private:
  void interruptHandler();
  uint8_t triggerPin;
  bool isTriggered;
};

} /* namespace RobotSensor */
