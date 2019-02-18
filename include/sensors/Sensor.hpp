/*
 * Sensor.hpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#pragma once

#include "Device.hpp"
#include <thread>

namespace RobotDevice::Sensor
{
template <typename T>
class Sensor : public Device
{
public:
  Sensor();
  virtual ~Sensor();
  virtual T getReading() = 0;
  virtual void reset() = 0;

private:
  virtual void interruptHandler() = 0;
};

} // namespace RobotDevice::Sensor
