/*
 * DistanceSensor.h
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */
#pragma once

#include "../sensors/Sensor.hpp"
#include "DeviceFactory.hpp"
#include <cstdint>

namespace RobotDevice::Sensor
{
class DistanceSensor final : public Sensor<double>
{
public:
  DistanceSensor(uint8_t triggerPin, uint8_t inputPin);
  virtual ~DistanceSensor();
  int init();
  double getReading();
  void reset();
  int start();
  void stop();

private:
  void interruptHandler();
  uint8_t triggerPin = 0;
  uint8_t inputPin = 1;
};
} // namespace RobotDevice::Sensor
