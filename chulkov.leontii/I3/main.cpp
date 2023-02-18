#include <iostream>
#include <cstddef>
#include <cstring>
#include "findsamechar.h"
#include "sortstringbyascii.h"

int main()
{
  size_t cap = 10;
  char* cstring = new char[cap];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == cap - 1)
    {
      try
      {
        cstring[cap - 1] = '\0';
        char* newstr = new char[cap + 20];
        std::strcpy(newstr, cstring);
        delete [] cstring;
        cstring = newstr;
        cap += 20;
      }
      catch (...)
      {
        delete [] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  const size_t size2 = 4;
  if (size == 0)
  {
    std::cerr << "Empty string\n";
    delete [] cstring;
    return 1;
  }
  else
  {
    cstring[size - 1] = '\0';
  }
  char newstr2[size2] = "azs";
  char* newstr3 = nullptr;
  const unsigned short alphabet = 100;
  try
  {
    newstr3 = new char[alphabet + 1];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete [] cstring;
    return 1;
  }
  std::cout << "Same symbols\t" << findSameChar(cstring, newstr2) << '\n';
  std::cout << "celled string\t" << sortStringByAscii(newstr3, cstring, newstr2) << '\n';
  delete [] cstring;
  delete [] newstr3;
  return 0;
}
