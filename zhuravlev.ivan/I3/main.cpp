#include <iostream>
#include <exception>
#include <cstring>
#include <makeString.h>
#include "finder_three_same_elements.h"
#include "finder_same_elements_in_two_string.h"

int main()
{
  size_t size = 0;
  size_t capacity = 10;
  char* cstring = nullptr;
  try
  {
    cstring = makeCstring(capacity, size, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  size_t size_of_static = 18;
  const char* static_string = "ABCDFEabcdef135790";
  try
  {
    char* destination = new char[size + size_of_static];
    destination[0] = '\0';
    destination = finderThreeSameElementsInTwoStrings(destination, cstring, static_string);
    std::cout << destination << "\n";
    delete[] destination;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }
  try
  {
    char* destination = new char[size];
    destination[0] = '\0';
    destination = finderThreeSameElements(destination, cstring);
    std::cout << destination << "\n";
    delete[] destination;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }
  delete[] cstring;
  return 0;
}
