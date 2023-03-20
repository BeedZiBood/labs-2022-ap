#include "allocationAndDeleteMatrix.h"
#include <new>

long long** createMatrix(size_t count_rows, size_t count_cols)
{
  long long** result = nullptr;
  try
  {
    result = new long long*[count_rows];
  }
  catch(const std::bad_alloc& e)
  {
    return nullptr;
  }
  for (long long** cur_row_ptr = result; cur_row_ptr < result + count_rows; ++cur_row_ptr)
  {
    try
    {
      *cur_row_ptr = new long long[count_cols];
    }
    catch(const std::bad_alloc& e)
    {
      deleteMatrix(result, static_cast< size_t >(cur_row_ptr - result - 1));
      return nullptr;
    }
  }
  return result;
}

void deleteMatrix(const long long* const* const matrix, const size_t count_rows)
{
  for (const long long* const* cur_row_ptr = matrix; cur_row_ptr < matrix + count_rows; ++cur_row_ptr)
  {
    delete[] *cur_row_ptr;
  }
  delete[] matrix;
}
