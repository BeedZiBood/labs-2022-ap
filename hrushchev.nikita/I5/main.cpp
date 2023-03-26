#include <iostream>
#include <inputcstring.hpp>
#include "isexpression.hpp"

int main()
{
  char* c_string = nullptr;
  try
  {
    c_string = inputCString(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isExpression(c_string) << "\n";
  delete[] c_string;
}

