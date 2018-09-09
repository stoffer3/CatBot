/*
 * MotorSpeedOutOfRangeException.cpp
 *
 *  Created on: Dec 30, 2017
 *      Author: stoffer
 */

#include  <exception>
#include "exceptions/MotorSpeedOutOfRangeException.hpp"

namespace std
{

  MotorSpeedOutOfRangeException::MotorSpeedOutOfRangeException(const char * error /*= "Motor speed is out of range!"*/)
  {
    errorMessage = error;
  }

  const char * MotorSpeedOutOfRangeException::what() const noexcept
  {
    return errorMessage.c_str();
  }

} /* namespace RobotActuator */
