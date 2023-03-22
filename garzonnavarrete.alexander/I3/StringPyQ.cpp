#include "StringPyQ.h"
#include <cstddef>

char *getSumOfStrings(char *arr_sum, const char *cstring_p, const char *cstring_q)
{
  char *result = arr_sum;
  while (*cstring_p || *cstring_q)
  {
    if (*cstring_p)
    {
      *result++ = *cstring_p++;
    }
    if (*cstring_q)
    {
      *result++ = *cstring_q++;
    }
  }
  *result = '\0';
  return arr_sum;
}
