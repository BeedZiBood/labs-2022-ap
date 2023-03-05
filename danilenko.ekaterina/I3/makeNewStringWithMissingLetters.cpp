#include "makeNewStringWithMissingLetters.h"

bool isNecessaryLetter(const char* source, char letter)
{
  for (const char* i = source; *i != '\0'; i++)
  {
    if (*i == letter)
    {
      return true;
    }
  }
  return false;
}

char* makeNewStringWithMissingLetters(char* destination, const char* source)
{
  char* new_dest = destination;
  for (char i = 'a'; i <= 'z'; i++)
  {
    if (!isNecessaryLetter(source, i))
    {
      *new_dest++ = i;
    }
  }
  *new_dest = '\0';
  return destination;
}
