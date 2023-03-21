#include "make_table.h"
#include <iomanip>
#include "cosx.h"
#include <iostream>
void printTableRow(std::ostream& out, double x, double cos_error, unsigned cos_members)
{
  out << std::left << std::setw(10) << std::setfill(' ') << x;
  out << std::right << std::setw(15) << std::setfill(' ') << std::setprecision(5)
      << cosx(x, cos_error, cos_members) << '\n';
}
void printTable(std::ostream& out, double cos_error, unsigned cos_members, double left, double right, double step)
{
  const int col_width = 15;
  out << std::left << std::setw(col_width) << "x" << std::setw(col_width) << "f(x)" << '\n';
  out << std::left << std::setw(col_width) << std::setfill('-') << ""
      << std::setw(col_width) << std::setfill('-') << ">  out << std::fixed << std::setprecision(5)" << '\n';
  for (double x = left; x <= right; x += step)
  {
    out << std::left << std::setw(col_width) << x << std::setw(col_width) << cosx(x, cos_error, cos_members) << '\n';
  }
}
