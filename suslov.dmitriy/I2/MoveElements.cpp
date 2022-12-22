#include "MoveElements.h"
#include <algorithm>
void move_elements(int *arr, size_t size, size_t m, size_t n)
{
  if (size == 0)
  {
    return;
  }
  for (size_t i = m; i <= n; i++)
  {
    std::swap(arr[i], arr[size - (n - i + 1)]);
  }
}
