#include "countrowswithdifferentelements.h"

size_t countRowsWithDifferentElements(const int* arr, const size_t m, const size_t n)
{
  size_t count = 0;
  size_t elementscounter = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n - 1; j++)
    {
      for (size_t h = 1; h < n; h++)
      {
        if (arr[i * m + j] == arr[i * m + h])
        {
          elementscounter++;
        }
      }
      if (elementscounter == 0)
      {
        count++;
      }
      elementscounter = 0;
    }
  }
  return count;
}
