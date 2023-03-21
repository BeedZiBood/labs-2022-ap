#include "findrepeatedsymbols.h"
#include <cstddef>

bool findRepeatedSymbols(const char* source)
{
  for (size_t i = 0; source[i]; i++)
  {
    for (size_t j = i + 1; source[j]; j++)
    {
      if (source[i] == source[j])
      {
        return true;
      }
    }
  }
  return false;
}
