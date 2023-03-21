#include "countDescendingThrees.hpp"
#include <cstddef>
#include <stdexcept>

size_t zasulsky::countDescendingThrees(const int* arr, size_t size)
{
  if (size < 3) {
    throw std::invalid_argument("Incorrect size");
  }
  size_t count = 0;
  for (size_t i = 0; i < size - 2; i++) {
    if ((arr[i] > arr[i + 1]) && (arr[i + 1] > arr[i + 2])) {
      count++;
    }
  }
  return count;
}
