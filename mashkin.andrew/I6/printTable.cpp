#include "printTable.h"
#include <iostream>
#include <cstddef>
#include <cmath>
#include <iomanip>
#include "divSinXOnX.h"

void printRowInTable(std::ostream& out, double x, double absError, unsigned numberMax)
{
  double sinXOnX = sin(x) / x;
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << divSinXOnX(x, absError, numberMax) << " ";
  out << std::setw(10) << std::setprecision(5) << sinXOnX << "\n";
}

void printTable(std::ostream& out, double left, double right, size_t numberMax, double absError, double step)
{
  if (left > right || left * left > 1 || right * right > 1)
  {
    throw std::logic_error("incorrect borders");
  }
  for (double x = left; x + step < right; x += step)
  {
    printRowInTable(out, x, absError, numberMax);
  }
  printRowInTable(out, right, absError, numberMax);
}
