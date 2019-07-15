#include "Status.hpp"

Status Cast::sig2stat(int sig) {
    switch (sig) {
        case 10:
            return Status::init;
        case 12:
            return Status::active;
        case 30:
            return Status::pause;
        case 16:
            return Status::inactive;

        default:
            return Status::error;
    }
}

int Cast::stat2sig(Status status) {
    switch (status) {
        case Status::init:
            return 10;
        case Status::active:
            return 12;
        case Status::pause:
            return 30;
        case Status::inactive:
            return 16;

        default:
            return 31;
    }
}

Status::Status() {
    init_signal_handler();
    set_initState_signal();
    set_activeState_signal();
    set_inactiveState_signal();
    set_pauseState_signal();
    set_errorState_signal();
}

Status::~Status() {}

void Status::init_signal_handler() { signalManagerPtr = std::make_shared<Signal>(); }

void Status::set_initState_signal() { signalManagerPtr->add(Cast::stat2sig(Status::init), ); }

void Status::set_activeState_signal() { signalManagerPtr->add(Cast::stat2sig(Status::active)); }

void Status::set_pauseState_signal() { signalManagerPtr->add(Cast::stat2sig(Status::pause)); }

void Status::set_inactiveState_signal() { signalManagerPtr->add(Cast::stat2sig(Status::inactive)); }

void Status::set_errorState_signal() { signalManagerPtr->add(Cast::stat2sig(Status::error)); }

void Status::getStatus() { status = Cast::sig2stat(signalManagerPtr->getSigReceived()); }
