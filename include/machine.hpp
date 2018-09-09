/*
 * Machine.hpp
 *
 *  Created on: Dec 9, 2017
 *      Author: stoffer
 */

#pragma once

#define FSM_MAX_CYCLE_PER_SECOND 2
#define FSM_MAX_CYCLE_DURATION_MSEC (1000 / FSM_MAX_CYCLE_PER_SECOND)

#include "sensors/Sensor.hpp"
#include "sensors/DistanceSensor.hpp"
#include "sensors/BumperSensor.hpp"
#include "actuators/HeartBeat.hpp"
#include "RobotWorldMap.hpp"
#include <memory>

namespace FiniteStateMachine
{
  int runFsm();

  class Machine
  {
  private:
    enum InternalMachineState
    {
      Init_State,Oberserve_State,Decision_State,Act_State,Finalizing_State
    };

    class MachineState
    {
    public:
      MachineState(Machine *innerMachine);
      virtual ~MachineState();
      virtual void doInitialiation();
      virtual void doObserve();
      virtual void doDecition();
      virtual void doAct();
      virtual void doFinalizing();

      Machine *innerMachine;
    private:
      MachineState();
    };

    class InitialisationState final: public MachineState
    {
    public:
      InitialisationState(Machine *innerMachine);
      ~InitialisationState();
      void doInitialiation() override;
    };

    class ObserveState final: public MachineState
    {
    public:
      ObserveState(Machine *innerMachine);
      ~ObserveState();
      void doObserve() override;
    private:
    };
    class DecisionState final: public MachineState
    {
    public:
      DecisionState(Machine *innerMachine);
      ~DecisionState();
      void doDecition() override;
    };
    class ActState final: public MachineState
    {
    public:
      ActState(Machine *innerMachine);
      ~ActState();
      void doAct() override;
    };
    class FinalizingState final: public MachineState
    {
    public:
      FinalizingState(Machine *innerMachine);
      ~FinalizingState();
      void doFinalizing() override;
    };
    std::shared_ptr<MachineState> currentState;
    std::shared_ptr<InitialisationState> initialisationState;
    std::shared_ptr<ObserveState> observeState;
    std::shared_ptr<DecisionState> decisionState;
    std::shared_ptr<ActState> actState;
    std::shared_ptr<FinalizingState> finalizingState;
  public:
    Machine();
    ~Machine();
    void setCurrent(InternalMachineState newState);
    void doInitialiation();
    void doObserve();
    void doDecition();
    void doAct();
    void doFinalizing();
  };
} /* namespace FiniteStateMachine */
