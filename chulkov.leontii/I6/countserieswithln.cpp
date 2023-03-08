#include "countserieswithln.h"
#include <cmath>
#include <stdexcept>

class TaylorSeriesWithLn
{
  public:
    explicit TaylorSeriesWithLn(double x):
      x_(x),
      degree_(x),
      m_(0.0),
      n_(1)
    {
      if (x <= 2 || x >= 3)
      {
        throw std::invalid_argument("x out of range");
      }
    }
    double operator()()
    {
      m_ = 2 / ((2 * n_ - 1) * x_);
      x_ *= degree_ * degree_;
      n_++;
      return m_;
    }
  private:
    double x_;
    double degree_;
    double m_;
    unsigned n_;
};

double countSeriesWithLn(double x, double error, unsigned c)
{
  double sum = 0;
  TaylorSeriesWithLn ln(x);
  while (c-- > 0 && std::abs(ln()) > error)
  {
    sum += ln();
  }
  if (c == 0)
  {
    throw std::invalid_argument("Maximum number of repetitions exceeded\n");
  }
  return sum;
}
