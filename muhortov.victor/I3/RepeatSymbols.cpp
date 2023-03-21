#include "RepeatSymbols.hpp"

char *repeatSymbols(char *destination, const char *cstring)
{
  char *startpos = destination;
  bool repeat = false;
  bool finded = false;
  char symbol = ' ';

  while (*cstring)
  {
    symbol = *cstring;
    for (const char *i = cstring + 1; *i != '\0'; i++)
    {
      if (symbol == *i)
      {
        repeat = true;
      }
    }
    for (char *i = startpos; i < destination; i++)
    {
      if (symbol == *i)
      {
        finded = true;
      }
    }
    if (repeat && !finded && symbol != ' ')
    {
      *destination = symbol;
      destination++;
    }
    repeat = false;
    finded = false;
    cstring++;
  }

  *destination = '\0';

  return destination;
}
