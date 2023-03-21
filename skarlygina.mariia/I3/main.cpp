#include <iostream>
#include <exception>
#include <cstring_capacity.h>
#include <extended_string.h>
#include "decimal_digits.h"
#include "string_common_symbols.h"

int main()
{
  std::pair< size_t, char* > result = {0, nullptr};
  size_t size = result.first;
  char* cstring = result.second;
  try
  {
    result = makeNewCString(std::cin);
    size = result.first;
    cstring = result.second;
  }
  catch (const std::exception& e)
  {
    delete[] cstring;
    std::cerr << e.what();
    return 1;
  }

  char* destination = nullptr;
  char* string_source = nullptr;
  const size_t size_source = size;

  try
  {
    string_source = new char[size_source];
    for (size_t i = 0; i < size_source - 1; i++)
    {
      string_source[i] = '1';
    }
    string_source[size_source - 1] = '\0';
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] string_source;
    delete[] cstring;
    return 1;
  }

  try
  {
    destination = new char[size_source + size];
    destination = addDecimalDigits(destination, cstring, string_source);
    if (destination[0] != '\0')
    {
      std::cout << destination << "\n";
    }
    else std::cout << "Error while making first function \n";
    delete[] destination;
    destination = nullptr;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] destination;
    delete[] cstring;
    return 1;
  }

  try
  {
    destination = new char[size_source + size];
    destination = makeStringCommonSymbols(destination, cstring, string_source);
    if (destination[0] != '\0')
    {
      std::cout << destination << "\n";
    }
    else std::cout << "There are no common symbols \n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] destination;
    delete[] cstring;
    return 1;
  }

  delete[] destination;
  delete[] string_source;
  delete[] cstring;
}
