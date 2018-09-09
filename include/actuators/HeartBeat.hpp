/*
 * HeartBeat.hpp
 *
 *  Created on: Dec 23, 2017
 *      Author: stoffer
 */
#pragma once
#include "Actuator.hpp"
#include "wiringPi.h"
#include <cstdint>
#include <thread>

namespace RobotDevice::Actuator
{
  class HeartBeat final: public Actuator
  {
  public:
    HeartBeat(uint8_t outPin);
    virtual ~HeartBeat();
    int init();
  private:
    void doWork();
    uint8_t outPin;
    bool status = true;
  };
} /* namespace RobotSensor */

