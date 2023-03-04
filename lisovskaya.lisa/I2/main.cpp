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
  if (argc > 2)
  {
    std::cerr << "Not correct amount of parametrs" << "\n";
    return 1;
  }
  std::srand(std::time(nullptr));
  int arr1[] = {2, 5, 3, 4, 6, 7, 1};
  std::cout << counterBeforeMin(arr1, 7) << std::endl;
  std::cout << findArithmeticMean(arr1, 7) << std::endl;
  size_t n = 0;
  std::cin >> n;
  if (!std::cin)
  {
    std::cout << "error input" << "\n";
    return 2;
  }
  int *array2 = new int[n];
  array2 = generateRand(array2, n);
  try
  {
    std::cout << counterBeforeMin(array2, n) << "\n";
    std::cout << findArithmeticMean(array2, n) << "\n";
  }
  catch (const std::runtime_error &e)
  {
    std::cout << 0 << "\n" << 0;
    delete[] array2;
    return 2;
  }
  delete[] array2;
  int size = 0;
  std::ifstream in(argv[1]);
  in >> size;
  if (!in)
  {
    std::cerr << "error reading file" << "\n";
    return 2;
  }
  if (size > 0)
  {
    int *array3 = new int[size];
    try
    {
      array3 = readArray(in, size, array3);
      std::cout << counterBeforeMin(array3, size) << "\n";
      std::cout << findArithmeticMean(array3, size) << "\n";
    }
    catch (const std::runtime_error &e)
    {
      std::cout << e.what();
      delete[] array3;
      return 2;
    }
    catch (const std::length_error &e)
    {
      std::cout << e.what();
      delete[] array3;
      return 2;
    }
  }
  else
  {
    return 0;
  }
  delete[] array2;
  return 0;
}
