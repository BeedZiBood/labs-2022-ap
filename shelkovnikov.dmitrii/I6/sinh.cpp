#include "sinh.h"
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include "member_of_series.h"
double sinh(double x, double error, unsigned int k)
{
  MemberOfSeries memberOfSeries(x);
  double res = 0;
  double summand = x;
  unsigned count_summand = 1;
  while (std::fabs(summand) > error && count_summand < k)
  {
    res += summand;
    count_summand++;
    summand = memberOfSeries();
  }
  if (count_summand >= k && abs(summand) > error)
  {
    throw std::out_of_range("The specified accuracy has not been reached");
  }
  return res;
}
void print_row(std::ostream &out, double x, double error, unsigned int k)
{
  out << std::fixed << std::setfill(' ') << std::setw(5) << std::setprecision(2);
  out << x << ' ';
  out << sinh(x, error, k);
}
void print_table(std::ostream &out, double left, double right, double step, double error, unsigned k)
{
  if (left > right)
  {
    throw std::out_of_range("Right more then left");
  }
  for (; left <= right; left += step)
  {
    try
    {
      print_row(out, left, error, k);
    }
    catch (const std::out_of_range &e)
    {
      out << e.what();
    }
    out << '\n';
  }
}
