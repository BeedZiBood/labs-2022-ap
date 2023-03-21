#include "countcolumnsequalsumelement.hpp"
#include "countduplicates.hpp"
#include <cstddef>

size_t countColumnsEqualSumElement(const int* array, int* arr_column_sums, const size_t rows, const size_t columns)
{
  if (columns == 1)
  {
    return 0;
  }

  int current_sum = 0;

  for (size_t i = 0; i < columns; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      current_sum += array[i + rows * j];
    }
    arr_column_sums[i] = current_sum;
    current_sum = 0;
  }

  return countDuplicates(arr_column_sums, columns);
}

