#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include "count_column_which_duplicate_elements.h"
#include "check_lower_triangular_matrix.h"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "The arguments are not correct!\n";
    return 1;
  }
  std::ifstream inputfile(argv[2]);
  if (!inputfile)
  {
    std::cerr << "Error file\n";
    return 1;
  }
  size_t row = 0;
  inputfile >> row;
  if (!inputfile)
  {
    std::cerr << "Incorrect arguments of the matrix\n";
    return 1;
  }
  size_t column = 0 ;
  inputfile >> column;
  if (!inputfile)
  {
    std::cerr << "Incorrect arguments of the matrix\n";
    return 1;
  }
  size_t size = row * column;
  std::ofstream outputfile(argv[3]);
  if (!outputfile)
  {
    std::cerr << "Error file\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    if (size > 1000)
    {
      std::cerr << "Too much elements\n";
      return 1;
    }
    int arr[1000];
    for (size_t i = 0; i < row; i++)
    {
      for (size_t j = 0; j < column; j++)
      {
        inputfile >> arr[column * i + j];
        if (!inputfile)
        {
          std::cerr << "Error reading elements\n";
          return 1;
        }
      }
    }
    outputfile << countColumnWhichDuplicateElements(arr, row, column) << "\n";
    if (!outputfile)
    {
      std::cerr << "Error writing elements\n";
      return 1;
    }
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    if (row != column)
    {
      std::cerr << "This matrix not square\n";
      return 1;
    }
    const size_t size_sqrt_matrix = row;
    int * dArr = new int[size];
    for (size_t i = 0; i < row; i++)
    {
      for (size_t j = 0; j < column; j++)
      {
        inputfile >> dArr[column * i + j];
        if (!inputfile)
        {
          std::cerr << "Error reading elements\n";
          delete [] dArr;
          return 1;
        }
      }
    }
    outputfile << checkLowerTriangularMatrix(dArr, size_sqrt_matrix);
    if (!outputfile)
    {
      std::cerr << "Error writing elements\n";
      delete [] dArr;
      return 1;
    }
    delete [] dArr;
  }
  else
  {
    std::cerr << "First argument must be 1 or 2\n";
    return 1;
  }
  return 0;
}
