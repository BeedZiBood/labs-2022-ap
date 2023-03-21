#include "table.h"
#include "sequence.h"
#include <iomanip>
#include <cmath>
#include <stdexcept>
void printTable(std::ostream &out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << countSequence(x, absError, numberMax) << " ";
  out << std::setw(10) << (1 / pow(1 + x, 3))  << "\n";
}
void outTable(std::ostream &out, double l, double r, double s, double absError, unsigned numberMax)
{
  if (l > r)
  {
    throw std::logic_error("Borders error");
  }
  for (double x = r; x - s >= l; x = x - s)
  {
    try
    {
      printTable(out << "\n", x, absError, numberMax);
    }
    catch (const std::exception &e)
    {
      out << e.what() << '\n';
    }
  }
  try
  {
    printTable(out << "\n", l, absError, numberMax);
  }
  catch (const std::exception &e)
  {
    out << e.what() << '\n';
  }
}
