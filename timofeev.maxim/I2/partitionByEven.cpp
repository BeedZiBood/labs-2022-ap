#include "partitionByEven.h"
#include <algorithm>
#include <stdexcept>
int *partitionByEven(int *arr, size_t size)
{
  if (size == 0)
  {
    throw std::length_error("Size error");
  }
  int *l = arr;
  int *r = arr + size - 1;
  if (l == r)
  {
    return l;
  }
  else if (l < r)
  {
    do
    {
      while (*l % 2 == 0)
      {
        l++;
        if (l >= r)
        {
          return l;
        }
      }
      while (*r % 2 != 0)
      {
        r--;
        if (r <= l)
        {
          return r;
        }
      }
      if ((*l % 2 != 0) || (*r % 2 == 0))
      {
        std::swap(*l, *r);
        l++;
        r--;
      }
    }
    while (l < r);
  }
  return l;
}
