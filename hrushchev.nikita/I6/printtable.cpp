#include "printtable.hpp"
#include <iostream>
#include <cstddef>
#include <cmath>
#include <ostream>
#include <iomanip>
#include "taylorsum.hpp"

void printTableRow(std::ostream& out, const double x, const size_t number_max, const double abs_error)
{
    double taylor = taylorSum(x, number_max, abs_error);
    out << std::setw(5) << x << " ";
    out << std::setw(10) << std::setprecision(5) << taylor << " ";
    out << std::setw(10) << std::setprecision(5) << 1 / std::sqrt(1 - x * x) << "\n";
}
void printTable(std::ostream& out,
    const double abs_error, const double step, const double x_start, const double x_end, const size_t number_max)
{
  for (double x = x_start; x <= x_end; x += step)
  {
    printTableRow(out, x, number_max, abs_error);
  }
}

