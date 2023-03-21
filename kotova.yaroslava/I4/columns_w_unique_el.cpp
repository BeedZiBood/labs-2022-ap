#include "columns_w_unique_el.h"
bool isUnique(const int* matrix, size_t column, size_t line)
{
  for (size_t i = 0; i < line; i++)
  {
    for (size_t j = 0; j < line; j++)
    {
      if ((*(matrix + column * i) == *(matrix + column * j)) && i != j)
      {
        return false;
      }
    }
  }
  return true;
}
size_t countUniqueElOfCol(const int* matrix, size_t column, size_t line)
{
  size_t cnt = 0;
  for (size_t curr_column = 0; curr_column < column; curr_column++)
  {
    if (isUnique((matrix + curr_column), column, line))
    {
      cnt++;
    }
  }
  return cnt;
}
