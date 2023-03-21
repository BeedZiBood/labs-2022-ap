#include "deleteextraspaces.h"
#include <cctype>

char *deleteExtraSpaces(char *destination, const char *source)
{
  auto j = destination;
  for (auto i = source; *i != '\0'; i++) {
    if (!std::isspace(*i)) {
      *j = *i;
      j++;
    } else if (j != destination && *(j - 1) != ' ') {
      *j = ' ';
      j++;
    }
  }
  if (*(j - 1) == ' ') {
    j--;
  }
  *j = '\0';
  return destination;
}
