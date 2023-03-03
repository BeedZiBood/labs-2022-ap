#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include "duplicateRows.h"
#include "matrixWaveValue.h"
int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cout << "Invalid number of arguments." << '\n';
    return 1;
  }
  size_t rows = 0;
  size_t columns = 0;
  std::ifstream file(argv[2]);
  file >> rows >> columns;
  if (!file)
  {
    std::cout << "Error.";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int matrix[1000];
    for (size_t i = 0; i < rows * columns; i++)
    {
      file >> matrix[i];
      if (!file)
      {
        std::cout << "Error..";
        return 1;
      }
    }
    std::ofstream out(argv[3]);
    out << countDuplicateRows(matrix, rows, columns) << "\n";
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    if (rows != columns)
    {
      std::cerr << "Matrix must be square" << '\n';
      return 1;
    }
    int *matrix = new int[rows * columns];
    for (size_t i = 0; i < rows * columns; i++)
    {
      file >> matrix[i];
      if (!file)
      {
        std::cout << "Error...";
        delete[] matrix;
        return 1;
      }
    }
    size_t index_row = 2;
    size_t index_col = 3;
    std::ofstream out(argv[3]);
    int* dir = assignMatrixWaveValue(matrix, rows, columns, index_row, index_col);
    for (int *i = dir, counter = 1; counter <= static_cast< int >(columns*rows); ++i)
    {
      out << *i << " ";
      if (counter % columns == 0)
      {
        out << "\n";
      }
      counter++;
    }
    delete[] matrix;
  }
  else
  {
    std::cout << "No such parameter";
    return 1;
  }
  return 0;
}
