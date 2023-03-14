#include "readMatrix.h"

int* readMatrix(int* matrix, size_t size_1, std::ifstream& fileInput)
{
  for (size_t i = 0; i < size_1; i++)
  {
    fileInput >> matrix[i];
    if (!fileInput)
    {
      throw std::length_error("Problems while reading file\n");
    }
  }
  return matrix;
}
