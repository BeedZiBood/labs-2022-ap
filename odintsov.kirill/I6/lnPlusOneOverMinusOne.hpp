#ifndef LNPLUSONEOVERMINUSONE_HPP
#define LNPLUSONEOVERMINUSONE_HPP

#include <iosfwd>

namespace odintsov {
  double lnPlusOneOverMinusOne(double x, double absError, unsigned numberMax);
  std::ostream& outputComparison(std::ostream& out, double x, double absError, unsigned numberMax);
  std::ostream& outputComparisonTable(std::ostream& out, double l, double r, double step, double absError, unsigned num);
}

#endif
