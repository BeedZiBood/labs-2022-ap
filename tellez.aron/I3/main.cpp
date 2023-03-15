#include <iostream>
#include "removeLatinLetters.h"
#include "countUniqueLatinLetters.h"
char* makeNewCapacityCString(char* cstring, size_t& capacity, size_t size)
{
  char* newstring = new char[capacity + 20];
  for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  capacity += 20;
  return newstring;
}
int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *newCString = makeNewCapacityCString(cstring, capacity, size);
        delete [] cstring;
        cstring = newCString;
        newCString = nullptr;
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
  char* destination = nullptr;
  try
  {
    destination = new char[size];
    destination = removeLatinLetters(destination, cstring);
    if (destination[0] != '\0')
    {
      std::cout << "Text without latin letters: " << destination << "\n";
    }
    else std::cout << "Error while removing latin letters \n";
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
  std::cout << "Number of unique Latin letters in the string: " << countUniqueLatinLetters(cstring) << "\n";
  delete[] cstring;
  return 0;
}
