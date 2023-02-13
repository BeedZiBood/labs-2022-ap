#ifndef WORKWITHIOANOTHER_H
#define WORKWITHIOANOTHER_H

#include <iostream>
#include <fstream>

std::uint16_t inputMatrixOrder(const char* file_name);

void printSpiralMatrix(const std::uint32_t* spiral_matrix,
    std::uint16_t matrixOrder,
    const char* file_name);

#endif
