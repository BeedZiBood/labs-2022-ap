#include "SumUnderMainDiagonal.hpp"
#include <cmath>

double sumUnderMainDiagonal(const double *smooth_arr, size_t cols, size_t rows)
{
  double sum = 0;

  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      if (j < i)
      {
        sum += std::abs(smooth_arr[cols * i + j]);
      }
    }
  }

  return sum;
}
