cmake_minimum_required(VERSION 3.24)
project(I4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(I4
        check_lower_triangular_matrix.cpp
        check_lower_triangular_matrix.h
        count_column_which_duplicate_elements.cpp
        count_column_which_duplicate_elements.h
        main.cpp)
