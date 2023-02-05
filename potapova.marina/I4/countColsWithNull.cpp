#include "countColsWithNull.h"
#include <cstddef>

size_t countColsWithNull(const int* matrix, size_t count_rows, size_t count_cols)
{
  size_t result = 0;

  for (const int* cur_col_ptr = matrix; cur_col_ptr < matrix + count_rows; cur_col_ptr += count_rows)
  {
    for (const int* cur_rlrm_ptr = cur_col_ptr; cur_elem_ptr < cur_col_ptr + count_rows; ++cur_elem_ptr)
    {
      if (*cut_elem_ptr == 0)
      {
        ++result;
        break;
      }
    }
  }
  return result;
}
