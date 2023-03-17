#include <cstddef>
#include <iostream>
#include <fstream>
#include <ctime>
#include "counterBeforeMin.h"
#include "findArithmeticMean.h"
#include "generateRand.h"
#include "readArray.h"

int main(int argc, char *argv[])
{
  std::srand(std::time(nullptr));
  int arr1[] = {2, 5, 3, 4, 6, 7, 1};
  std::cout << counterBeforeMin(arr1, 7) << "\n";
  std::cout << findArithmeticMean(arr1, 7) << "\n";
  size_t n = 0;
  std::cin >> n;
  if (!std::cin)
  {
    std::cout << "error input" << "\n";
    return 2;
  }
  int *array2 = new int[n];
  if (n > 0)
  {
    array2 = generateRand(array2, n);
    try
    {
      std::cout << counterBeforeMin(array2, n) << "\n";
      std::cout << findArithmeticMean(array2, n) << "\n";
      delete[] array2;
    }
    catch (const std::runtime_error &e)
    {
      std::cout << 0 << "\n" << 0;
      delete[] array2;
      return 2;
    }
  }
  else
  {
    std::cout << "Dynamic array error" << "\n";
    delete[] array2;
  }
  if (argc != 2)
  {
    std::cerr << "Not correct amount of parametrs" << "\n";
    return 1;
  }
  size_t line = 0;
  std::ifstream in(argv[1]);
  in >> line;
  if (!in)
  {
    std::cerr << "error reading file" << "\n";
    return 1;
  }
  if (line > 0)
  {
    int *array3 = new int[line];
    if (readArray(in, line, array3))
    {
      try
      {
        std::cout << counterBeforeMin(array3, line) << "\n";
        std::cout << findArithmeticMean(array3, line) << "\n";
        delete[] array3;
      }
      catch (const std::length_error &e)
      {
        std::cout << e.what();
        delete[] array3;
        return 2;
      }
    }
  }
  else
  {
    return 0;
  }
  delete[] array2;
  return 0;
}
