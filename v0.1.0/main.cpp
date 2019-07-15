#include <Janus/Signal.hpp>
#include <iostream>
#include <unistd.h>

#include <Janus/Data.hpp>

int main(){
// Test *p = new Test();
//  std::cout << p->getPid() << "\n";
//  p->lifeCycle();
//  delete p;

    Signal Stest;

    int pid = getpid();
    std::cout << "Process pid : " << pid << std::endl;
    Stest.add(30,3255);
    Stest.add(2,1);


    while(true){
    sleep(3);
    Stest.getManagerSignalsData().show();
    };




    return 0;
}
