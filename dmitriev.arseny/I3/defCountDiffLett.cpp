#include "defCountDiffLett.h"
#include <cstddef>
#include <cctype>

size_t defCountDiffLett(const char* cStr)
{
  size_t count = 0;

  for (int i = 0, moreThanOne = 0; cStr[i]; i++, moreThanOne = 0)
  {
    if (std::isalpha(cStr[i]))
    {
      for (int j = i + 1; cStr[j]; j++)
      {
        if (cStr[i] == cStr[j])
        {
          moreThanOne = 1;
        }
      }
      if (!moreThanOne)
      {
        count++;
      }
    }

  }

  return count;
}
