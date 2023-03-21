#include "count_lines_with_unique_elements.h"
size_t count_contains_element(const int element, const int *arr, const size_t size)
{
  size_t count = 0;
  for (size_t i = 0; i < size && count < 2; i++)
  {
    if (element == arr[i])
    {
      count++;
    }
  }
  return count;
}
bool is_unique_line(const int *arr, const size_t size)
{
  bool fl = true;
  for (size_t j = 0; j < size && fl; j++)
  {
    if (count_contains_element(arr[j], arr, size) != 1)
    {
      fl = false;
    }
  }
  return fl;
}
size_t count_lines_with_unique_elements(const int *arr, const size_t n, const size_t m)
{
  size_t count = 0;
  for (size_t i = 0; i < n; i++)
  {
    if (is_unique_line(arr + i * n, m))
    {
      count++;
    }
  }
  return count;
}
