#include "create_square_matrix.h"

int* createSquareMatrix(const int* dynamicMatrix, size_t rows, size_t columns, int* squareMatrix, size_t squareMatrixSize)
{
  if (columns < rows)
  {
    for (size_t i = 0; i < (squareMatrixSize * squareMatrixSize); ++i)
    {
      squareMatrix[i] = dynamicMatrix[i];
    }
  }
  else if (columns > rows)
  {
    for (size_t i = 0; i < squareMatrixSize; ++i)
    {
      for (size_t j = 0; j < squareMatrixSize; ++j)
      {
        squareMatrix[squareMatrixSize * i + j] = dynamicMatrix[columns * i + j];
      }
    }
  }
  return squareMatrix;
}
