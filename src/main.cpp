/*
 * Main.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: stoffer
 */

#include "machine.hpp"
#include "RobotController.hpp"
#include "actuators/Motor.hpp"

using namespace std;

int main (void)
{
  auto fsmStatus = FiniteStateMachine::runFsm();
  return fsmStatus;
  // return 0;
}

