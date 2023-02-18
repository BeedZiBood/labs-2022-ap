#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include "sumIndices.h"
#include "downSequence.h"
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Error" << "\n";
    return 1;
  }
  int arr_1[10] = {10, 8, 6, 4, 2, 8, 5, 7, 3, 1};
  std::cout << getSumOfIndices(arr_1, 10) << "\n";
  std::cout << getDownSequence(arr_1, 10) << "\n";
  size_t n = 0;
  std::cin >> n;
  int * arr_2 = new int[n];
  std::srand(time(nullptr));
  for (size_t i = 0; i < n; i++)
  {
    arr_2[i] = (std::rand() % 10) + 1;
  }
  std::cout << getSumOfIndices(arr_2, n) << "\n";
  std::cout << getDownSequence(arr_2, n) << "\n";
  delete[] arr_2;
  std::ifstream in(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file";
    return 1;
  }
  size_t size = 0;
  in >> size;
  if (in.fail())
  {
    std::cout << "Error.";
    return 1;
  }
  if (size == 0)
  {
    return 0;
  }
  int *arr_3 = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    in >> arr_3[i];
    if (!in)
    {
      std::cout << "Error..";
      delete[] arr_3;
      return 1;
    }
  }
  std::cout << getSumOfIndices(arr_3, size) << "\n";
  std::cout << getDownSequence(arr_3, size) << "\n";
  delete[] arr_3;
  return 0;
}
