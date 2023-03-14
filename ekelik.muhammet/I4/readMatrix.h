#ifndef READ_MATRIX_H
#define READ_MATRIX_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

void readMatrix(std::ifstream& inputFile, int* matrix, size_t numRows, size_t numCols);

#endif
