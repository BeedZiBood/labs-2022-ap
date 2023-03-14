#include "printtable.h"
#include <iostream>
#include <cstddef>
#include <cmath>
#include <ostream>
#include <iomanip>
#include "arctan.h"

void printTableRow(std::ostream& out, double x, double absError, unsigned maxNumber)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << arctan(x, maxNumber, absError) << " ";
  out << std::setw(10) << std::setprecision(5) << std::atan(x) << "\n";
}

void printTable(std::ostream& out, double m1, double m2, double mStep, size_t maxNumber, double absError)
{
  for (double x = m1; x + mStep <= m2; x = x + mStep)
  {
    try
    {
      printTableRow(out << "\n", x, absError, maxNumber);
    }
    catch (const std::exception& e)
    {
      out << e.what() << '\n';
    }
  }
}
