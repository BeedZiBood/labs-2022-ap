#include "printrow.h"
#include <iomanip>
#include <cmath>
#include "arccos.h"

void printRowInTable(std::ostream & out, double x, double absError, unsigned maxnumber)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << countArccos(x, absError, maxnumber) << " ";
  out << std::setw(10) << std::setprecision(5) << std::acos(x) << "\n";
}

void printTable(std::ostream & out, double borderleft, double borderright, double step, unsigned maxnumber, double absError)
{
  for (double i = borderleft; i + step < borderright; i += step)
  {
    printRowInTable(out << "\n", i, maxnumber, absError);
  }
  printRowInTable(out << "\n", borderright, maxnumber, absError);
  out << "\n";
}
