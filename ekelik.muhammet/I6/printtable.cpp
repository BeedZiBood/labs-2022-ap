#include "printtable.h"
#include <iostream>
#include <cstddef>
#include <cmath>
#include <ostream>
#include <iomanip>
#include "arctan.h"

void printTableRow(std::ostream& out, double x, size_t maxNumber, double absError)
{
  double result = arctan(x, maxNumber, absError);
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << result << " ";
  out << std::setw(10) << std::setprecision(5) << std::atan(x) << "\n";
}

void printTable(std::ostream& out, double absError, double mStep, double m1, double m2, size_t maxNumber)
{
  for (double x = m1; x <= m2; x += mStep)
  {
    printTableRow(out, x, maxNumber, absError);
  }
}
