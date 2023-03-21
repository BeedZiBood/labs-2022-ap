#include "threeRepeats.hpp"
#include <cstddef>
#include "getMatrixValue.hpp"

size_t odintsov::countValRepeatsInCol(int val, const int* arr, size_t rows, size_t cols, size_t col) {
  size_t count = 0;
  for (size_t i = 0; i < rows; i++) {
    if (val == odintsov::getMatrixValue(arr, rows, cols, i, col)) {
      count++;
    }
  }
  return count;
}

size_t odintsov::countValRepeatsInRow(int val, const int* arr, size_t rows, size_t cols, size_t row)
{
  size_t count = 0;
  for (size_t i = 0; i < cols; i++) {
    if (val == odintsov::getMatrixValue(arr, rows, cols, row, i)) {
      count++;
    }
  }
  return count;
}

bool odintsov::isThreeRepeatsInCol(const int* arr, size_t rows, size_t cols, size_t col)
{
  for (size_t i = 0; i < rows - 2; i++) {
    int val = odintsov::getMatrixValue(arr, rows, cols, i, col);
    if (countValRepeatsInCol(val, arr, rows, cols, col) >= 3) {
      return true;
    }
  }
  return false;
}

bool odintsov::isThreeRepeatsInRow(const int* arr, size_t rows, size_t cols, size_t row)
{
  for (size_t i = 0; i < cols - 2; i++) {
    int val = odintsov::getMatrixValue(arr, rows, cols, row, i);
    if (countValRepeatsInRow(val, arr, rows, cols, row) >= 3) {
      return true;
    }
  }
  return false;
}

size_t odintsov::countColsWithThreeRepeats(const int* arr, size_t rows, size_t cols)
{
  size_t colsThreeRepeat = 0;
  for (size_t i = 0; i < cols; i++) {
    if (isThreeRepeatsInCol(arr, rows, cols, i)) {
      colsThreeRepeat++;
    }
  }
  return colsThreeRepeat;
}

size_t odintsov::countRowsWithThreeRepeats(const int* arr, size_t rows, size_t cols)
{
  size_t rowsThreeRepeat = 0;
  for (size_t i = 0; i < rows; i++) {
    if (isThreeRepeatsInRow(arr, rows, cols, i)) {
      rowsThreeRepeat++;
    }
  }
  return rowsThreeRepeat;
}
