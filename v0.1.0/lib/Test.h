#ifndef __TEST_H__
#define __TEST_H__

#include <unistd.h>
#include "ProcessHandler.hpp"

class Test : public ProcessHandler {
   public:
    Test(){};
    ~Test(){};

   private:
    void initState() {
        std::cout << "state init \n";
        usleep(10000000);
    };

    /* * *
      TODO Active - state
    * * */
    void activeState() {
        std::cout << "state  active\n";
        usleep(10000000);
    };

    /* * *
      TODO Pause - state
    * * */
    void pauseState() {
        std::cout << "state  pause\n";
        usleep(10000000);
    };

    /* * *
      TODO Execption - state
    * * */
    void errorState() {
        std::cout << "state  error\n";
        usleep(10000000);
    };

    /* * *
      TODO Inactive - state
    * * */
    void inactiveState() {
        std::cout << "state  inactive\n";
        usleep(10000000);
    };
};

#endif
