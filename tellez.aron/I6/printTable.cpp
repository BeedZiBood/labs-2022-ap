#include "printTable.h"
#include <iomanip>
#include <cmath>
#include "findExp.h"

void printRow(std::ostream& out, double x, double absError, unsigned int numberMax)
{
  out << std::setw(5) << x << " "<< std::setprecision(5);
  out << std::setw(10) << exp(x, absError, numberMax) << " ";
  out << std::setw(10) << std::exp(x * (-1)) << "\n";
}

void printTable(std::ostream& out, double left, double right, double step, double absError, unsigned int numberMax)
{
  for (double x = left; x <= right; x += step)
  {
    printRow(out, x, absError, numberMax);
  }
}
