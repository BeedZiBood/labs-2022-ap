#include "create_table.h"
#include <iomanip>
#include <cmath>
#include "arctg.h"

void printTableRow(std::ostream& out, double x, double absError, unsigned numberMax, int precision)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(precision) << std::atan(x) << ' ';
  out << std::setw(5) << std::setprecision(precision) << arctg(x, absError, numberMax) << '\n';
}

void createTable(std::ostream& out, double left_border, double right_border, double step, double absError, unsigned numberMax, int precision)
{
  if (left_border > right_border)
  {
    throw std::invalid_argument("Wrong input");
  }
  for (double x = left_border; x <= right_border; x += step)
  {
    try
    {
      printTableRow(out, x , absError, numberMax , precision);
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what();
    }
  }
}
