#include "deleteLatinLetters.h"
#include <cctype>

char* deleteLatinLetters(char* destination1, const char* source_1)
{
  char* j = destination1;
  for (const char* i = source_1; *i != '\0'; i++)
  {
    if (!std::isalpha(*i))
    {
      *j = *i;
      ++j;
    }
  }
  *j = '\0';
  return destination1;
}
