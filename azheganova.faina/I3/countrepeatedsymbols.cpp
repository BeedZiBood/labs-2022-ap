#include "countrepeatedsymbols.h"

bool count_repeated_symbols(const char* source, int capacity)
{
  int countofrepeatedsymbol = 1;
  for (char i = 'a'; i <= 'z'; i++)
  {
    for (size_t sizestring = 0; sizestring < capacity; sizestring++)
    {
      if (i == source[sizestring])
      {
        countofrepeatedsymbol++;
      }
    }
    if (countofrepeatedsymbol > 1)
    {
      return true;
    }
    return false;
  }
}
