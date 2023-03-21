#include "findEvenMax.hpp"
#include <cstddef>
#include <stdexcept>

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
