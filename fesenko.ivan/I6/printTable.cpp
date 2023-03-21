#include "printTable.h"
#include <cmath>
#include <iomanip>
#include "countExponent.h"

void printTableRow(std::ostream &out, double x, unsigned numberMax, double absError)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << countExponent(x, absError, numberMax) << " ";
  out << std::setw(10) << std::setprecision(5) << std::exp(x) << "\n";
}

void printTable(std::ostream &out, double left, double right, double step, unsigned numberMax, double absError)
{
  for (double x = left; x < right; x += step) {
    printTableRow(out, x, numberMax, absError);
    if (x + step > right) {
      printTableRow(out, right, numberMax, absError);
    }
  }
}
