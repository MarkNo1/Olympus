#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <unistd.h>
#include <exception>
#include <iostream>
#include "Status.hpp"

class ProcessHandler : public Status {
   public:
    ProcessHandler();

    ~ProcessHandler();

    /* * *
      Get the pid of the process
    * * */
    int getPid();

    /* * *
      Init pid of the process
    * * */
    void initPid();

    /* * *
      TODO LIFECYCLE
    * * */
    void lifeCycle();

   protected:
    /* * *
      TODO Initialization - state
    * * */
    virtual void initState();

    /* * *
      TODO Active - state
    * * */
    virtual void activeState();

    /* * *
      TODO Pause - state
    * * */
    virtual void pauseState();

    /* * *
      TODO Execption - state
    * * */
    virtual void errorState();

    /* * *
      TODO Inactive - state
    * * */
    virtual void inactiveState();

   protected:
    int pid;
};

#endif
