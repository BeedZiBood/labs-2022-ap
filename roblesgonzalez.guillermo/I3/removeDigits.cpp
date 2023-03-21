#include "removeDigits.h"
#include <cctype>
char *removeDigits(char *destination, const char *source)
{
  if (destination == nullptr || source == nullptr)
  {
    return nullptr;
  }
  char *result = destination;
  while (*source != '\0')
  {
    if (!std::isdigit(*source))
    {
      *destination = *source;
      destination++;
    }
    source++;
  }
  *destination = '\0';
  return result;
}
