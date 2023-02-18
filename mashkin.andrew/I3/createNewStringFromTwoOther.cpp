#include "createNewStringFromTwoOther.h"
#include <cstddef>
#include <cctype>

char* createNewStringFromTwoOther(char* newStringFromTwoOther, const char* cstring1, const char* cstring2, size_t size)
{
  for (const char* i = cstring1; *i; i++)
  {
    if (std::isdigit(*i))
    {
      bool repetition = false;
      for (char* j = newStringFromTwoOther; *j; j++)
      {
        if (*j == *i)
        {
          repetition = true;
          break;
        }
      }
      if (!repetition)
      {
        for (const char* j = cstring2; *j; j++)
        {
          if (*j == *i)
          {
            newStringFromTwoOther[size] = *j;
            size++;
          }
        }
      }
    }
  }
  newStringFromTwoOther[size] = '\0';
  return newStringFromTwoOther;
}
