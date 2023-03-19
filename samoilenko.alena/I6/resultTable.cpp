#include "resultTable.h"
#include <iomanip>
#include <cmath>
#include "calculateTheExponent.h"

void printTableRow(std::ostream& out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << calculateTheExponent(absError, x, numberMax) << ' ';
  out << std::setw(10) << std::exp(x * x * (-1)) << '\n';
}

void printTable(std::ostream& out, double step, double right, double left, double absError, unsigned numberMax)
{
  for (double x = left; x + step <= right; x += step)
  {
    try
    {
      printTableRow(out, x, absError, numberMax);
    }
    catch (const std::exception &ex)
    {
      out << ex.what() << '\n';
    }
  }
}
