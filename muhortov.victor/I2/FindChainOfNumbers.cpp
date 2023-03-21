#include "FindChainOfNumbers.hpp"

int findChain(const int* arr, size_t size)
{
  size_t count = 0;
  for (size_t i = 0; i < size - 1; i++)
  {
    if (arr[i] + 1 == arr[i + 1])
    {
      count++;
    }
  }
  return count;
}
