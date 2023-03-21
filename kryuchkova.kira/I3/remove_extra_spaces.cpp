#include "remove_extra_spaces.h"
#include <cctype>
#include <cstddef>

char *removeExtraSpaces(char *destination, const char *cstring)
{
  char *over_destination = destination;

  while (std::isspace(*cstring))
  {
    cstring++;
  }

  while (*cstring)
  {
    if (!(std::isspace(*cstring) && std::isspace(*(cstring - 1))))
    {
      *over_destination = *cstring;
      over_destination++;
    }
    cstring++;
  }

  if (std::isspace(*(cstring - 1)))
  {
    over_destination--;
  }
  *over_destination = '\0';
  return destination;
}
