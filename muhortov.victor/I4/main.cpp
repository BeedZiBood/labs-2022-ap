#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>
#include "CountMoreThanThree.hpp"
#include "SmoothingMatrix.hpp"
#include "SumUnderMainDiagonal.hpp"

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: 4 arguments nof found\n";
    return 1;
  }
  size_t cols = 0;
  size_t rows = 0;
  std::ifstream in(argv[2]);
  in >> cols;
  in >> rows;

  if (!in)
  {
    std::cerr << "Error: problems with reading file\n";
    return 1;
  }

  // tasks 16 and 17

  if (!std::strcmp(argv[1], "1"))
  {
    int arr[1000];
    if (cols * rows > 1000)
    {
      std::cout << "Error: too big matrix\n";
      return 1;
    }
    for (size_t i = 0; i < cols; i++)
    {
      for (size_t j = 0; j < rows; j++)
      {
        in >> arr[cols * i + j];
        if (!in)
        {
          std::cerr << "Error: problems with reading file\n";
          return 1;
        }
      }
    }
    std::ofstream out(argv[3]);
    out << findCountMoreThanThree(arr, cols, rows) << '\n';
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    int *arr = nullptr;
    if (cols == 0 && rows == 0)
    {
      std::cout << "Empty dynamic array\n";
      return 0;
    }

    try
    {
      arr = new int[cols * rows];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Error: " << e.what();
      return 1;
    }

    for (size_t i = 0; i < cols; i++)
    {
      for (size_t j = 0; j < rows; j++)
      {
        in >> arr[cols * i + j];
        if (!in)
        {
          std::cerr << "Error: problems with reading file\n";
          delete[] arr;
          return 1;
        }
      }
    }

    double *smooth_arr = nullptr;

    try
    {
      smooth_arr = new double[cols * rows];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Error: " << e.what();
      delete[] arr;
      return 1;
    }

    smoothingMatrix(arr, cols, rows, smooth_arr);

    std::ofstream out(argv[3]);
    out << sumUnderMainDiagonal(smooth_arr, cols, rows);

    delete[] arr;
    delete[] smooth_arr;
  }
  else
  {
    std::cerr << "Error: no such parameter\n";
    return 1;
  }

  return 0;
}
