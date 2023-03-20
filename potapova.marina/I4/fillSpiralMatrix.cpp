#include "fillSpiralMatrix.h"

void fillSpiralMatrix(long long** const dest, const size_t matrix_order)
{
  static size_t count_slice = 0;
  static long long cur_elem_val = 1;
  if (matrix_order == 1)
  {
    dest[0][count_slice] = cur_elem_val;
  }
  else if (matrix_order > 1)
  {
    long long* const first_elem_ptr = dest[0] + count_slice;
    long long* const end_of_row_ptr = first_elem_ptr + matrix_order - 1;
    for (long long* cur_elem_ptr = end_of_row_ptr; cur_elem_ptr >= first_elem_ptr; --cur_elem_ptr)
    {
      *cur_elem_ptr = cur_elem_val++;
    }
    long long** last_row_ptr = dest + matrix_order - 1;
    for (long long** cur_row_ptr = dest + 1; cur_row_ptr <= last_row_ptr; ++cur_row_ptr)
    {
      (*cur_row_ptr)[count_slice] = cur_elem_val++;
    }
    const long long* const last_elem_ptr = *last_row_ptr + count_slice + matrix_order;
    for (long long* cur_elem_ptr = *last_row_ptr + count_slice + 1; cur_elem_ptr < last_elem_ptr; ++cur_elem_ptr)
    {
      *cur_elem_ptr = cur_elem_val++;
    }
    for (long long** cur_row_ptr = last_row_ptr - 1; cur_row_ptr > dest; --cur_row_ptr)
    {
      (*cur_row_ptr)[matrix_order + count_slice - 1] = cur_elem_val++;
    }
    ++count_slice;
    fillSpiralMatrix(dest + 1, matrix_order - 2);
  }
}
