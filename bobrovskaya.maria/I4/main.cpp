#include <iostream>
#include <cstring>
#include <fstream>
#include <readMatrix.h>
#include "countColumnsWithUniqueElements.h"
#include "numberRowsNoConcecutiveIndeticalElements.h"

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "The arguments are not correct!\n";
    return 1;
  }
  size_t rows = 0;
  size_t column = 0;
  std::ifstream inputFile(argv[2]);
  if (!inputFile)
  {
    std::cerr << "Error file\n";
    return 1;
  }
  inputFile >> rows >> column;
  size_t size = rows * column;
  if (!inputFile)
  {
    std::cerr << "Incorrect arguments of the matrix\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int matrix[1000];
    if (readMatrixFromFile(matrix, size, inputFile) == nullptr)
    {
      std::cerr << "Error file/n";
      return 1;
    }
    std::ofstream outputFile(argv[3]);
    outputFile << countColumnsWithUniqueElements(matrix, rows, column) << "\n";
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    if (rows != column)
    {
      std::cerr << "Matrix must be square\n";
      return 1;
    }
    int *matrix = new int[rows * column];
    if (readMatrixFromFile(matrix, size, inputFile) == nullptr)
    {
      std::cerr << "Error writing elements\n";
      delete[] matrix;
      return 1;
    }
    std::ofstream outputFile(argv[3]);
    outputFile << countRowsWithoutRepeating(matrix, rows, column) << "\n";
    delete[] matrix;
  }
  else
  {
    std::cerr << "First argument must be 1 or 2\n";
    return 1;
  }
  return 0;
}
