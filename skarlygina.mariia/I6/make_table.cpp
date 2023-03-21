#include "make_table.h"
#include <cmath>
#include <iomanip>
#include "sinx.h"

void printTableRow(std::ostream& out, double x, double error, unsigned members)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << sinx(x, error, members) << ' ';
  out << std::setw(10) << std::setprecision(5) << std::sin(x) << '\n';
}

void printTable(std::ostream& out, double error, unsigned members, double left_border, double right_border, double step)
{
  for (double x = left_border; x <= right_border; x = x + step)
  {
    printTableRow(out, x, error, members);
    if (x + step >= right_border)
    {
      printTableRow(out, right_border, error, members);
    }
  }
}
