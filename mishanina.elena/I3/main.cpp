#include <iostream>
#include <ctime>
#include <inputString.h>
#include "removeExtraSpaces.h"
#include "hasItTheSameSimbols.h"

int main()
{
  std::srand(std::time(nullptr));
  size_t capacity1 = 10;
  char* cstring1 = nullptr;
  try
  {
    cstring1 = inputString(capacity1, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] cstring1;
    return 1;
  }

  char* destination = nullptr;
  try
  {
    destination = new char[capacity1];
    destination[0] = '\0';
    destination = removeExtraSpaces(destination, cstring1);
    std::cout << destination << "\n";
    delete[] destination;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] destination;
    delete[] cstring1;
    return 1;
  }

  size_t capacity2 = 10;
  char* cstring2 = nullptr;
  try
  {
    cstring2 = new char[capacity2];
    for (size_t i = 0; i < capacity2; i++)
    {
      char simbol = std::rand() % 10 + 0x61;
      cstring2[i] = simbol;
    }
    cstring2[capacity2 - 1] = '\0';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] cstring1;
    delete[] cstring2;
    return 1;
  }

  bool result = false;
  try
  {
    result = hasItTheSameSimbols(cstring1, cstring2);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] cstring1;
    delete[] cstring2;
    return 1;
  }
  if (result)
  {
    std::cout << "Strings have the same simbols" << "\n";
  }
  else
  {
    std::cout << "Strings don't have the same simbols" << "\n";
  }
  delete[] cstring1;
  delete[] cstring2;
  return 0;
}
