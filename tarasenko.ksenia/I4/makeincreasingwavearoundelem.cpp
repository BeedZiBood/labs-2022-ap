#include "makeincreasingwavearoundelem.hpp"
#include <algorithm>
#include <stdexcept>

int * makeIncreasingWaveAroundElem(int * arr, size_t m, size_t n, size_t row_number_elem, size_t col_number_elem)
{
  if (row_number_elem > m || col_number_elem > n )
  {
    throw std::invalid_argument("Incorrect data entered");
  }
  row_number_elem--;
  col_number_elem--;
  arr[row_number_elem * n + col_number_elem] = 1;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      size_t abs_diff_i_row_number_elem = std::max(i, row_number_elem) - std::min(i, row_number_elem);
      size_t abs_diff_j_col_number_elem = std::max(j, col_number_elem) - std::min(j, col_number_elem);
      arr[i * n + j] = 1 + std::max(abs_diff_i_row_number_elem, abs_diff_j_col_number_elem);
    }
  }
  return arr;
}
