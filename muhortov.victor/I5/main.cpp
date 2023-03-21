#include <iostream>
#include <makecstring.hpp>
#include "IsRealNumber.hpp"

int main()
{
  size_t size = 0;
  size_t capacity = 10;

  char *c_string = makeCString(size, capacity,std::cin);

  if (c_string[0] == '\n')
  {
    std::cout << "Empty string";
    delete[] c_string;
    return 2;
  }

  std::cout << std::boolalpha << isRealNum(c_string) << '\n';

  delete[] c_string;
}
