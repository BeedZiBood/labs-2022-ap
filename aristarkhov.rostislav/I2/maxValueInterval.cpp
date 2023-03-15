#include "maxValueInterval.h"

int maxValueInterval(const int* arr, size_t size, int start_interval, int end_interval)
{
  int max_interval = start_interval - 1;
  if (size != 0)
  {
    for (size_t i = 0; i < size; i++)
    {
      if ((arr[i] > max_interval) && (start_interval <= arr[i]) && (arr[i] <= end_interval))
      {
        max_interval = arr[i];
      }
    }
  }
  return max_interval;
}
