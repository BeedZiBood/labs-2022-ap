#include "is-repeating-points-in-array.hpp"

bool chemodurov::isRepeatingPointsInArray(const point_t * arr, size_t arr_size)
{
  for (size_t i = 0; i < arr_size; ++i)
  {
    for (size_t j = i + 1; j < arr_size; ++j)
    {
      if (arr[i] == arr[j])
      {
        return true;
      }
    }
  }
  return false;
}
