#pragma once

#include <signal.h>

#include <Janus/Data.hpp>
#include <Mnemosyne/Manager.h>

class Signal {
public:
    Signal();
    ~Signal();

    void add(int sig_id, int pid);
    static void callback(int signalValue, siginfo_t *si, void *data);
    data::vector::Manager<SignalData> & getManagerSignalsData();


private:
    void setup(int sig_id, SignalAction *new_, SignalAction *backup_);

protected:

    data::map::Manager<int, ActionData> ManagerActionData;
    static data::vector::Manager<SignalData> ManagerSignalsData;
};






