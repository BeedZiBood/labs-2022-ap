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
    size_t *matrix = new size_t[rows * columns];
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
    size_t index_row = 5;
    size_t index_col = 3;
    std::ofstream out(argv[3]);
    try
    {
      size_t* dir = assignMatrixWaveValue(matrix, rows, columns, index_row, index_col);
      for (size_t *i = dir, counter = 1; counter <= (columns*rows); ++i)
      {
        out << *i << " ";
        if (counter % columns == 0)
        {
          out << "\n";
        }
        counter++;
      }
    }
    catch (const std::invalid_argument &e)
    {
      delete[] matrix;
      std::cout << "Error:\n";
      std::cout << e.what();
      return 0;
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
