#include "matrixWaveValue.h"
#include <stdexcept>
size_t* assignMatrixWaveValue(size_t* matrix, size_t cols, size_t rows, size_t index_row, size_t index_col)
{
  if (index_row > rows || index_col > cols)
  {
    throw std::invalid_argument("First number of indexes that are out");
  }
  index_row--;
  index_col--;
  matrix[cols * index_row + index_col] = 1;
  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      size_t row_difference, col_difference;
      if (i > index_row)
      {
        row_difference = i - index_row;
      }
      else
      {
        row_difference = index_row - i;
      }
      if (j > index_col)
      {
        col_difference = j - index_col;
      }
      else
      {
        col_difference = index_col - j;
      }
      size_t max_difference = row_difference > col_difference ? row_difference : col_difference;
      matrix[cols * i + j] = max_difference + 1;
    }
  }
  return matrix;
}
