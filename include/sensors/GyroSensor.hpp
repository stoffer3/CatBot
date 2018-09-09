/*
 * GyroSensor.hpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */
#pragma once

#include "../sensors/Sensor.hpp"

namespace RobotDevice::Sensor
{
  class GyroSensor final: public Sensor<int>
  {
  public:
    GyroSensor();
    virtual ~GyroSensor();
    int init();
    int getReading();
    void reset();
  private:
    void doWork();
  };

} /* namespace RobotSensor */

