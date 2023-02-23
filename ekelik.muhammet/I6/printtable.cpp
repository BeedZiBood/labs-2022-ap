#include "printtable.h"

#include <iostream>
#include <cstddef>
#include <cmath>
#include <ostream>
#include <iomanip>

void printTableRow(std::ostream& out, const double x, const size_t number_max, const double abs_error, double (*func)(const double, const size_t, const double))
{
  double result = func(x, number_max, abs_error);
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << result << " ";
  out << std::setw(10) << std::setprecision(5) << std::atan(x) << "\n";
}

void printTable(std::ostream& out,
    const double abs_error, const double step, const double x_start, const double x_end, const size_t number_max, double (*func)(const double, const size_t, const double))
{
  for (double x = x_start; x <= x_end; x += step)
  {
    printTableRow(out, x, number_max, abs_error, func);
  }
}
