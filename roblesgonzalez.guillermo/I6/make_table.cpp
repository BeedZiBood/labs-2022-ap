#include "make_table.h"
#include "cosx.h"
#include <iomanip>
#include <iostream>
#include <cmath>
void printTableRow(std::ostream& out, double x, double cos_error, size_t cos_members)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << cosx(x, cos_error, cos_members) << '\n';
}
void printTable(std::ostream& out, double cos_error, size_t cos_members, double left, double right, double step)
{
  for (double x = left; x + step <= right; x += step)
  {
    printTableRow(out, x, cos_error, cos_members);
  }
  printTableRow(out, right, cos_error, cos_members);
}
