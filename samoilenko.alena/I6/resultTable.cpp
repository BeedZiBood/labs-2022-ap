#include "resultTable.h"
#include <iomanip>
#include <cmath>
#include "calculateTheExponent.h"

void printTableRow(std::ostream& out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << calculateTheExponent(absError, x, numberMax) << ' ';
  out << std::setw(10) << std::exp(x * x * (-1)) << '\n';
}

