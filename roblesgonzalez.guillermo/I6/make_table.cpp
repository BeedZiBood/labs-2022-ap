#include "make_table.h"
#include <iomanip>
#include <cmath>
#include "cosx.h"
void printTableRow(std::ostream& out, double x, double cos_error, size_t cos_members)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << cosx(x, cos_error, cos_members);
}
void printTable(std::ostream& out, double cos_error, size_t cos_members, double left, double right, double step)
{
  for (double x = left; x + step <= right; x += step)
  {
    try
    {
      printTableRow(out << "\n", x, cos_error, cos_members);
    }
    catch (const std::exception& e)
    {
      out << e.what() << '\n';
    }
  }
  try
  {
    printTableRow(out << "\n", right, cos_error, cos_members);
  }
  catch (const std::exception& e)
  {
    out << e.what() << '\n';
  }
}
