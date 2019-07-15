#include "ProcessHandler.hpp"

/**
 * Default Contructor.
 */
ProcessHandler::ProcessHandler() : StatusSignals() { initPid(); }

/**
   Destructor.
*/
ProcessHandler::~ProcessHandler() {}

/* * *
Get the pid of the ProcessHandler
* * */
int ProcessHandler::getPid() { return pid; }

/* * *
Init pid of the ProcessHandler
* * */
void ProcessHandler::initPid() { pid = getpid(); }

/* * *
  Initialization - state
* * */
void ProcessHandler::initState() {}

/* * *
  Active - state
* * */
void ProcessHandler::activeState() {}

/* * *
  Pause - state
* * */
void ProcessHandler::pauseState() {}

/* * *
  Error - state
* * */
void ProcessHandler::errorState() {}

/* * *
  Inactive - state
* * */
void ProcessHandler::inactiveState() {}

/* * *

      LIFECYCLE

* * */
void ProcessHandler::lifeCycle() {
    while (true) {
        std::cout << "- ProcessHandler@lifeCycle - \n";

        getStatus();

        switch (status) {
            case Status::init:
                initState();
                break;

            case Status::active:
                activeState();
                break;

            case Status::pause:
                pauseState();
                break;

            case Status::inactive:
                inactiveState();
                break;

            default:
                errorState();
                break;
        }
    }
}
