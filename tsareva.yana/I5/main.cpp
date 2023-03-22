#include <iostream>
#include <input_string.h>
#include "is_float.h"

int main()
{
  char * cstring = nullptr;
  try
  {
    cstring = inputString(std::cin);
  }
  catch (const std::exception & e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete [] cstring;
}
