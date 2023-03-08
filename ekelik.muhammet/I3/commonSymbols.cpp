#include "commonSymbols.h"

#include <cstddef>
#include <cstring>

char* findCommonSymbols(char* myCommonSymbols, const char* source1)
{
  char maxChars[3] = {};
  size_t maxCounts[3] = {};
  for (size_t i = 0; source1[i] != 0; i++)
  {
    char c = source1[i];
    size_t cnt = 0;
    for (size_t j = 0; source1[j] != 0; j++)
    {
      if (source1[j] == c)
      {
        cnt++;
      }
    }
    if (cnt > maxCounts[0])
    {
      maxCounts[2] = maxCounts[1];
      maxCounts[1] = maxCounts[0];
      maxCounts[0] = cnt;
      maxChars[2] = maxChars[1];
      maxChars[1] = maxChars[0];
      maxChars[0] = c;
    }
    else if (cnt > maxCounts[1] && c != maxChars[0])
    {
      maxCounts[2] = maxCounts[1];
      maxCounts[1] = cnt;
      maxChars[2] = maxChars[1];
      maxChars[1] = c;
    }
    else if (cnt > maxCounts[2] && c != maxChars[0] && c != maxChars[1])
    {
      maxCounts[2] = cnt;
      maxChars[2] = c;
    }
  }

  size_t index = 0;
  for (size_t i = 0; i < 3; i++)
  {
    if (maxChars[i] != 0)
    {
      myCommonSymbols[index++] = maxChars[i];
    }
  }
  myCommonSymbols[index] = '\0';

  return myCommonSymbols;
}
