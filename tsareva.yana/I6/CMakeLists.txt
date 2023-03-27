cmake_minimum_required(VERSION 3.24)
project(I6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(I6
        arccos.cpp
        arccos.h
        factorial.cpp
        factorial.h
        main.cpp
        print_table.cpp
        print_table.h)
