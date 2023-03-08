#include "deleteSpaces.h"
#include <cctype>
char *deleteSpaces(char *destination, const char *src)
{
  auto j = destination;
  for (auto i = src; *i != '\0'; i++)
  {
    if (!std::isspace(*i))
    {
      *j = *i;
      j++;
    } else if (j != destination && *(j - 1) != ' ') {
      *j = ' ';
      j++;
    }
  }
  if (*(j - 1) == ' ')
  {
    j--;
  }
  *j = '\0';
  return destination;
}
