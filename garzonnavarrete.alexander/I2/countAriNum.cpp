#include "countAriNum.h"
#include <stdexcept>
#include <cstddef>

double countAriNum(const int *input_array, size_t array_size)
{
  if (array_size == 0)
  {
    throw std::runtime_error("Zero size");
  }
  double sum = 0;
  for (size_t i = 0; i < array_size; i += 2)
  {
    sum += input_array[i];
  }
  return sum / ((array_size + 1) / 2);
}
