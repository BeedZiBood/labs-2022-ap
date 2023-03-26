#include "findArithmeticMean.h"
#include <stdexcept>
double findArithmeticMean(const int *ar, size_t m)
{
  if (m == 0)
  {
    throw std::runtime_error("meh");
  }
  int sum = 0;
  size_t n = 0;
  for (size_t i = 0; i < m; i += 2)
  {
    sum += ar[i];
    n++;
  }
  return static_cast< double >(sum) / static_cast< double >(n);
}
