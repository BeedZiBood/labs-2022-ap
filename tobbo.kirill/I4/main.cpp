#include "arrays.h"
#include <cstring>

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of parameters\n";
    return 1;
  }
  std::ifstream in(argv[2]);
  if (!in)
  {
    std::cerr << "Error while rading from file\n";
    return 1;
  }

  size_t rows = 0;
  in >> rows;
  if (!in)
  {
    std::cerr << "Error while reading rows\n";
    return 1;
  }
  size_t cols = 0;
  in >> cols;
  if (!in)
  {
    std::cerr << "Error while reading columns\n";
    return 1;
  }
  if (rows * cols > 1000)
  {
    std::cerr << "Too many rows or columns. Max is 1000 elements\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cerr << "Cannot open output file\n";
    return 1;
  }
  std::cout << "Rows: " << rows << " Cols: " << cols << "============================\n";
  if (!strcmp(argv[1], "1"))
  {
    int arr[1000];
    try
    {
      fillArray(arr, rows, cols, &in);
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << "\n";
      return 1;
    }
    std::cout << "Task: 1-----------------------\n";
    printArray(std::cout, arr, rows, cols);
    size_t positiveRowsCount = getPositiveRowsCount(reinterpret_cast< int* >(&arr), rows, cols);
    output << "Found positive rows count: " << positiveRowsCount << "\n";
  }
  else if (!strcmp(argv[1], "2"))
  {
    if (rows != cols)
    {
      std::cerr << "Square matrix is supported only\n";
      return 1;
    }
    int* arr = new int[rows * cols];
    try
    {
      fillArray(arr, rows, cols, &in);
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << "\n";
      delete[] arr;
      return 1;
    }
    std::cout << "Task: 2-----------------------\n";
    printArray(output, arr, rows, cols);
    int maxSumDiag = getMaxSumDiag(arr, rows);
    output << "Max sum in diagonals except main one: " << maxSumDiag << "\n";
    delete[] arr;
  }
  else
  {
    std::cerr << "Unexpected task number. #3, #14 are supported\n";
    return 1;
  }

  return 0;
}
