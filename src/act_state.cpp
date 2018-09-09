/*
 * act_state.cpp
 *
 *  Created on: Dec 17, 2017
 *      Author: stoffer
 */

#include "machine.hpp"
#include "RobotController.hpp"

namespace FiniteStateMachine
{
  Machine::ActState::ActState(Machine *innerMachine) : MachineState(innerMachine)
  {
  }

  Machine::ActState::~ActState()
  {
  }

  void Machine::ActState::doAct()
  {

    //RobotController::RobotController::Instance().doAction();
    this->innerMachine->setCurrent(Oberserve_State);
  }
}



