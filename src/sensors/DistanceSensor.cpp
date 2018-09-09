/*
 * DistanceSensor.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#include "../../include/sensors/DistanceSensor.hpp"
#include "wiringPi.h"

namespace RobotDevice::Sensor
{

  DistanceSensor::DistanceSensor(uint8_t triggerPin, uint8_t inputPin)
  {
    this->triggerPin = triggerPin;
    this->inputPin = inputPin;
  }

  DistanceSensor::~DistanceSensor()
  {
    // TODO Auto-generated destructor stub
  }

  int DistanceSensor::init()
  {
    pinMode(triggerPin, OUTPUT);
    pinMode(inputPin, INPUT);

    return 0;
  }

  double DistanceSensor::getReading()
  {
    return 0.0;
  }

  void DistanceSensor::reset()
  {
  }

  void DistanceSensor::doWork()
  {

  }
} /* namespace RobotSensor */
