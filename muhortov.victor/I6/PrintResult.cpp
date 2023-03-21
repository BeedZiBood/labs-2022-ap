#include "PrintResult.hpp"
#include <cmath>
#include <iomanip>
#include <cstddef>
#include "CalculateCoshinus.hpp"

void print(std::ostream &out, double x, double ads_Error, size_t number_Max)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << calculateCoshinusInTaylor(x, ads_Error, number_Max) << ' ';
  out << std::setw(10) << std::setprecision(5) << std::cosh(x) << '\n';
}
