#include "createStringCommonSymbols.h"
#include <cctype>
#include <cstddef>

size_t defineNumberCommonSymbols(const char* source, const char p)
{
  size_t count = 0;
  for (size_t i = 0; source[i] != '\0'; i++)
  {
    if (p == source[i])
    {
      count++;
    }
  }
  return count;
}

char* createStringCommonSymbols(char* destination2, const char* source_1, const char* source_2)
{
  size_t res = 0;
  for (size_t i = 0; source_1[i] != '\0'; i++)
  {
    if (defineNumberCommonSymbols(source_1 + i + 1, source_1[i]) == 0)
    {
      if (defineNumberCommonSymbols(source_2, source_1[i]) > 0)
      {
        destination2[res++] = source_1[i];
      }
    }
  }
  destination2[res] = '\0';
  return destination2;
}
