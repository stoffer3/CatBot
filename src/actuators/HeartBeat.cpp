/*
 * HeartBeat.cpp
 *
 *  Created on: Dec 23, 2017
 *      Author: stoffer
 */

#include "actuators/HeartBeat.hpp"
#include <thread>
#include <iostream>
#include <chrono>
#include "wiringPi.h"

#define HEARTBEAT_THREAD_SLEEP_TIME 500

namespace RobotDevice::Actuator
{
  HeartBeat::HeartBeat(uint8_t outPin)
  {
    this->outPin = outPin;
    this->threadSleepTime = HEARTBEAT_THREAD_SLEEP_TIME;
  }

  HeartBeat::~HeartBeat()
  {
    // TODO Auto-generated destructor stub
  }

  void HeartBeat::doWork()
  {
    digitalWrite(outPin,status);
    status = !status;
  }

  int HeartBeat::init()
  {
    pinMode(outPin, OUTPUT);

    return 0;
  }

  int HeartBeat::start()
  {
    execution = true;
    executionThread =  new std::thread([&]() {
      while(execution)
      {
         doWork();
         std::this_thread::sleep_for(std::chrono::milliseconds(threadSleepTime));
      }
    });
    return 0;
  }

  void HeartBeat::stop()
  {
    execution = false;
    executionThread->join();
  }
} /* namespace RobotSensor */
