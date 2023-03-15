#include "reading_elements.h"
#include <stdexcept>
void readElements(int* matrix, size_t column, size_t line, std::istream& file_matrix_in)
{
  for (size_t i = 0; i < column * line; i++)
  {
    file_matrix_in >> matrix[i];
    if (!file_matrix_in)
    {
      throw std::runtime_error("something went wrong..");
    }
  }
}
