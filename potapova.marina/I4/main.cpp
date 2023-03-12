#include <cstring>
#include <iostream>
#include <fstream>
#include "countColsWithNull.h"
#include "countRowsWithoutNull.h"
#include "inputOutputStaticMatrix.h"
#include "fillSpiralMatrix.h"
#include "workWithIO.h"
#include "getCountOfSaddlePoints.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect count of main arguments\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << argv[2] << " cannot be open\n";
    return 1;
  }
  size_t count_rows = 0;
  size_t count_cols = 0;
  if (!(input >> count_rows >> count_cols))
  {
    std::cerr << "Input error\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << argv[3] << " cannot be open\n";
    return 1;
  }
  if (std::strcmp(argv[1], "1") == 0)
  {
    long long matrix[1000];
    inputMatrix(matrix, count_rows, count_cols, input);
    output << countRowsWithoutNull(matrix, count_rows, count_cols) << ' '
           << countColsWithNull(matrix, count_rows, count_cols) << '\n';
  }
  else if (strcmp(argv[1], "2") == 0)
  {
    long long** matrix = new long long*[count_rows];
    for (long long** cur_row_ptr = matrix; cur_row_ptr < matrix + count_rows; ++cur_row_ptr)
    {
      *cur_row_ptr = new long long[count_cols];
    }
    inputMatrix(matrix, count_rows, count_cols, input);
    output << getCountOfSaddlePoints(matrix, count_rows, count_cols);
    delete[] matrix;
    size_t& matrix_order = count_rows;
    long long** spiral_matrix;
    try
    {
      spiral_matrix = new long long*[matrix_order];
      for (long long** cur_row_ptr = spiral_matrix; cur_row_ptr < spiral_matrix + matrix_order; ++cur_row_ptr)
      {
        *cur_row_ptr = new long long[matrix_order];
      }
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Allocation failed: " << e.what() << '\n';
      return 1;
    }
    fillSpiralMatrix(spiral_matrix, matrix_order);
    printSpiralMatrix(spiral_matrix, matrix_order, output);
    delete[] spiral_matrix;
  }
  else
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  return 0;
}
