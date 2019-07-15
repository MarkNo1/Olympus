//
// Created by MarkNo1 on 28/08/18.
//
# pragma once

#include <signal.h>
#include <iostream>
#include <Mnemosyne/Data.h>

using SignalAction = struct sigaction ;

class SignalData : Data{
public:
    SignalData(int signalValue, siginfo_t *info, void *data);
    ~SignalData();
    siginfo_t* getInformation();
    pid_t  getPidSender() const;
    int getSignalID() const;
    void* getData();
    friend std::ostream& operator<<(std::ostream& os, const SignalData& dt);
private:
    void copyInformationStruct(siginfo_t *information_);

private:
    siginfo_t *information;
    pid_t pid_sender;
    int signal_id;
    void *data;
};


class ActionData: Data {
public:
    ActionData(int pid_handled_, int signal_id_,
                                 SignalAction new_action_,
                                 SignalAction backup_action_);
    ~ActionData();
    pid_t & getPidHandled();
    int & getSignalID();
    SignalAction & getNewAction();
    SignalAction & getBackupAction();

private:
    SignalAction backup_action;
    SignalAction new_action;
    pid_t pid_handled;
    int signal_id;

};


