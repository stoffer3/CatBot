/*
 * observe_state.cpp
 *
 *  Created on: Dec 17, 2017
 *      Author: stoffer
 */

#include "machine.hpp"

#include "RobotController.hpp"

#include <iostream>

namespace FiniteStateMachine
{
  Machine::ObserveState::ObserveState(Machine *innerMachine) : MachineState(innerMachine)
  {
  }

  Machine::ObserveState::~ObserveState()
  {
  }

  void Machine::ObserveState::doObserve()
  {
    RobotController::RobotController::Instance().updateWorldMap(); // Update map1
    this->innerMachine->setCurrent(Decision_State);
  }
}
