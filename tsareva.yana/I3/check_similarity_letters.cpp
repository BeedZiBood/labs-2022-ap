#include "check_similarity_letters.h"

char * checkSmilarityLetters(char * res, const char * i, const char * j)
{
  bool noMatches = true;
  while (*i)
  {
    noMatches = true;
    while (*j && noMatches)
    {
      if (*i == *j)
      {
        noMatches = false;
      }
      j++;
    }
    if (noMatches)
    {
      *res++ = *i;
    }
    i++;
  };
  return res;
}
