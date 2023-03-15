#include "countUniqueLatinLetters.h"
#include <cctype>
size_t countLatinLetters(size_t latin_alphabet[])
{
  size_t sum = 0;
  for (size_t i = 0; i < 26; i++)
  {
    if (latin_alphabet[i] == 1)
    {
      sum++;
    }
  }
  return sum;
}
size_t countUniqueLatinLetters(const char *source)
{
  size_t latin_alphabet[26] = {0};
  while (*source != '\0')
  {
    if (std::isalpha(*source))
    {
      latin_alphabet[std::toupper(*source) - 65] = 1;
    }
    source++;
  }
  return countLatinLetters(latin_alphabet);
}
