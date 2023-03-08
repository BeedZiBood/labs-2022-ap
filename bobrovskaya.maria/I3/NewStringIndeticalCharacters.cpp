#include "NewStringIndeticalCharacters.h"

char *newStringIndeticalCharacters(char *destination, const char *source1, const char *source2)
{
  char *result = destination;
  for (const char *i = source1; *i != '\0'; i++)
  {
    for (const char *j = source2; *j != '\0'; j++)
    {
      bool exists = false;
      if (*i == *j)
      {
        for (const char *k = destination; *k != '\0'; k++)
        {
          if (*k == *i)
          {
            exists = true;
            break;
          }
        }
        if (!exists)
        {
          *result = *i;
          ++result;
        }
      }
    }
  }
  *result = '\0';
  return destination;
}
