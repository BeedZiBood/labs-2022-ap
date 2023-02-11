#include "sort.hpp"
#include <iostream>
#include <cstddef>
int sort(int arr[], size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
       std::swap(arr[j], arr[j + 1]);
      }
    }
  }
  std::cout << "Sort array: ";
  for (size_t i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  delete[] arr;
  return 0;
}
