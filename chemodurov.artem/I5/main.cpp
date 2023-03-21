#include <iostream>
#include <extendCString.h>
#include <getCString.h>
#include "isRealNumber.h"

int main()
{
  char * c_string = nullptr;
  try
  {
    c_string = chemodurov::getCString(std::cin);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << chemodurov::isRealNumber(c_string) << "\n";
  delete [] c_string;
  return 0;
}
