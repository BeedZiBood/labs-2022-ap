#include <iostream>
#include <cstring>
#include "PositiveRows.h"
#include "ReadMatrix.h"
#include "MinDiagonalSum.h"

int main(int argc, char* argv[])
{
  // Checking command line input arguments
  if (argc != 4)
  {
    std::cerr << "Error! Invalid number of arguments";
    return 1;
  }
  const char* taskNumber = argv[1];
  if (std::strcmp(taskNumber, "1") && std::strcmp(taskNumber, "2"))
  {
    std::cerr << "Error! Invalid task number. The task number must be 1 or 2";
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  std::ofstream outputFile(argv[3]);
  if (!inputFile.is_open())
  {
    std::cerr << "Error! The input file cannot be opened";
    return 1;
  }
  else if (!outputFile.is_open())
  {
    std::cerr << "Error! The output file cannot be opened";
    return 1;
  }

  size_t rows = 1000;
  size_t columns = 1000;
  inputFile >> rows >> columns;
  if (rows == 0 || columns == 0)
  {
    return 0;
  }
  if (!inputFile)
  {
    std::cerr << "Error! An error occurred when reading the size of the matrix";
    return 1;
  }
  if (rows * columns > 1000)
  {
    std::cerr << "Error! The size of the matrix exceeds 1000 elements";
    return 1;
  }

  // Starting tasks
  if (!std::strcmp(taskNumber, "1"))
  {
    int matrix[1000];
    if (readMatrixFromFile(matrix, rows, columns, inputFile) == nullptr)
    {
      std::cerr << "Error! An error occurred when reading matrix elements" << "\n";
      return 1;
    }
    size_t result = getPosRowsCount(matrix, rows, columns);
    outputFile << result << "\n";
    std::cout << result;
    if (!outputFile)
    {
      std::cerr << "Error! An error occurred when writing the result to the output file";
      return 1;
    }
  }
  else
  {
    if (rows != columns)
    {
      std::cerr << "Error! The specified dimensions of the matrix do not correspond to the square matrix";
      return 1;
    }
    int* matrix = nullptr;
    matrix = new int[rows * columns];
    if (readMatrixFromFile(matrix, rows, columns, inputFile) == nullptr)
    {
      std::cerr << "Error! An error occurred when reading matrix elements" << "\n";
      delete[] matrix;
      return 1;
    }

    size_t result = minDiagonalSumParallelToSecondary(matrix, rows);
    outputFile << minDiagonalSumParallelToSecondary(matrix, rows) << "\n";
    std::cout << result;
    if (!outputFile)
    {
      std::cerr << "Error! An error occurred when writing the result to the output file";
      delete[] matrix;
      return 1;
    }
    delete[] matrix;
  }
  inputFile.close();
  outputFile.close();
  return 0;
}
