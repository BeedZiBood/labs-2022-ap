#include "delete_identical_chars.h"
#include <cctype>
#include <cstddef>

char *deleteIdenticalChars(char *destination, const char *cstring_first, const char *cstring_second)
{
  bool identical_chars = false;
  char *over_destination = destination;
  const char *start = cstring_second;
  while (*cstring_first)
  {
    cstring_second = start;
    while (*cstring_second)
    {
      if (*cstring_first == *cstring_second)
      {
        identical_chars = true;
      }
      cstring_second++;
    }
    if (!identical_chars)
    {
      *over_destination = *cstring_first;
      over_destination++;
    }
    identical_chars = false;
    cstring_first++;
  }
  *over_destination = '\0';
  return destination;
}
