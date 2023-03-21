#include "movearrayleft.h"

void moveArrayLeft(int *arr, const size_t size, const int shift)
{
  int howmuchshiftnow = 0;
  while (howmuchshiftnow++ < shift)
  {
    int firstposition = arr[0];
    int secondposition = arr[1];
    for (size_t i = 0; i < size - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    arr[size - 1] = firstposition;
    arr[size] = secondposition;
  }
}
