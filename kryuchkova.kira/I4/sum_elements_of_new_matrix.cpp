#include "sum_elements_of_new_matrix.h"
#include <cmath>
#include <iostream>

double sum_elements_of_new_matrix(int *matrix, size_t rows, size_t columns)
{
  double sum_elements = 0;
  double element = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      int neighbors = 0;
      int sum_nei = 0;
      if (j < i)
      {
        if (i != 0)
        {
          neighbors++;
          sum_nei = sum_nei + abs(matrix[(i - 1) * rows + j]);
          std::cout << matrix[(i - 1) * rows + j] << ' ';
        }
        if (j != 0)
        {
          neighbors++;
          sum_nei = sum_nei + abs(matrix[i * rows + (j - 1)]);
          std::cout << matrix[i * rows + (j - 1)] << ' ';
        }
        if ((i + 1) < rows)
        {
          neighbors++;
          sum_nei = sum_nei + abs(matrix[(i + 1) * rows + j]);
          std::cout << matrix[(i + 1) * rows + j] << ' ';
        }
        if ((j + 1) < columns)
        {
          neighbors++;
          sum_nei = sum_nei + abs(matrix[i * rows + (j + 1)]);
          std::cout << matrix[i * rows + (j + 1)] << ' ';
        }
        element = sum_nei / neighbors;
        sum_elements = sum_elements + element;
        std::cout << '\n';
      }
    }
  }
  return sum_elements;
}