#include <iostream>
#include <cstddef>
#include <inputstring.h>
#include "rowvalidation.h"

int main()
{
  char * cstring = nullptr;
  try
  {
    cstring = inputString(std::cin);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete [] cstring;
}
