#include "expandCString.h"

char *expandCString(char *cstring, size_t size, size_t &capacity)
{
  char *newstr = new char[capacity + 20];
  for (auto i = cstring, j = newstr; i != cstring + size; i++, j++) {
    *j = *i;
  }
  capacity += 20;
  return newstr;
}
