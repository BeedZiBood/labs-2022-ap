#include "printtable.h"
#include <iostream>
#include <cstddef>
#include <cmath>
#include <ostream>
#include <iomanip>
#include "arctan.h"

void printTableRow(std::ostream& out, double x, double absError, unsigned maxNumber, int precision)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(precision) << arctan(x, absError, maxNumber) << " ";
  out << std::setw(10) << std::setprecision(precision) << 1.0 / pow(1 + x*x, 2) * x << "\n";
}

void printTable(std::ostream& out, double m1, double m2, double mStep, unsigned maxNumber, double absError, int precision)
{
  out << std::setw(5) << "x" << " ";
  out << std::setw(10) << "arctan(x)" << " ";
  out << std::setw(10) << "atan(x)" << "\n";
  if (m1 > m2)
  {
    throw std::logic_error("Borders error");
  }
  for (double x = m1; x + mStep <= m2; x = x + mStep)
  {
    try
    {
      printTableRow(out << "\n", x, absError, maxNumber, precision);
    }
    catch (const std::exception& e)
    {
      out << e.what() << '\n';
    }
  }
  try
  {
    printTableRow(out << "\n", m2, absError, maxNumber, precision);
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}
