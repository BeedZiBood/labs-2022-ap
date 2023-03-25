#include "uncommonSymbols.h"
#include <cstring>

char* findUncommonSymbols(char* mySymbols, const char* source1, const char* source2)
{
  size_t sizeUnique = 0;
  bool isCommon = false;

  for (; *source1; source1++)
  {
    for (const char* j = source2; *j; j++)
    {
      if (*source1 == *j)
      {
        isCommon = true;
        break;
      }
    }
    if (!isCommon)
    {
      mySymbols[sizeUnique] = *source1;
      sizeUnique++;
    }
    isCommon = false;
  }
  mySymbols[sizeUnique] = '\0';
  return mySymbols;
}
