#include <exception>
#include "ArrayOperations.h"

std::istream& inputArray(int* arr, size_t size, std::istream& stream)
{
  for (size_t i = 0; i < size; ++i) {
    stream >> arr[i];
  }
  return stream;
}

size_t sortedRowsCount(const int* arr, size_t rows, size_t cols)
{
  size_t cnt = 0;

  for (size_t i = 0; i < rows; ++i) {
    cnt++;
    for (size_t j = 0; j < cols - 1; ++j) {
      size_t offset = i * cols;
      if (arr[offset + j] > arr[offset + j + 1]) {
        cnt--;
        break;
      }
    }
  }
  return cnt;
}

bool isTriangular(const int* arr, size_t rows, size_t cols)
{
  if (rows != cols) {
    return false;
  }

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = i + 1; j < cols; ++j) {
      size_t offset = i * cols;
      if (arr[offset + j] != 0) {
        return false;
      }
    }
  }
  return true;
}
