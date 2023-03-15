#include "readMatrix.h"

void readMatrix(std::ifstream& inputFile, int* matrix, size_t numRows, size_t numCols)
{
  for (size_t i = 0; i < numRows; i++)
  {
    for (size_t j = 0; j < numCols; j++)
    {
      if (!(inputFile >> *(matrix + i * numCols + j)))
      {
        throw std::runtime_error("Error: Failed to read matrix element!");
      }
    }
  }
}
