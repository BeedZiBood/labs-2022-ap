#include "most_common_characters.h"
#include <cstddef>
#include <utility>

size_t countFirstCharAppearances(const char* cstr)
{
  size_t count = 0;
  for (const char* c = cstr; *c != '\0'; c++)
  {
    if (*c == *cstr)
    {
      count++;
    }
  }
  return count;
}

void sortTwo(char* cstr)
{
  if (cstr[0] > cstr[1])
  {
    std::swap(cstr[0], cstr[1]);
  }
}

void sortThree(char* cstr)
{
  sortTwo(cstr);
  sortTwo(cstr + 1);
  sortTwo(cstr);
}

char* printMostCommonCharacters(char* destination, const char* source)
{
  destination[0] = '\0';
  destination[1] = '\0';
  destination[2] = '\0';
  destination[3] = '\0';
  size_t count1 = 0;
  size_t count2 = 0;
  size_t count3 = 0;
  for (const char* c = source; *c != '\0'; c++)
  {
    if (*c == destination[0] || *c == destination[1] || *c == destination[2])
    {
      continue;
    }
    size_t count = countFirstCharAppearances(c);
    if (count > count1)
    {
      count1 = count;
      destination[0] = *c;
    }
    else if (count > count2)
    {
      count2 = count;
      destination[1] = *c;
    }
    else if (count > count3)
    {
      count3 = count;
      destination[2] = *c;
    }
  }
  sortThree(destination);
  return destination;
}
