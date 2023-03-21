#include "PrintTableRow.hpp"
#include <iomanip>
#include <cmath>

void printTableRow(std::ostream &out, double x, double custom_exp)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << custom_exp << " ";
  out << std::setw(10) << std::setprecision(5) << std::exp(-1 * (x * x)) << "\n";
}
