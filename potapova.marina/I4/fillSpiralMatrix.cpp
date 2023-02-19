#include "fillSpiralMatrix.h"

void fillSpiralMatrix(std::uint32_t* const dest,
                      const std::uint16_t matrix_order)
{
  static std::uint16_t original_matrix_order = 0;

  if (original_matrix_order == 0)
  {
    original_matrix_order = matrix_order;
  }

  static std::uint32_t cur_elem_val = 1;

  if (matrix_order == 1 && (original_matrix_order & 1) == 1)
  {
    *dest = cur_elem_val;
  }
  else if (matrix_order > 1)
  {
    for (std::uint32_t* cur_elem_ptr = dest + matrix_order - 1;
      cur_elem_ptr >= dest;
      --cur_elem_ptr)
    {
      *cur_elem_ptr = cur_elem_val++;
    }

    std::uint32_t* first_elem_in_last_row_ptr =
      dest + original_matrix_order * (matrix_order - 1);

    for (std::uint32_t* cur_elem_ptr = dest + original_matrix_order;
      cur_elem_ptr <= first_elem_in_last_row_ptr;
      cur_elem_ptr += original_matrix_order)
    {
      *cur_elem_ptr = cur_elem_val++;
    }

    for (std::uint32_t* cur_elem_ptr = first_elem_in_last_row_ptr + 1;
      cur_elem_ptr < first_elem_in_last_row_ptr + matrix_order;
      ++cur_elem_ptr)
    {
      *cur_elem_ptr = cur_elem_val++;
    }

    for (std::uint32_t* cur_elem_ptr = first_elem_in_last_row_ptr -
           original_matrix_order + matrix_order - 1;
      cur_elem_ptr > dest + matrix_order - 1;
      cur_elem_ptr -= original_matrix_order)
    {
      *cur_elem_ptr = cur_elem_val++;
    }

    fillSpiralMatrix(dest + original_matrix_order + 1, matrix_order - 2);
  }
}
