#include <iostream>
#include "outputanarray.h"
void outputAnArray(const int* array, size_t count_elements)
{
  for (size_t i = 0; i < count_elements; i++)
  {
    if (i == count_elements - 1)
    {
      std::cout << array[i];
    }
    else
    {
      std::cout << array[i] << " ";
    }
  }
}