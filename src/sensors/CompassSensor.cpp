/*
 * CompassSensor.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#include "../../include/sensors/CompassSensor.hpp"
#include <sensors/Sensor.hpp>

namespace RobotDevice::Sensor
{
  int CompassSensor::init()
  {
    return 0;
  }

  int CompassSensor::getReading()
  {
    return 0;
  }

  void CompassSensor::reset()
  {
  }

  CompassSensor::CompassSensor()
  {
  }

  CompassSensor::~CompassSensor()
  {
  }

  void CompassSensor::doWork()
  {

  }
} /* namespace RobotSensor */
