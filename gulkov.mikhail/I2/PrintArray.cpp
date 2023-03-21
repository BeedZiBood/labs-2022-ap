#include "PrintArray.hpp"
#include <cstddef>
#include <ostream>

void print_array(const int *arr, size_t size, std::ostream& streamOut)
{
  for (size_t i = 0; i < size; i++)
  {
    if (i == size - 1)
    {
      streamOut << arr[i];
    }
    else
    {
      streamOut << arr[i] << " ";
    }
  }
}
