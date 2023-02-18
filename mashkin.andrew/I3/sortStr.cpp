#include "sortStr.h"
#include <cstddef>
#include <algorithm>

char* sort(char* fromThreeLetters, size_t endIndex)
{
  for (char* i = fromThreeLetters; endIndex != 3; i++, endIndex++)
  {
    char* var1 = i;
    var1++;
    size_t end = 0;
    for (char* j = var1; end != 2 - endIndex; j++, end++)
    {
      if (*i > *j)
      {
        std::swap(*j, *i);
      }
    }
  }
  return fromThreeLetters;
}
