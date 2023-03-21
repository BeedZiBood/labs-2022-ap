#include <iostream>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include "readString.h"
#include "removeDuplicateSpaces.h"
#include "removeDigits.h"

int main()
{
  try
  {
    char *inputString = readString(std::cin);
    size_t len = std::strlen(inputString);
    char *newString = new char[len + 1];
    removeDuplicateSpaces2(newString, inputString);
    removeDigits(newString, newString);
    std::cout << newString << '\n' ;
    delete[] inputString;
    delete[] newString;
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
