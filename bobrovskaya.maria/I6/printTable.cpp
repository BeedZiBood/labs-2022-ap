#include <iomanip>
#include <cmath>
#include "calculationE.h"
void printTableRow(std::ostream& out, double x, double absError, unsigned numberMax)
{
out << std::setw(5) << x << ' ';
out << std::setw(10) << std::setprecision(5) << calculationExp(x, absError, numberMax) << ' ';
out << std::setw(10) << std::exp(x * (-1)) <<  '\n';
}
void printTable(std::ostream& out, double left, double right, double step, double absError, unsigned numberMax)
{
  for (double x = left; x + step <= right; x += step)
  {
    try
    {
      printTableRow(out, x, absError, numberMax);
    }
    catch (const std::exception &e)
    {
      out << e.what() << '\n';
    }
  }
}
