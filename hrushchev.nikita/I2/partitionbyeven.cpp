#include "partitionbyeven.hpp"
#include <utility>

int* partitionByEven(int* arr, const size_t size)
{
  int* left = arr;
  int* right = arr + size - 1;

  while (left < right)
  {
    while (*left % 2 == 0)
    {
      left++;
      if (left == arr + size - 1)
      {
        return left;
      }
    }
    while (*right % 2 != 0)
    {
      right--;
      if (right == arr)
      {
        return right;
      }
    }
    if ((*right % 2 == 0) || (*left % 2 != 0))
    {
      std::swap(arr[left - arr], arr[right - arr]);
      left++;
      right--;
    }
    else
    {
      break;
    }
  }
  return left;
}
