#include "arccos.h"
#include <cmath>
#include "factorial.h"

double arcCos(double x, double absError, unsigned max_member)
{
  const double pi = 3.14;
  double sum = pi / 2;
  double next = x;
  unsigned members = 1;
  double numerator = 0.0;
  double denominator = 0.0;

  do
  {
    sum -= next;
    numerator = factorial(2 * members) * std::pow(next, 2 * members + 1);
    denominator = std::pow(4, members) * std::pow(factorial(members), 2) * (2 * members + 1);
    next = numerator / denominator;
    members++;
  }
  while (std::fabs(next) > absError && members >= max_member);

  return sum;
}
