//
// Created by renault on 30/08/18.
//

#ifndef ARBITER_FACTORY_H
#define ARBITER_FACTORY_H

#include <Mnemosyne/Data.h>
#include <utility>

namespace data {

    template<typename DataType>
    class Factory {
        static_assert(std::is_base_of<Data, DataType>::value, "DataType must inherit from Data class");
    public:
        Factory() = default;

        ~Factory() = default;

        template<typename... ArgsT>
        DataType *New(ArgsT... args) {
            return new DataType(std::forward<ArgsT>(args)...);
        };

        virtual void Delete(DataType *data) {
            delete data;
        };
    };

}

#endif //ARBITER_FACTORY_H
