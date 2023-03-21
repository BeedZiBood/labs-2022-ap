#include "print_result.h"

void printResult(std::ostream& out, double x, unsigned members, double error)
{
  std::setprecision(5);
  out << std::fixed << std::setw(5) << x << ' ';
  out << std::setw(10) << sqrtOneMinusXToPowerOfMinusZeroPointFive(x, members, error) << ' ';
  out << std::setw(10) << 1 / std::sqrt(1 - x * x) << '\n';
}
