#include "sinx.h"
#include <cmath>

double sinx(double x, double error, unsigned max_members)
{
  double summ = 0.0;
  double next = x;
  unsigned members = 1;
  long int factorial = 0;
  const double numerator = -1.0 * x * x;

  do
  {
    summ += next;
    factorial = (2 * members * (1 + 2 * members));
    next = next * numerator / factorial;
    members++;
  }
  while (std::fabs(next) > error || members != max_members);

  return summ;
}
