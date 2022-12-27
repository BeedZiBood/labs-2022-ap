#include "samePositiveElements.h"
#include <cstddef>

bool isThereTheSamePositiveElements(const int* arr, const size_t size, bool& ans)
{
  for (size_t i = 0; i + 1 < size; ++i)
  {
    if (arr[i] < 1)
    {
      continue;
    }
    for (size_t j = i + 1; j < size; ++j)
    {
      if (arr[j] < 1)
      {
        continue;
      }
      ans = arr[i] == arr[j];
      if (ans)
      {
        return ans;
      }
    }
  }
  return ans;
}
