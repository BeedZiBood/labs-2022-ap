#include "array.hpp"
#include <cstddef>
#include <stdexcept>
#include <limits>

unsigned zasulsky::countDescendingThrees(const int* arr, size_t size)
{
  if (size < 3) {
    throw std::invalid_argument("Incorrect size");
  }
  unsigned count = 0;
  for (size_t i = 0; i < size - 2; i++) {
    if ((arr[i] > arr[i + 1]) && (arr[i + 1] > arr[i + 2])) {
      if (count == std::numeric_limits< size_t >::max()) {
        throw std::overflow_error("Overflow");
      }
      count++;
    }
  }
  return count;
}
const int* zasulsky::findEvenMax(const int* arr, size_t size)
{
  if (size == 0) {
    throw std::invalid_argument("Incorrect size");
  }
  const int* maxEven = nullptr;
  for (size_t i = 0; i < size; i++) {
    if ((arr[i] % 2 == 0) && ((maxEven == nullptr) || (arr[i] > *maxEven))) {
      maxEven = arr + i;
    }
  }
  if (maxEven == nullptr) {
    throw std::logic_error("Max even value not found");
  }
  return maxEven;
}
