#include "RepLetters.h"
#include <cctype>
char* replacingLetters(const char* source, char* destination)
{
  auto k = destination;
  for (auto i = source; *i != '\0'; ++i)
  {
    if (std::isalpha(*i))
    {
      *k = std::tolower(*i);
      k++;
    }
  }
  *k = '\0';
  return destination;
}
