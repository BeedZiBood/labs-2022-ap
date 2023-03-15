#include "printTable.hpp"
#include <iomanip>
#include <cmath>
#include "sinOverX.hpp"

void printTableRow(std::ostream& out, double x, double absError, unsigned numberMax)
{
  double result1 = zasulsky::sinOverX(x, absError, numberMax);
  double result2 = std::sin(x) / x;
  out << std::setw(5) << std::fixed << std::setprecision(2) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << result1 << ' ';
  out << std::setw(10) << result2;
}

void zasulsky::printTable(std::ostream& out, double l, double r, double step, double absError, unsigned numberMax)
{
  for (double i = l; i < r - step; i += step)
  {
    printTableRow(out, i, absError, numberMax);
    out << "\n";
  }
  printTableRow(out, r, absError, numberMax);
}
