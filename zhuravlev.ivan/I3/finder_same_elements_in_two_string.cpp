#include "finder_same_elements_in_two_string.h"

char* finderThreeSameElementsInTwoStrings(char* destination, const char* main_source, const char* static_string)
{
  auto result_string = destination;
  for (auto i = main_source; *i != '\0'; ++i)
  {
    for (auto j = static_string; *j != '\0'; ++j)
    {
      if (*i == *j)
      {
        *result_string = *i;
        ++result_string;
      }
    }
  }
  *result_string = '\0';
  return destination;
}
