#include "matrixOperations.h"
#include <algorithm>
#include <cmath>

size_t turkin::getNotZeroLines(const int * matrix, size_t mx, size_t my)
{
  size_t amount = 0;
  for (size_t i = 0; i < mx; i++)
  {
    for (size_t q = 0; q < my; q++)
    {
      if (matrix[i * mx + q] == 0)
      {
        amount++;
        break;
      }
    }
  }
  return my - amount;
}

size_t turkin::getSameSumLines(const int * matrix, size_t mx, size_t my)
{
  size_t amount = 0;
  int sum = 0;
  for (size_t i = 0; i < mx; i++)
  {
    sum = getSumOfLine(matrix, mx, my, i);
    for (size_t q = 0; q < mx; q++)
    {
      if (sum == getSumOfLine(matrix, mx, my, q) && i != q)
      {
        amount++;
      }
    }
  }
  return amount;
}

int turkin::getSumOfLine(const int * matrix, size_t mx, size_t my, size_t line)
{
  int sum = 0;
  for (size_t q = 0; q < my; q++)
  {
    sum = sum + matrix[line * mx + q];
  }
  return sum;
}

size_t turkin::getSaddlePoints(int * matrix, size_t mx, size_t my)
{
  size_t amount = 0;
  for (size_t i = 0; i < mx; i++)
  {
    for (size_t q = 0; q < my; q++)
    {
      int element = turkin::get(matrix, i, q);
      int * row = turkin::getRow(matrix, my, i);
      int * column = turkin::getColumn(matrix, mx, my, q);
      if (element == *std::min_element(row, row + my) && element == *std::max_element(column, column + mx))
      {
        amount++;
      }
      delete [] row;
      delete [] column;
    }
  }
  return amount;
}

size_t turkin::getSumOfModules(int * matrix, size_t mx, size_t my)
{
  int * smoothedMatrix = turkin::getSmoothedMatrix(matrix, mx, my);
  size_t sum = 0;
  for (size_t i = 0; i < mx; i++)
  {
    for (size_t q = 0; q < i; q++)
    {
      sum = sum + std::abs(turkin::get(smoothedMatrix, i, q));
    }
  }
  delete [] smoothedMatrix;
  return sum;
}

int * turkin::getSmoothedMatrix(const int * matrix, size_t mx, size_t my)
{
  int * result = new int[mx * my];
  size_t amount = 0;
  int sum = 0;
  for (size_t i = 0; i < mx; i++)
  {
    for (size_t q = 0; q < my; q++)
    {
      sum = 0;
      amount = 0;
      for (size_t k = (i == 0) ? i : i - 1; k <= i + 1; k++)
      {
        for (size_t l = (q == 0) ? q : q - 1; l <= q + 1; l++)
        {
          if ((k != i && l != q) && k < mx && l < my)
          {
            sum = sum + turkin::get(matrix, k, l);
            amount++;
          }
        }
      }
      turkin::set(result, i, q, sum / amount);
    }
  }
  return result;
}
