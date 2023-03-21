#include "createMassAllLettStrs.h"
#include <stdexcept>
#include <cstddef>
#include <cctype>

char* createMassAllLettStrs(char* cStrAllLett, const char* cStr1, const char* cStr2)
{
  size_t elInResStr = 0;

  for (size_t i = 0, moreThanOne = 0; cStr2[i]; i++, moreThanOne = 0)
  {
    if (std::isalpha(cStr2[i]))
    {
      for (size_t j = i + 1; cStr2[j]; j++)
      {
        if (std::tolower(cStr2[i]) == std::tolower(cStr2[j]))
        {
          moreThanOne = 1;
        }
      }
      for (size_t j = 0; cStr1[j]; j++)
      {
        if (std::tolower(cStr2[i]) == std::tolower(cStr1[j]))
        {
          moreThanOne = 1;
        }
      }
      if (!moreThanOne)
      {
        cStrAllLett[elInResStr++] = std::tolower(cStr2[i]);
      }
    }
  }

  for (size_t i = 0, moreThanOne = 0; cStr1[i]; i++, moreThanOne = 0)
  {
    if (std::isalpha(cStr1[i]))
    {
      for (size_t j = i + 1; cStr1[j]; j++)
      {
        if (std::tolower(cStr1[i]) == std::tolower(cStr1[j]))
        {
          moreThanOne = 1;
        }
      }
      if (!moreThanOne)
      {
        cStrAllLett[elInResStr++] = std::tolower(cStr1[i]);
      }
    }
  }

  for (size_t i = 0; i < elInResStr; i++)
  {
    for (size_t j = i + 1; j < elInResStr; j++)
    {
      if (cStrAllLett[i] > cStrAllLett[j])
      {
        std::swap(cStrAllLett[i], cStrAllLett[j]);
      }
    }
  }

  cStrAllLett[elInResStr] = '\0';

  return cStrAllLett;
}
