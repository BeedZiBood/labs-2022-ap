#include "CheckRepeat.hpp"
#include <stdexcept>
#include <cstddef>

bool has_repeating_numbers(const int* arr, size_t size, unsigned int index_m, unsigned int index_n)
{
  bool has_repeating = false;
  size_t max_of_index = std::max(index_m, index_n);

  if (max_of_index > size)
  {
    throw std::invalid_argument("Invalid indexes!");
  }
  if (index_n < index_m)
  {
    unsigned int temp = index_m;
    index_m = index_n;
    index_n = temp;
  }
  else if (index_n == index_m)
  {
    return false;
  }

  for (unsigned int i = index_m; i <= index_n; i++)
  {
    for (unsigned int j = index_m; j < index_n - 1; j++)
    {
      if (arr[i] == arr[j] && i != j)
      {
        has_repeating = true;
        break;
      }
    }
  }

  return has_repeating;
}
