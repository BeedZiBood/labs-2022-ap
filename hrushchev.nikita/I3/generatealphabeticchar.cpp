#include "generatealphabeticchar.hpp"
#include <cstdlib>

char generateAlphabeticChar()
{
  if (std::rand() % 2)
  {
    return static_cast< char >(65 + (std::rand() % 26));
  }
  else
  {
    return static_cast< char >(97 + (std::rand() % 26));
  }
}
