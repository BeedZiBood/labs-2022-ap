#include "workWithIO.h"

std::istream& inputMatrix(long long* const matrix, const size_t count_rows, const size_t count_cols, std::istream& in)
{
  for (long long* cur_elem_ptr = matrix; cur_elem_ptr < matrix + count_rows * count_cols; ++cur_elem_ptr)
  {
    in >> *cur_elem_ptr;
  }
  return in;
}

std::istream& inputMatrix(long long* const* const matrix, const size_t count_rows, const size_t count_cols, std::istream& in)
{
  for (long long* const* cur_row_ptr = matrix; cur_row_ptr < matrix + count_rows; ++cur_row_ptr)
  {
    for (long long* cur_elem_ptr = *cur_row_ptr; cur_elem_ptr < *cur_row_ptr + count_cols; ++cur_elem_ptr)
    {
      in >> *cur_elem_ptr;
    }
  }
  return in;
}

void printMatrix(const long long* const* const matrix, const size_t matrix_order, std::ostream& out)
{
  for (const long long* const* cur_row_ptr = matrix; cur_row_ptr < matrix + matrix_order; ++cur_row_ptr)
  {
    const long long* cur_elem_ptr = *cur_row_ptr;
    for (; cur_elem_ptr < *cur_row_ptr + matrix_order - 1; ++cur_elem_ptr)
    {
      out << *cur_elem_ptr << ' ';
    }
    out << *cur_elem_ptr << '\n';
  }
}
