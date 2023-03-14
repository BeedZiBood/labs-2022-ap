#include "readMatrix.h"

int* readMatrixFromFile(int* matrix, size_t size, std::ifstream& inputFile)
{
  for (size_t i = 0; i < size; i++)
  {
    inputFile >> matrix[i];
    if (!inputFile)
    {
      return nullptr;
    }
  }
  return matrix;
}
