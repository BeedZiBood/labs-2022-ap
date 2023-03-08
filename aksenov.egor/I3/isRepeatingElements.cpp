#include "isRepeatingElements.h"
#include <cctype>
#include <cstddef>
bool isRepeatingElements(const char *src)
{
  const char *p1 = src;
  const char *p2 = src + 1;
  while (*p1 != '\0')
  {
    while (*p2 != '\0')
    {
      if (*p1 == *p2)
      {
        return true;
      }
      p2++;
    }
    p1++;
    p2 = p1 + 1;
  }
  return false;
}
