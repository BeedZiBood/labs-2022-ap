#include "printTable.h"
#include "defineArcSin.h"
#include <cmath>
#include <iomanip>

void printRowInTable(std::ostream& out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << defineArcSin(x, absError, numberMax) << " ";
  out << std::setw(10) << std::setprecision(5) << std::asin(x) << "\n";
}

void printTable(std::ostream& out, double leftBorder, double rightBorder, double step, unsigned numberMax, double absError)
{
  if (leftBorder > rightBorder)
  {
    throw std::logic_error("incorrect borders");
  }
  for (double x = leftBorder; x + step < rightBorder; x = x + step)
  {
    try
    {
      printRowInTable(out << "\n", x, absError, numberMax);
    }
    catch (const std::exception& e)
    {
      out << e.what() << '\n';
    }
  }
  try
  {
    printRowInTable(out << "\n", rightBorder, absError, numberMax);
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}
