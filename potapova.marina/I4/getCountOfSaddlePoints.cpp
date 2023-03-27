#include "getCountOfSaddlePoints.h"
#include <limits>
#include <new>

long long getMinElemInRow(const long long* const* const begin_elem_ptr, const size_t count_cols)
{
  long long min_elem = std::numeric_limits< long long >::max();
  for (const long long* cur_elem_ptr = *begin_elem_ptr; cur_elem_ptr < *begin_elem_ptr + count_cols; ++cur_elem_ptr)
  {
    if (*cur_elem_ptr < min_elem)
    {
      min_elem = *cur_elem_ptr;
    }
  }
  return min_elem;
}

long long getMaxElemInCol(const long long* const* const matrix, const size_t count_rows, const size_t num_col)
{
  long long max_elem = std::numeric_limits< long long >::min();
  for (const long long* const* cur_row_ptr = matrix; cur_row_ptr < matrix + count_rows; ++cur_row_ptr)
  {
    long long cur_elem = (*cur_row_ptr)[num_col];
    if (cur_elem > max_elem)
    {
      max_elem = cur_elem;
    }
  }
  return max_elem;
}

bool isMinInRow(const long long* const* const matrix,
  const size_t count_cols,
  const size_t num_row,
  const long long elem)
{
  return getMinElemInRow(matrix + num_row, count_cols) == elem;
}

bool isMaxInCol(const long long* const* const matrix,
  const size_t count_rows,
  const size_t num_col,
  const long long elem)
{
  return getMaxElemInCol(matrix, count_rows, num_col) == elem;
}

bool isSaddlePoint(const long long* const* const matrix,
  const size_t count_rows,
  const size_t count_cols,
  const size_t num_row,
  const size_t num_col,
  const long long elem)
{
  return isMinInRow(matrix, count_cols, num_row, elem) && isMaxInCol(matrix, count_rows, num_col, elem);
}

size_t getCountOfSaddlePoints(const long long* const* const matrix,
  const size_t count_rows,
  const size_t count_cols)
{
  size_t result = 0;
  for (size_t num_cur_row = 0; num_cur_row < count_rows; ++num_cur_row)
  {
    for (size_t num_cur_col = 0; num_cur_col < count_cols; ++num_cur_col)
    {
      if (isSaddlePoint(matrix, count_rows, count_cols, num_cur_row, num_cur_col, matrix[num_cur_row][num_cur_col]))
      {
        ++result;
      }
    }
  }
  return result;
}
