#include <Janus/Signal.hpp>

#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
#include <signal.h>
#include <string.h>

data::vector::Manager<SignalData> Signal::ManagerSignalsData;

/**
 * Default Contructor.
 */
Signal::Signal(){}

/**
 * Destructor.
 */
Signal::~Signal() {

}


/**
 *  Catch the signal
 * @param signalValue
 * @param info
 * @param data
 */
void Signal::callback(int signalValue, siginfo_t *info, void *data) {

    // Store the Signal Received Information in the queue
    Signal::ManagerSignalsData.add(signalValue, info, data);

    std::cout << "Signal@callback: " << signalValue
              << "  from pid: " << (int) info->si_pid << std::endl;
}


/**
 *  Setup signal handler
 * @param sig_id
 * @param new_
 * @param backup_
 */
void Signal::setup(int sig_id, SignalAction *new_, SignalAction *backup_) {
    // Clean signalID
    sigemptyset(&new_->sa_mask);
    // Add signal to catch
    sigaddset(&new_->sa_mask, sig_id);
    // Optional Flag set none
    new_->sa_flags = SA_SIGINFO;
    // Assign callback
    new_->sa_handler = (sighandler_t)(Signal::callback);
    // Copy previous signal
    sigaction(sig_id, NULL, backup_);
    // Attach signal to process
    sigaction(sig_id, new_, NULL);
}


/**
 * Add signal to catch
 * @param sig_id
 * @param pid
 */
void Signal::add(int sig_id, int pid) {
    SignalAction new_, backup_;

    // Init the struct
    memset(&new_, '\0', sizeof(SignalAction));
    memset(&backup_,'\0', sizeof(SignalAction));

    // Attach the signal
    setup(sig_id, &new_, &backup_);

    // Add the ActionInfo to the map
//    DMmActions.add(sig_id, actionFactory.New(pid, sig_id, new_, backup_));
    ManagerActionData.add(pid, pid, sig_id, new_, backup_);
    std::cout << "Signal:" << sig_id << " from process:" << pid << " now is handled!" << std::endl;
}

/**
 * Return Queue
 * @return  DataManagerVector DMvSignalsQueue
 */
data::vector::Manager<SignalData> & Signal::getManagerSignalsData() {
    return Signal::ManagerSignalsData;
}

