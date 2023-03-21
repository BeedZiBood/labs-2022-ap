#include "SumStrings.hpp"
#include <cstddef>

char *sum_strings(char *arr_sum, const char *cstring_one, const char *cstring_two)
{

  size_t size_sum = 0;

  for (size_t i = 0; *cstring_one || *cstring_two; i++)
  {
    if ((i % 2 == 0 && *cstring_one) || !(*cstring_two))
    {
      arr_sum[i] = *cstring_one;
      size_sum++;
      if (!(*cstring_two))
      {
        cstring_one++;
      }
    }
    else if ((i % 2 != 0 && *cstring_two) || !(*cstring_one))
    {
      arr_sum[i] = *cstring_two;
      size_sum++;
      cstring_two++;
    }
  }

  arr_sum[size_sum] = '\0';

  return arr_sum;

}
