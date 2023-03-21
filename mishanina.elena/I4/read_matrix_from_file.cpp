#include "read_matrix_from_file.h"

int* readMatrixFromFile(int* matrix, size_t rows, size_t columns, std::ifstream& input)
{
  for (size_t i = 0; i < rows * columns; i++)
  {
    input >> matrix[i];
    if (!input)
    {
      throw std::runtime_error("ERROR: file cannot be read\n");
    }
  }
  return matrix;
}
