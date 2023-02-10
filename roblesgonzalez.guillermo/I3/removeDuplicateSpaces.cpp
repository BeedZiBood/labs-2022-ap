#include <ctype.h>
#include <limits.h>
#include "removeDuplicateSpaces.h"
size_t removeDuplicateSpaces(char *destination, const char *source)
{
  size_t size = 0;
  size_t d = 0;
  while (isspace(source[d]))
  {
    d++;
  }
  while (source[d])
  {
    if (isspace(source[d]))
    {
      char space_char = source[d];
      while (isspace(source[d]))
      {
        d++;
      }
      destination[size] = space_char;
      size++;
    }
    else
    {
      destination[size] = source[d];
      size++;
    }
      d++;
  }
  if (size > 0)
  {
    size--;
    while (isspace(destination[size]))
    {
      size--;
    }
    size++;
  }
  destination[size] = '\0';
  return size;
}
