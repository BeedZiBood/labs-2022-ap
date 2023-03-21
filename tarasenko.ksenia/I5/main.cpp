#include <iostream>
#include <extendcstring.hpp>
#include <writecstring.hpp>
#include "isfloat.hpp"

int main()
{
  char * cstring = nullptr;
  try
  {
    cstring = writeCString(std::cin);
  }
  catch (const std::exception & e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete [] cstring;
}
