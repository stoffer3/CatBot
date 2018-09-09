/*
 * BumperSensor.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#include "../../include/sensors/BumperSensor.hpp"
#include <wiringPi.h>

namespace RobotDevice::Sensor
{

  BumperSensor::BumperSensor(uint8_t triggerPin)
  {
    this->triggerPin = triggerPin;
    this->isTriggered = false;
  }

  BumperSensor::~BumperSensor()
  {
    // TODO Auto-generated destructor stub
  }

  int BumperSensor::init()
  {
    pinMode(triggerPin, INPUT);
    return 0;
  }

  bool BumperSensor::getReading()
  {
    return isTriggered;
  }

  void BumperSensor::reset()
  {
    isTriggered = false;
  }

  void BumperSensor::doWork()
  {
    if(!isTriggered)
      isTriggered = !digitalRead(triggerPin);
  }
} /* namespace RobotSensor */
