#include "array.hpp"
#include <stdexcept>
#include <limits>
#include <cstddef>

odintsov::Array::Array(size_t cap):
  data(new int[cap]),
  size(0),
  cap(cap)
{}

odintsov::Array::~Array()
{
  delete [] data;
}

void odintsov::Array::append(int val)
{
  if (size == cap) {
    throw std::length_error("Error: cannot append to full array");
  }
  data[size++] = val;
}

const int* odintsov::findMax(const int* arr, size_t size, int lowBound, int highBound)
{
  const int* max = nullptr;
  for (size_t i = 0; i < size; i++) {
    if ((lowBound <= arr[i]) && (arr[i] <= highBound)) {
      if ((max == nullptr) || (*max < arr[i])) {
        max = arr + i;
      }
      if (*max == highBound) {
        return max;
      }
    }
  }
  if (max == nullptr) {
    throw std::logic_error("Error: max value could not be found in array");
  }
  return max;
}

float odintsov::getAvgEvenIndices(const int* arr, size_t size)
{
  float sum = 0.0f;
  size_t n = (size + 1) / 2;
  if (n == 0) {
    return 0.0f;
  }
  for (size_t i = 0; i < size; i += 2) {
    sum += 1.0f * arr[i];
  }
  return sum / n;
}
