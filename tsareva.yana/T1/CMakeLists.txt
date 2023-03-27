cmake_minimum_required(VERSION 3.24)
project(T1)

set(CMAKE_CXX_STANDARD 14)

include_directories(../common)
set(SOURCE_FILES
        ../common/golden_ratio.h)

add_executable(T1
        ${SOURCE_FILES}
        base_types.cpp
        base_types.h
        main.cpp
        rectangle.cpp
        rectangle.h
        shape.h parallelogram.cpp diamond.h diamond.cpp isotropic_scale.h isotropic_scale.cpp)
