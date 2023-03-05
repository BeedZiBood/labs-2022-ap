#include "allcharsofcstrings.hpp"
#include "sortcharsbyascii.hpp"
#include <cstddef>
#include <cctype>
int allCharsOfCstrings(char* destination, const char* cstring, const char* cstringInside)
{
  size_t sizeOfDestination = 0;
  size_t notLonelyChar = 0;
  for (size_t i = 0; cstringInside[i]; i++)
  {
    if (std::isalpha(cstringInside[i]))
    {
      for (size_t j = i + 1; cstringInside[j]; j++)
      {
        if (std::tolower(cstringInside[i]) == std::tolower(cstringInside[j]))
        {
          notLonelyChar = 1;
        }
      }
      for (size_t j = 0; cstringInside[j]; j++)
      {
        if (std::tolower(cstringInside[i]) == std::tolower(cstringInside[j]))
        {
          notLonelyChar = 1;
        }
      }
      if (!notLonelyChar)
      {
        destination[sizeOfDestination++] = std::tolower(cstringInside[i]);
      }
    }
  }
  for (size_t i = 0, notLonelyChar = 0; cstring[i]; i++, notLonelyChar = 0)
  {
    if (std::isalpha(cstring[i]))
    {
      for (size_t j = i + 1; cstring[j]; j++)
      {
        if (std::tolower(cstring[i]) == std::tolower(cstring[j]))
        {
          notLonelyChar = 1;
        }
      }
      if (!notLonelyChar)
      {
        destination[sizeOfDestination++] = std::tolower(cstring[i]);
      }
    }
  }
  sortCharsByAscii(destination, sizeOfDestination);
  destination[sizeOfDestination] = '\0';
  return 0;
}
