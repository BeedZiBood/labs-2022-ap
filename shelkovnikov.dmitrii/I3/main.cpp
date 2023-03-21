#include <iostream>
#include <limits>
#include <string_input.h>
#include "removeextraspaces.h"
#include "getothersymbols.h"
int main()
{
  char *str = nullptr;
  size_t size = 0;
  try
  {
    str = string_input(std::cin, size);
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  try
  {
    char *res1 = new char[size];
    remove_extra_spaces(res1, str);
    std::cout << res1 << '\n';
    delete[] res1;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete[] str;
    return 2;
  }
  try
  {
    char res2[27];
    get_other_symbols(res2, str);
    std::cout << res2 << '\n';
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete[] str;
    return 2;
  }
  delete[] str;
  return 0;
}
