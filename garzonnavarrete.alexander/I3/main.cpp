#include <iostream>
#include "EraseLatLet.h"
#include "StringPyQ.h"

char* makeNewCapacityCString(char* cstring, size_t& capacity, size_t size, size_t increaseBy)
{
  char* newstring = new char[capacity + increaseBy];
  for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  capacity += increaseBy;
  return newstring;
}

int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  cstring[0] = '\0';
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        size_t increaseBy;
        std::cout << "Enter capacity increase: ";
        std::cin >> increaseBy;
        char* newCString = makeNewCapacityCString(cstring, capacity, size, increaseBy);
        delete[] cstring;
        cstring = newCString;
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << "\n";
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cout << "Error while reading the string \n";
    delete[] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  char* sum_result = new char[size * 2];
  getSumOfStrings(sum_result, cstring, cstring);
  std::cout << "Sum of two strings: " << sum_result << "\n";
  delete[] sum_result;
  char* erase_result = new char[size];
  erase_result = eraseLatLet(erase_result, cstring);
  if (erase_result[0] != '\0')
  {
    std::cout << "Text without latin letters: " << erase_result << "\n";
  }
  else
  {
    std::cout << "Error while removing latin letters \n";
  }
  delete[] erase_result;
  delete[] cstring;
  return 0;
}
