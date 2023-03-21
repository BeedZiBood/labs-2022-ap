#include "readArray.h"

int* readArrayFromFile(int* matrix, size_t size, std::ifstream& input)
{
  for (size_t i = 0; i < size; i++)
  {
    input >> matrix[i];
    if (!input)
    {
      return nullptr;
    }
  }
  return matrix;
}
