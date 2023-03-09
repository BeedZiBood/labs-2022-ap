#include "printtable.h"
#include <iostream>
#include <cstddef>
#include <cmath>
#include <ostream>
#include <iomanip>
#include "arctan.h"

void printTableRow(std::ostream& out, double x, size_t max_Number, double abs_Error)
{
  double result = arctan(x, max_Number, abs_Error);
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << result << " ";
  out << std::setw(10) << std::setprecision(5) << std::atan(x) << "\n";
}

void printTable(std::ostream& out, double abs_Error, double m_step, double m_1, double m_2, size_t max_Number)
{
  for (double x = m_1; x <= m_2; x += m_step)
  {
    printTableRow(out, x, max_Number, abs_Error);
  }
}
