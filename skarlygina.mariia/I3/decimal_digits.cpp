#include "decimal_digits.h"
#include <stdexcept>

char* addDecimalDigits(char* destination, const char* first_source, const char* second_source)
{
  auto res = destination;
  for (auto i = first_source; *i != '\0'; ++i)
  {
    *res = *i;
    ++res;
  }
  for (auto i = first_source; *i != '\0'; ++i)
  {
    if (std::isdigit(*i))
    {
      for (auto j = second_source; *j != '\0'; ++j)
      {
        if (*i == *j)
        {
          *(res + 1) = '\0';
          *res = *i;
          ++res;
        }
      }
    }
  }
  *res = '\0';
  return destination;
}
