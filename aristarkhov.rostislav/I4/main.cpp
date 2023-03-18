#include <iostream>
#include <cstring>
#include <fstream>
#include <cstddef>
#include <readMatrix.h>
#include "countGrowingElements.h"
#include "SumUnderMainDiagonal.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error!\n";
    return 1;
  }
  std::ifstream fileInput(argv[2]);
  if (!fileInput.is_open())
  {
    std::cerr << "Error while open file to read\n";
    return 1;
  }

  std::ofstream fileOutput(argv[3]);
  if (!fileOutput.is_open())
  {
    std::cerr << "Error while opening file\n";
    return 1;
  }

  size_t line = 0;
  size_t column = 0;
  const size_t max_size = 1000;

  if (!std::strcmp(argv[1], "1"))
  {
    int matrix[max_size];

    fileInput >> line >> column;
    if (!fileInput)
    {
      std::cerr << "Problems while reading file\n";
      return 1;
    }
    size_t size_1 = line * column;
    if (size_1 > max_size)
    {
      std::cerr << "Too many value\n";
      return 1;
    }
    try
    {
      readMatrix(matrix, size_1, fileInput);
    }
    catch (const std::length_error& e)
    {
      std::cout << e.what() << "\n";
      return 1;
    }

    fileOutput << countGrowingElements(matrix, line, column) << '\n';
  }

  else if (!std::strcmp(argv[1], "2"))
  {
    fileInput >> line >> column;
    if (line != column)
    {
      std::cerr << "Matrix must be square\n";
      return 1;
    }
    if (!fileInput)
    {
      std::cerr << "Problems while reading file\n";
      return 1;
    }
    size_t size_2 = line * column;
    int* matrix = new int[size_2];
    try
    {
      readMatrix(matrix, size_2, fileInput);
    }
    catch (const std::length_error& e)
    {
      std::cout << e.what() << "\n";
      delete[] matrix;
      return 1;
    }
    fileOutput << sumUnderMainDiagonal(matrix, line, column) << '\n';
    delete[] matrix;
  }
  return 0;
}
