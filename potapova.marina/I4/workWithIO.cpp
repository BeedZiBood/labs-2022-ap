#include "workWithIO.h"

bool inputMatrix(long long* const matrix, size_t count_rows, size_t count_cols, std::ifstream& in)
{
  for (long long* cur_elem_ptr = matrix; cur_elem_ptr < matrix + count_rows * count_cols; ++cur_elem_ptr)
  {
    if (!(in >> *cur_elem_ptr))
    {
      return false;
    }
  }
  return true;
}

bool inputMatrix(long long* const* const matrix, size_t count_rows, size_t count_cols, std::ifstream& in)
{
  for (long long* const* cur_row_ptr = matrix; cur_row_ptr < matrix + count_rows; ++cur_row_ptr)
  {
    for (long long* cur_elem_ptr = *cur_row_ptr; cur_elem_ptr < *cur_row_ptr + count_cols; ++cur_elem_ptr)
    {
      if (!(in >> *cur_elem_ptr))
      {
        return false;
      }
    }
  }
  return true;
}

void printSpiralMatrix(const long long* const* const spiral_matrix, const size_t matrix_order, std::ostream& out)
{
  for (const long long* const* cur_row_ptr = spiral_matrix; cur_row_ptr < spiral_matrix + matrix_order; ++cur_row_ptr)
  {
    for (const long long* cur_elem_ptr = *cur_row_ptr; cur_elem_ptr < *cur_row_ptr + matrix_order; ++cur_elem_ptr)
    {
      out << *cur_elem_ptr << ' ';
    }
    out << '\n';
  }
}
