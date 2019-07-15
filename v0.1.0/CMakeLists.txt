cmake_minimum_required(VERSION 3.5)
project(Arbiter)

set(CMAKE_CXX_STANDARD 14)

#find_library(ZMQ_LIB libzmq)

include_directories(lib)

add_library(
        Janus
        src/Janus/Signal.cpp
        src/Janus/Data.cpp
        )

add_executable(main main.cpp)

target_link_libraries(main  Janus)

#target_link_libraries(main  ${ZMQ_LIB})
