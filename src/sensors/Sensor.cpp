/*
 * Sensor.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#include "../../include/sensors/Sensor.hpp"

namespace RobotDevice::Sensor
{
  template<typename T>
  inline RobotDevice::Sensor::Sensor<T>::Sensor()
  {
  }

  template<typename T>
  inline RobotDevice::Sensor::Sensor<T>::~Sensor()
  {
  }

  // Tell compiler that we explicit need the following types
  template class RobotDevice::Sensor::Sensor<int>;
  template class RobotDevice::Sensor::Sensor<bool>;
  template class RobotDevice::Sensor::Sensor<double>;
} /* namespace RobotSensor */
