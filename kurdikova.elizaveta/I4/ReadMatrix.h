#ifndef READMATRIX_H
#define READMATRIX_H
#include <fstream>

int* readMatrixFromFile(int* matrix, size_t rows, size_t columns, std::ifstream& inputFile);
#endif
