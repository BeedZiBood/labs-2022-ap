#include "getMinSumOfDiagonal.h"
#include <stdexcept>
#include <limits>

long long calcSumOfMainDiagonal(const int *arr, size_t rows, size_t cols)
{
  long long summ = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    summ += arr[i * (cols + 1)];
  }
  return summ;
}
long long calcSumOfUpperDiagonal(const int *arr, size_t rows, size_t cols)
{
  long long summ = 0;
  for (size_t i = 0; i < rows - 1; ++i)
  {
    summ += arr[(i + 1) * cols + i];
  }
  return summ;
}
long long calcSumOfLowerDiagonal(const int *arr, size_t rows, size_t cols)
{
  long long summ = 0;
  for (size_t i = 0; i < rows - 1; ++i)
  {
    summ += arr[i * cols + (i + 1)];
  }
  return summ;
}
long long calcMinSummSecondaryDiagonal(const int *arr, size_t rows, size_t cols)
{
  const int *intArr = (arr);
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  if (rows != cols)
  {
    throw std::invalid_argument("Matrix is not square");
  }
  long long min_summ = std::numeric_limits< int >::max();
  min_summ = std::min(min_summ, calcSumOfMainDiagonal(intArr, rows, cols));
  min_summ = std::min(min_summ, calcSumOfUpperDiagonal(intArr, rows, cols));
  min_summ = std::min(min_summ, calcSumOfLowerDiagonal(intArr, rows, cols));
  return min_summ;
}
