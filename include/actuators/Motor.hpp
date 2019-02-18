/*
 * Motor.hpp
 *
 *  Created on: Dec 30, 2017
 *      Author: stoffer
 */

#pragma once

#define DEFAULT_MOTOR_PWM_CYCLE 100 //Default 100 cycle per second

#include "Actuator.hpp"
#include <cstdint>

namespace RobotDevice::Actuator
{

  class Motor final: public Actuator
  {
  public:
    Motor(uint8_t motorEnablePin, uint8_t forwardPwmPin, uint8_t backwardPwmPin);
    virtual ~Motor();
    int init();
    int start() override;
    void stop() override;
    int8_t getSpeed() const;
    void setSpeed(int8_t speed);
    bool isMotorEnable() const;

  private:
    uint8_t forwardPwmPin, backwardPwmPin, motorEnablePin, forwardSpeed, backwardSpeed;
    int8_t speed;
    bool motorEnable;
  };

} /* namespace RobotActuator */

