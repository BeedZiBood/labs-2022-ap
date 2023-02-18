#include "countduplicates.hpp"
#include "partitionbyascending.hpp"
#include <cstddef>
#include <algorithm>

size_t countDuplicates(int* array, const size_t size)
{
  size_t count = 0;
  size_t current_count = 1;

  array = partitionByAscending(array, array + size);
  for (size_t i = 0; i < size - 1; i++)
  {
    if (array[i] == array[i + 1])
    {
      current_count++;
    }
    else
    {
      if (current_count> 1)
      {
        count += current_count;
      }
      current_count = 1;
    }
  }
  return count;
}

