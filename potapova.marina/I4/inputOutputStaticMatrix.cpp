#include "inputOutputStaticMatrix.h"
#include <cstddef>
#include <fstream>

void inputStaticMatrix(int* matrix, size_t size, std::ifstream & input)
{
  for (size_t i = 0; i < size; i++)
  {
    input >> matrix[i];
  }
}

void setMatrixElement(int* matrix, size_t num_rows, size_t num_cols, int element)
{
  matrix[num_rows * num_rows + num_cols] = element;
}

int outputStaticMatrix(const int* matrix, size_t num_rows, size_t num_cols)
{
  return matrix[num_rows * num_rows + num_cols];
}
