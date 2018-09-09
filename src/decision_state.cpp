/*
 * decision_state.cpp
 *
 *  Created on: Dec 17, 2017
 *      Author: stoffer
 */

#include "machine.hpp"
#include "RobotController.hpp"

namespace FiniteStateMachine
{
  Machine::DecisionState::DecisionState(Machine *innerMachine) : MachineState(innerMachine)
  {
  }

  Machine::DecisionState::~DecisionState()
  {
  }

  void Machine::DecisionState::doDecition()
  {
    auto robotWorldMap = RobotController::RobotController::Instance().getRobotWorldMap();
    RobotAction::RobotAction action;

    // Find out what to do
    if (robotWorldMap.frontBumperActivated)
    {
      action.type = RobotAction::RobotAction::STOP;
      RobotController::RobotController::Instance().setAction(std::move(action));
    }

    this->innerMachine->setCurrent(Act_State);
  }
}

