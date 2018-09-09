/*
 * AccelerometerSensor.hpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#pragma once

#include "../sensors/Sensor.hpp"

namespace RobotDevice::Sensor
{
  class AccelerometerSensor final: public Sensor<int>
  {
  public:
    AccelerometerSensor();
    virtual ~AccelerometerSensor();
    int init();
    int getReading();
    void reset();
  private:
    void doWork();
  };

} /* namespace RobotSensor */
