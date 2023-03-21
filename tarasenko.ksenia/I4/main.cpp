#include <iostream>
#include <fstream>
#include <cstring>
#include "countrowswithnullelem.hpp"
#include "makeincreasingwavearoundelem.hpp"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect amount of data entered\n";
    return 1;
  }
  size_t m, n = 0;
  std::ifstream in(argv[2]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file\n";
    return 1;
  }
  in >> m >> n;
  if (!in)
  {
    std::cout << "Error while reading file\n";
    return 1;
  }
  std::ofstream out(argv[3]);
  if (!std::strcmp(argv[1], "1"))
  {
    if (m * n > 0)
    {
      if (m * n > 1000)
      {
        std::cout << "Incorrect data entered\n";
        return 1;
      }
      int arr[1000] = {};
      for (size_t i = 0; i < m * n; i++)
      {
        in >> arr[i];
        if (!in)
        {
          std::cout << "Error while reading file\n";
          return 1;
        }
      }
      out << countRowsWithNullElem(arr, m, n) << "\n";
      if (!out)
      {
        std::cout << "Error while writing\n";
        return 1;
      }
    }
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    if (m * n > 0)
    {
      int * arr = new int[m * n];
      for (size_t i = 0; i < m * n; i++)
      {
        in >> arr[i];
        if (!in)
        {
          std::cout << "Error while reading file\n";
          delete [] arr;
          return 1;
        }
      }
      size_t row_number_elem = 3;
      size_t col_number_elem = 2;
      try
      {
        arr = makeIncreasingWaveAroundElem(arr, m, n, row_number_elem, col_number_elem);
      }
      catch (const std::invalid_argument & e)
      {
        std::cout << e.what() << "\n";
        delete [] arr;
        return 1;
      }
      for (size_t i = 0; i < m; i++)
      {
        for (size_t j = 0; j < n; j++)
        {
          out << arr[i * n + j];
        }
        if (!out)
        {
          std::cout << "Error while writing\n";
          delete [] arr;
          return 1;
        }
        out << "\n";
      }
      delete [] arr;
    }
  }
  else
  {
    std::cout << "There is no such task option\n";
    return 1;
  }
}
