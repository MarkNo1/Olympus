//
// Created by MarkNo1 on 28/08/18.
//

#include <Janus/Data.hpp>


/***********************************
 *                                 *
 *           SignalData            *
 *                                 *
 ***********************************/


/**
 * Constructor
 * @param signal_id_
 * @param information_
 * @param data_
 */

SignalData::SignalData(int signal_id_, siginfo_t *information_, void *data_):
                                                    signal_id(signal_id_),
                                                    data(data_) {
    information = new siginfo_t;
    copyInformationStruct(information_);
    pid_sender=information_->si_pid;

}
/**
 * Destructor
 */
SignalData::~SignalData() {
    delete information;
}

/**
 * Get information structure
 * @return siginfo_t information
 */
siginfo_t *SignalData::getInformation() {
    return information;
}

/**
 * Get pid sender
 * @return pid_t pidSender
 */
pid_t SignalData::getPidSender() const {
    return pid_sender;
}

/**
 * Get Signal id
 * @return int signal_id
 */
int SignalData::getSignalID() const{
    return signal_id;
}


/**
 * get data sent
 * @return void* data
 */
void *SignalData::getData() {
    return data;
}

/**
 * Print
 * @param os
 * @param dt
 * @return
 */
std::ostream& operator<<(std::ostream& os, const SignalData& dt){
        os << "PID: " << dt.getPidSender() << std::endl;
        os << "SIG: " << dt.getSignalID() << std::endl;
}




/**
 * Copy information struct
 * @param information_
 */
void SignalData::copyInformationStruct(siginfo_t *information_) {
    information->si_code = information_->si_code;
    information_->si_errno = information->si_errno;
    information->si_signo = information->si_signo;
}





/***********************************
 *                                 *
 *  ActionData   *
 *                                 *
 ***********************************/

/**
 * Constructor
 * @param pid_handled_
 * @param signal_id_
 * @param new_action_
 * @param backup_action_
 */
ActionData::ActionData(int pid_handled_, int signal_id_, SignalAction new_action_,
                                                           SignalAction backup_action_):
                                                           pid_handled(pid_handled_),
                                                           signal_id(signal_id_),
                                                           new_action(new_action_),
                                                           backup_action(backup_action_){}

/**
 * Destructor
 */
ActionData::~ActionData() {
}

/**
 * Get pid_t pid_handled
 * @return
 */
pid_t &ActionData::getPidHandled() {
    return pid_handled;
}


/**
 * Get int signal_id
 * @return
 */
int &ActionData::getSignalID() {
    return signal_id;
}


/**
 * Get SignalAction new_action
 * @return
 */
SignalAction & ActionData::getNewAction() {
    return new_action;
}

/**
 * Get SignalAction backup_action
 * @return
 */
SignalAction & ActionData::getBackupAction() {
    return backup_action;
}

