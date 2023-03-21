#include "make_square_matrix.h"

int* makeSquareMatrix(const int* source, size_t rows, size_t columns, int* destination, size_t square_size)
{
  if (columns < rows)
  {
    for (size_t i = 0; i < (square_size * square_size); ++i)
    {
      destination[i] = source[i];
    }
  }
  else if (columns > rows)
  {
    for (size_t i = 0; i < square_size; ++i)
    {
      for (size_t j = 0; j < square_size; ++j)
      {
        destination[(i * square_size) + j] = source[(i * columns) + j];
      }
    }
  }
  return destination;
}
