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
    int start();
    void stop();
  private:
    uint32_t threadSleepTime = DEFAULT_THREAD_SLEEP_TIME;
    std::thread *executionThread = nullptr;
    void doWork();
    uint8_t outPin;
    bool status = true;
  };
} /* namespace RobotSensor */

