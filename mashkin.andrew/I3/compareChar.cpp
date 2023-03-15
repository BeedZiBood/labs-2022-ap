#include "compareChar.h"
#include <cstddef>

bool compare(const char* fromThreeLetters, const char* i, size_t endIndex)
{
  for (const char* j = fromThreeLetters; endIndex != 3; j++, endIndex++)
  {
    if (*j == *i)
    {
      return false;
    }
  }
  return true;
}
