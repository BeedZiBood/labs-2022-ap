#include "getothersymbols.h"
char *get_other_symbols(char *destination, const char *source)
{
  size_t k = 0;
  for (char i = 'a', j = 'A'; i <= 'z'; i++, j++)
  {
    bool fl = true;
    for (size_t d = 0; source[d]; d++)
    {
      if (source[d] == i || source[d] == j)
      {
        fl = false;
      }
    }
    if (fl)
    {
      destination[k] = i;
      k++;
    }
  }
  destination[k] = '\0';
  return destination;
}
