#include <iostream>
#include <fstream>
#include "workWithIOAnother.h"

size_t inputMatrixOrder(const char* file_name)
{
  std::ifstream in(file_name);
  if (!in.is_open())
  {
    std::cerr << "Can't open " << file_name << '\n';
    retun 1;
  }
  size_t result;
  in >> result;
  return result;
}

void printSpiralMatrix(const size_t* const spiral_matrix, const size_t matrix_order, const char* const file_name)
{
  std::ofstream out(file_name);
  if (!out.is_open())
  {
    std::cerr << "Can't open " << file_name << '\n';
    return 1;
  }
  for (const size_t* cur_row_ptr = spiral_matrix; cur_row_ptr < spiral_matrix + matrix_order * matrix_order; cur_row_ptr += matrix_order)
  {
    for (const size_t* cur_elem_ptr = cur_row_ptr; cur_elem_ptr < cur_row_ptr + matrix_order; ++cur_elem_ptr)
    {
      out << *cur_elem_ptr << ' ';
    }
    out << '\n';
  }
}
