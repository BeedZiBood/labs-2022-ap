#include "printTable.h"
#include <ostream>
#include <iomanip>
#include <cmath>
#include <cstddef>
#include "countArth.h"

void createTableRow(std::ostream& out, double x, double absError, unsigned members)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << countArth(x, absError, members) << ' ';
  out << std::setw(10) << std::setprecision(5) << std::atanh(x) << '\n';
}

void createTable(std::ostream& out, double x, size_t members, double absError)
{
  try
  {
    createTableRow(out, x, absError, members);
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}

void printTable(std::ostream& out, double left, double right, size_t members, double absError, double step)
{
  for (double x = left; x + step <= right; x = x + step)
  {
    createTable(out << "\n", x, members, absError);
  }
  createTable(out << "\n", right, members, absError);
}
