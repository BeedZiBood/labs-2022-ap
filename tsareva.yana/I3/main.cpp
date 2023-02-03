#include <iostream>
#include <cstddef>
#include <cstring>
#include <limits>
#include "change_chars.h"
#include "generate_new_line.h"
#include "golden_ratio.h"

int main()
{
  size_t capacity_1 = 10;
  size_t max_size_t = std::numeric_limits< size_t >::max();
  char* str_1 = new char[capacity_1];
  size_t size_1 = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size_1 == capacity_1)
    {
      if (capacity_1 == max_size_t)
      {
        std::cout << "Too much";
        delete [] str_1;
        return 1;
      }
      else
      {
        capacity_1 = goldenRatio(capacity_1);
      }
      try
      {
        char* newstr = new char[capacity_1];
        auto *i = str_1;
        auto *j = newstr;
        while (i != str_1 + size_1)
        {
          *(j++) = *(i++);
        }
        delete [] str_1;
        str_1 = newstr;
      }
      catch (...)
      {
        delete [] str_1;
        return 1;
      }
    }
    std::cin >> str_1[size_1];
  }
  while (std::cin && str_1[size_1++] != '\n');
  if (!std::cin && !size_1)
  {
    std::cout << "error";
    delete[] str_1;
    return 2;
  }
  str_1[size_1 - 1] = '\0';
  const char *str_2 = "abcdefgh";
  size_t size_2 = strlen(str_2);
  try
  {
    char *res1 = new char[size_1 + size_2];
    generate_new_line(res1, str_1, str_2);
    std::cout << res1 << '\n';
    delete[] res1;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete[] str_1;
    return 2;
  }
  try
  {
    char* res2 = new char[size_1];
    change_chars(res2, str_1);
    std::cout << res2 << '\n';
    delete[] res2;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete[] str_1;
    return 2;
  }
  delete[] str_1;
  return 0;
}
