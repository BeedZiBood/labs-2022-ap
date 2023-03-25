#include "scanMatrix.h"
std::istream& scanSize(std::istream &in_stream, size_t &n, size_t &m)
{
  if (!(in_stream >> n))
  {
    throw std::runtime_error("error");
  }
  if (!(in_stream >> m))
  {
    throw std::runtime_error("error");
  }
  return in_stream;
}
std::istream& scanMatrix(int *matrix, std::istream &in_stream, const size_t n, const size_t m)
{
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (!(in_stream >> matrix[i * n + j]))
      {
        throw std::runtime_error("matrix error");
      }
    }
  }
  return in_stream;
}
