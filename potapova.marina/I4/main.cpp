#include "countColIfContainsZero.h"
#include "countStrsWithoutNull.h"
#include "inputOutputStaticMatrix.h"
#include "fillSpiralMatrix.h"
#include "workWithIO.h"
#include "getCountOfSaddlePoints.h"

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cerr << "Incorrect count of main arguments\n";

    return 1;
  }

  const std::uint16_t matrix_order = inputMatrixOrder(argv[1]);

  std::uint32_t* spiral_matrix;

  try
  {
    spiral_matrix = new std::uint32_t[matrix_order * matrix_order];
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';

    return 1;
  }

  fillSpiralMatrix(spiral_matrix, matrix_order);
  printSpiralMatrix(spiral_matrix, matrix_order, argv[2]);

  delete[] spiral_matrix;

  size_t count_rows;
  size_t count_cols;
  std::int64_t* matrix;

  inputMatrix(count_rows, count_cols, matrix, argv[1]);

  printCountOfSaddlePoints(
      getCountOfSaddlePoints(matrix, count_rows, count_cols),
      argv[2]);

  delete[] matrix;

  

  return 0;
}
