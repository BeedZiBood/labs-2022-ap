#include "makeNewStringWithoutRepeat.h"

char* copyElementsWithoutRepeat(char* destination, const char* source1, const char* source2)
{
  bool match = false;
  for (const char* i = source1; *i != '\0'; i++)
  {
    match = false;
    for (const char* j = source2; *j != '\0'; j++)
    {
      if (*i == *j)
      {
        match = true;
        break;
      }
    }
    if (match == false)
    {
      *destination = *i;
      ++destination;
    }
  }
  *destination = '\0';
  return destination;
}

char* makeNewStringWithoutRepeat(char* destination, const char* source1, const char* source2)
{
  char* d = copyElementsWithoutRepeat(destination, source1, source2);
  copyElementsWithoutRepeat(d, source2, source1);
  return destination;
}
