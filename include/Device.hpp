/*
 * Device.hpp
 *
 *  Created on: Jan 2, 2018
 *      Author: stoffer
 */

#pragma once

#define DEFAULT_THREAD_SLEEP_TIME 100

#include <thread>
#include <atomic>

namespace RobotDevice
{
class Device
{
public:
  Device();
  virtual ~Device();
  virtual int init() = 0;
  virtual int start() = 0;
  virtual void stop() = 0;

protected:
  std::atomic_bool execution = false;
};

} // namespace RobotDevice
