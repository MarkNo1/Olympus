//
// Created by renault on 30/08/18.
//

#ifndef ARBITER_MANAGER_H
#define ARBITER_MANAGER_H

#include <Mnemosyne/Data.h>
#include <Mnemosyne/Factory.h>
#include <iostream>
#include <vector>
#include <map>

namespace data {

    /**
     *  TODO :
     *          .inl implementation
     *          clean method
     *          override operator << std::cout
     *          for the rest its just beautiful :D
     */

    namespace vector {
        template<typename DataType>
        class Manager {
            using DataVect = std::vector<DataType*>;
            static_assert(std::is_base_of<Data, DataType>::value, "DataType must inherit from Data class");
        public:
            Manager() = default;

            ~Manager() = default;

            template<typename ...ArgsT>
            void add(ArgsT... args) {
                vector.push_back(factory.New(std::forward<ArgsT>(args)...));
            };

            void show(){
                for (const auto element: vector){
                    std::cout << "=========== \n";
                    std::cout << *element;
                }
            };

            DataType &getLastItem() { vector.back(); };

            DataVect &getVector() { return vector; };

        private:
            Factory <DataType> factory;
            DataVect vector;
        };
    }

    namespace map {
        template<typename KeyType, typename DataType>
        class Manager {
            static_assert(std::is_base_of<Data, DataType>::value, "DataType must inherit from Data class");
        public:
            Manager()=default;
            ~Manager()=default;

            template<typename ...ArgsT>
            void add(KeyType key, ArgsT... args){
                map.insert(std::pair<KeyType,DataType *>(key,factory.New(std::forward<ArgsT>(args)...)));
            };

            void clean(){};

            DataType &  getItem(KeyType &value){return map[value];};

            std::map<KeyType, DataType> &getMap(){ return map;};

        private:
            Factory<DataType> factory;
            std::map<KeyType, DataType *> map;
        };
    }
}





#endif //ARBITER_MANAGER_H
