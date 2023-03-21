#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>
#include "count_lines_with_unique_elements.h"
#include "minimum_sums_of_diagonals.h"
int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cout << "Check parameters";
    return 1;
  }
  size_t n = 0;
  size_t m = 0;
  std::ifstream in(argv[2]);
  in >> n >> m;
  if (!in)
  {
    std::cout << "Error";
    return 1;
  }
  if (!strcmp(argv[1], "1"))
  {
    int arr[1000];
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        in >> arr[n * i + j];
        if (!in)
        {
          std::cout << "Error";
          return 1;
        }
      }
    }
    std::ofstream out(argv[3]);
    out << count_lines_with_unique_elements(arr, n, m) << "\n";
    try
    {
      out << minimum_sums_of_diagonals(arr, n, m) << "\n";
    }
    catch (const std::runtime_error &e)
    {
      std::cout << e.what();
    }
  }
  else if (!strcmp(argv[1], "2"))
  {
    int *arr = new int[n * m];
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        in >> arr[i * n + j];
        if (!in)
        {
          std::cout << "Error";
          delete[] arr;
          return 1;
        }
      }
    }
    std::ofstream out(argv[3]);
    out << count_lines_with_unique_elements(arr, n, m) << "\n";
    try
    {
      out << minimum_sums_of_diagonals(arr, n, m) << "\n";
    }
    catch (const std::runtime_error &e)
    {
      std::cout << e.what();
    }
    delete[] arr;
  }
  else
  {
    std::cout << "No such parameter";
    return 1;
  }
  return 0;
}
