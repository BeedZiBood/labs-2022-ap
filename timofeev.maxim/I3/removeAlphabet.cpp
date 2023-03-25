#include "removeAlphabet.h"
#include <cctype>
char *removeAlphabet(char *destination, const char *source)
{
  size_t sizeout = 0;
  size_t sizein = 0;
  while (source[sizein])
  {
    if (!std::isalpha(source[sizein]))
    {
      while (!std::isalpha(source[sizein]) && source[sizein])
      {
        char sumbl = (source[sizein]);
        destination[sizeout] = sumbl;
        sizeout++;
        sizein++;
      }
      sizein--;
    }
    sizein++;
  }
  destination[sizeout] = '\0';
  return destination;
}
