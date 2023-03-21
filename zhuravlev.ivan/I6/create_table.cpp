#include "create_table.h"
#include <iomanip>
#include <cmath>
#include "arctg.h"

void printTableRow(std::ostream& out, double x, double absError, unsigned numberMax, int precision)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(precision) << std::atan(x) << ' ';
  out << std::setw(10) << std::setprecision(precision) << arctg(x, absError, numberMax) << '\n';
}

void createTable(std::ostream& out, double l_border, double r_border, double step, double absError, unsigned numberMax, int precision)
{
  if (l_border > r_border)
  {
    throw std::invalid_argument("Wrong input");
  }
  out << "coordinate" << "\t" << "library atan " << std::setw(5) << "selfmade atan\n";
  for (double x = l_border; x <= r_border; x += step)
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
