#include "calculateArithmeticMean.h"
#include <stdexcept>
double calculateArithmeticMean(const int *arr, size_t size)
{
  int c = 0;
  if (size == 0)
  {
    throw std::runtime_error("Zero size");
  }
  double sum = 0;
  for (size_t i = 0; i < size; i += 2)
  {
    sum += arr[i];
    c++;
  }
  return sum / c;
}
