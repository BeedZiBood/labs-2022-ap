#include <iostream>
#include "getCountOfSaddlePoints.h"

int getMinElemInRow(const int* const begin_elem_ptr, const size_t count_cols)
{
  int mn = INT64_MAX;
  for (const int* cur_elem_ptr = begin_elem_ptr; cur_elem_ptr < begin_elem_ptr + count_cols; ++cur_elem_ptr)
  {
    if (*cur_elem_ptr < mn)
    {
      mn = *cur_elem_ptr;
    }
  }
  return mn;
}

int getMaxElemInCol(const int* const matrix, const size_t count_rows, const size_t count_cols, const size_t num_col)
{
  int mx(INT64_MIN);
  for (const int* cur_row_ptr = matrix; cur_row_ptr < matrix + count_rows * count_cols; cur_row_ptr += count_cols)
  {
    int cur_elem = *(cur_row_ptr + num_col);
    if (cur_elem > mx)
    {
      mx = cur_elem;
    }
  }
  return mx;
}

bool isMinInRow(int*& min_elems_in_rows, const int* const matrix, const size_t count_rows,
                  const size_t count_cols, const size_t num_row, const int elem)
{
  if (min_elems_in_rows == nullptr)
  {
    try
    {
      min_elems_in_rows = new int[count_rows];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Allocation error " << e.what() << '\n';
      return 1;
    }
    int* min_elem_in_cur_row = min_elems_in_rows;
    for (const int* cur_row_ptr = matrix; cur_row_ptr < matrix + count_rows * count_cols; cur_row_ptr += count_cols, ++min_elem_in_cur_row)
    {
      *min_elem_in_cur_row = getMinElemInRow(cur_row_ptr, count_cols);
    }
  }
  return min_elems_in_rows[num_row] == elem;
}

bool isMaxInCol(int*& max_elems_in_cols, const int* const matrix, const size_t count_rows,
                  const size_t count_cols, const size_t num_col, const int elem)
{
  if (max_elems_in_cols == nullptr)
  {
    try
    {
      max_elems_in_cols = new int[count_cols];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Allocation error " << e.what() << '\n';
      return 1;
    }
    int* max_elem_in_cur_col = max_elems_in_cols;
    for (size_t num_cur_col = 0; num_cur_col < count_cols;  ++num_cur_col, ++max_elem_in_cur_col)
    {
      *max_elem_in_cur_col = getMaxElemInCol(matrix, count_rows, count_cols, num_cur_col);
    }
  }
  return max_elems_in_cols[num_col] == elem;
}

size_t getCountOfSaddlePoints(const int* const matrix, const size_t count_rows, const size_t count_cols)
{
  size_t result = 0;
  int* min_elems_in_rows = nullptr;
  int* max_elems_in_cols = nullptr;
  for (size_t num_cur_row = 0; num_cur_row < count_rows; ++num_cur_row)
  {
    for (size_t num_cur_col = 0; num_cur_col < count_cols; ++num_cur_col)
    {
      int cur_elem = matrix[num_cur_row * count_cols + num_cur_col];
      if (isMinInRow(min_elems_in_rows, matrix, count_rows, count_cols, num_cur_row, cur_elem)
            && isMaxInCol(max_elems_in_cols, matrix, count_rows, count_cols, num_cur_col, cur_elem))
      {
        ++result;
      }
    }
  }
  delete[] min_elems_in_rows;
  delete[] max_elems_in_cols;
  return result;
}
