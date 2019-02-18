/*
 * BumperSensor.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: stoffer
 */

#include "../../include/sensors/BumperSensor.hpp"
#include <wiringPi.h>
#include <functional>
#include <iostream>

namespace RobotDevice::Sensor
{
 static std::function<void()> fptrInterruptHandler;

BumperSensor::BumperSensor(uint8_t triggerPin)
{
  this->triggerPin = triggerPin;
  this->isTriggered = false;
  fptrInterruptHandler = std::bind(&RobotDevice::Sensor::BumperSensor::interruptHandler, this);
}

BumperSensor::~BumperSensor()
{
  // TODO Auto-generated destructor stub
}

void BumperSensor::interruptHandler()
{
  isTriggered = true;
  std::cout << "BumperSensor Interrupt" << std::endl;
}

void callbackWrapper()
{
 fptrInterruptHandler();
}

int BumperSensor::init()
{
  pinMode(triggerPin, INPUT);
  pullUpDnControl(triggerPin, PUD_UP);  
  wiringPiISR(triggerPin, INT_EDGE_FALLING, &callbackWrapper);
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

// void BumperSensor::doWork()
// {
//   if(!isTriggered)
//     isTriggered = !digitalRead(triggerPin);
// }

int BumperSensor::start()
{
  return 0;
}

void BumperSensor::stop()
{
}

} // namespace RobotDevice::Sensor
