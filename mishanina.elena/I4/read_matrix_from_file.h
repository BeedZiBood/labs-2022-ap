#ifndef READ_MATRIX_FROM_FILE_H
#define READ_MATRIX_FROM_FILE_H
#include <fstream>
#include <istream>
#include <cstddef>

int* readMatrixFromFile(int* matrix, size_t rows, size_t columns, std::ifstream& input);

#endif
