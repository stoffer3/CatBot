/*
 * Machine.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: stoffer
 */
#include <chrono>
#include <thread>
#include <iostream>
#include "machine.hpp"
#include <string>
#include "RobotWorldMap.hpp"

namespace FiniteStateMachine
{
  int runFsm()
  {
    bool running = true;
    FiniteStateMachine::Machine *machine = new FiniteStateMachine::Machine();
    std::cout << "Running FSM" << std::endl;
    machine->doInitialiation();
    while(running)
    {
      machine->doObserve();
      machine->doDecition();
      machine->doAct();   
      std::this_thread::sleep_for(std::chrono::milliseconds(FSM_MAX_CYCLE_DURATION_MSEC)); //SHOULD BE REMOVED
    }
    machine->doFinalizing();
    std::cout << "Stopping FSM" << std::endl;
    return 0;
  }

  Machine::Machine()
  {
     initialisationState = std::make_shared<InitialisationState>(this);
     observeState = std::make_shared<ObserveState>(this);
     decisionState = std::make_shared<DecisionState>(this);
     actState = std::make_shared<ActState>(this);
     finalizingState = std::make_shared<FinalizingState>(this);
     setCurrent(Init_State);
  }

  Machine::~Machine()
  {
  }

  void Machine::setCurrent(InternalMachineState newState)
  {
    switch(newState)
    {
    case Init_State:
      currentState = initialisationState;
      break;
    case Oberserve_State:
      currentState = observeState;
      break;
    case Decision_State:
      currentState = decisionState;
      break;
    case Act_State:
      currentState = actState;
      break;
    case Finalizing_State:
      currentState = finalizingState;
      break;
    }
  }

  void Machine::doInitialiation()
  {
    currentState->doInitialiation();
  }

  void Machine::doObserve()
  {
    currentState->doObserve();
  }

  void Machine::doDecition()
  {
    currentState->doDecition();
  }

  void Machine::doAct()
  {
    currentState->doAct();
  }

  void Machine::doFinalizing()
  {
    currentState->doFinalizing();
  }
}

