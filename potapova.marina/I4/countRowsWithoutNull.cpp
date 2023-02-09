#include "countRowsWithoutNull.h"
#include <cstddef>

size_t countRowsWithoutNull(const int* matrix,
                            const size_t count_rows,
                            const size_t count_cols)
{
  size_t result = 0;
  size_t num_zero_rows = 0;

  for (const int* cur_row_ptr = matrix;
      cur_row_ptr < matrix + count_cols * count_rows;
      cur_row_ptr += count_cols)
  {
    for (const int* cur_elem_ptr = cur_row_ptr;
        cur_elem_ptr < cur_row_ptr + count_cols;
        ++cur_elem_ptr)
    {
      if (*cur_elem_ptr == 0)
      {
        ++num_zero_rows;
        break;
      }
    }
  }
  result = count_rows - num_zero_rows;
  return result;
}
