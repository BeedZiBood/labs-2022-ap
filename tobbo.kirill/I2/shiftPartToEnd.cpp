#include "shiftPartToEnd.h"
#include <stdexcept>

void shiftPartToEnd(int* arr, size_t size, size_t start_index, size_t end_index)
{
  if (start_index > end_index || end_index > (size - 1))
  {
    throw std::invalid_argument("Wrong input indexes");
  }
  size_t shift_size = end_index - start_index;
  for (size_t i = 0; i < shift_size; i++)
  {
    int tmp = arr[size - i - 1];
    arr[size - i - 1] = arr[end_index - i - 1];
    arr[end_index - i - 1] = tmp;
  }
}
