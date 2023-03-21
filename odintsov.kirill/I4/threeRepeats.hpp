#ifndef THREEREPEATS_HPP
#define THREEREPEATS_HPP

#include <cstddef>

namespace odintsov {
  int getMatrixVal(const int* arr, size_t rows, size_t cols, size_t x, size_t y);
  size_t countValRepeatsInCol(int val, const int* arr, size_t rows, size_t cols, size_t col);
  size_t countValRepeatsInRow(int val, const int* arr, size_t rows, size_t cols, size_t row);
  bool isThreeRepeatsInCol(const int* arr, size_t rows, size_t cols, size_t col);
  bool isThreeRepeatsInRow(const int* arr, size_t rows, size_t cols, size_t row);
  size_t countColsWithThreeRepeats(const int* arr, size_t rows, size_t cols);
  size_t countRowsWithThreeRepeats(const int* arr, size_t rows, size_t cols);
}

#endif
