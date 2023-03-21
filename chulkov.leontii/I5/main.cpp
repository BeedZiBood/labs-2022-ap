#include <iostream>
#include <cstring>
#include <makecsting.h>
#include "gettingrealnumber.h"

int main()
{
  char* cstring = nullptr;
  try
  {
    cstring = makeCSting(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << getRealNumber(cstring) << "\n";
  delete[] cstring;
}
