#include "count_max_sum_diag.h"
#include <cstddef>

int countMaxSumDiag(const int* arr, size_t nRows, size_t nColomns)
{
  int max_sum = 0;
  int sum1 = 0;
  int sum2 = 0;
  for (size_t i = 0; i < nRows ; i++)
  {
    for (size_t j = i; j < nColomns; j++)
    {
      if (j * nRows + (j - i) != (nRows + 1) * j)
      {
        sum1 += arr[j * nRows + (j - i)];
      }
    }
    if (sum1 > max_sum)
    {
      max_sum = sum1;
    }
    sum1 = 0;
  }
  for (size_t i = 0; i < nRows; i++)
  {
    for (size_t j = 0; j < nColomns - i; j++)
    {
      if ((j + i) * nRows + j != (nRows + 1) * j)
      {
        sum2 += arr[(j + i) * nRows + j];
      }
    }
    if (sum2 > max_sum)
    {
      max_sum = sum2;
    }
    sum2 = 0;
  }
  return max_sum;
}
