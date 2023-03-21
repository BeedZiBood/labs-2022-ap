#include "count_diagonals_without_zeros.h"
size_t countDiagonalsWithoutZeros(const int* array, size_t rows)
{
  size_t count = 0;
  bool isZero = false;
  for (size_t i = 0; i < rows; i++)
  {
    size_t j = 0;
    isZero = false;
    while (j <= i)
    {
      if (array[i + (rows - 1) * j] == 0)
      {
        isZero = true;
        break;
      }
      j++;
    }
    if (!isZero)
    {
      count++;
    }
  }
  for (size_t i_reverse = rows * (rows - 1) + 1; i_reverse < rows * rows; i_reverse++)
  {
    size_t j_reverse = 0;
    isZero = false;
    while (j_reverse <= rows * rows - 1 - i_reverse)
    {
      if (array[i_reverse - (rows - 1) * j_reverse] == 0)
      {
        isZero = true;
        break;
      }
      j_reverse++;
    }
    if (!isZero)
    {
      count++;
    }
  }
  return count;
}
