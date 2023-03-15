#include "scanLocalMinima.h"
size_t countRowsWithZeros(const size_t n, const size_t m, const int *matrix)
{
  size_t k = 0;
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (matrix[i * n + j] == 0)
      {
        k++;
        break;
      }
    }
  }
  return k;
}
