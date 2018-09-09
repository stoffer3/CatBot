/*
 * finalizing_state.cpp
 *
 *  Created on: Dec 17, 2017
 *      Author: stoffer
 */

#include "machine.hpp"

namespace FiniteStateMachine
{
  Machine::FinalizingState::FinalizingState(Machine *innerMachine) : MachineState(innerMachine)
  {
  }

  Machine::FinalizingState::~FinalizingState()
  {
  }

  void Machine::FinalizingState::doFinalizing()
  {

  }
}


