#include "getCountOfSaddlePoints.h"

std::int64_t getMinElemInRow(const std::int64_t* const begin_elem_ptr,
                             const size_t count_cols)
{
  std::int64_t mn = INT64_MAX;

  for (const std::int64_t* cur_elem_ptr = begin_elem_ptr;
    cur_elem_ptr < begin_elem_ptr + count_cols;
    ++cur_elem_ptr)
  {
    if (*cur_elem_ptr < mn)
    {
      mn = *cur_elem_ptr;
    }
  }

  return mn;
}

std::int64_t getMaxElemInCol(const std::int64_t* const matrix,
                             const size_t count_rows,
                             const size_t count_cols,
                             const size_t num_col)
{
  std::int64_t mx(INT64_MIN);

  for (const std::int64_t* cur_row_ptr = matrix;
    cur_row_ptr < matrix + count_rows * count_cols;
    cur_row_ptr += count_cols)
  {
    std::int64_t cur_elem = *(cur_row_ptr + num_col);
    if (cur_elem > mx)
    {
      mx = cur_elem;
    }
  }

  return mx;
}

bool isMinInRow(std::int64_t*& min_elems_in_rows,
                const std::int64_t* const matrix,
                const size_t count_rows,
                const size_t count_cols,
                const size_t num_row,
                const std::int64_t elem)
{
  if (min_elems_in_rows == nullptr)
  {
    try
    {
      min_elems_in_rows = new std::int64_t[count_rows];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Allocation error " << e.what() << '\n';
      std::exit(1);
    }

    std::int64_t* min_elem_in_cur_row = min_elems_in_rows;
    for (const std::int64_t* cur_row_ptr = matrix;
        cur_row_ptr < matrix + count_rows * count_cols;
        cur_row_ptr += count_cols, ++min_elem_in_cur_row)
    {
      *min_elem_in_cur_row = getMinElemInRow(cur_row_ptr, count_cols);
    }
  }

  return min_elems_in_rows[num_row] == elem;
}

bool isMaxInCol(std::int64_t*& max_elems_in_cols,
                const std::int64_t* const matrix,
                const size_t count_rows,
                const size_t count_cols,
                const size_t num_col,
                const std::int64_t elem)
{
  if (max_elems_in_cols == nullptr)
  {
    try
    {
      max_elems_in_cols = new std::int64_t[count_cols];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Allocation error " << e.what() << '\n';
      std::exit(1);
    }

    std::int64_t* max_elem_in_cur_col = max_elems_in_cols;
    for (size_t num_cur_col = 0;
        num_cur_col < count_cols;
        ++num_cur_col, ++max_elem_in_cur_col)
    {
      *max_elem_in_cur_col = getMaxElemInCol(matrix, count_rows,
                                             count_cols, num_cur_col);
    }
  }

  return max_elems_in_cols[num_col] == elem;
}

size_t getCountOfSaddlePoints(const std::int64_t* const matrix,
                                   const size_t count_rows,
                                   const size_t count_cols)
{
  size_t result = 0;
  std::int64_t* min_elems_in_rows = nullptr;
  std::int64_t* max_elems_in_cols = nullptr;

  for (size_t num_cur_row = 0; num_cur_row < count_rows; ++num_cur_row)
  {
    for (size_t num_cur_col = 0; num_cur_col < count_cols; ++num_cur_col)
    {
      std::int64_t cur_elem = matrix[num_cur_row * count_cols + num_cur_col];
      if (isMinInRow(min_elems_in_rows, matrix, count_rows,
                     count_cols, num_cur_row, cur_elem) &&
                     isMaxInCol(max_elems_in_cols, matrix, count_rows,
                     count_cols, num_cur_col, cur_elem))
      {
        ++result;
      }
    }
  }

  delete[] min_elems_in_rows;
  delete[] max_elems_in_cols;

  return result;
}
