#include "print_table.h"
#include <iomanip>
#include <cmath>

void printTable(std::ostream &out, double x, double exp_value)
{
  std::setprecision(5);
  out << std::setw(5) << x << " ";
  out << std::setw(10) << exp_value << " ";
  out << std::setw(10) << std::asin(x) << "\n";
}
