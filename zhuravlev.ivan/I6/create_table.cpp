#include <iomanip>
#include <cmath>
#include "create_table.h"
#include "arctg.h"

void printTableRow(std::ostream& out, double x, double error, unsigned cnt)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) <<std::setprecision(5) << std::atan(x) << ' ';
  out << std::setw(5) <<std::setprecision(5) << arctg(x, error, cnt) << '\n';
}

void createTable(std::ostream& out, double left_border, double right_border, double step, double error, unsigned members)
{
  for (double i = left_border; i <= right_border; i = i + step)
  {
    printTableRow(out, i, error,  members);
    if (right_border <=  step + i)
    {
      printTableRow(out, i , error, members);
    }
  }
}
