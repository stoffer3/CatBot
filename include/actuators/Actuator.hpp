/*
 * Actuator.hpp
 *
 *  Created on: Dec 23, 2017
 *      Author: stoffer
 */

#pragma once
#include "Device.hpp"

namespace RobotDevice::Actuator
{

  class Actuator : public Device
  {
  public:
    Actuator();
    virtual ~Actuator();
  private:
  };

} /* namespace RobotSensor */
