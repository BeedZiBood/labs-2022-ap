#include "countdifferentletters.h"
size_t countDifferentLetters(const char* source)
{
  size_t count = 0;
  size_t lettercounter = 0;
  for (size_t i = 0; source[i]; i++)
  {
    for (size_t j = i + 1; source[j]; j++)
    {
      if (source[i] == source[j])
      {
        lettercounter++;
      }
    }
    if (lettercounter == 0)
    {
      count++;
    }
    lettercounter = 0;
  }
  return count;
}
