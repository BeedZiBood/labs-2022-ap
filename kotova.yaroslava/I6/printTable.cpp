#include "printTable.hpp"
#include <iomanip>
#include <cmath>
#include "calculateExp.hpp"
void printRow(std::ostream& out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << " "<< std::setprecision(5);
  out << std::setw(10) << exp(x, absError, numberMax) << " ";
  out << std::setw(10) << std::exp(x * (-1)) << "\n";
}
void printTable(std::ostream& out, double left, double right, double step, double absError, unsigned numberMax)
{
  for (double x = left; x + step <= right; x += step)
  {
    printRow(out, x, absError, numberMax);
  }
  printRow(out, right, absError, numberMax);
}
