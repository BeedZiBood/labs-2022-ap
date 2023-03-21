#include "unitestring.hpp"
#include <cstddef>

char* uniteString(char* destination, const char* source1, const char* source2)
{
  if ((source1 == nullptr) || (source2 == nullptr))
  {
    return nullptr;
  }

  char* j = destination;
  const char* s1 = source1;
  const char* s2 = source2;

  while ((*s1 != '\0') && (*s2 != '\0'))
  {
    *j++ = *s1++;
    *j++ = *s2++;
  }

  if (*s1 != '\0')
  {
    while (*s1 != '\0')
    {
      *j++ = *s1++;
    }
  }
  else if (*s2 != '\0')
  {
    while (*s2 != '\0')
    {
      *j++ = *s2++;
    }
  }

  *j = '\0';
  return destination;
}
