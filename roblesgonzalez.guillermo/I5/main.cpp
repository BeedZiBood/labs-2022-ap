#include <iostream>
#include "readString.h"
#include "findRealNumber.h"
int main()
{
  char *cstring = nullptr;
  try
  {
    cstring = readString(std::cin);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }
  std::cout << std::boolalpha << isRealNumber(cstring) << '\n';
  delete[] cstring;
  return 0;
}
