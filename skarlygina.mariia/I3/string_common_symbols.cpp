#include "string_common_symbols.h"

char* makeStringCommonSymbols(char* destination, const char* first_source, const char* second_source)
{
  auto res = destination;
  for (auto i = first_source; *i != '\0'; i++)
  {
    for (auto j = second_source; *j != '\0'; j++)
    {
      if (*j == *i)
      {
        *res = *i;
        ++res;
      }
    }
  }
  *res = '\0';
  return destination;
}
