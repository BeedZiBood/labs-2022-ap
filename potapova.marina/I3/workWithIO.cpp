#include "workWithIO.h"

char* stdinGetLine()
{
  char* result;

  try
  {
    result = new char[capasity_block];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }

  size_t result_size = 0;
  size_t result_capasity = capasity_block;
  *result = '\000';

  char cur_char;
  std::cin >> std::noskipws;
  while (std::cin >> cur_char && cur_char != '\n')
  {
    pushBack(result, result_size, result_capasity, cur_char);
  }

  return result;
}
