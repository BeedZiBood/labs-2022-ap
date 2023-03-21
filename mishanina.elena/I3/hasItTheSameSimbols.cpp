#include "hasItTheSameSimbols.h"

bool hasItTheSameSimbols(const char* cstring1, const char* cstring2)
{
  const char* cstr1 = cstring1;
  while (*cstr1 != '\0')
  {
    const char* cstr2 = cstring2;
    while (*cstr2 != '\0')
    {
      if (*cstr1 == *cstr2)
      {
        return true;
      }
      cstr2++;
    }
    cstr1++;
  }
  return false;
}
