#include "printTable.h"
#include <cmath>
#include <iomanip>
#include "arcTg.h"

void printRowInTable(std::ostream& out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << calcArcTg(x, absError, numberMax) << " ";
  out << std::setw(10) << std::atan(x) << "\n";
}

void printTable(std::ostream& out, double leftBorder, double rightBorder, double step, unsigned numberMax, double absError)
{
  if (leftBorder > rightBorder)
  {
    throw std::invalid_argument("Incorrect borders");
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
}
