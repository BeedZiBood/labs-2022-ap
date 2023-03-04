#include "workWithStrs.h"
#include "workWithIO.h"

char* getLineFromFile(size_t* const result_size_ptr, std::istream& in)
{
  char* result = new char[CAPACITY_BLOCK];
  size_t result_size = 0;
  size_t result_capasity = CAPACITY_BLOCK;
  char cur_char = '\0';
  in >> std::noskipws;
  while (in >> cur_char && cur_char != '\n')
  {
    result = pushBack(result, result_size, result_capasity, cur_char);
  }
  if (cur_char == '\0')
  {
    delete[] result;
    return nullptr;
  }
  if (result_size_ptr != nullptr)
  {
    *result_size_ptr = result_size;
  }
  return result;
}
