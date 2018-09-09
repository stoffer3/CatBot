/*
 * MotorSpeedOutOfRangeException.hpp
 *
 *  Created on: Dec 30, 2017
 *      Author: stoffer
 */

#pragma once
#include <exception>
#include <string>

namespace std
{

  class MotorSpeedOutOfRangeException: public std::exception
  {
  public:
    // Construct with given error message:
    MotorSpeedOutOfRangeException(const char * error = "Motor speed is out of range!");

    // Provided for compatibility with std::exception.
    const char * what() const noexcept;
  private:
    std::string errorMessage;
  };

} /* namespace RobotActuator */

