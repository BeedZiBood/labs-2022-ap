#include <iostream>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include "getSumofMinandMaxElements.h"
#include "countAscendingPairs.h"
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Incorrect number of parameters";
    return 1;
  }
  int arr1[] = {2, 4, 6, 8, 10, 12, 14};
  try
  {
    std::cout << getSumofMinandMaxElements(arr1, 7) << "\n";
    std::cout << countAscendingPairs(arr1, 7) << "\n";
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  size_t n = 0;
  std::cin >> n;
  int *arr2 = new int[n];
  std::srand(time(nullptr));
  for (size_t i = 0; i < n; i++)
  {
    arr2[i] = std::rand();
  }
  try
  {
    std::cout << getSumofMinandMaxElements(arr2, n) << "\n";
    std::cout << countAscendingPairs(arr2, n) << "\n";
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    delete[] arr2;
    return 2;
  }
  delete[] arr2;
  std::ifstream in(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file\n";
    return 1;
  }
  size_t size = 0;
  in >> size;
  if (!in)
  {
    std::cout << "Error reading file\n";
    return 1;
  }
  int *arr = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    in >> arr[i];
    if (!in)
    {
      std::cout << "Error reading file\n";
      delete[] arr;
      return 1;
    }
  }
  try
  {
    std::cout << getSumofMinandMaxElements(arr, size) << "\n";
    std::cout << countAscendingPairs(arr, size) << "\n";
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    delete[] arr;
    return 2;
  }
  delete[] arr;
  return 0;
}
