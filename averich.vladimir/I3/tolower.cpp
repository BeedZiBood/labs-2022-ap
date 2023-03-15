#include "tolower.h"

char to_lower(char c)
{
  if (c >= 'A' && c <= 'Z')
  {
    c += ' ';// 'A'-'Z' > 'a'-'z', to_lower analogue
  }
  return c;
}
