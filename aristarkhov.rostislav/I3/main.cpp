#include <iostream>
#include <createCString.h>
#include "deleteLatinLetters.h"
#include "createStringCommonSymbols.h"

int main()
{
  size_t size = 0;
  char* source_1 = nullptr;
  try
  {
    source_1 = createCString(std::cin, size);
    if (source_1[0] == '\0')
    {
      delete[] source_1;
      throw std::logic_error("Empty input");
    }
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  char* destination1 = nullptr;
  try
  {
    destination1 = new char[size];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] source_1;
    return 1;
  }
  destination1 = deleteLatinLetters(destination1, source_1);
  std::cout << destination1 << '\n';
  delete[] destination1;

  char* destination2 = nullptr;
  char source_2[] = "abcdefg";
  try
  {
    destination2 = new char[size];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] source_1;
    return 1;
  }
  destination2 = createStringCommonSymbols(destination2, source_1, source_2);
  std::cout << destination2 << '\n';

  delete[] source_1;
  delete[] destination2;
  return 0;
}
