#include <iostream>
#include <cstddef>
#include <cstring>
#include "removeDuplicateSpaces.h"
#include "removeDigits.h"
#include "readString.h"
int main()
{
  constexpr size_t initialCapacity = 10;
  constexpr size_t capacityIncrement = 20;
  char *cstring = new char[initialCapacity];
  readString(cstring, initialCapacity, capacityIncrement);
  size_t len = std::strlen(cstring);
  char *newString = new char[len + 1];
  removeDuplicateSpaces2(newString, cstring);
  removeDigits(newString, cstring);
  std::cout << newString << '\n';
  delete[] newString;
  delete[] cstring;
  return 0;
}
