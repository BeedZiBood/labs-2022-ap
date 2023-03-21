#include "calculateSumOfModules.h"
#include <algorithm>
int *countSmoothedMatrix(const int *matrix, size_t n, size_t m)
{
  int *matrixSmoothed = nullptr;
  try
  {
    matrixSmoothed = new int[n * m];
  }
  catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      int sum = 0;
      for (size_t k = std::max< size_t >(i - 1, 0); k < std::min< size_t >(i + 1, n); ++k)
      {
        for (size_t l = std::max< size_t >(j - 1, 0); l < std::min< size_t >(j + 1, m); ++l)
        {
          if (k != i or l != j)
          {
            sum += matrix[k * n + l];
          }
        }
      }
      matrixSmoothed[i * n + j] = sum;
    }
  }
  return matrixSmoothed;
}
int countSum(const int *matrix, const size_t n)
{
  int sum = 0;
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < i; ++j)
    {
      sum += matrix[i * n + j];
    }
  }
  return sum;
}
