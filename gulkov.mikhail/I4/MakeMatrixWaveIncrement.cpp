#include "MakeMatrixWaveIncrement.hpp"
#include <stdexcept>

int *makeMatrixWaveIncrement(int *matrix, size_t cols, size_t rows, size_t index_row, size_t index_col)
{
  if (index_row > rows || index_col > cols)
  {
    throw std::invalid_argument("First number indexes are out of bounds.");
  }
  index_row--;
  index_col--;
  matrix[cols * index_row + index_col] = 1;
  for (size_t i = 0; i < cols; i++)
  {
    for (size_t j = 0; j < rows; j++)
    {
      size_t row_difference = std::max(i, index_row) - std::min(i, index_row);
      size_t col_difference = std::max(j, index_col) - std::min(j, index_col);
      matrix[cols * i + j] = std::max(row_difference, col_difference) + 1;
    }
  }
  return matrix;
}
