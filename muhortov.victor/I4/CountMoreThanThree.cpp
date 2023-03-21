#include "CountMoreThanThree.hpp"

size_t findCountMoreThanThree(const int *arr, size_t cols, size_t rows)
{
  size_t repeat_counter = 0;
  size_t count_triple_cols = 0;
  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      for (size_t k = 0; k < rows && repeat_counter < 4; k++)
      {
        if (arr[cols * i + j] == arr[cols * i + k])
        {
          repeat_counter++;
        }
        if (repeat_counter > 3)
        {
          count_triple_cols++;
          j = cols * i + rows;
          break;
        }
      }
      repeat_counter = 0;
    }
  }

  return count_triple_cols;
}
