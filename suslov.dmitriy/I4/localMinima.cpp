#include "localMinima.h"
#include <iostream>
bool scanMatrixOne(int matrix[1000], std::istream &in_stream, size_t &n, size_t &m)
{
  if (!in_stream.eof())
  {
    in_stream >> n;
  }
  else
  {
    return false;
  }
  if (!in_stream.eof())
  {
    in_stream >> m;
  }
  else
  {
    return false;
  }
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (!in_stream.eof())
      {
        in_stream >> matrix[i * m + j];
      }
      else
      {
        return false;
      }
    }
  }
  return true;
}
size_t counterZero(int matrix[1000], size_t n, size_t m)
{
  size_t k = 0;
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (matrix[i * m + j] == 0)
      {
        k++;
        break;
      }
    }
  }
  return k;
}
