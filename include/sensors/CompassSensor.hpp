/*
 * CompassSensor.hpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#pragma once

#include "../sensors/Sensor.hpp"

namespace RobotDevice::Sensor
{
  class CompassSensor final: public Sensor<int>
  {
  public:
    CompassSensor();
    virtual ~CompassSensor();
    int init();
    int getReading();
    void reset();
    int start();
    void stop();
  private:
    void doWork();
  };

} /* namespace RobotSensor */
