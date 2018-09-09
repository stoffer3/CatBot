/*
 * InitialisationState.cpp
 *
 *  Created on: Dec 17, 2017
 *      Author: stoffer
 */

#include "machine.hpp"
#include "RobotController.hpp"

namespace FiniteStateMachine
{
  Machine::InitialisationState::InitialisationState(Machine *innerMachine) : MachineState(innerMachine)
  {
  }

  Machine::InitialisationState::~InitialisationState()
  {
  }

  void Machine::InitialisationState::doInitialiation()
  {
    auto error = RobotController::RobotController::Instance().init();
    // Start Robot
    RobotAction::RobotAction actionDirection, actionStart;
    actionStart.type = RobotAction::RobotAction::START;
    actionStart.driveDirection = new std::vector<int>();
    RobotController::RobotController::Instance().setAction(std::move(actionStart));

    // Set Direction of Robot
    actionDirection.type = RobotAction::RobotAction::DIRECTION;
    actionDirection.driveDirection = new std::vector<int>();
    RobotController::RobotController::Instance().setAction(std::move(actionDirection));

    this->innerMachine->setCurrent(Oberserve_State);
  }
}

