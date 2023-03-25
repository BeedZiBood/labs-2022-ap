#include <iostream>
#include <string>
#include <ReadString.h>
#include "IsItARealNumber.h"

int main()
{
  char* number = nullptr;
  try
  {
    number = readString(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isRealNumber(number) << "\n";
  delete[] number;
  return 0;
}
