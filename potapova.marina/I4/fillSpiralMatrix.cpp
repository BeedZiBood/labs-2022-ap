#include <iostream>
#include "fillSpiralMatrix.h"

void printSpiralMatrix(const long long* const* const spiral_matrix, const size_t matrix_order, size_t count_slice)
{
  for (const long long* const* cur_row_ptr = spiral_matrix; cur_row_ptr < spiral_matrix + matrix_order; ++cur_row_ptr)
  {
    for (const long long* cur_elem_ptr = *cur_row_ptr + count_slice;
          cur_elem_ptr < *cur_row_ptr + matrix_order + count_slice; ++cur_elem_ptr)
    {
      std::cout << *cur_elem_ptr << ' ';
    }
    std::cout << '\n';
  }
}

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
    for (long long* cur_elem_ptr = dest[0] + count_slice + matrix_order - 1; cur_elem_ptr >= dest[0] + count_slice; --cur_elem_ptr)
    {
      *cur_elem_ptr = cur_elem_val++;
      printSpiralMatrix(dest, matrix_order, count_slice);
    }
    long long** last_row_ptr = dest + matrix_order - 1;
    for (long long** cur_row_ptr = dest + 1; cur_row_ptr <= last_row_ptr; ++cur_row_ptr)
    {
      (*cur_row_ptr)[count_slice] = cur_elem_val++;
      printSpiralMatrix(dest, matrix_order, count_slice);
    }
    for (long long* cur_elem_ptr = *last_row_ptr + count_slice + 1;
          cur_elem_ptr < *last_row_ptr + count_slice + matrix_order; ++cur_elem_ptr)
    {
      *cur_elem_ptr = cur_elem_val++;
      printSpiralMatrix(dest, matrix_order, count_slice);
    }
    for (long long** cur_row_ptr = last_row_ptr - 1; cur_row_ptr > dest; --cur_row_ptr)
    {
      (*cur_row_ptr)[matrix_order + count_slice - 1] = cur_elem_val++;
      printSpiralMatrix(dest, matrix_order, count_slice);
    }
    ++count_slice;
    fillSpiralMatrix(dest + 1, matrix_order - 2);
  }
}
