#include "createlatinletteredstringfromstrings.h"
#include "hasdoubledchars.h"

#include <readthestring.h>

#include <iostream>
#include <cstddef>

int main()
{
  char* c_string = nullptr;
  
  try
  {
    c_string = readTheString();
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    delete[] c_string;
    return EXIT_FAILURE;
  }
  
  char* destination = nullptr;
  try
  {
    destination = new char[27];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] c_string;
    delete[] destination;
    return EXIT_FAILURE;
  }
  
  const char c_string_predefined[] = "abZ";
  destination = createLatinLetteredStringFromStrings(c_string, c_string_predefined);
  
  std::cout << "All chars of cstring: " << destination << '\n';
  std::cout << "Repeating chars: " << std::boolalpha << hasDoubledChars(c_string) << '\n';
  delete[] c_string;
  delete[] destination;
  
  return EXIT_SUCCESS;
}
