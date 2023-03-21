#include "DelNumbers.h"
#include <cctype>
char* deleteNumbers(const char* source, char* destination)
{
  auto k = destination;
  for (auto i = source; *i != '\0'; i++)
  {
    if (!std::isdigit(*i))
    {
      *k = *i;
      ++k;
    }
  }
  *k = '\0';
  return destination;
}
