#include "CountPositiveCols.hpp"

size_t countPositiveCols(const int *array, size_t cols, size_t rows)
{
  size_t positive_cols = 0;
  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      if (array[cols * i + j] > 0)
      {
        positive_cols++;
        break;
      }
    }
  }
  return positive_cols;
}
