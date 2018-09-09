/*
 * Device.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: stoffer
 */

#include "Device.hpp"
#include <thread>
#include <chrono>

namespace RobotDevice
{
  Device::Device()
  {
    // TODO Auto-generated constructor stub

  }

  Device::~Device()
  {
    // TODO Auto-generated destructor stub
  }

  int Device::start()
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

  void Device::stop()
  {
    execution = false;
    executionThread->join();
  }

} /* namespace RobotController */
