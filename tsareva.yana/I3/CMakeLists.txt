cmake_minimum_required(VERSION 3.24)
project(I3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(I3
        change_register.cpp
        change_register.h
        generate_new_line.cpp
        generate_new_line.h
        ../common/golden_ratio.cpp
        ../common/golden_ratio.h
        check_similarity_letters.h
        check_similarity_letters.cpp
        main.cpp)
