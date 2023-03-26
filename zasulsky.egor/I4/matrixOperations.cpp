#include "matrixOperations.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>

size_t zasulsky::getMatrixIndex(size_t, size_t cols, size_t row, size_t col)
{
  return cols * row + col;
}

int zasulsky::getMatrixValue(const int* matrix, size_t rows, size_t cols, size_t row, size_t col)
{
  return matrix[getMatrixIndex(rows, cols, row, col)];
}

std::istream& zasulsky::fillMatrixFromStream(int* matrix, size_t rows, size_t cols, std::istream& in)
{
  for (size_t i = 0; i < rows * cols; i++) {
    in >> matrix[i];
    if (!in) {
      throw std::runtime_error("Input error");
    }
  }
  return in;
}
