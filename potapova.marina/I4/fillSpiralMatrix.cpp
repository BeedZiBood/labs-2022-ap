#include "fillSpiralMatrix.h"

void fillSpiralMatrix(size_t* const dest, const size_t matrix_order)
{
  static size_t orig_matrix_order = 0;
  if (orig_matrix_order == 0)
  {
    orig_matrix_order = matrix_order;
  }
  static size_t cur_elem_val = 1;
  if (matrix_order == 1 && (orig_matrix_order & 1) == 1)
  {
    *dest = cur_elem_val;
  }
  else if (matrix_order > 1)
  {
    for (size_t* cur_elem_ptr = dest + matrix_order - 1; cur_elem_ptr >= dest; --cur_elem_ptr)
    {
      *cur_elem_ptr = cur_elem_val++;
    }
    size_t* first_in_row_ptr = dest + orig_matrix_order * (matrix_order - 1);
    for (size_t* cur_elem_ptr = dest + orig_matrix_order; cur_elem_ptr <= first_in_row_ptr; cur_elem_ptr += orig_matrix_order)
    {
      *cur_elem_ptr = cur_elem_val++;
    }
    for (size_t* cur_elem_ptr = first_in_row_ptr + 1; cur_elem_ptr < first_in_row_ptr + matrix_order; ++cur_elem_ptr)
    {
      *cur_elem_ptr = cur_elem_val++;
    }
    for (size_t* cur_elem_ptr = first_in_row_ptr - orig_matrix_order + matrix_order - 1;
          cur_elem_ptr > dest + matrix_order - 1; cur_elem_ptr -= orig_matrix_order)
    {
      *cur_elem_ptr = cur_elem_val++;
    }
    fillSpiralMatrix(dest + orig_matrix_order + 1, matrix_order - 2);
  }
}
