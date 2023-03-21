#include "transfervariables.h"

void transferVariables(int *arr, const size_t size, const size_t M, const size_t N)
{
  size_t newi = size - 1;
  if (size > N)
  {
    for (size_t i = N; i >= M ; i--)
    {
      int temp = arr[i];
      arr[i] = arr[newi];
      arr[newi] = temp;
      newi--;
    }
  }
}
