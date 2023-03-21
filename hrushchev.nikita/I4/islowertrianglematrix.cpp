#include "islowertrianglematrix.hpp"
#include <cstddef>

bool isLowerTriangleMatrix(const int* array, const size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if ((j > i) && (array[i * size + j] != 0))
      {
        return false;
      }
    }
  }
  return true;
}
