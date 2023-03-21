#include <iostream>
#include <extendcstring.hpp>
#include "deletelatinletters.hpp"
#include "replacesetchar.hpp"

int main()
{
  size_t capacity = 10;
  char * cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        cstring = extendCString(cstring, capacity, size);
      }
      catch (const std::exception & e)
      {
        std::cerr << e.what() << "\n";
        delete [] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (!std::cin && !size)
  {
    std::cout << "Error\n";
    delete [] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cout << "Empty string\n";
    delete [] cstring;
    return 2;
  }
  size_t res_str1_size = size;
  char * res_str1 = nullptr;
  try
  {
    res_str1 = new char[res_str1_size];
    res_str1 = deleteLatinLetters(res_str1, cstring);
    std::cout << res_str1 << "\n";
  }
  catch (const std::bad_alloc & e)
  {
    std::cout << e.what() << "\n";
    delete [] res_str1;
    delete [] cstring;
    return 1;
  }
  delete [] res_str1;
  size_t res_str2_size = size;
  char * res_str2 = nullptr;
  char char1 = '1';
  char char2 = '2';
  try
  {
    res_str2 = new char[res_str2_size];
    res_str2 = replaceSetChar(res_str2, cstring, char1, char2);
    std::cout << res_str2 << "\n";
  }
  catch (const std::bad_alloc & e)
  {
    std::cout << e.what() << "\n";
    delete [] res_str2;
    delete [] cstring;
    return 1;
  }
  delete [] res_str2;
  delete [] cstring;
}
