#include "MatrixWrapper.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>

odintsov::MatrixWrapper::MatrixWrapper(size_t rows, size_t cols):
  rows(rows),
  cols(cols),
  arr(new int*[rows])
{
  for (size_t r = 0; r < rows; r++) {
    try {
      arr[r] = new int[cols];
    } catch (const std::bad_alloc& err) {
      for (size_t delR = 0; delR < r; delR++) {
        delete [] arr[delR];
      }
      delete arr;
      throw;
    }
  }
}

odintsov::MatrixWrapper::~MatrixWrapper()
{
  for (size_t r = 0; r < rows; r++) {
    delete [] arr[r];
  }
  delete [] arr;
}

std::istream& odintsov::MatrixWrapper::readRow(std::istream& in, size_t row)
{
  for (size_t c = 0; c < cols; c++) {
    in >> arr[row][c];
    if (!in) {
      throw std::runtime_error("Stream read error");
    }
  }
  return in;
}

std::istream& odintsov::MatrixWrapper::readMatrix(std::istream& in)
{
  for (size_t r = 0; r < rows; r++) {
    readRow(in, r);
  }
  return in;
}

std::ostream& odintsov::MatrixWrapper::outputRow(std::ostream& out, size_t row)
{
  if (rows == 0 || cols == 0) {
    return out;
  }
  for (size_t c = 0; c < cols - 1; c++) {
    out << arr[row][c] << ' ';
    if (!out) {
      throw std::runtime_error("Stream write error");
    }
  }
  return out << arr[row][cols - 1];
}

std::ostream& odintsov::MatrixWrapper::outputMatrix(std::ostream& out)
{
  if (rows == 0 || cols == 0) {
    return out;
  }
  for (size_t r = 0; r < rows - 1; r++) {
    outputRow(out, r) << '\n';
  }
  return outputRow(out, rows - 1);
}
