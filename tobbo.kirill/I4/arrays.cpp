#include "arrays.h"
#include <cstddef>
#include <cstring>
#include <stdexcept>

void fillArray(int* arr, size_t rows, size_t cols, std::ifstream& in)
{
  size_t size = rows * cols;
  for (size_t i = 0; i < size; ++i)
  {
    in >> arr[i];
    if (in.fail())
    {
      throw std::runtime_error("Error while readaing from file");
    }
  }
}

void printArray(std::ostream& out, const int* arr, size_t rows, size_t cols)
{
  for (size_t row = 0; row < rows; row++)
  {
    for (size_t col = 0; col < cols; col++)
    {
      out << arr[row * cols + col];
      if (col == (cols - 1) && row < (rows - 1))
      {
        out << "\n";
      }
      else
      {
        out << " ";
      }
    }
  }
}

size_t getPositiveRowsCount(const int* arr, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t row = 0; row < rows; row++)
  {
    bool foundNegative = false;
    for (size_t col = 0; col < cols; col++)
    {
      if (arr[row * cols + col] < 0)
      {
        foundNegative = true;
        break;
      }
    }
    if (!foundNegative)
    {
      count++;
    }
  }
  return count;
}

int calcSumDiagonal(const int* arr, size_t rows, size_t cols, size_t diagNum)
{
  int summ = 0;
  for (size_t row = 0; row < rows; ++row)
  {
    for (size_t col = 0; col < cols; ++col)
    {
      if ((row + col) == diagNum)
      {
        summ += arr[row * cols + rows - 1 - col];
      }
    }
  }
  return summ;
}

int getMaxSumDiag(const int* arr, size_t size)
{
  size_t rows = size;
  size_t cols = size;
  int maxSum = 0;
  for (size_t diag = 0; diag < (2 * rows) - 1; ++diag)
  {
    if (diag + 1 != rows)
    {
      int sum = calcSumDiagonal(arr, rows, cols, diag);
      if (maxSum < sum)
      {
        maxSum = sum;
      }
    }
  }
  return maxSum;
}
