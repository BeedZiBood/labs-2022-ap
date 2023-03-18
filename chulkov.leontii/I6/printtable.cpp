#include "printtable.h"
#include "countserieswithln.h"
#include <iomanip>
#include <cmath>

void printTableRow(std::ostream& out, double x, double error, unsigned c)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << countSeriesWithLn(x, error, c) << " ";
  out << std::setw(10) << std::log((x + 1) / (x - 1)) << "\n";
}

void printTable(std::ostream& out, double left, double right, double step, double error, unsigned c)
{
  for (double i = left; std::round(i * 10) / 10 <= right; i += step)
  {
    printTableRow(out, i, error, c);
  }
}
