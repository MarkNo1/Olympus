#ifndef __STATUS_SIGNALHANDLER_H__
#define __STATUS_SIGNALHANDLER_H__

#include <memory>
#include <vector>
#include "Signal.hpp"

enum class Status { init = 10, active = 12, pause = 16, inactive = 17, error = 30 };

class Cast {
   private:
    Cast();

   public:
    static Status sig2stat(int signal);
    static int stat2sig(Status status);
};

class Status {
   public:
    typedef std::shared_ptr<Signal> signalManagerPtr;

    Status();

    ~Status();

   private:
    void init_signal_handler();
    void set_initState_signal();
    void set_activeState_signal();
    void set_inactiveState_signal();
    void set_pauseState_signal();
    void set_errorState_signal();

   protected:
    void getStatus();

   protected:
    Status status;
    sHandler handlerPtr;
};

#endif
