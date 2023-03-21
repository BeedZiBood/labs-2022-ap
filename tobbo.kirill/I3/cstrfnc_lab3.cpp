#include "cstrfnc_lab3.h"
#include <cmath>
#include <cstring>
#include <stdexcept>

bool isIntersectedStrings(const char* str1, const char* str2)
{
  const char* s1 = str1;
  while (*s1 != '\0')
  {
    const char* s2 = str2;
    while (*s2 != '\0')
    {
      if (*s1 == *s2)
      {
        return true;
      }
      s2++;
    }
    s1++;
  }
  return false;
}

bool isLowerVowel(char c)
{
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

bool isUpperVowel(char c)
{
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');
}

bool isVowel(char c)
{
  return (isLowerVowel(c) || isUpperVowel(c));
}

char* removeLatinVowelSymbols(char* destination, const char* source)
{
  char* dst = destination;
  for (const char* i = source; *i != '\0'; i++)
  {
    bool found = isVowel(*i);
    if (!found)
    {
      *(dst++) = *i;
    }
  }
  *dst = '\0';
  return destination;
}
