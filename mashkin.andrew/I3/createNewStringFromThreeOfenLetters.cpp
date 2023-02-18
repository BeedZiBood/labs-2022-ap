#include "createNewStringFromThreeOfenLetters.h"
#include <cstddef>
#include "sortStr.h"
#include "compareChar.h"

char* createNewStringFromThreeOftenLetters(char* fromThreeLetters, const char* string1, size_t endIndex)
{
  size_t countLetter = 0;
  size_t index = 0;
  size_t arrCountyOfLetter[3]{};
  for (const char* i = string1; *i; i++)
  {
    index = 0;
    if (compare(fromThreeLetters, i, endIndex))
    {
      countLetter = 0;
      for (const char* j = string1; *j; j++)
      {
        *i == *j ? countLetter++ : countLetter;
      }
      for (char* j = fromThreeLetters; endIndex != 3; j++, index++, endIndex++)
      {
        if (arrCountyOfLetter[index] < countLetter)
        {
          for (size_t k = 2 - index; k > index; k--)
          {
            j[k] = j[k - 1];
            arrCountyOfLetter[k] = arrCountyOfLetter[k - 1];
          }
          *j = *i;
          arrCountyOfLetter[index] = countLetter;
          break;
        }
      }
    }
    endIndex = 0;
  }
  fromThreeLetters = sort(fromThreeLetters, endIndex);
  return fromThreeLetters;
}
