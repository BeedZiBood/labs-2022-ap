#include "countDiagonalsWithoutZero.h"

size_t countDiagonalsWithoutZero(const int* array, size_t n)
{
  bool flag;
  int count = 0;
  for (size_t k = 0; k < 2 * (n - 1); k++)
  {
    flag = false;
    for (size_t i = 0; i < n && !flag; i++)
    {
      size_t j = k - i;
      if (j < n && array[i * j] == 0)
      {
        flag = true;
      }
    }
    if (flag == true)
    {
      count++;
    }
  }
  return count;
}
