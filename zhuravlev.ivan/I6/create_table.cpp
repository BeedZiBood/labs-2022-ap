#include "create_table.h"
#include <iomanip>
#include <cmath>
#include "arctg.h"

void printTableRow(std::ostream& out, double x, double error, unsigned cnt, int precision)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(precision) << std::atan(x) << ' ';
  out << std::setw(5) << std::setprecision(precision) << arctg(x, error, cnt) << '\n';
}

void createTable(std::ostream& out, double left_border, double right_border, double step, double error, unsigned members, int precision)
{
  if (left_border > right_border)
  {
    throw std::invalid_argument("Wrong input");
  }
  for (double i = left_border; i <= right_border; i += step)
  {
    try
    {
      printTableRow(out, i , error, members , precision);
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what();
    }
  }
}
