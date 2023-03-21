#include "printtable.h"
#include <iomanip>
#include <cmath>
#include "sqrt1minusxsquare.h"

void printRowInTable(std::ostream & out, double x, size_t max_members, double error)
{
  out << std::fixed << std::setw(10) << std::setprecision(4) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << chemodurov::sqrt1MinusXSquare(x, max_members, error) << ' ';
  out << std::setw(10) << std::setprecision(5) << 1 / (std::sqrt(1 - x * x));
}

void chemodurov::printTable(std::ostream & out, double left, double right, double step, size_t max_mem, double err)
{
  for (double i = left; i + step < right; i += step)
  {
    printRowInTable(out << "\n", i, max_mem, err);
  }
  printRowInTable(out << "\n", right, max_mem, err);
  out << "\n";
}
