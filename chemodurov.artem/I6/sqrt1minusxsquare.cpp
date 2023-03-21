#include "sqrt1minusxsquare.h"
#include <stdexcept>
#include "nextsqrt1minusxsquare.h"

double chemodurov::sqrt1MinusXSquare(double x, size_t max_members, double error)
{
  double res = 0.0;
  size_t members = 0;
  double current = 0.0;
  Sqrt1MinusXSquare sqrt1(x);
  do
  {
    if (members == max_members && current > error)
    {
      throw std::runtime_error("Accuracy was not achieved");
    }
    current = sqrt1();
    res += current;
  }
  while (current > error);
  return res;
}
