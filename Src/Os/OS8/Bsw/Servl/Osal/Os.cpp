/////////////////////////////////////////////////////// 
//  Copyright 2013 Stephan Hage.
//  Copyright 2013 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

#include <array>
#include <algorithm>

#include <Bsw/Servl/Osal/Os.h>
#include <Bsw/Common/Irq/McalIrq.h>
#include <Bsw/Common/Cpu/McalCpu.h>
#include <Bsw/Util/Time/Time.hpp>

EXTERN_C
{
  typedef void (*function_type_extern_c)(void);
  typedef uint8 tOsTcbVariableRamPart;
  tOsTcbVariableRamPart Os_aTcbVariableRamPart[rpMaxID + 1U];
  uint8 Os_ucTaskIndex;
}

namespace os
{
  class task_control_block
  {
  public:
    typedef function_type_extern_c function_type;

    typedef util::timer<Gpt_ValueType> timer_type;
    typedef timer_type::tick_type      tick_type;

    task_control_block(const function_type i,
                       const function_type f,
                       const tick_type c,
                       const tick_type o = static_cast<tick_type>(0U)) : init (i),
                                                                         func (f),
                                                                         cycle(c),
                                                                         timer(o) { }

    task_control_block(const task_control_block& tcb) : init (tcb.init),
                                                        func (tcb.func),
                                                        cycle(tcb.cycle),
                                                        timer(tcb.timer) { }

    void initialize(void) const { init(); }

    bool execute(void)
    {
      if(timer.timeout())
      {
        // Increment the task's interval timer with the task cycle.
        timer.start_interval(cycle);

        // Call the task.
        func();

        return true;
      }
      else
      {
        return false;
      }
    }

  private:
    const function_type init;
    const function_type func;
    const tick_type     cycle;
    timer_type          timer;

    task_control_block();
    task_control_block& operator=(const task_control_block&);
  };

  typedef std::array<task_control_block, OS_TASK_COUNT> task_list_type;

  task_list_type task_list = OS_TASK_LIST;

  void start_os(void)
  {
    // Initialize the tasks.
    std::for_each(task_list.begin(),
                  task_list.end(),
                  [](const task_control_block& tcb)
                  {
                    tcb.initialize();
                  });

    bool ecu_state_is_shutdown = false;

    do
    {
      // Find the next ready task using a priority-based find algorithm.
      const task_list_type::const_iterator it_ready_task =
        std::find_if(task_list.begin(),
                     task_list.end(),
                     [](task_control_block& tcb) -> bool
                     {
                       return tcb.execute();
                     });

      // Acquire the new ecu state from the running task.
      EcuM_StateType ecu_state_from_the_running_task;

      const Std_ReturnType result = EcuM_GetState(&ecu_state_from_the_running_task);

      static_cast<void>(result);

      ecu_state_is_shutdown = (ecu_state_from_the_running_task == ECUM_STATE_SHUTDOWN);

      // Did we reach the end of the list without finding any ready-task?
      const bool no_ready_task_was_found = (it_ready_task == task_list.end());

      // If no ready-task was found, then service the idle task.
      if(no_ready_task_was_found && (ecu_state_is_shutdown == false))
      {
        OS_TASK_IDLE();
      }
    }
    while(ecu_state_is_shutdown == false);

    // Here, we know that the state ECUM_STATE_SHUTDOWN has been set by a user.
    // We call ShutdownOS(), and ShutdownOS() will subsequently call
    // the application-specific instance of ShutdownHook_App().
    // Control might or might *not* return to the main() subroutine,
    // depending on the application-specific functionality of
    // ShutdownHook_App().
    ShutdownOS();
  }
}

EXTERN_C void StartOS(void)
{
  StartupHook();

  os::start_os();
}

EXTERN_C void StartupHook(void)
{
  EnableAllInterrupts();
}

EXTERN_C
StatusType SetEvent(TaskIdType TaskIndex, EventMaskType TaskEvent)
{
  if (TaskIndex < rpMaxID)
  {
    McalIrqDisableAll();
    Os_aTcbVariableRamPart[static_cast<uint8_least>(TaskIndex)] |= TaskEvent;
    McalIrqEnableAll();

    return E_OK;
  }
  else
  {
    return E_NOT_OK;
  }
}

EXTERN_C
StatusType ClearEvent(EventMaskType TaskEvent)
{
  if (Os_ucTaskIndex < static_cast<uint8_least>(rpMaxID))
  {
    EventMaskType MyClearMask = static_cast<EventMaskType>(~TaskEvent);

    McalIrqDisableAll();
    Os_aTcbVariableRamPart[Os_ucTaskIndex] &= MyClearMask;
    McalIrqEnableAll();

    return E_OK;
  }
  else
  {
    return E_NOT_OK;
  }
}

EXTERN_C
StatusType GetEvent(TaskIdType TaskIndex, EventMaskRefType TaskEventReference)
{
  if (TaskIndex < rpMaxID)
  {
    *TaskEventReference = Os_aTcbVariableRamPart[static_cast<uint8_least>(TaskIndex)];

    return E_OK;
  }
  else
  {
    *TaskEventReference = static_cast<EventMaskType>(0U);

    return E_NOT_OK;
  }
}

EXTERN_C
void DisableAllInterrupts(void)
{
  // Disable All Interrupts
  mcal::irq::disable_all();
}

EXTERN_C
void EnableAllInterrupts(void)
{
  // Enable global interrupts.
  mcal::irq::enable_all();
}

EXTERN_C
void ShutdownOS(void)
{
  EcuM_ShutdownHook_App();

  ShutdownHook();

  EcuM_Shutdown();
}

EXTERN_C
void ShutdownHook(void)
{
  DisableAllInterrupts();

  EcuM_ShutdownHook();
}
