#include "getcountmaxelement.hpp"

size_t getCountMaxElement(const int* arr, const size_t size)
{
  if (arr == nullptr || size == 0)
  {
    return 0;
  }

  int max_element = arr[0];
  size_t count_max_element = 1;
  for (size_t i = 1; i < size; i++)
  {
    if (arr[i] > max_element)
    {
      max_element = arr[i];
      count_max_element = 1;
    }

    if (arr[i] == max_element)
    {
      count_max_element++;
    }
  }
  return count_max_element;
}
