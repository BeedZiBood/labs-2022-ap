#include "SumUnderMainDiagonal.h"
#include <cmath>

double SumUnderMainDiagonal(const int* matrix, size_t line, size_t column)
{
  double absSum = 0;
  for (size_t i = 1; i < column; i++)
  {
    for (size_t j = 0; j < i; j++)
    {
      double localSum = 0;
      size_t localCount = 0;
      if (j - 1 >= 0 && j - 1 < line)
      {
        localSum = localSum + matrix[line * i + (j - 1)];
        localCount++;
      }
      if (j + 1 >= 0 && j + 1 < line)
      {
        localSum = localSum + matrix[line * i + (j + 1)];
        localCount++;
      }
      if (i - 1 >= 0 && i - 1 < column)
      {
        localSum = localSum + matrix[line * (i - 1) + j];
        localCount++;
      }
      if (i + 1 >= 0 && i + 1 < column)
      {
        localSum = localSum + matrix[line * (i + 1) + j];
        localCount++;
      }
      absSum = absSum + std::abs(localSum / localCount);
    }
  }
  return absSum;
}
