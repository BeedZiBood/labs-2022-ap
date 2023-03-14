#include "latin_letters.h"
#include <cstddef>
#include <cctype>

char* createStringNewLatinLetters(char* destination, const char* source)
{
  size_t k = 0;
  for (char i = 'a'; i <= 'z'; i++)
  {
    bool exist = false;
    for (size_t j = 0; source[j] != '\0'; j++)
    {
      if (std::tolower(source[j]) == i)
      {
        exist = true;
        break;
      }
    }
    if (!exist)
    {
      destination[k++] = i;
    }
  }
  destination[k] = '\0';
  return destination;
}
