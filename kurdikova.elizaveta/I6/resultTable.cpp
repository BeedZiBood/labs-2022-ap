#include "resultTable.h"
#include <iomanip>
#include <cmath>
#include "naturalLogarithm.h"

void printTableRow(std::ostream& out, const double x, const size_t numberMax, const double absError)
{
  out << std::left << std::setprecision(10) << "| " << std::setw(5) << x;
  out << " | " << std::setw(14) << getNaturalLog(x, numberMax, absError);
  out << " | " << std::setw(23) << std::log((x + 1) / (x - 1)) << " |\n";
}

void printTable(std::ostream& out, const double left, const double right,
    const double step, const size_t numberMax, const double absError)
{
  const double EPS = 0.1E-10;
  out << "|-------|----------------|-------------------------|\n";
  out << "|   X   |  Taylor's row  |  std::log((x+1)/(x-1))  |\n";
  out << "|-------|----------------|-------------------------|\n";
  for (double x = left; x < right; x += step)
  {
    printTableRow(out, x, numberMax, absError);
    if (std::fabs(x + step - right) < EPS || x + step > right)
    {
      printTableRow(out, right, numberMax, absError);
      out << "|_______|________________|_________________________|\n";
      return;
    }
  }
  out << "|_______|________________|_________________________|\n";
}
