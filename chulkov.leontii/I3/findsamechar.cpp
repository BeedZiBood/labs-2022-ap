#include "findsamechar.h"

bool findSameChar(const char* str, const char* newstr)
{
  for (const char* i = str; *i; i++)
  {
    for (const char* j = newstr; *j; j++)
    {
      if (*i == *j)
      {
        return true;
      }
    }
  }
  return false;
}
