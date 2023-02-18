#include "increaseLineSize.h"
char *increaseSize(const char *cstring, size_t capasity, size_t size)
{
  char *newstring = new char[capasity + 20];
  char *j = newstring;
  for (const char *i = cstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  return newstring;
}
