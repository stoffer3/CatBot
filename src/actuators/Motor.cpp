/*
 * Motor.cpp
 *
 *  Created on: Dec 30, 2017
 *      Author: stoffer
 */

#include "actuators/Motor.hpp"
#include <wiringPi.h>
#include <softPwm.h>
#include <cmath>
#include "exceptions/MotorSpeedOutOfRangeException.hpp"

namespace RobotDevice::Actuator
{

  Motor::Motor(uint8_t motorEnablePin, uint8_t forwardPwmPin, uint8_t backwardPwmPin)
  {
    this->motorEnablePin = motorEnablePin;
    this->forwardPwmPin = forwardPwmPin;
    this->backwardPwmPin = backwardPwmPin;
    this->motorEnable = false;
  }

  Motor::~Motor()
  {
    // TODO Auto-generated destructor stub
  }

  int Motor::init()
  {
    int error = 0;
    error &= softPwmCreate(forwardPwmPin, 0, DEFAULT_MOTOR_PWM_CYCLE);
    error &= softPwmCreate(backwardPwmPin, 0, DEFAULT_MOTOR_PWM_CYCLE);
    pinMode(motorEnablePin, OUTPUT);

    return error;
  }

  int Motor::start()
  {
    digitalWrite(motorEnablePin, TRUE);
    motorEnable = true;
    Actuator::start();

    return 0;
  }

  void Motor::stop()
  {
    digitalWrite(motorEnablePin, FALSE);
    motorEnable = false;
    Actuator::stop();
  }

  void Motor::doWork()
  {
    softPwmWrite(forwardPwmPin, forwardSpeed);
    softPwmWrite(backwardPwmPin, backwardSpeed);
  }


  int8_t Motor::getSpeed() const
  {
    return speed;
  }

  void Motor::setSpeed(int8_t speed)
  {
    if(std::abs(speed) > DEFAULT_MOTOR_PWM_CYCLE) throw std::MotorSpeedOutOfRangeException();
    this->speed = speed;
    this->backwardSpeed = speed < 0 ? std::abs(speed) : 0;
    this->forwardSpeed = speed >= 0 ? speed : 0;
  }

  bool Motor::isMotorEnable() const
  {
    return motorEnable;
  }

} /* namespace RobotActuator */
