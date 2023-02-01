#include <iostream>
#include <exception>
#include <cstring>
#include "finder.three.same.elements.h"
#include "finder_same_elements_in_two_string.h"
#include "array.expansion.h"

int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  size_t size_of_static = 18;
  const char* static_string = "ABCDFEabcdef135790";
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        capacity += 20;
        arrayExpansion(*cstring, capacity);
      }
      catch (const std::bad_alloc &e)
      {
        delete [] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (size == 0)
  {
    std::cout << "Empty string!" << "\n";
  }
  cstring[size - 1] = '\0';
  char* cstring_for_sec_func = new char[size];
  strcpy(cstring_for_sec_func, cstring);
  try
  {
    char* destination = new char[size + size_of_static];
    std::cout << finderThreeSameElementsInTwoStrings(destination, cstring, static_string) << "\n";
    delete [] cstring;
    delete [] destination;
  }
  catch (const std::bad_alloc &e)
  {
    delete [] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }

  try
  {
    char* destination = new char[size];
    std::cout << finderThreeSameElements(destination, cstring_for_sec_func) << "\n";
    delete [] cstring_for_sec_func;
    delete [] destination;
  }
  catch (const std::bad_alloc &e)
  {
    delete [] cstring_for_sec_func;
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
