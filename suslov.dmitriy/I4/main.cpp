#include <iostream>
#include <fstream>
#include <cstring>
#include "scanMatrix.h"
#include "scanLocalMinima.h"
#include "calculateSumOfModules.h"
int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "nooooooooooo" << "\n";
    return 1;
  }
  std::ofstream out_stream(argv[3]);
  if (!out_stream.is_open())
  {
    std::cerr << "=(" << "\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int matrix[1000];
    size_t n = 0;
    size_t m = 0;
    std::ifstream in_stream(argv[2]);
    if (!in_stream.is_open())
    {
      std::cerr << "errrr" << "\n";
      return 1;
    }
    try
    {
      scanSize(in_stream, n, m);
    }
    catch (...)
    {
      std::cerr << "Error" << "\n";
      return 2;
    }
    if (n * m > 1000)
    {
      std::cerr << "beda" << "\n";
      return 2;
    }
    try
    {
      scanMatrix(matrix, in_stream, n, m);
      out_stream << countRowsWithZeros(n, m, matrix) << "\n";
      return 0;
    }
    catch (...)
    {
      std::cerr << "error" << "\n";
      return 2;
    }
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    size_t n = 0;
    size_t m = 0;
    std::ifstream in_stream(argv[2]);
    if (!in_stream.is_open())
    {
      std::cerr << "=()" << "\n";
      return 1;
    }
    try
    {
      scanSize(in_stream, n, m);
    }
    catch (...)
    {
      std::cerr << "Error" << "\n";
      return 2;
    }
    int *matrix = nullptr;
    try
    {
      matrix = new int[n * m];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "brr...memory" << "\n";
      return 1;
    }
    try
    {
      scanMatrix(matrix, in_stream, n, m);
      int *s_matrix = countSmoothedMatrix(matrix, n, m);
      if (s_matrix != nullptr)
      {
        out_stream << countSum(s_matrix, n);
        delete[] s_matrix;
      }
      delete[] matrix;
      return 0;
    }
    catch (...)
    {
      std::cerr << "=()" << "\n";
      delete[] matrix;
      return 2;
    }
  }
  std::cerr << "<3" << "\n";
  return 2;
}
