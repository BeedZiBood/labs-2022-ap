#include "printResult.h"
#include "sqrtOnePlusX.h"
#include <cmath>
#include <iomanip>

void printResultRow(std::ostream& out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << " | ";
  out << std::setw(10) << std::setprecision(5) << sqrtOnePlusX(x, absError, numberMax) << " | ";
  out << std::setw(10) << std::setprecision(5) << std::sqrt(1 + x);
}

void printResult(std::ostream& out, double left, double right, double step, double absError, unsigned numberMax)
{
  if (left > right)
  {
    throw std::logic_error("incorrect borders");
  }

  for (double x = left; x + step < right; x = x + step)
  {
    try
    {
      printResultRow(out << '\n', x, absError, numberMax);
    }
    catch (const std::exception& e)
    {
      out << e.what() << '\n';
    }
  }

  try
  {
    printResultRow(out << "\n", right, absError, numberMax);
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}
