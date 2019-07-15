//
// Created by renault on 30/08/18.
//

#ifndef ARBITER_DATA_H
#define ARBITER_DATA_H

#include <iostream>

class Data{
public:
    Data()=default;
    ~Data()=default;

    virtual void destroy() {std::cout << "Destroy not Implemented" << std::endl;};
};


#endif //ARBITER_DATA_H
