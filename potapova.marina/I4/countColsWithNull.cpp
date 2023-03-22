#include "countColsWithNull.h"

size_t countColsWithNull(const long long* const matrix, size_t count_rows, size_t count_cols)
{
  size_t result = 0;
  for (const long long* cur_col_ptr = matrix; cur_col_ptr < matrix + count_cols; ++cur_col_ptr)
  {
    const long long* const end_of_row_ptr = cur_col_ptr + count_rows * count_cols;
    for (const long long* cur_elem_ptr = cur_col_ptr; cur_elem_ptr < end_of_row_ptr; cur_elem_ptr += count_rows)
    {
      if (*cur_elem_ptr == 0)
      {
        ++result;
        break;
      }
    }
  }
  return result;
}
