#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include <readingFile.h>
#include "CollsWithZero.h"
#include "calculateModulsSum.h"
int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cout << "Invalid arguments" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cout << "Input error" << "\n";
    return 1;
  }
  size_t r = 0;
  size_t c = 0;
  size_t dynMatrixSize = 0;
  input >> r >> c;
  dynMatrixSize = r * c;
  if (!input)
  {
    std::cout << "Input error" << "\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cout << "Output file is not opened" << "\n";
    return 1;
  }
  if (std::strcmp(argv[1], "1") == 0)
  {
    int arr[1000];
    if (dynMatrixSize > 1000)
    {
      std::cout << "> 1000" << "\n";
      return 1;
    }
    for (size_t i = 0; i < dynMatrixSize; i++)
    {
      input >> arr[i];
      if (!input)
      {
        std::cout << "Input error" << "\n";
        return 1;
      }
    }
    output << countColsWithZero(arr, r, c);
  }
  else if (std::strcmp(argv[1], "2") == 0)
  {
    int *matrix = new int [dynMatrixSize];
    try
    {
      matrix = readFile(input, dynMatrixSize, matrix);
    }
    catch (const std::length_error &e)
    {
      std::cout << e.what() << "\n";
      delete[] matrix;
      return 1;
    }
    int *smoothed_matrix = countSmoothedMatrix(matrix, r, c);
    if (smoothed_matrix != nullptr)
    {
      output << countSum(smoothed_matrix, r);
      delete[] smoothed_matrix;
    }
    delete[] matrix;
  }
  else
  {
    std::cout << "Error" << "\n";
    return 1;
  }
  return 0;
}
