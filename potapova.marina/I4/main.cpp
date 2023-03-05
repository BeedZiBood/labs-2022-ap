#include <cstring>
#include <iostream>
#include <fstream>
#include "countColsWithNull.h"
#include "countRowsWithoutNull.h"
#include "inputOutputStaticMatrix.h"
#include "fillSpiralMatrix.h"
#include "workWithIO.h"
#include "getCountOfSaddlePoints.h"
#include "workWithIOAnother.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect count of main arguments\n";
    return 1;
  }
  size_t count_rows = 0;
  size_t count_cols = 0;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "File cannot be open\n";
    return 1;
  }
  input >> count_rows >> count_cols;
  if (!input)
  {
    std::cerr << "File is empty\n";
    return 1;
  }
  if (count_rows * count_cols > 1000)
  {
    std::cerr << "Incorrect range";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int static_arr[1000];
    for (size_t i = 0; i < count_rows * count_cols; ++i)
    {
      input >> static_arr[i];
      if (!input)
      {
        std::cerr << "Error\n";
        return 1;
      }
    }
    std::ofstream output(argv[3]);
    output << countRowsWithoutNull(static_arr, count_rows, count_cols) << " "
           << countColsWithNull(static_arr, count_rows, count_cols) << "\n";
  }
  else if (!strcmp(argv[1], "2"))
  {
    const size_t matrix_order = inputMatrixOrder(argv[2]);
    size_t* spiral_matrix;
    try
    {
      spiral_matrix = new size_t[matrix_order * matrix_order];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Allocation failed: " << e.what() << '\n';
      return 1;
    }
    fillSpiralMatrix(spiral_matrix, matrix_order);
    printSpiralMatrix(spiral_matrix, matrix_order, argv[3]);
    delete[] spiral_matrix;
    size_t count_rows;
    size_t count_cols;
    int* matrix;
    inputMatrix(count_rows, count_cols, matrix, argv[2]);
    printCountOfSaddlePoints(getCountOfSaddlePoints(matrix, count_rows, count_cols), argv[3]);
    delete[] matrix;
  }
  else
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  return 0;
}
