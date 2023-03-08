#include <iostream>
#include <cstddef>
#include <cstring>
#include <makecsting.h>
#include "findsamechar.h"
#include "sortstringbyascii.h"

int main()
{
  char* cstring = nullptr;
  try
  {
    cstring = makeCSting(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Empty input\n";
    delete[] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }
  const size_t size2 = 4;
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
