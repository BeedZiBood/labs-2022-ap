#include "print_table.h"
#include <iomanip>
#include <cmath>

void printTable(std::ostream &out, double x, double exp_value)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << exp_value << " ";
  out << std::setw(10) << std::setprecision(5) << std::asin(x) << "\n";
}
