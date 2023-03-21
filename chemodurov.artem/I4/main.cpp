#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include "arrays.h"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect amount of command line args\n";
    return 2;
  }
  if (std::strcmp(argv[1], "1") && std::strcmp(argv[1], "2"))
  {
    std::cerr << "Incorrect variant of task\n";
    return 2;
  }

  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Error while open file to read\n";
    return 1;
  }
  size_t rows = 0;
  input >> rows;
  if (!input)
  {
    std::cerr << "Error while reading rows\n";
    return 1;
  }
  size_t cols = 0;
  input >> cols;
  if (!input)
  {
    std::cerr << "Error while reading columns\n";
    return 1;
  }
  size_t size = rows * cols;
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Error while open file to write\n";
    return 1;
  }

  if (!std::strcmp(argv[1], "1"))
  {
    constexpr size_t max_size = 1000;
    if (size > max_size)
    {
      std::cerr << "Too much elements\n";
      return 1;
    }
    int arr[max_size];
    for (size_t i = 0; i < size; ++i)
    {
      input >> arr[i];
      if (!input)
      {
        std::cerr << "Error while reading elements\n";
        return 1;
      }
    }
    size_t number_growing = chemodurov::countGrowingRows(arr, rows, cols);
    output << number_growing << "\n";
    if (!output)
    {
      std::cerr << "Error while writing number of growing rows\n";
      return 1;
    }
  }
  else
  {
    if ((rows * cols) == 0)
    {
      output << "0\n";
      if (!output)
      {
        std::cerr << "Error while writing summ\n";
        return 1;
      }
      return 0;
    }
    int * arr = new int[rows * cols];
    for (size_t i = 0; i < size; ++i)
    {
      input >> arr[i];
      if (!input)
      {
        std::cerr << "Error while reading elements\n";
        delete [] arr;
        return 1;
      }
    }
    size_t rows_square = std::min(rows, cols);
    int * square = nullptr;
    if (cols == rows)
    {
      square = arr;
      arr = nullptr;
    }
    else
    {
      try
      {
        square = new int[rows_square * rows_square];
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << e.what() << "\n";
        delete [] arr;
        return 1;
      }
    }
    if (cols < rows)
    {
      for (size_t i = 0; i < (rows_square * rows_square); ++i)
      {
        square[i] = arr[i];
      }
    }
    else if (cols > rows)
    {
      for (size_t i = 0; i < rows_square; ++i)
      {
        for (size_t j = 0; j < rows_square; ++j)
        {
          square[(i * rows_square) + j] = arr[(i * cols) + j];
        }
      }
    }
    long long summ = 0;
    try
    {
      summ = chemodurov::calcMinSummSecondaryDiagonal(square, rows_square, rows_square);
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what() << "\n";
      delete [] arr;
      delete [] square;
      return 1;
    }
    output << summ << "\n";
    if (!output)
    {
      std::cerr << "Error while writing summ\n";
      delete [] arr;
      delete [] square;
      return 1;
    }
    delete [] arr;
    delete [] square;
  }
  return 0;
}
