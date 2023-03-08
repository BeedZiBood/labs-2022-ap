#include "printTable.h"
#include "coshinus.h"
#include <iostream>
#include <iomanip>
#include <cmath>
void printTableRow(std::ostream &out, double x, double absError, size_t numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << calculateCoshinus(x, absError, numberMax) << " ";
  out << std::setw(10) << std::cosh(x) << "\n";
}
void printTable(std::ostream &out, double l, double r, double step, double absError, size_t numberMax)
{
  if (l > r)
  {
    throw std::logic_error("Invalid borders");
  }
  for (double x = r; x - step >= l; x = x - step)
  {
    try
    {
      printTableRow(out << "\n", x, absError, numberMax);
    }
    catch (const std::exception &e)
    {
      out << e.what() << "\n";
    }
  }
  try
  {
    printTableRow(out << "\n", l, absError, numberMax);
  }
  catch (const std::exception &e)
  {
    out << e.what() << "\n";
  }
}
