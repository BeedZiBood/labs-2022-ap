#include <cstring>
#include <iostream>
#include <fstream>
#include "countColsWithNull.h"
#include "countRowsWithoutNull.h"
#include "getCountOfSaddlePoints.h"
#include "fillSpiralMatrix.h"
#include "workWithIO.h"
#include "allocationAndDeleteMatrix.h"

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
    if(!inputMatrix(matrix, count_rows * count_cols, input))
    {
      std::cerr << "Input error\n";
      return 1;
    }
    output << countRowsWithoutNull(matrix, count_rows, count_cols) << ' ';
    output << countColsWithNull(matrix, count_rows, count_cols) << '\n';
  }
  else if (strcmp(argv[1], "2") == 0)
  {
    long long** matrix;
    if ((matrix = createMatrix(count_rows, count_cols)) == nullptr)
    {
      std::cerr << "Allocation of matrix failed\n";
      return 1;
    }
    if (!inputMatrix(matrix, count_rows, count_cols, input))
    {
      std::cerr << "Input error\n";
      deleteMatrix(matrix, count_rows);
      return 1;
    }
    output << getCountOfSaddlePoints(matrix, count_rows, count_cols) << '\n';
    deleteMatrix(matrix, count_rows);
    size_t& matrix_order = count_rows;
    long long** spiral_matrix;
    if ((spiral_matrix = createMatrix(matrix_order, matrix_order)) == nullptr)
    {
      std::cerr << "Allocation of matrix failed\n";
      return 1;
    }
    fillSpiralMatrix(spiral_matrix, matrix_order);
    printMatrix(spiral_matrix, matrix_order, output);
    deleteMatrix(spiral_matrix, count_rows);
  }
  else
  {
    std::cerr << "Incorrect exercise number\n";
    return 1;
  }
  return 0;
}
