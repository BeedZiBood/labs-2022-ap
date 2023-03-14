#ifndef READMATRIX_H
#define READMATRIX_H

#include <cstddef>
#include <fstream>

int* readMatrix(int* matrix, size_t size, std::ifstream& fileInput);

#endif
