#include "CheckRepeatingElements.h"
#include <stdexcept>

size_t checkRepeatEl(const int* array, size_t size, size_t index_m, size_t index_n)
{
  size_t repeat_cnt = 0;
  {
    size_t max_of_index = std::max(index_m, index_n);
    if (max_of_index > size)
    {
      throw std::invalid_argument("Error");
    }
  }
  if (index_m < index_n)
  {
    for (size_t i = index_m; i < index_n; i++)
    {
      for (size_t j = i + 1; j < index_n; j++)
      {
        if (array[i] == array[j])
        {
          repeat_cnt++;
          break;
        }
      }
    }
  }
  return repeat_cnt;
}


