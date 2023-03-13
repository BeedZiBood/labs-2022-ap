#include <new>
#include "getCountOfSaddlePoints.h"

long long getMinElemInRow(const long long* const* const begin_elem_ptr, const size_t count_cols)
{
  long long min_elem = 9223372036854775807LL;
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
  long long max_elem = -9223372036854775807LL - 1;
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

bool isMinInRow(long long* min_elems_in_rows, const long long* const* const matrix,
                const size_t count_cols, const size_t num_row, const long long elem)
{
  if (min_elems_in_rows == nullptr)
  {
    return getMinElemInRow(matrix + num_row, count_cols) == elem; 
  }
  return min_elems_in_rows[num_row] == elem;
}

bool isMaxInCol(long long* max_elems_in_cols, const long long* const* const matrix,
                const size_t count_rows, const size_t num_col, const long long elem)
{
  if (max_elems_in_cols == nullptr)
  {
    return getMaxElemInCol(matrix, count_rows, num_col);
  }
  return max_elems_in_cols[num_col] == elem;
}

size_t getCountOfSaddlePoints(const long long* const* const matrix, const size_t count_rows, const size_t count_cols)
{
  size_t result = 0;
  long long* min_elems_in_rows;
  long long* max_elems_in_cols;
  try
  {
    min_elems_in_rows = new long long[count_rows];
    max_elems_in_cols = new long long[count_cols];
    long long* min_elem_in_cur_row = min_elems_in_rows;
    for (const long long* const* cur_row_ptr = matrix; cur_row_ptr < matrix + count_rows; ++cur_row_ptr, ++min_elem_in_cur_row)
    {
      *min_elem_in_cur_row = getMinElemInRow(cur_row_ptr, count_cols);
    }
    long long* max_elem_in_cur_col = max_elems_in_cols;
    for (size_t num_cur_col = 0; num_cur_col < count_cols; ++num_cur_col, ++max_elem_in_cur_col)
    {
      *max_elem_in_cur_col = getMaxElemInCol(matrix, count_rows, num_cur_col);
    }
  }
  catch (const std::bad_alloc&)
  {
    min_elems_in_rows = nullptr;
    max_elems_in_cols = nullptr;
  }

  for (size_t num_cur_row = 0; num_cur_row < count_rows; ++num_cur_row)
  {
    for (size_t num_cur_col = 0; num_cur_col < count_cols; ++num_cur_col)
    {
      long long cur_elem = matrix[num_cur_row][num_cur_col];
      if (isMinInRow(min_elems_in_rows, matrix, count_cols, num_cur_row, cur_elem)
          && isMaxInCol(max_elems_in_cols, matrix, count_rows, num_cur_col, cur_elem))
      {
        ++result;
      }
    }
  }
  delete[] min_elems_in_rows;
  delete[] max_elems_in_cols;
  return result;
}
