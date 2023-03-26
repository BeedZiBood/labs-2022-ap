#include "CountDifferentLetters.h"

size_t countDifLetters(const char *source1)
{
  size_t countLetters = 0;
  size_t letterCounter = 0;
  for (size_t i = 0; source1[i] != '\0'; i++)
  {
    for (size_t j = i + 1; source1[j] != '\0'; j++)
    {
      if (source1[i] == source1[j])
      {
        letterCounter++;
      }
    }
    if (letterCounter == 0)
    {
      countLetters++;
    }
    letterCounter = 0;
  }
  return countLetters;
}
