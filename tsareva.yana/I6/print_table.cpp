#include "print_table.h"
#include <iomanip>
#include <cmath>
#include "arccos.h"

void printRowInTable(std::ostream & out, double x, unsigned members, double absError)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << arcCos(x, absError, members) << ' ';
  out << std::setw(10) << std::setprecision(5) << std::acos(x) << '\n';
}

void printTable(std::ostream & out, double left_limit, double right_limit, double step, unsigned members, double absError)
{
  for (double x = left_limit; x + step <= right_limit; x = x + step)
  {
    printRowInTable(out, x, absError, members);
  }
  printRowInTable(out, right_limit, absError, members);
  out << '\n';
}
