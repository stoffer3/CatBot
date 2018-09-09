/*
 * Device.hpp
 *
 *  Created on: Jan 2, 2018
 *      Author: stoffer
 */

#pragma once

#define DEFAULT_THREAD_SLEEP_TIME 100

#include <thread>

namespace RobotDevice
{
class Device
{
public:
  Device();
  virtual ~Device();
  virtual int init() = 0;
  virtual int start();
  virtual void stop();

private:
  virtual void doWork() = 0;
  bool execution = false;
  std::thread *executionThread = nullptr;

protected:
  uint32_t threadSleepTime = DEFAULT_THREAD_SLEEP_TIME;
};

} /* namespace RobotController */
