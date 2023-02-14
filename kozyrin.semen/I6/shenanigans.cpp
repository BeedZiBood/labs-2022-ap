#include <iomanip>
#include "shenanigans.h"

double unsign(double n)
{
  if (n < 0) {
    return -n;
  }
  return n;
}

double term::operator()()
{
  n += 2;
  value = -value * x * x / (n - 1) / n;
  return value;
}

double customCos(double x, double error, size_t maxNum)
{
  term getNext{x};
  double res = 0;
  double curr = 1;
  size_t cnt = 0;

  while (unsign(curr) >= error) {
    cnt++;
    if (cnt > maxNum) {
      throw std::runtime_error("Expected accuracy could not be achieved");
    }
    res += curr;
    curr = getNext();
  }
  return res;
}

void printRow(std::ostream& stream, double x, double customRes) {
  stream << std::setw(5) << std::setprecision(5) << x << "  ";
  try {
    stream << std::setw(7) << std::setprecision(5) << customRes << "  ";
  }
  catch (std::runtime_error & err) {
    throw err;
  }
  stream << std::setw(5) << std::setprecision(5) << cos(x) << '\n';
}

void printTable(std::ostream& stream, double lb, double rb, double error, size_t maxNum, double step)
{
  for (double i = lb; i <= rb; i += step) {
    try {
      printRow(stream, i, customCos(i, error, maxNum));
    }
    catch (std::runtime_error & err) {
      throw err;
    }
  }
}
