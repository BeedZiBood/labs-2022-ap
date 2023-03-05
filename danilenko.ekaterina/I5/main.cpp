﻿#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "createStringFromInput.h"
#include "isRealNumber.h"

int main()
{
  char* string = nullptr;
  std::cout << "Enter string: ";
  try
  {
    string = createStringFromInput(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  bool result = isRealNumber(string);
  std::cout << std::boolalpha << result << '\n';
  delete[] string;
  return 0;
}
