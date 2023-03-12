cmake_minimum_required(VERSION 3.24)
project(I1)

set(CMAKE_CXX_STANDARD 17)

add_executable(I1 main.cpp main.cpp/main.cpp LocalMax.h sequence.cpp sequence.cpp sequence.h LocalMax.cpp LocalMax.cpp sequence.cpp)
