#include "EraseLatLet.h"
#include <cctype>
char* eraseLatLet(char *destination, const char *source)
{
  const char *src = source;
  char *dst = destination;
  while (*src != '\0')
  {
    if (!std::isalpha(*src))
    {
      *dst = *src;
      dst++;
    }
    src++;
  }
  *dst = '\0';
  return destination;
}
