#include "lnPlusOneOverMinusOne.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

class LnTermGenerator {
  public:
    explicit LnTermGenerator(double x):
      oneOverXSquared(1 / (x * x)),
      term(2 / x),
      number(0)
    {}

    double operator()()
    {
      if (number == 0) {
        number++;
        return term;
      }
      term *= (number++) * 2 - 1;
      term *= oneOverXSquared;
      term /= number * 2 - 1;
      return term;
    }
  private:
    double oneOverXSquared;
    double term;
    unsigned number;
};

double odintsov::lnPlusOneOverMinusOne(double x, double absError, unsigned numberMax)
{
  if ((x <= 2.0) || (x >= 3.0)) {
    throw std::invalid_argument("x is set incorrectly");
  }
  double result = 0.0;
  LnTermGenerator generateTerm(x);
  double term = 0.0;
  for (unsigned i = 0; i < numberMax; i++) {
    term = generateTerm();
    if (term < absError) {
      break;
    }
    result += term;
  }
  if (term > absError) {
    throw std::runtime_error("absolute error not achieved");
  }
  return result;
}

std::ostream& odintsov::outputComparison(std::ostream& out, double x, double absError, unsigned numberMax)
{
  out << std::setw(7) << std::setprecision(5) << x << ' ';
  out << std::setw(7) << std::setprecision(5) << lnPlusOneOverMinusOne(x, absError, numberMax) << ' ';
  return out << std::setw(7) << std::setprecision(5) << std::log((x + 1) / (x - 1));
}

std::ostream& odintsov::outputComparisonTable(std::ostream& out, double l, double r, double step, double absError, unsigned num)
{
  if (r < l) {
    throw std::invalid_argument("interval set incorrectly");
  }
  for (double x = l; x < r; x += step) {
    outputComparison(out, x, absError, num) << '\n';
  }
  return outputComparison(out, r, absError, num);
}
