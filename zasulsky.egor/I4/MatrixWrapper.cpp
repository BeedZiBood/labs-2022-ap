#include "MatrixWrapper.hpp"
#include <cstddef>

zasulsky::MatrixWrapper::MatrixWrapper(size_t rows, size_t cols):
  rows(rows),
  cols(cols),
  matrix(new int[rows * cols])
{}

zasulsky::MatrixWrapper::~MatrixWrapper()
{
  delete [] matrix;
}
