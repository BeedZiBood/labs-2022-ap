#include "Partition.hpp"

int *partition(int* arr, size_t size)
{
  int *lastpos = arr + size - 1;
  while (arr < lastpos)
  {
    if (*arr % 2 != 0)
    {
      for (int *i = lastpos; i > arr; i--)
      {
        if (*i % 2 == 0)
        {
          std::swap(*i, *arr);
          break;
        }
      }
    }
    arr++;
  }
  return arr;
}
