#include "printTable.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "calculateAtanSum.h"

void printTable(double abs_error, size_t num_max, double start, double end, double step)
{
  std::cout << std::setw(3) << "N" << std::setw(10) << "x";
  std::cout << std::setw(12) << "sum(x)" << std::setw(12) << "atan(x)" << '\n';
  size_t count_rows = static_cast< size_t >((end - start) / step + 1);
  for (size_t num_row = 1; num_row <= count_rows; ++num_row, start += step)
  {
    std::cout << std::setw(3) << num_row << std::setw(10);
    std::cout << std::fixed << std::setprecision(4) << start;
    std::cout << std::setprecision(6) << std::setw(12) << calculateAtanSum(start, abs_error, num_max);
    std::cout << std::setw(12) << atan(start) << '\n';
  }
}
