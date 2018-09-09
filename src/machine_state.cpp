/*
 * MachineState.cpp
 *
 *  Created on: Dec 17, 2017
 *      Author: stoffer
 */

#include "machine.hpp"
#include "exceptions/notImplementedException.hpp"

namespace FiniteStateMachine
{
  Machine::MachineState::MachineState(Machine *innerMachine)
  {
    this->innerMachine = innerMachine;
  }

  Machine::MachineState::~MachineState()
  {
  }

  void Machine::MachineState::doInitialiation()
  {
    throw std::NotImplementedException("myFunction is not implemented yet.");
  }

  void Machine::MachineState::doObserve()
  {
    throw std::NotImplementedException("myFunction is not implemented yet.");
  }

  void Machine::MachineState::doDecition()
  {
    throw std::NotImplementedException("myFunction is not implemented yet.");
  }

  void Machine::MachineState::doAct()
  {
    throw std::NotImplementedException("myFunction is not implemented yet.");
  }

  void Machine::MachineState::doFinalizing()
  {
    throw std::NotImplementedException("myFunction is not implemented yet.");
  }

}

