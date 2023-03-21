#include "ArrayOperations.h"
#include <iostream>
#include <limits>
#include <algorithm>

void printArray(std::ostream& stream, const int* arr, size_t size, const char* sep)
{
  size_t last_id = size - 1;
  for (size_t i = 0; i < last_id; i++) {
    stream << arr[i] << sep;
  }
  stream << arr[last_id];
}

void randomizeArray(int* arr, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    arr[i] = std::rand();
  }
}

void shitByIndexes(int* arr, size_t size, size_t n, size_t m)
{
  if (m > size) {
    throw std::runtime_error("index out of range");
  }
  if (m < n) {
    throw std::runtime_error("left index cannot be greater than right");
  }
  if (size == m) {
    return;
  }
  int curr = 0;

  for (size_t j = 1; j <= m - n; ++j) {
    curr = arr[size - 1];

    for (size_t i = size - 2; i >= n; --i) {
      std::swap(curr, arr[i]);
    }
    arr[size - 1] = curr;
  }
}

const int* maxEven(const int* arr, size_t size)
{
  int max = std::numeric_limits< int >::min();
  const int* max_elem = nullptr;

  for (size_t i = 1; i < size; i += 2) {
    if (arr[i] > max) {
      max = arr[i];
      max_elem = arr + i;
    }
  }

  return max_elem;
}
