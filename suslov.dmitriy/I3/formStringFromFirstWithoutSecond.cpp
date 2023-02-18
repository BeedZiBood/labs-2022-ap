#include "formStringFromFirstWithoutSecond.h"
char *formStringFromFirstWithoutSecond(char *destination, const char *source_1, const char *source_2)
{
  char *c = destination;
  const char *i = source_1;
  while (*i != '\0')
  {
    const char *j = source_2;
    while (*j != '\0' && *j != *i)
    {
      j++;
    }
    if (*j != *i)
    {
      *c = *i;
      c++;
    }
    i++;
  }
  *c = '\0';
  return destination;
}
